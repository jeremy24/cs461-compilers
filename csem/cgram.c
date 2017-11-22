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

#line 2 "cgram.y"
  /* grammar for subset of C. The grammar does not recognize all C syntax:
     For example:
     1. Character literals
     2. Structres
     3. Double constants
     4. Nested paraenthesis of the form "if((x == 1))"
     5. etc.
  */
# include <stdio.h>
# include "cc.h"
# include "scan.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"
#line 18 "cgram.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
   int inttype;
   char *str_ptr;
   struct sem_rec *rec_ptr;
   struct id_entry *id_ptr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 48 "y.tab.c"

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

#define ID 257
#define CON 258
#define STR 259
#define CHAR 260
#define ELSE 261
#define FLOAT 262
#define DOUBLE 263
#define FOR 264
#define IF 265
#define INT 266
#define RESERVED 267
#define RETURN 268
#define WHILE 269
#define DO 270
#define CONTINUE 271
#define BREAK 272
#define GOTO 273
#define LVAL 274
#define SET 275
#define SETOR 276
#define SETXOR 277
#define SETAND 278
#define SETLSH 279
#define SETRSH 280
#define SETADD 281
#define SETSUB 282
#define SETMUL 283
#define SETDIV 284
#define SETMOD 285
#define OR 286
#define AND 287
#define BITOR 288
#define BITXOR 289
#define BITAND 290
#define EQ 291
#define NE 292
#define GT 293
#define GE 294
#define LT 295
#define LE 296
#define LSH 297
#define RSH 298
#define ADD 299
#define SUB 300
#define MUL 301
#define DIV 302
#define MOD 303
#define UNARY 304
#define NOT 305
#define COM 306
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   12,   12,   13,   13,   15,   15,    7,    7,    8,
    8,    8,   10,   10,   10,   10,   14,   16,    9,    9,
   18,   18,   19,   19,   20,   11,    5,   21,   17,   17,
   22,   22,   25,   25,   23,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,    6,    6,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    3,    3,   26,   26,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    1,    1,
};
static const short yylen[] = {                            2,
    1,    0,    2,    2,    1,    0,    3,    2,    3,    1,
    3,    4,    1,    1,    1,    1,    3,    4,    2,    1,
    2,    3,    2,    4,    0,    0,    0,    3,    0,    2,
    2,    3,    2,    3,    0,    2,    7,   11,   10,   11,
   16,    2,    2,    3,    2,    3,    1,    1,    0,    1,
    3,    3,    3,    3,    3,    3,    4,    4,    2,    1,
    1,    3,    0,    1,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    2,    2,    1,    3,
    4,    3,    1,    1,    1,    4,
};
static const short yydefred[] = {                         2,
    0,    0,   20,   13,   14,   15,   16,    0,    0,    0,
    3,    5,   29,    4,    0,    0,    0,    0,    8,    0,
    0,    9,   21,    0,    0,    6,    0,   17,   30,    0,
   23,    0,   22,    0,    0,   11,    0,   93,   94,    0,
    0,    0,    0,   26,    0,    0,    0,    0,    0,    0,
   48,   29,    0,    0,    0,   47,   31,    0,    0,    0,
    0,   12,    0,    0,   33,    0,    0,    0,   45,    0,
   26,   25,   42,   43,    0,    0,   86,   87,   88,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   36,    0,   32,   24,    7,    0,   90,    0,
    0,    0,    0,    0,    0,    0,   46,    0,   35,   44,
   28,   92,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   83,   84,   85,   34,   96,    0,   91,   26,   59,    0,
    0,    0,    0,    0,    0,   26,   26,   26,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   35,   26,    0,    0,    0,    0,   57,    0,   25,   26,
   26,   27,   37,   35,    0,    0,   26,   27,    0,   27,
   35,   26,    0,    0,   26,   39,   26,   26,   38,   40,
   25,   35,   27,   26,   41,
};
static const short yydgoto[] = {                          1,
   54,  115,  111,  116,  187,  175,    8,   19,    9,   10,
   72,    2,   11,   12,   34,   13,   20,   17,   25,  119,
   56,   29,   30,   57,   58,  113,
};
static const short yysindex[] = {                         0,
    0, -173,    0,    0,    0,    0,    0,   -7,   -9, -219,
    0,    0,    0,    0, -210,  221,  -73,  -21,    0,  -53,
  -21,    0,    0, -210,   10,    0,  -92,    0,    0,    6,
    0, -189,    0, -189,  -14,    0,  -31,    0,    0,   67,
   72,   56,   76,    0,   38,   40, -156, -139,   80,   80,
    0,    0,   80,  705,  644,    0,    0,   29, -210,    5,
 -210,    0,   80,   69,    0,   80,   73,  -35,    0,  660,
    0,    0,    0,    0,   58,   28,    0,    0,    0,    3,
  168,   80,   80,   80,   80,   80,   80,   80,   80,   80,
   80,   80,   80,   80,   80,   80,   80,   80,   80,   80,
   80,   80,    0,  -30,    0,    0,    0,  443,    0, -140,
   37, -140,   87,   73, -158,   54,    0,   73,    0,    0,
    0,    0, -140, -140, -140, -140, -140, -140, -140, -140,
 -140, -140, -140, -117, -176, -100, -112, -112, -295, -295,
    0,    0,    0,    0,    0,   80,    0,    0,    0,   80,
   80,   80,   80,   80,   80,    0,    0,    0,   57, -122,
 -140,   73, -140, -140, -140, -140, -140, -140,   73,   73,
    0,    0,  111, -182,   95, -132,    0,  -97,    0,    0,
    0,    0,    0,    0,   73,   80,    0,    0,   61,    0,
    0,    0,  106,  126,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,  169,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -23,    0,   52,
  -15,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -40,    0,    0,  540,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  133,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  109,    0,  112,    0,    0,
    0,    0,    0,    0,    0,  152,    0,    0,    0,   52,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  540,    0,    0,    0,    0,    0,   50,
    0,  -25,    0,    0,  -29,    0,    0,    0,    0,    0,
    0,    0,  500,  512,  563,  582,  593,  604,  624,  635,
  680,  741,  768,  484,  473,  462,  323,  418,  202,  292,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   59,  117,  -19,   -6,   -2,    4,   17,   21,    0,    0,
    0,    0,    0,  119,    0,  -27,    0,  -17,    0,    0,
    0,    0,    0,    0,    0,  129,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  131, 1016,    0, -103, -170,    0,  160,  -11,    0,    9,
  821,    0,    0,    0,    0,    0,  143,    0,    0, -177,
    0, -116,    0,  146,    0,   20,
};
#define YYTABLESIZE 1202
static const short yytable[] = {                         18,
   36,  184,  160,   22,   64,  100,  101,  102,   64,   64,
  149,   60,   31,   58,  159,   64,   19,  192,   18,  194,
   10,   51,   26,  202,   24,   10,   65,  144,   10,   60,
   16,   58,  204,   64,   52,   10,   15,   18,   56,   51,
   59,   26,   61,   10,   54,   53,   21,  106,   15,   26,
   33,   14,   52,   32,  178,   63,   56,   55,  174,   63,
   63,   53,   54,  107,   51,  176,  177,  188,   53,   27,
    4,   28,    5,    6,  195,   55,    7,  147,   62,   53,
  146,  189,   18,    3,   18,  203,    4,   51,    5,    6,
   61,   35,    7,   61,  158,   53,   73,  172,   74,   62,
   75,  193,   62,  156,  157,   26,   66,   26,   53,  109,
   35,   67,   53,   95,   69,   71,  120,   76,   63,   53,
   96,   97,   98,   99,  100,  101,  102,  121,   52,   93,
   94,   95,  150,  151,  152,  153,  154,  155,   96,   97,
   98,   99,  100,  101,  102,  148,  173,   93,   94,   95,
  180,   52,   95,  181,  157,   95,   96,   97,   98,   99,
  100,  101,  102,  182,  197,   35,  198,   63,    1,   63,
   95,   94,   95,   89,   35,   49,   89,   50,   77,   96,
   97,   98,   99,  100,  101,  102,   98,   99,  100,  101,
  102,   89,   95,   60,   80,   95,   96,   97,   98,   99,
  100,  101,  102,  105,   95,  190,    0,    0,  122,    0,
   95,    0,    0,    0,    0,    0,   18,   18,   18,    0,
    0,    0,    0,   18,   18,   89,    0,   18,   18,   18,
   18,   18,   18,    0,    0,    0,    0,    0,    0,   26,
   26,   26,   81,    0,   95,   81,   26,   26,    0,   18,
   26,   26,   26,   26,   26,   26,   60,   60,   58,   18,
   81,   23,   37,   38,   39,   18,   51,   51,    0,   40,
   41,    0,   26,   42,   43,   44,   45,   46,   47,   52,
   52,    0,   26,   56,   56,  104,   38,   39,   26,   54,
   54,    0,   40,   41,   81,   48,   42,   43,   44,   45,
   46,   47,   55,   55,    0,   49,   53,   53,   35,   35,
   35,   50,   68,   38,   39,   35,   35,    0,   48,   35,
   35,   35,   35,   35,   35,   68,   38,   39,   49,   68,
   38,   39,   82,    0,   50,   82,   68,   38,   39,  156,
  157,   35,  156,  157,    0,   48,  156,  157,    0,    0,
   82,   35,    0,    0,    0,   49,    0,   35,   48,    0,
    0,   50,   48,   79,    0,    0,   79,    0,   49,   48,
    0,    0,   49,    0,   50,    0,    0,  114,   50,   49,
    0,   79,    0,    0,   82,   50,   95,   95,   95,   95,
   95,   95,   95,   95,   95,   95,   95,   95,   95,   95,
   95,   95,   95,   95,   95,   95,   95,   95,   95,   95,
   95,   95,   95,   95,   95,   79,    0,    0,   89,   89,
   89,   89,   89,   89,   89,   89,   89,   89,   89,   89,
   89,   89,   89,   89,   89,   89,    0,   95,   95,   95,
   95,   95,   95,   95,   95,   95,   95,   95,   95,   95,
   95,   95,   95,   95,   95,   93,   94,   95,   80,    0,
    0,   80,    0,    0,   96,   97,   98,   99,  100,  101,
  102,    0,    0,    0,    0,    0,   80,    0,    0,    0,
    4,    0,    5,    6,    0,    0,    7,   81,   81,   81,
   81,   81,   81,   81,   81,   81,   81,   81,   81,   81,
   81,   81,   78,    0,    0,   78,    0,    0,    0,    0,
   80,    0,    0,   77,    0,    0,   77,    0,    0,    0,
   78,    0,    0,    0,   76,    0,    0,   76,    0,    0,
    0,   77,    0,    0,    0,  145,    0,    0,    0,    0,
   65,    0,   76,   65,    0,    0,    0,    0,    0,    0,
    0,    0,   66,    0,   78,   66,    0,    0,   65,    0,
    0,    0,    0,    0,    0,   77,    0,    0,    0,    0,
   66,    0,    0,    0,    0,    0,   76,   82,   82,   82,
   82,   82,   82,   82,   82,   82,   82,   82,   82,   82,
   82,   82,   65,    0,    0,    0,    0,    0,   95,    0,
    0,    0,    0,   67,   66,    0,   67,    0,   79,   79,
   79,   79,   79,   79,   79,   79,   79,   79,   79,   79,
   79,   67,   68,    0,    0,   68,    0,    0,    0,    0,
    0,    0,    0,   69,    0,    0,   69,    0,    0,    0,
   68,    0,    0,    0,   70,    0,    0,   70,    0,    0,
    0,   69,    0,    0,    0,   67,    0,    0,    0,    0,
    0,    0,   70,    0,   71,    0,    0,   71,    0,    0,
    0,    0,    0,    0,   68,   72,    0,    0,   72,    0,
    0,    0,   71,    0,    0,   69,    0,    0,    0,    0,
    0,    0,    0,   72,    0,    0,   70,    0,    0,    0,
    0,    0,  103,   80,   80,   80,   80,   80,   80,   80,
   80,   80,   80,   80,   80,   80,   71,    0,  117,    0,
   73,    0,    0,   73,    0,    0,    0,   72,    0,    0,
   93,   94,   95,    0,    0,    0,    0,    0,   73,   96,
   97,   98,   99,  100,  101,  102,    0,   78,   78,   78,
   78,   78,   78,   78,   78,   78,   78,   78,   77,   77,
   77,   77,    0,   77,   77,   77,   77,   77,   77,   76,
   76,   76,   73,    0,   76,   76,   76,   76,   76,   76,
    0,   74,    0,    0,   74,   65,   65,    0,    0,    0,
   65,   65,   65,   65,   65,   65,    0,   66,   66,   74,
    0,    0,   66,   66,   66,   66,   66,   66,   75,    0,
    0,   75,    0,    0,   95,   95,   95,   95,   95,   95,
   95,   95,   95,   95,   95,    0,   75,   95,   95,   95,
    0,    0,    0,   74,    0,    0,   95,   95,   95,   95,
   95,   95,   95,    0,    0,    0,    0,    0,   67,   67,
    0,    0,    0,   67,   67,   67,   67,   67,   67,    0,
   75,    0,    0,    0,    0,    0,    0,   68,   68,    0,
    0,    0,   68,   68,   68,   68,   68,   68,   69,   69,
    0,    0,    0,   69,   69,   69,   69,   69,   69,   70,
   70,  118,    0,    0,   70,   70,   70,   70,   70,   70,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   71,
   71,    0,    0,    0,   71,   71,   71,   71,   71,   71,
   72,   72,    0,    0,    0,   72,   72,   72,   72,   72,
   72,   93,   94,   95,    0,    0,    0,    0,    0,    0,
   96,   97,   98,   99,  100,  101,  102,   93,   94,   95,
    0,    0,    0,    0,    0,    0,   96,   97,   98,   99,
  100,  101,  102,    0,    0,   73,   73,    0,  162,    0,
   73,   73,   73,   73,   73,   73,  169,  170,  171,   82,
   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
    0,    0,  179,    0,    0,    0,    0,    0,  183,    0,
  185,  186,    0,    0,    0,    0,    0,  191,    0,    0,
    0,    0,  196,    0,    0,  199,    0,  200,  201,    0,
    0,    0,    0,    0,  205,    0,   74,   74,    0,    0,
    0,   74,   74,   74,   74,   74,   74,    0,    0,    0,
    0,    0,    0,    0,    0,   55,    0,    0,    0,    0,
    0,    0,    0,   75,   75,    0,    0,   70,   75,   75,
   75,   75,   75,   75,   78,   79,    0,    0,   81,    0,
    0,    0,    0,   55,    0,    0,    0,    0,  108,  110,
    0,  112,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  123,  124,  125,
  126,  127,  128,  129,  130,  131,  132,  133,  134,  135,
  136,  137,  138,  139,  140,  141,  142,  143,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  161,    0,    0,    0,  163,  164,  165,  166,  167,
  168,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  112,
};
static const short yycheck[] = {                         40,
   93,  179,  119,   15,   40,  301,  302,  303,   40,   40,
  114,   41,   24,   41,  118,   41,   40,  188,   59,  190,
   44,   41,   40,  201,   16,   41,   58,   58,   44,   59,
   40,   59,  203,   59,   41,   59,   44,  257,   41,   59,
   32,   59,   34,   59,   41,   40,  257,   59,   44,  123,
   41,   59,   59,   44,  171,   91,   59,   41,  162,   91,
   91,   41,   59,   59,   59,  169,  170,  184,   40,   91,
  260,  125,  262,  263,  191,   59,  266,   41,   93,   59,
   44,  185,  123,  257,  125,  202,  260,   59,  262,  263,
   41,   40,  266,   44,   41,   40,   59,   41,   59,   41,
  257,   41,   44,  286,  287,  123,   40,  125,   40,   41,
   59,   40,   40,  290,   59,   40,   59,  257,   91,   40,
  297,  298,  299,  300,  301,  302,  303,  125,  123,  288,
  289,  290,  291,  292,  293,  294,  295,  296,  297,  298,
  299,  300,  301,  302,  303,   59,  269,  288,  289,  290,
   40,  123,   41,   59,  287,   44,  297,  298,  299,  300,
  301,  302,  303,  261,   59,  258,   41,   59,    0,   41,
   59,  289,  290,   41,  123,   59,   44,   59,   48,  297,
  298,  299,  300,  301,  302,  303,  299,  300,  301,  302,
  303,   59,   41,   34,   52,   44,  297,  298,  299,  300,
  301,  302,  303,   58,   93,  186,   -1,   -1,   41,   -1,
   59,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,
   -1,   -1,   -1,  264,  265,   93,   -1,  268,  269,  270,
  271,  272,  273,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,   41,   -1,   93,   44,  264,  265,   -1,  290,
  268,  269,  270,  271,  272,  273,  286,  287,  286,  300,
   59,   41,  257,  258,  259,  306,  286,  287,   -1,  264,
  265,   -1,  290,  268,  269,  270,  271,  272,  273,  286,
  287,   -1,  300,  286,  287,  257,  258,  259,  306,  286,
  287,   -1,  264,  265,   93,  290,  268,  269,  270,  271,
  272,  273,  286,  287,   -1,  300,  286,  287,  257,  258,
  259,  306,  257,  258,  259,  264,  265,   -1,  290,  268,
  269,  270,  271,  272,  273,  257,  258,  259,  300,  257,
  258,  259,   41,   -1,  306,   44,  257,  258,  259,  286,
  287,  290,  286,  287,   -1,  290,  286,  287,   -1,   -1,
   59,  300,   -1,   -1,   -1,  300,   -1,  306,  290,   -1,
   -1,  306,  290,   41,   -1,   -1,   44,   -1,  300,  290,
   -1,   -1,  300,   -1,  306,   -1,   -1,  305,  306,  300,
   -1,   59,   -1,   -1,   93,  306,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,  293,  294,  295,  296,  297,  298,
  299,  300,  301,  302,  303,   93,   -1,   -1,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,
  298,  299,  300,  301,  302,  303,   -1,  286,  287,  288,
  289,  290,  291,  292,  293,  294,  295,  296,  297,  298,
  299,  300,  301,  302,  303,  288,  289,  290,   41,   -1,
   -1,   44,   -1,   -1,  297,  298,  299,  300,  301,  302,
  303,   -1,   -1,   -1,   -1,   -1,   59,   -1,   -1,   -1,
  260,   -1,  262,  263,   -1,   -1,  266,  286,  287,  288,
  289,  290,  291,  292,  293,  294,  295,  296,  297,  298,
  299,  300,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   93,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   59,   -1,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
   -1,   59,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   41,   -1,   59,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   41,   -1,   93,   44,   -1,   -1,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   59,   -1,   -1,   -1,   -1,   -1,   93,  286,  287,  288,
  289,  290,  291,  292,  293,  294,  295,  296,  297,  298,
  299,  300,   93,   -1,   -1,   -1,   -1,   -1,   59,   -1,
   -1,   -1,   -1,   41,   93,   -1,   44,   -1,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  297,
  298,   59,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   59,   -1,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
   -1,   59,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   -1,   59,   -1,   41,   -1,   -1,   44,   -1,   -1,
   -1,   -1,   -1,   -1,   93,   41,   -1,   -1,   44,   -1,
   -1,   -1,   59,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   -1,   -1,   93,   -1,   -1,   -1,
   -1,   -1,   59,  286,  287,  288,  289,  290,  291,  292,
  293,  294,  295,  296,  297,  298,   93,   -1,   59,   -1,
   41,   -1,   -1,   44,   -1,   -1,   -1,   93,   -1,   -1,
  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   59,  297,
  298,  299,  300,  301,  302,  303,   -1,  286,  287,  288,
  289,  290,  291,  292,  293,  294,  295,  296,  286,  287,
  288,  289,   -1,  291,  292,  293,  294,  295,  296,  286,
  287,  288,   93,   -1,  291,  292,  293,  294,  295,  296,
   -1,   41,   -1,   -1,   44,  286,  287,   -1,   -1,   -1,
  291,  292,  293,  294,  295,  296,   -1,  286,  287,   59,
   -1,   -1,  291,  292,  293,  294,  295,  296,   41,   -1,
   -1,   44,   -1,   -1,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  285,   -1,   59,  288,  289,  290,
   -1,   -1,   -1,   93,   -1,   -1,  297,  298,  299,  300,
  301,  302,  303,   -1,   -1,   -1,   -1,   -1,  286,  287,
   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,   -1,
   93,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,   -1,
   -1,   -1,  291,  292,  293,  294,  295,  296,  286,  287,
   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,  286,
  287,   71,   -1,   -1,  291,  292,  293,  294,  295,  296,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,
  287,   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,
  286,  287,   -1,   -1,   -1,  291,  292,  293,  294,  295,
  296,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,
  297,  298,  299,  300,  301,  302,  303,  288,  289,  290,
   -1,   -1,   -1,   -1,   -1,   -1,  297,  298,  299,  300,
  301,  302,  303,   -1,   -1,  286,  287,   -1,  148,   -1,
  291,  292,  293,  294,  295,  296,  156,  157,  158,  275,
  276,  277,  278,  279,  280,  281,  282,  283,  284,  285,
   -1,   -1,  172,   -1,   -1,   -1,   -1,   -1,  178,   -1,
  180,  181,   -1,   -1,   -1,   -1,   -1,  187,   -1,   -1,
   -1,   -1,  192,   -1,   -1,  195,   -1,  197,  198,   -1,
   -1,   -1,   -1,   -1,  204,   -1,  286,  287,   -1,   -1,
   -1,  291,  292,  293,  294,  295,  296,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   30,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  286,  287,   -1,   -1,   42,  291,  292,
  293,  294,  295,  296,   49,   50,   -1,   -1,   53,   -1,
   -1,   -1,   -1,   58,   -1,   -1,   -1,   -1,   63,   64,
   -1,   66,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   82,   83,   84,
   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
   95,   96,   97,   98,   99,  100,  101,  102,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  146,   -1,   -1,   -1,  150,  151,  152,  153,  154,
  155,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  186,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"ID","CON","STR","CHAR","ELSE","FLOAT","DOUBLE","FOR","IF","INT","RESERVED",
"RETURN","WHILE","DO","CONTINUE","BREAK","GOTO","LVAL","SET","SETOR","SETXOR",
"SETAND","SETLSH","SETRSH","SETADD","SETSUB","SETMUL","SETDIV","SETMOD","OR",
"AND","BITOR","BITXOR","BITAND","EQ","NE","GT","GE","LT","LE","LSH","RSH","ADD",
"SUB","MUL","DIV","MOD","UNARY","NOT","COM",
};
static const char *yyrule[] = {
"$accept : prog",
"prog : externs",
"externs :",
"externs : externs extern",
"extern : dcl ';'",
"extern : func",
"dcls :",
"dcls : dcls dcl ';'",
"dcl : type dclr",
"dcl : dcl ',' dclr",
"dclr : ID",
"dclr : ID '[' ']'",
"dclr : ID '[' CON ']'",
"type : CHAR",
"type : FLOAT",
"type : DOUBLE",
"type : INT",
"func : fhead stmts '}'",
"fhead : fname fargs '{' dcls",
"fname : type ID",
"fname : ID",
"fargs : '(' ')'",
"fargs : '(' args ')'",
"args : type dclr",
"args : args ',' type dclr",
"s :",
"m :",
"n :",
"block : '{' stmts '}'",
"stmts :",
"stmts : stmts lblstmt",
"lblstmt : b stmt",
"lblstmt : b labels stmt",
"labels : ID ':'",
"labels : labels ID ':'",
"b :",
"stmt : expr ';'",
"stmt : IF '(' cexpr ')' m lblstmt m",
"stmt : IF '(' cexpr ')' m lblstmt ELSE n m lblstmt m",
"stmt : WHILE '(' m cexpr ')' m s lblstmt n m",
"stmt : DO m s lblstmt WHILE '(' m cexpr ')' ';' m",
"stmt : FOR '(' expro ';' m cexpro ';' m expro n ')' m s lblstmt n m",
"stmt : CONTINUE ';'",
"stmt : BREAK ';'",
"stmt : GOTO ID ';'",
"stmt : RETURN ';'",
"stmt : RETURN expr ';'",
"stmt : block",
"stmt : ';'",
"cexpro :",
"cexpro : cexpr",
"cexpr : expr EQ expr",
"cexpr : expr NE expr",
"cexpr : expr LE expr",
"cexpr : expr GE expr",
"cexpr : expr LT expr",
"cexpr : expr GT expr",
"cexpr : cexpr AND m cexpr",
"cexpr : cexpr OR m cexpr",
"cexpr : NOT cexpr",
"cexpr : expr",
"exprs : expr",
"exprs : exprs ',' expr",
"expro :",
"expro : expr",
"expr : lval SET expr",
"expr : lval SETOR expr",
"expr : lval SETXOR expr",
"expr : lval SETAND expr",
"expr : lval SETLSH expr",
"expr : lval SETRSH expr",
"expr : lval SETADD expr",
"expr : lval SETSUB expr",
"expr : lval SETMUL expr",
"expr : lval SETDIV expr",
"expr : lval SETMOD expr",
"expr : expr BITOR expr",
"expr : expr BITXOR expr",
"expr : expr BITAND expr",
"expr : expr LSH expr",
"expr : expr RSH expr",
"expr : expr ADD expr",
"expr : expr SUB expr",
"expr : expr MUL expr",
"expr : expr DIV expr",
"expr : expr MOD expr",
"expr : BITAND lval",
"expr : SUB expr",
"expr : COM expr",
"expr : lval",
"expr : ID '(' ')'",
"expr : ID '(' exprs ')'",
"expr : '(' expr ')'",
"expr : CON",
"expr : STR",
"lval : ID",
"lval : ID '[' expr ']'",

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
#line 208 "cgram.y"
# include <stdio.h>
# include <stdlib.h>

extern int lineno;

/* 
 * main - read a program, and parse it
 */
main(int argc, char *argv)
{

   enterblock();
   initlex();
   enterblock();
   if (yyparse())
      yyerror("syntax error");
   exit(0);
}

/*
 * yyerror - issue error message
 */
yyerror(char msg[])
{
   fprintf(stderr, " %s.  Line %d\n", msg, lineno);
}
#line 665 "y.tab.c"

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
case 1:
#line 44 "cgram.y"
	{}
break;
case 2:
#line 47 "cgram.y"
	{}
break;
case 3:
#line 48 "cgram.y"
	{}
break;
case 4:
#line 51 "cgram.y"
	{}
break;
case 5:
#line 52 "cgram.y"
	{}
break;
case 6:
#line 55 "cgram.y"
	{}
break;
case 7:
#line 56 "cgram.y"
	{}
break;
case 8:
#line 59 "cgram.y"
	{ yyval.id_ptr = dcl(yystack.l_mark[0].id_ptr, yystack.l_mark[-1].inttype, 0); }
break;
case 9:
#line 60 "cgram.y"
	{ yyval.id_ptr = dcl(yystack.l_mark[0].id_ptr, yystack.l_mark[-2].id_ptr->i_type&~T_ARRAY, 0); }
break;
case 10:
#line 63 "cgram.y"
	{ yyval.id_ptr = dclr(yystack.l_mark[0].str_ptr, 0, 1); }
break;
case 11:
#line 64 "cgram.y"
	{ yyval.id_ptr = dclr(yystack.l_mark[-2].str_ptr, T_ARRAY, 1); }
break;
case 12:
#line 65 "cgram.y"
	{ yyval.id_ptr = dclr(yystack.l_mark[-3].str_ptr, T_ARRAY, atoi(yystack.l_mark[-1].str_ptr)); }
break;
case 13:
#line 68 "cgram.y"
	{ yyval.inttype = T_INT; }
break;
case 14:
#line 69 "cgram.y"
	{ yyval.inttype = T_DOUBLE; }
break;
case 15:
#line 70 "cgram.y"
	{ yyval.inttype = T_DOUBLE; }
break;
case 16:
#line 71 "cgram.y"
	{ yyval.inttype = T_INT; }
break;
case 17:
#line 74 "cgram.y"
	{ ftail(); }
break;
case 18:
#line 77 "cgram.y"
	{ fhead(yystack.l_mark[-3].id_ptr); }
break;
case 19:
#line 80 "cgram.y"
	{ yyval.id_ptr = fname(yystack.l_mark[-1].inttype, yystack.l_mark[0].str_ptr); }
break;
case 20:
#line 81 "cgram.y"
	{ yyval.id_ptr = fname(T_INT, yystack.l_mark[0].str_ptr); }
break;
case 21:
#line 84 "cgram.y"
	{ enterblock(); }
break;
case 22:
#line 85 "cgram.y"
	{ enterblock(); }
break;
case 23:
#line 88 "cgram.y"
	{ dcl(yystack.l_mark[0].id_ptr, yystack.l_mark[-1].inttype, PARAM); }
break;
case 24:
#line 89 "cgram.y"
	{ dcl(yystack.l_mark[0].id_ptr, yystack.l_mark[-1].inttype, PARAM); }
break;
case 25:
#line 92 "cgram.y"
	{ startloopscope(); }
break;
case 26:
#line 95 "cgram.y"
	{ yyval.inttype = m(); }
break;
case 27:
#line 98 "cgram.y"
	{ yyval.rec_ptr = n(); }
break;
case 28:
#line 101 "cgram.y"
	{ }
break;
case 29:
#line 104 "cgram.y"
	{ }
break;
case 30:
#line 105 "cgram.y"
	{ }
break;
case 31:
#line 108 "cgram.y"
	{ }
break;
case 32:
#line 109 "cgram.y"
	{ }
break;
case 33:
#line 112 "cgram.y"
	{ labeldcl(yystack.l_mark[-1].str_ptr); }
break;
case 34:
#line 113 "cgram.y"
	{ labeldcl(yystack.l_mark[-1].str_ptr); }
break;
case 35:
#line 116 "cgram.y"
	{ bgnstmt(); }
break;
case 36:
#line 120 "cgram.y"
	{ }
break;
case 37:
#line 122 "cgram.y"
	{ doif(yystack.l_mark[-4].rec_ptr, yystack.l_mark[-2].inttype, yystack.l_mark[0].inttype); }
break;
case 38:
#line 124 "cgram.y"
	{ doifelse(yystack.l_mark[-8].rec_ptr, yystack.l_mark[-6].inttype, yystack.l_mark[-3].rec_ptr, yystack.l_mark[-2].inttype, yystack.l_mark[0].inttype); }
break;
case 39:
#line 126 "cgram.y"
	{ dowhile(yystack.l_mark[-7].inttype, yystack.l_mark[-6].rec_ptr, yystack.l_mark[-4].inttype, yystack.l_mark[-1].rec_ptr, yystack.l_mark[0].inttype); }
break;
case 40:
#line 128 "cgram.y"
	{ dodo(yystack.l_mark[-9].inttype, yystack.l_mark[-4].inttype, yystack.l_mark[-3].rec_ptr, yystack.l_mark[0].inttype); }
break;
case 41:
#line 130 "cgram.y"
	{ dofor(yystack.l_mark[-11].inttype, yystack.l_mark[-10].rec_ptr, yystack.l_mark[-8].inttype, yystack.l_mark[-6].rec_ptr, yystack.l_mark[-4].inttype, yystack.l_mark[-1].rec_ptr, yystack.l_mark[0].inttype); }
break;
case 42:
#line 132 "cgram.y"
	{ docontinue(); }
break;
case 43:
#line 134 "cgram.y"
	{ dobreak(); }
break;
case 44:
#line 136 "cgram.y"
	{ dogoto(yystack.l_mark[-1].str_ptr); }
break;
case 45:
#line 138 "cgram.y"
	{ doret((struct sem_rec *) NULL); }
break;
case 46:
#line 140 "cgram.y"
	{ doret(yystack.l_mark[-1].rec_ptr); }
break;
case 47:
#line 142 "cgram.y"
	{ }
break;
case 48:
#line 144 "cgram.y"
	{ }
break;
case 49:
#line 147 "cgram.y"
	{ yyval.rec_ptr = node(0, 0, n(), 0); }
break;
case 50:
#line 148 "cgram.y"
	{}
break;
case 51:
#line 151 "cgram.y"
	{ yyval.rec_ptr = rel("==", yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 52:
#line 152 "cgram.y"
	{ yyval.rec_ptr = rel("!=", yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 53:
#line 153 "cgram.y"
	{ yyval.rec_ptr = rel("<=", yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 54:
#line 154 "cgram.y"
	{ yyval.rec_ptr = rel(">=", yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 55:
#line 155 "cgram.y"
	{ yyval.rec_ptr = rel("<",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 56:
#line 156 "cgram.y"
	{ yyval.rec_ptr = rel(">",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 57:
#line 157 "cgram.y"
	{ yyval.rec_ptr = ccand(yystack.l_mark[-3].rec_ptr, yystack.l_mark[-1].inttype, yystack.l_mark[0].rec_ptr); }
break;
case 58:
#line 158 "cgram.y"
	{ yyval.rec_ptr = ccor(yystack.l_mark[-3].rec_ptr, yystack.l_mark[-1].inttype, yystack.l_mark[0].rec_ptr); }
break;
case 59:
#line 159 "cgram.y"
	{ yyval.rec_ptr = ccnot(yystack.l_mark[0].rec_ptr); }
break;
case 60:
#line 160 "cgram.y"
	{ yyval.rec_ptr = ccexpr(yystack.l_mark[0].rec_ptr); }
break;
case 61:
#line 163 "cgram.y"
	{ yyval.rec_ptr = yystack.l_mark[0].rec_ptr; }
break;
case 62:
#line 164 "cgram.y"
	{ yyval.rec_ptr = exprs(yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 63:
#line 167 "cgram.y"
	{}
break;
case 64:
#line 168 "cgram.y"
	{}
break;
case 65:
#line 171 "cgram.y"
	{ yyval.rec_ptr = set("",   yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 66:
#line 172 "cgram.y"
	{ yyval.rec_ptr = set("|",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 67:
#line 173 "cgram.y"
	{ yyval.rec_ptr = set("^",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 68:
#line 174 "cgram.y"
	{ yyval.rec_ptr = set("&",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 69:
#line 175 "cgram.y"
	{ yyval.rec_ptr = set("<<", yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 70:
#line 176 "cgram.y"
	{ yyval.rec_ptr = set(">>", yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 71:
#line 177 "cgram.y"
	{ yyval.rec_ptr = set("+",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 72:
#line 178 "cgram.y"
	{ yyval.rec_ptr = set("-",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 73:
#line 179 "cgram.y"
	{ yyval.rec_ptr = set("*",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 74:
#line 180 "cgram.y"
	{ yyval.rec_ptr = set("/",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 75:
#line 181 "cgram.y"
	{ yyval.rec_ptr = set("%",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 76:
#line 182 "cgram.y"
	{ yyval.rec_ptr = opb("|",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 77:
#line 183 "cgram.y"
	{ yyval.rec_ptr = opb("^",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 78:
#line 184 "cgram.y"
	{ yyval.rec_ptr = opb("&",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 79:
#line 185 "cgram.y"
	{ yyval.rec_ptr = opb("<<", yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 80:
#line 186 "cgram.y"
	{ yyval.rec_ptr = opb(">>", yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 81:
#line 187 "cgram.y"
	{ yyval.rec_ptr = op2("+",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 82:
#line 188 "cgram.y"
	{ yyval.rec_ptr = op2("-",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 83:
#line 189 "cgram.y"
	{ yyval.rec_ptr = op2("*",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 84:
#line 190 "cgram.y"
	{ yyval.rec_ptr = op2("/",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 85:
#line 191 "cgram.y"
	{ yyval.rec_ptr = op2("%",  yystack.l_mark[-2].rec_ptr, yystack.l_mark[0].rec_ptr); }
break;
case 86:
#line 193 "cgram.y"
	{ yyval.rec_ptr = yystack.l_mark[0].rec_ptr; }
break;
case 87:
#line 194 "cgram.y"
	{ yyval.rec_ptr = op1("-",      yystack.l_mark[0].rec_ptr); }
break;
case 88:
#line 195 "cgram.y"
	{ yyval.rec_ptr = op1("~",      yystack.l_mark[0].rec_ptr); }
break;
case 89:
#line 196 "cgram.y"
	{ yyval.rec_ptr = op1("@",      yystack.l_mark[0].rec_ptr); }
break;
case 90:
#line 197 "cgram.y"
	{ yyval.rec_ptr = call(yystack.l_mark[-2].str_ptr, (struct sem_rec *) NULL); }
break;
case 91:
#line 198 "cgram.y"
	{ yyval.rec_ptr = call(yystack.l_mark[-3].str_ptr, yystack.l_mark[-1].rec_ptr); }
break;
case 92:
#line 199 "cgram.y"
	{ yyval.rec_ptr = yystack.l_mark[-1].rec_ptr; }
break;
case 93:
#line 200 "cgram.y"
	{ yyval.rec_ptr = con(yystack.l_mark[0].str_ptr); }
break;
case 94:
#line 201 "cgram.y"
	{ yyval.rec_ptr = string(yystack.l_mark[0].str_ptr); }
break;
case 95:
#line 204 "cgram.y"
	{ yyval.rec_ptr = id(yystack.l_mark[0].str_ptr); }
break;
case 96:
#line 205 "cgram.y"
	{ yyval.rec_ptr = indx(id(yystack.l_mark[-3].str_ptr), yystack.l_mark[-1].rec_ptr); }
break;
#line 1255 "y.tab.c"
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
