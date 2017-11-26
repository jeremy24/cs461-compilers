#include <stdio.h>
# include <stdlib.h>
# include <assert.h>

# include "cc.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"

#define MAXARGS 50
#define MAXLOCS 50

extern int localnum;
extern int formalnum;
extern int ntmp;

extern int  localwidths[MAXLOCS];

extern char formaltypes[MAXARGS];
extern char localtypes[MAXLOCS];
extern struct sem_rec ** top;

int functype;
int relexpr = 0;


void skip();
void putbak(int);
void yyerror(char*);

int _currlabel = 0;
int _currbranch = 0;

int currlabel() { return _currlabel;   }
int nextlabel() { return ++_currlabel; }

int currbr() { return   _currbranch; }
int nextbr() { return ++_currbranch; }


#define MAXLOOPSIZE 50


struct loopjunk {
	struct sem_rec * breaks;
	struct sem_rec * conts;
};

// make a thing so hold all the nonsense from loops
struct loopjunk loopscopes[MAXLOOPSIZE];

int _loop = 0;

struct loopjunk * loopcurr;

int incloop()  { return ++_loop; }
int decloop()  { return --_loop; }
int currloop() { return   _loop; } 

/*
struct sem_rec * cast( struct sem_rec * p, int type)
{
	if ( type == T_DOUBLE && p->s_mode != T_DOUBLE) p->s_mode =  type;
	else if ( type != T_DOUBLE && p->s_mode == T_DOUBLE ) 
	return (p);

}
*/

char char_type( int type )
{
	if ( (type & T_INT)		== T_INT    ) return 'i';
	if ( (type & T_DOUBLE)	== T_DOUBLE ) return 'f';
	if ( (type & T_STR )	== T_STR	) return 's';
	return '?';
}

int int_type ( int type )
{
	if ( (type & T_INT)    == T_INT    ) return T_INT;
	if ( (type & T_DOUBLE) == T_DOUBLE ) return T_DOUBLE;
	if ( (type & T_STR )    == T_STR    ) return T_STR;
	return -1;
}

int are_diff( struct sem_rec * x, struct sem_rec * y )
{
	int xm = x->s_mode;
	int ym = y->s_mode;

	//printf("are diff: %d  %d\n", xm, ym);

	if ( (xm & ym & T_INT) == T_INT ) return 0;
	if ( (xm & ym &T_DOUBLE) == T_DOUBLE) return 0;
	return 1;	
}


//static void print_id_entry( struct id_entry * );
//static void print_scope(int);
//static void print_type(int);
//static int eat_chars(int);
//static char * ret_chars(int);



struct sem_rec * conv_to_int( struct sem_rec * x )
{
	if ( ( x -> s_mode & T_INT ) != T_INT )
	{
		printf("t%d := cvi t%d\n", nexttemp(), x->s_place);
		return node(currtemp(), T_INT, NULL, NULL);
	}
	return x;
}

struct sem_rec * conv_to_float( struct sem_rec * x )
{
	if ( ( x -> s_mode & T_DOUBLE ) != T_DOUBLE )
	{
		printf("t%d := cvf t%d\n", nexttemp(), x->s_place);
		return node(currtemp(), T_DOUBLE, NULL, NULL);
	}
	return x;
}



/*
 * backpatch - backpatch list of quadruples starting at p with k
 */
void backpatch(struct sem_rec *p, int k)
{
	
	// sometimes wwe backpatch null junk in loop
	// so we can leave this out where we are not debugging
	// an if/else issue
	/*
	if ( p == NULL )
	{
		fprintf(stderr, "ERROR backpatch: p is NULL on k = %d\n", k);
		assert(0);
	}
	*/

	//fprintf(stderr, "sem: backpatch not implemented\n");
	for ( ; p ; p = p->back.s_link )
	{
		printf("B%d=L%d\n", p->s_place,k);
	}
}



/*
 * bgnstmt - encountered the beginning of a statement
 */
void bgnstmt()
{
	int c;
	extern int lineno;
	static int laststmt = 0;

	skip();

	c = getchar();
	putbak(c);
	if ( c != '}' && lineno != laststmt )
	{
		printf("bgnstmt %d\n", lineno);
		laststmt = lineno;
	}
	//   fprintf(stderr, "sem: bgnstmt not implemented\n");
}

/*
 * call - procedure invocation
 */
