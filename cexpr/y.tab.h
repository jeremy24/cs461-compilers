#define NUM 257
#define VAR 258
#define LSHIFT 259
#define RSHIFT 260
#define DUMP 261
#define CLEAR 262
#define ASSIGN 263
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
extern YYSTYPE yylval;
