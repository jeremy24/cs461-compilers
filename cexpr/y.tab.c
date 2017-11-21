#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 6 "ex.y"
	#include <stdio.h>
	#include <limits.h>

	#define ADD		0
	#define SUB		1
	#define MULT	2
	
	int sym[26] =  {0};
	int error = 0;
#line 17 "ex.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int num;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 40 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUM 257
#define VAR 258
#define LSHIFT 259
#define RSHIFT 260
#define DUMP 261
#define CLEAR 262
#define ASSIGN 263
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,   14,   14,   14,   14,    1,    4,    4,    6,
    5,    5,   12,   12,   11,   11,   10,   10,    9,    9,
    9,    2,    2,    2,    3,    3,    3,    3,    8,    8,
    7,    7,   13,   13,   13,
};
static const short yylen[] = {                            2,
    2,    3,    1,    1,    1,    1,    1,    1,    3,    3,
    1,    3,    1,    3,    1,    3,    1,    3,    1,    3,
    3,    1,    3,    3,    1,    3,    3,    3,    1,    2,
    1,    2,    3,    1,    1,
};
static const short yydefred[] = {                         0,
   35,    0,    5,    6,    0,    0,    0,    0,    3,    0,
    0,    7,    8,   29,   25,    0,    0,    0,    0,   31,
    0,    0,    0,   34,   30,   32,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,   12,   33,    2,    0,    0,   26,   27,   28,    0,
    0,    0,    0,    0,
};
static const short yydgoto[] = {                          8,
    9,   10,   11,   12,   13,    0,   14,   15,   16,   17,
   18,   19,   20,   21,
};
static const short yysindex[] = {                       -31,
    0,  -58,    0,    0,  -33,  -38,    6,  -31,    0,  -15,
   32,    0,    0,    0,    0, -151,  -34,  -81, -106,    0,
  -25,   15,  -33,    0,    0,    0,  -58,    3,   -9,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,    0,
  -15,    0,    0,    0,   32,   32,    0,    0,    0,  -15,
  -15, -151,  -34,  -81,
};
static const short yyrindex[] = {                         0,
    0,  -37,    0,    0,    0,    0,    0,    0,    0,    2,
  -18,    0,    0,    0,    0,   21,  -17,   -3,   24,    0,
    0,    0,    0,    0,    0,    0,  -26,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   31,    0,    0,    0,  -12,   -6,    0,    0,    0,    7,
   11,   26,   -5,   22,
};
static const short yygindex[] = {                         0,
   51,   64,   80,    0,    0,    0,   68,   70,   34,   37,
   39,    0,   78,   84,
};
#define YYTABLESIZE 273
static const short yytable[] = {                         34,
   34,    7,   23,   37,   34,   34,    7,   34,    7,   34,
   34,   34,   38,    5,   34,   34,   34,   39,   34,   22,
   34,    4,   22,   15,   22,   23,   22,   30,   23,   31,
   23,   24,   23,   40,   24,   16,   24,   13,   24,   19,
   22,   15,   19,   43,   20,    7,   23,   20,   21,   44,
    5,   21,   24,   16,    7,   13,   34,   28,   17,    5,
   19,   17,   14,   18,   11,   20,   18,   34,   34,   21,
   52,    9,   25,   32,   53,   22,   15,   54,   33,   17,
   14,   23,   11,   26,   18,   41,   34,   24,   16,    9,
   42,   29,    6,    0,    6,   19,    0,   34,   50,   51,
   20,   47,   48,   49,   21,   22,   15,   35,   36,   45,
   46,   23,    0,    0,   17,    0,    0,   24,   16,   18,
   13,    0,    0,    0,    0,   19,    0,    0,    0,    0,
   20,    6,    0,    0,   21,    0,    0,    0,    0,    0,
    6,    0,    0,    0,   17,   14,    0,    0,    0,   18,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   22,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,   24,
    0,   34,   34,    1,   24,    1,    2,    0,    0,    3,
    4,    0,   34,   34,    0,    0,    0,    0,    0,    0,
   22,   22,    0,    0,    0,    0,   23,   23,    0,    0,
    0,    0,   24,   24,    0,    0,    0,    0,    0,    0,
   19,   19,    1,   27,    0,   20,   20,    0,    0,   21,
   21,    1,   24,
};
static const short yycheck[] = {                         37,
   38,   40,   61,   38,   42,   43,   40,   45,   40,   47,
   37,   38,   94,   45,   41,   42,   43,  124,   45,   38,
   47,   59,   41,   41,   43,   38,   45,   43,   41,   45,
   43,   38,   45,   59,   41,   41,   43,   41,   45,   38,
   59,   59,   41,   41,   38,   40,   59,   41,   38,   59,
   45,   41,   59,   59,   40,   59,   94,    7,   38,   45,
   59,   41,   41,   38,   41,   59,   41,   94,   37,   59,
   37,   41,    5,   42,   38,   94,   94,   39,   47,   59,
   59,   94,   59,    6,   59,   22,  124,   94,   94,   59,
   23,    8,  126,   -1,  126,   94,   -1,  124,   35,   36,
   94,   32,   33,   34,   94,  124,  124,  259,  260,   30,
   31,  124,   -1,   -1,   94,   -1,   -1,  124,  124,   94,
  124,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,
  124,  126,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,
  126,   -1,   -1,   -1,  124,  124,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,
   -1,  259,  260,  257,  258,  257,  258,   -1,   -1,  261,
  262,   -1,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,
  259,  260,   -1,   -1,   -1,   -1,  259,  260,   -1,   -1,
   -1,   -1,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,
  259,  260,  257,  258,   -1,  259,  260,   -1,   -1,  259,
  260,  257,  258,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 263
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,"'~'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"NUM","VAR","LSHIFT","RSHIFT","DUMP","CLEAR","ASSIGN",
};
static const char *yyrule[] = {
"$accept : commands",
"commands : command ';'",
"commands : commands command ';'",
"command : EXPR",
"command : VAR",
"command : DUMP",
"command : CLEAR",
"EXPR : EXPR_ASSIGN",
"EXPR_ASSIGN : EXPR_ASSIGN_SIMPLE",
"EXPR_ASSIGN : VAR ASSIGN EXPR_ADD_SUB",
"EXPR_ASSIGN_LOOP : EXPR_ASSIGN_LOOP '=' VAR",
"EXPR_ASSIGN_SIMPLE : EXPR_BIT_OR",
"EXPR_ASSIGN_SIMPLE : VAR '=' EXPR_BIT_NOT",
"EXPR_BIT_OR : EXPR_BIT_XOR",
"EXPR_BIT_OR : EXPR_BIT_OR '|' EXPR_BIT_XOR",
"EXPR_BIT_XOR : EXPR_BIT_AND",
"EXPR_BIT_XOR : EXPR_BIT_XOR '^' EXPR_BIT_AND",
"EXPR_BIT_AND : EXPR_SHIFT",
"EXPR_BIT_AND : EXPR_BIT_AND '&' EXPR_SHIFT",
"EXPR_SHIFT : EXPR_ADD_SUB",
"EXPR_SHIFT : EXPR_SHIFT LSHIFT EXPR_ADD_SUB",
"EXPR_SHIFT : EXPR_SHIFT RSHIFT EXPR_ADD_SUB",
"EXPR_ADD_SUB : EXPR_MULT_DIV",
"EXPR_ADD_SUB : EXPR_ADD_SUB '+' EXPR_MULT_DIV",
"EXPR_ADD_SUB : EXPR_ADD_SUB '-' EXPR_MULT_DIV",
"EXPR_MULT_DIV : EXPR_NEGATE",
"EXPR_MULT_DIV : EXPR_MULT_DIV '*' EXPR_NEGATE",
"EXPR_MULT_DIV : EXPR_MULT_DIV '/' EXPR_NEGATE",
"EXPR_MULT_DIV : EXPR_MULT_DIV '%' EXPR_NEGATE",
"EXPR_NEGATE : EXPR_BIT_NOT",
"EXPR_NEGATE : '-' EXPR_BIT_NOT",
"EXPR_BIT_NOT : EXPR_PARENS",
"EXPR_BIT_NOT : '~' EXPR_PARENS",
"EXPR_PARENS : '(' EXPR ')'",
"EXPR_PARENS : VAR",
"EXPR_PARENS : NUM",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 196 "ex.y"

main()
{
   if (yyparse())
      printf("\nInvalid expression.\n");
   else
      printf("\nCalculator off.\n");
}



int safe_add(int a, int b)
{
	int t;
	//if ( (a + b) < a ) return 0;
	return 1;
}

int safe_sub( int a, int b)
{
	//if ( (a-b) > a ) return ;
	return 1;
}

int safe_mult(int a, int b)
{
	//if ( (a*b) < a ) return 1;
	return 1;
}
int is_safe(int x, int y, int flag)
{
	switch(flag) 
	{
		case ADD:
			return safe_add(x,y);
		case SUB:
			return safe_sub(x, y);
		case MULT:
			return safe_mult(x, y);
		default:
			yyerror("Invalid flag passed to is_safe");
	}
}

yyerror(s)
char *s;
{
   fprintf(stderr, "%s\n", s);
}
#line 327 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 63 "ex.y"
	{  if(error==0) { printf("%d\n", yystack.l_mark[0].num); } error=0; }
break;
case 4:
#line 64 "ex.y"
	{  }
break;
case 5:
#line 65 "ex.y"
	{	
									size_t i = 0;
									for( i = 0 ; i < 26 ; ++i) 
									{
										char toke = i + 'a';
										printf("%c: %d\n",  toke, + sym[i]);
									}
								}
break;
case 6:
#line 73 "ex.y"
	{	memset(sym, 0x0, sizeof(int)*26); }
break;
case 9:
#line 81 "ex.y"
	{
									int flag = yystack.l_mark[-1].num;
									int * curr = sym + yystack.l_mark[-2].num;
									

									switch(flag)
									{
										case (int) '+':
											*curr = *curr + yystack.l_mark[0].num;
											break;
										
										case (int) '-':
											*curr = *curr - yystack.l_mark[0].num;
											break;

										case (int) '*':
											*curr = (*curr) * yystack.l_mark[0].num;
											break;	
										
										case (int) '/':
											*curr = *curr / yystack.l_mark[0].num;
											break;
										
										case (int) '%':
											*curr = *curr % yystack.l_mark[0].num;
											break;
										
										case (int) '<':
											*curr = *curr << yystack.l_mark[0].num;
											break;
										
										case (int) '>':
											*curr = *curr >> yystack.l_mark[0].num;
											break;

										case (int) '&':
											*curr = *curr & yystack.l_mark[0].num;
											break;

										case (int) '^':
											*curr = *curr ^ yystack.l_mark[0].num;
											break;

										case (int) '|':
											*curr = *curr | yystack.l_mark[0].num;	
											break;
									}
									printf("%d\n", *curr);
								}
break;
case 10:
#line 133 "ex.y"
	{ sym[yystack.l_mark[0].num] = sym[yystack.l_mark[-2].num]; }
break;
case 11:
#line 136 "ex.y"
	{ if ( error == 0 ) { /*printf("E: %d", $1);*/ } error = 0; }
break;
case 12:
#line 140 "ex.y"
	{ sym[yystack.l_mark[-2].num] = yystack.l_mark[0].num; if(error==0) { printf("%c: %d", (char)yystack.l_mark[-2].num+'a', yystack.l_mark[0].num); error=1; }else{ error=0; } }
break;
case 14:
#line 145 "ex.y"
	{ yyval.num = yystack.l_mark[-2].num | yystack.l_mark[0].num; }
break;
case 16:
#line 148 "ex.y"
	{ yyval.num = yystack.l_mark[-2].num ^ yystack.l_mark[0].num; }
break;
case 18:
#line 153 "ex.y"
	{ yyval.num = yystack.l_mark[-2].num & yystack.l_mark[0].num; }
break;
case 20:
#line 159 "ex.y"
	{ yyval.num = yystack.l_mark[-2].num << yystack.l_mark[0].num; }
break;
case 21:
#line 160 "ex.y"
	{ yyval.num = yystack.l_mark[-2].num >> yystack.l_mark[0].num; }
break;
case 23:
#line 166 "ex.y"
	{ if (is_safe(yystack.l_mark[-2].num, yystack.l_mark[0].num, ADD)) { yyval.num = yystack.l_mark[-2].num + yystack.l_mark[0].num; } else { printf("overflow"); error=1; }	}
break;
case 24:
#line 167 "ex.y"
	{ if (is_safe(yystack.l_mark[-2].num, yystack.l_mark[0].num, SUB)) { yyval.num = yystack.l_mark[-2].num - yystack.l_mark[0].num; } else { printf("overflow"); error=1; }    }
break;
case 26:
#line 172 "ex.y"
	{ if (is_safe(yystack.l_mark[-2].num, yystack.l_mark[0].num, MULT)) { yyval.num = yystack.l_mark[-2].num * yystack.l_mark[0].num; } else { printf("overflow"); error=1; }    }
break;
case 27:
#line 173 "ex.y"
	{ if ( yystack.l_mark[0].num == 0 ) { yyerror("dividebyzero"); error=1; } else { yyval.num = yystack.l_mark[-2].num / yystack.l_mark[0].num; }	}
break;
case 28:
#line 174 "ex.y"
	{ yyval.num = yystack.l_mark[-2].num % yystack.l_mark[0].num; }
break;
case 30:
#line 179 "ex.y"
	{ yyval.num = -(yystack.l_mark[0].num); }
break;
case 32:
#line 185 "ex.y"
	{ yyval.num = ~(yystack.l_mark[0].num); }
break;
case 33:
#line 189 "ex.y"
	{ yyval.num = yystack.l_mark[-1].num;	}
break;
case 34:
#line 190 "ex.y"
	{ yyval.num = sym[yystack.l_mark[0].num]; }
break;
#line 676 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