struct sem_rec *call(char *f, struct sem_rec *args)
{
	//fprintf(stderr, "sem: call not implemented\n");
	struct id_entry * p = lookup(f, 0);
	
	int type = T_INT;

	if ( p  == NULL )
	{
		fprintf(stderr, "Unknown function: %s\n", f);
	} else 
	{
		type = char_type(p->i_type);
	}
	

	//int head = args ->s_place;
	//fprintf(stderr, "List head: %d\n", args->s_place);
	int i = 0;

	struct sem_rec * prev;
	
	if ( args != NULL ) args ->s_false = NULL;

	int have_args = args != NULL;

	while ( 1 && have_args )
	{
		//printf("argi t%d\n", args->s_place);
		prev = args;
		if ( args ->back.s_link == NULL ) break;
		args = args -> back.s_link;
		args ->s_false = prev;
	}

	while ( 1 && have_args )
	{
		++i;
		printf("arg%c t%d\n", int_type(args->s_mode) == T_DOUBLE ? 'f' : 'i', args->s_place);
		if ( args ->s_false == NULL ) break;
		args = args ->s_false;
	}

	printf("t%d := global %s\n", nexttemp(), f);
	int call_label = currtemp();
	printf("t%d := f%c t%d %d\n", nexttemp(), char_type(type), call_label, i);
	//printf("fi 

	return node(currtemp(), type, NULL, NULL);
}

/*
 * ccand - logical and
 */
struct sem_rec *ccand(struct sem_rec *e1, int m, struct sem_rec *e2)
{
	//fprintf(stderr, "sem: ccand not implemented\n");
	backpatch(e1->back.s_true, m);
	
	return node(0, 0, e2->back.s_true, merge(e1->s_false, e2->s_false));
}

/*
 * ccexpr - convert arithmetic expression to logical expression
 */
struct sem_rec *ccexpr(struct sem_rec *e)
{
	struct sem_rec * tmp1 = e;


	if ( !relexpr )
	{
		con("0");
		tmp1 = node(nexttemp(), e->s_mode, NULL, NULL);
		printf("t%d := t%d !=%c t%d\n", 
				tmp1->s_place, e->s_place, char_type(e->s_place) == 'f'?'f':'i', e->s_place+1);
	}
	//else
	
		printf("bt t%d B%d\n", tmp1->s_place, nextbr());
		printf("br B%d\n", nextbr());
	//}
	
	tmp1->s_place = currbr();
	e->s_place = currbr()-1;

	//fprintf(stderr, "sem: ccexpr not implemented\n");
	
	
	return node(0,0,
			node(currbr()-1, T_LBL, NULL,NULL), node(currbr(), T_LBL, NULL, NULL)); //((struct sem_rec *) NULL);
}

/*
 * ccnot - logical not
 */
struct sem_rec *ccnot(struct sem_rec *e)
{
	//fprintf(stderr, "sem: ccnot not implemented\n");
	return node(0, 0, e->s_false, e->back.s_true);
}

/*
 * ccor - logical or
 */
struct sem_rec *ccor(struct sem_rec *e1, int m, struct sem_rec *e2)
{
	backpatch(e1->s_false, m);

	//fprintf(stderr, "sem: ccor not implemented\n");

	return node(0, 0, merge(e1->back.s_true, e2->back.s_true), e2->s_false);
}

/*
 * con - constant reference in an expression
 */
struct sem_rec *con(char *x)
{
	//fprintf(stderr, "sem: con implemented\n");
	//fprintf(stderr, "con val: %s\n", x);
	
	struct id_entry * p;

	if ((p = lookup(x, 0)) == NULL) {
		p = install(x, 0);
		p->i_type = T_INT;
		p->i_scope = GLOBAL;
		p ->i_defined = 1;
	}
	printf("t%d := %s\n", nexttemp(), x);
	
	return node(currtemp(), T_INT, NULL, NULL);
}

/*
 * dobreak - break statement
 */
void dobreak()
{
	//fprintf(stderr, "sem: dobreak not implemented\n");

	// generate the junk to do a jump
	struct sem_rec * tmp = n();
	loopcurr->breaks = merge(loopcurr->breaks, tmp);
}

/*
 * docontinue - continue statement
 */
void docontinue()
{
	//fprintf(stderr, "sem: docontinue not implemented\n");
	struct sem_rec * tmp = n();
	loopcurr->conts = merge(loopcurr->conts, tmp);
}

/*
 * dodo - do statement
 */
