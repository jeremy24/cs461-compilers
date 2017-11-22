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
extern YYSTYPE yylval;
