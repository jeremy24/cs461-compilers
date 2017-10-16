/*
 * This file defines an example yacc grammar for simple C expressions.
 */

%{
#include <stdio.h>
%}

%union {
  int num;
}

%token <num> NUM

%type <num> expr

%%
commands:
	|	commands command
	;

command	:	expr ';'      { printf("%d\n", $1); }
	;

expr	:	expr '+' NUM    { $$ = $1 + $3; }
	|	NUM                 { $$ = $1; }
	;

%%

main()
{
   if (yyparse())
      printf("\nInvalid expression.\n");
   else
      printf("\nCalculator off.\n");
}

yyerror(s)
char *s;
{
   fprintf(stderr, "%s\n", s);
}