void dodo(int m1, int m2, struct sem_rec *e, int m3)
{
	//fprintf(stderr, "sem: dodo not implemented\n");

	backpatch(e->back.s_true, m1);
	backpatch(e->s_false, m3);

	//struct loopjunk * top = &loopscopes[ currloop() ] + looptop ;
	
	backpatch(loopcurr->conts, m2);

	endloopscope(m3);
}

/*
 * dofor - for statement
 */
void dofor(int m1, struct sem_rec *e2, int m2, struct sem_rec *n1,
		int m3, struct sem_rec *n2, int m4)
{
	//fprintf(stderr, "sem: dofor not implemented\n");

	if ( e2  )
	{
		backpatch(e2->back.s_true, m3);
		backpatch(e2->s_false, m4);
	}

	//struct loopjunk * top = &loopscopes[ currloop() ];

	backpatch(loopcurr->conts, m2);
	backpatch(n1, m1);
	backpatch(n2, m2);

	if ( e2 )
	{
		endloopscope(m4);
	}


}

/*
 * dogoto - goto statement
 */
void dogoto(char *id)
{
	fprintf(stderr, "sem: dogoto not implemented\n");
}

/*
 * doif - one-arm if statement
 */
void doif(struct sem_rec *e, int m1, int m2)
{
	//fprintf(stderr, "sem: doif not implemented\n");
	//printf("eplace: %d  m1:  %d  m2: %d\n", e->s_place, m1, m2);
	//printf("etype: %d", e->s_mode);

	backpatch(e->back.s_true, m1);
	backpatch(e->s_false, m2);

	//printf("B%d=L%d\n", e->s_place, m1);
	//printf("B%d=L%d\n", e->s_place+1, m2);
	
}

/*
 * doifelse - if then else statement
 */
void doifelse(struct sem_rec *e, int m1, struct sem_rec *n,
		int m2, int m3)
{
	//fprintf(stderr, "sem: doifelse not implemented\n");
	//printf("%d  %d\n", e->s_place, n->s_place);
	//printf("%d %d %d\n", m1, m2, m3);
	//printf("B%d=L%d\n", e->s_place, m1);
	//printf("B%d=L%d\n", e->s_place+1, m2);
	//printf("B%d=L%d\n", n->s_place, m3);

	backpatch(e->back.s_true, m1);
	backpatch(e->s_false, m2);
	backpatch(n, m3);

}

/*
 * doret - return statement
 */
void doret(struct sem_rec *e)
{

	int loc = e->s_place;

	// we need to cast
	if ( functype != e -> s_mode )
	{
		printf("t%d := cv%c t%d\n", nexttemp(), functype == T_INT ? 'i' : 'f', e->s_place);
		loc = currtemp();
	}


	if ( e == NULL ) {
		fprintf(stderr, "NULL passed to doret\n");
		exit(1);
	}

	// fprintf(stderr, "sem: doret not implemented\n");
	switch ( int_type(functype) )
	{
		case T_DOUBLE:
			printf("retf t%d\n", loc);
			break;
		case T_INT:
			printf("reti t%d\n", loc);
			break;
		default:
			fprintf(stderr, "Invalid type in doret: %c\n", localtypes[0]);
	}
}

/*
 * dowhile - while statement
 */
void dowhile(int m1, struct sem_rec *e, int m2, struct sem_rec *n,
		int m3)
{
	//fprintf(stderr, "sem: dowhile not implemented\n");
	backpatch(e->back.s_true, m2);
	backpatch(e->s_false, m3);
	backpatch(n, m1);

	//struct loopjunk * top = &loopscopes[ currloop() ];

	backpatch(loopcurr->conts, m1);
	endloopscope(m3);
}

/*
 * endloopscope - end the scope for a loop
 */
void endloopscope(int m)
{
	//fprintf(stderr, "sem: endloopscope not implemented\n");
	
	struct loopjunk * top = &loopscopes[ currloop() ];

	backpatch(top->breaks, m);

	loopcurr--;
	decloop();
}

/*
 * exprs - form a list of expressions
 */
struct sem_rec *exprs(struct sem_rec *l, struct sem_rec *e)
{
	//fprintf(stderr, "%d -> %d\n", e->s_place, l->s_place);	
	e -> back.s_link = l;
	
	return e;//((struct sem_rec *) NULL);
}

/*
 * fhead - beginning of function body
 */

