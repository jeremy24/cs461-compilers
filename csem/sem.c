# include <stdio.h>
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


void skip();
void putbak(int);
void yyeccor(char*);

static void print_id_entry( struct id_entry * );
static void print_scope(int);
static void print_type(int);
static int eat_chars(int);
static char * ret_chars(int);



/*
 * backpatch - backpatch list of quadruples starting at p with k
 */
void backpatch(struct sem_rec *p, int k)
{
	fprintf(stderr, "sem: backpatch not implemented\n");
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
	fprintf(stderr, "sem: call not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * ccand - logical and
 */
struct sem_rec *ccand(struct sem_rec *e1, int m, struct sem_rec *e2)
{
	fprintf(stderr, "sem: ccand not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * ccexpr - convert arithmetic expression to logical expression
 */
struct sem_rec *ccexpr(struct sem_rec *e)
{
	fprintf(stderr, "sem: ccexpr not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * ccnot - logical not
 */
struct sem_rec *ccnot(struct sem_rec *e)
{
	fprintf(stderr, "sem: ccnot not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * ccor - logical or
 */
struct sem_rec *ccor(struct sem_rec *e1, int m, struct sem_rec *e2)
{
	fprintf(stderr, "sem: ccor not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * con - constant reference in an expression
 */
struct sem_rec *con(char *x)
{
	//fprintf(stderr, "sem: con implemented\n");
	//fprintf(stderr, "con val: %s\n", x);

	int type;

	switch ( localtypes[0] )
	{
		case 'i':
			printf("t%d := %s\n", nexttemp(), x);
			type = T_INT;
			return node(currtemp(), T_INT, NULL, NULL);
		case 'f':
			printf("t%d := %s\n", nexttemp(), x);
			return node(currtemp(), T_DOUBLE, NULL, NULL);
		default:
			fprintf(stderr, "Invalid type in con: %c\n", localtypes[0]);
			return (struct sem_rec *) NULL;
	}

	//struct sem_rec * = node(nexttmp(), localtypes[0], NULL,NULL);
	//return node(currtemp, ;
}

/*
 * dobreak - break statement
 */
void dobreak()
{
	fprintf(stderr, "sem: dobreak not implemented\n");
}

/*
 * docontinue - continue statement
 */
void docontinue()
{
	fprintf(stderr, "sem: docontinue not implemented\n");
}

/*
 * dodo - do statement
 */
void dodo(int m1, int m2, struct sem_rec *e, int m3)
{
	fprintf(stderr, "sem: dodo not implemented\n");
}

/*
 * dofor - for statement
 */
void dofor(int m1, struct sem_rec *e2, int m2, struct sem_rec *n1,
		int m3, struct sem_rec *n2, int m4)
{
	fprintf(stderr, "sem: dofor not implemented\n");
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
	fprintf(stderr, "sem: doif not implemented\n");
}

/*
 * doifelse - if then else statement
 */
void doifelse(struct sem_rec *e, int m1, struct sem_rec *n,
		int m2, int m3)
{
	fprintf(stderr, "sem: doifelse not implemented\n");
}

/*
 * doret - return statement
 */
void doret(struct sem_rec *e)
{
	// fprintf(stderr, "sem: doret not implemented\n");
	switch ( e->s_mode )
	{
		case T_DOUBLE:
			printf("retf t%d\n", e->s_place);
			break;
		case T_INT:
			printf("reti t%d\n", e->s_place);
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
	fprintf(stderr, "sem: dowhile not implemented\n");
}

/*
 * endloopscope - end the scope for a loop
 */
void endloopscope(int m)
{
	fprintf(stderr, "sem: endloopscope not implemented\n");
}

/*
 * exprs - form a list of expressions
 */
struct sem_rec *exprs(struct sem_rec *l, struct sem_rec *e)
{
	fprintf(stderr, "sem: exprs not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * fhead - beginning of function body
 */
void fhead(struct id_entry *p) {
	printf("func %s\n", p->i_name);
	unsigned int i;


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
	printf("fend\n");
	exit_block();
}

/*
 * id - variable reference
 */
struct sem_rec *id(char *x)
{
	fprintf(stderr, "sem: id\n");
	//printf("%s\n", localtypes);
	
	// formaltypes -> chars
	// formalnum -> int num of them



	if (localtypes[0] == 'f') {
		return node(nexttemp(), T_DOUBLE, NULL, NULL);
	} else if ( localtypes[0] == 'i' )
	{
		return node(nexttemp(), T_INT, NULL, NULL);
	} else
	{
		fprintf(stderr, "Invalid type: %c\n", localtypes[0]);
	}

	return ((struct sem_rec *) NULL);
}

/*
 * indx - subscript
 */
struct sem_rec *indx(struct sem_rec *x, struct sem_rec *i)
{
	fprintf(stderr, "sem: indx not implemented\n");
	return ((struct sem_rec *) NULL);
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
	fprintf(stderr, "sem: m not implemented\n");
	return (0);
}

/*
 * n - generate goto and return backpatch pointer
 */
struct sem_rec *n()
{
	fprintf(stderr, "sem: n not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * op1 - unary operators
 */
struct sem_rec *op1(char *op, struct sem_rec *y)
{

	fprintf(stderr, "sem: op1 not implemented\n");
	fprintf(stderr, "op: %s\n", op);	
	return ((struct sem_rec *) NULL);
}

/*
 * op2 - arithmetic operators
 */
struct sem_rec *op2(char *op, struct sem_rec *x, struct sem_rec *y)
{
	fprintf(stderr, "sem: op2 not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * opb - bitwise operators
 */
struct sem_rec *opb(char *op, struct sem_rec *x, struct sem_rec *y)
{
	fprintf(stderr, "sem: opb not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * rel - relational operators
 */
struct sem_rec *rel(char *op, struct sem_rec *x, struct sem_rec *y)
{
	fprintf(stderr, "sem: rel not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * set - assignment operators
 */
struct sem_rec *set(char *op, struct sem_rec *x, struct sem_rec *y)
{
	fprintf(stderr, "sem: set not implemented\n");
	return ((struct sem_rec *) NULL);
}

/*
 * startloopscope - start the scope for a loop
 */
void startloopscope()
{
	fprintf(stderr, "sem: startloopscope not implemented\n");
}

/*
 * string - generate code for a string
 */
struct sem_rec *string(char *s)
{
	fprintf(stderr, "sem: string not implemented\n");
	return ((struct sem_rec *) NULL);
}


char * ret_chars( int target )
{
	int c;
	char * ret = malloc(255);
	int i = 0;

	while ( c = getchar() )
	{
		if ( c == EOF ) break;
		if ( c == target ) break;
		//if ( c == ' ') continue;
		char cc = (char) c;
		printf("keeping: %c\n", cc);	
		ret[i] = cc;
		i++;
	}
	ret[i] = '\0';
	return ret;
}



int eat_chars(int target)
{
	int c;
	int n;

	while ( c = getchar() )
	{
		if ( c == EOF ) break;
		if ( c == target ) break;
		++n;
	}
	return n;
}





void print_type(int t)
{
	switch(t)
	{
		case T_INT:
			printf("int");
			break;
		case T_STR:
			printf("str");
			break;
		case T_DOUBLE:
			printf("double");
			break;
		case T_PROC:
			printf("procedure");
			break;
		case T_ARRAY:
			printf("array");
			break;
		case T_ADDR:
			printf("Addr");
			break;
		case T_LBL:
			printf("label");
			break;
		default:
			fprintf(stderr, "Unknown Type");
	}
}

void print_scope(int s)
{
	if ( s == LOCAL )
	{
		printf("local");
	} else if ( s == PARAM )
	{
		printf("param");

	} else if ( s == GLOBAL )
	{
		printf("global");
	} else {
		fprintf(stderr, "Unknown Scope");
	}
}


void print_id_entry( struct id_entry * s )
{
	printf("\n");
	printf("Name: %s\n", s->i_name);
	printf("\tType: ");  print_type(s->i_type);
	printf("\n");
	printf("\tScope: "); print_scope(s->i_scope);
	printf("\n");
}