void fhead(struct id_entry *p) {
	printf("func %s\n", p->i_name);
	unsigned int i;

	functype = p->i_type;

	for (i = 0; i < formalnum; i++) {
		if (formaltypes[i] == 'f') {
			printf("formal 8\n");
		} else if (formaltypes[i] == 'i') {
			printf("formal 4\n");
		} else {
			yyerror("formal type somehow stored incorrectly");
		}
	}
	for (i = 0; i < localnum; i++) {
		if (localtypes[i] == 'f') {
			printf("localloc %d\n", 8 * localwidths[i]);
		} else if (localtypes[i] == 'i') {
			printf("localloc %d\n", 4 * localwidths[i]);
		} else {
			yyerror("formal type somehow stored incorrectly");
		}
	}
}

/*
 * fname - function declaration
 */
struct id_entry *fname(int t, char *id) {
	struct id_entry *p;

	if ((p = lookup(id, 0)) == NULL) {
		p = install(id, 0);
	} else if (p->i_defined) {
		yyerror("procedure previously declared");
	} else if (p->i_type != t) {
		yyerror("function declaration types do not match");
	}

	p->i_type = t;
	p->i_scope = GLOBAL;
	p->i_defined = 1;

	enterblock();

	formalnum = 0;
	localnum = 0;

	return p;
}

/*
 * ftail - end of function body
 */
void ftail()
{
	//fprintf(stderr, "sem: ftail not implemented\n");
	functype = -1;
	printf("fend\n");
	leaveblock();
}



/*
 * id - variable reference
 */
struct sem_rec *id(char *x)
{	
	struct id_entry * p;
	//int type;

	if ((p = lookup(x, 0)) == NULL) {
		fprintf(stderr, "Variable %s not found\n", x);
	} else if ( p->i_defined )
	{	
		if ( p->i_scope == LOCAL )
		{
			printf("t%d := local %d\n", nexttemp(), p->i_offset);
	//		type = localtypes[p->i_offset] == 'f' ? T_DOUBLE : T_INT; //p->i_type;//localtypes[p->i_offset];
		} else if ( p->i_scope == GLOBAL )
		{
			printf("t%d := global %s\n", nexttemp(), p->i_name);
			
			//fprintf(stderr, "Global %s id type = %c  Raw =%d\n", x, type_code(p-> , p->i_type); 
	//		type = int_type( p->i_type);
		} else
		{
			printf("t%d := param %d\n", nexttemp(), p->i_offset);
	//		type = formaltypes[p->i_offset] == 'f' ? T_DOUBLE : T_INT;
			//type = p->i_type;//type = formaltypes[p->i_offset];
		}

	}

	return node(currtemp(), p->i_type | T_ADDR, NULL, NULL);// node(currtemp(), p->i_type, NULL, NULL);
}



/*
 * indx - subscript
 */
struct sem_rec *indx(struct sem_rec *x, struct sem_rec *i)
{
	//fprintf(stderr, "sem: indx not implemented\n");	

	printf("t%d := t%d []%c t%d\n", 
			nexttemp(), x->s_place, char_type(x->s_mode), i->s_place);


	return node(currtemp(), int_type(x->s_mode)&~T_ARRAY, NULL, NULL);
}

/*
 * labeldcl - process a label declaration
 */
void labeldcl(char *id)
{
	fprintf(stderr, "sem: labeldcl not implemented\n");
}

/*
 * m - generate label and return next temporary number
 */
int m()
{
	//fprintf(stderr, "sem: m not implemented\n");
	printf("label L%d\n", nextlabel());

	//node(currlabel(), T_LBL, NULL, NULL); 
	
	return currlabel();
}

/*
 * n - generate goto and return backpatch pointer
 */
struct sem_rec *n()
{
	//fprintf(stderr, "sem: n not implemented\n");
	printf("br B%d\n", nextbr());
	return node(currbr(), 0, NULL, NULL);
}

/*
 * op1 - unary operators
 */
struct sem_rec *op1(char *op, struct sem_rec *y)
{
	//fprintf(stderr, "sem: op1 not implemented\n");

	printf("t%d := %s%c t%d\n", nexttemp(), op, char_type(y->s_mode) , y->s_place);

	return node(currtemp(), y->s_mode & ~T_ADDR, NULL, NULL);
}

/*
 * op2 - arithmetic operators
 */
struct sem_rec *op2(char *op, struct sem_rec *x, struct sem_rec *y)
{
	//fprintf(stderr, "sem: op2 not implemented\n");

	if ( are_diff(x, y) )
	{
		x = conv_to_float(x);
		y = conv_to_float(y);
	}

	printf("t%d := t%d %s%c t%d\n", 
			nexttemp(), x->s_place, op, char_type(x->s_mode) , y->s_place);

	return node(currtemp(), x->s_mode, NULL, NULL);
}

/*
 * opb - bitwise operators
 */
struct sem_rec *opb(char *op, struct sem_rec *x, struct sem_rec *y)
{
	//fprintf(stderr, "sem: opb not implemented\n");
	
	x = conv_to_int(x);
	y = conv_to_int(y);

	printf("t%d := t%d %si t%d\n", nexttemp(), x->s_place, op, y->s_place);

	return node(currtemp(), T_INT, NULL, NULL);
}

/*
 * rel - relational operators
 */
struct sem_rec *rel(char *op, struct sem_rec *x, struct sem_rec *y)
{
	//fprintf(stderr, "sem: rel not implemented\n");

	if ( are_diff(x, y) )
	{
		x = conv_to_float(x);
		y = conv_to_float(y);
	}

	int place1, place2;

	printf("t%d := t%d %s%c t%d\n", nexttemp(), x->s_place, op, char_type(x->s_mode), y->s_place);
	printf("bt t%d B%d\n", currtemp(), nextbr());
	place1 = currbr();

	printf("br B%d\n", nextbr());
	place2=currbr();

	x->s_place=place1;
	y->s_place=place2;

	return node(currlabel(), 0, x, y);
}

/*
 * set - assignment operators
 */
struct sem_rec *set(char *op, struct sem_rec *x, struct sem_rec *y)
{
	//fprintf(stderr, "sem: set not implemented\n");
		
	struct sem_rec * tmp;

	tmp = y;
	char o = *op;

	int arith_op = o == '+' || o == '-' || o == '*' || o == '/' || o == '%';

	// if its a simple assign or an arithmatic operation make
	// sure that the types are the same
	// if its a binary op it will be forced to int
	// as necessary below
	if ( are_diff(x,y) && ( o == '\0' || arith_op) )
	{
		if ( int_type(x->s_mode) == T_INT )
		{
			y = conv_to_int(y);
		} else {
			y = conv_to_float(y);
		}
	}

	// its a plain assignment
	// make sure type are same and setup for printing
	// skip the fancy junk
	if (  o == '\0' )
	{
		// strip off the addr mode
		tmp = y;
		tmp ->s_mode = x->s_mode & ~T_ADDR;
	} else
		// else its not a vanilla assignment
		// its an oper assign so we need to check types
	{


		// if its a binary op assignment
		// conv to ints as per writeup
		// otherwise conversion is already handled above
		if ( o == '|' || o == '&' || o == '^' || o == '<' || o == '>' ) 
		{
			// it has to be ints
			x = conv_to_int(x);
			y = conv_to_int(y);
			// setup the bin part
			opb(op, x, y);
		}

		// print a deref
		printf("t%d := @%c t%d\n", nexttemp(), char_type(x->s_mode), x->s_place); 

		// print the op
		printf("t%d := t%d %s%c t%d\n",
				nexttemp(),currtemp(), op, char_type(x->s_mode), y->s_place);
		tmp ->s_place = currtemp();
	}

	printf("t%d := t%d =%c t%d\n", nexttemp(), x->s_place, char_type(x->s_mode), tmp->s_place);


	return node(currtemp(), tmp->s_mode, tmp->back.s_link, tmp->s_false);

}

/*
 * startloopscope - start the scope for a loop
 */
void startloopscope()
{
	//fprintf(stderr, "sem: startloopscope not implemented\n");

	int scope = incloop();
	if ( scope > MAXLOOPSIZE )
	{
		fprintf(stderr, "AHH loop size of %d is bigger than max of %d BAILING.\n",
				scope, MAXLOOPSIZE);

		exit(1);
	}

	//looptop = 0;

	loopcurr = &loopscopes[ currloop() ];
	loopcurr -> breaks = NULL;
	loopcurr -> conts = NULL;
}

/*
 * string - generate code for a string
 */
struct sem_rec *string(char *s)
{
	//fprintf(stderr, "sem: string not implemented\n");

	printf("t%d := %s\n", nexttemp(), s);
	return node(currtemp(), T_STR, NULL, NULL);

	//return ((struct sem_rec *) NULL);
}




















