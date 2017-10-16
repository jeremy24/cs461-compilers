/*
 * This file defines an example yacc grammar for simple C expressions.
 */

%{
	#include <stdio.h>
	int sym[26] =  {0};
%}

%union {
  int num;
}

%token <num> NUM
%token <num> VAR

%token<num> LSHIFT;
%token<num> RSHIFT;

%token<num> ASSIGN;

%type <num> expr




%%
commands:
	|	commands command ';'
	;

command	:	expr				{ printf("%d\n", $1); }
		|	VAR '='	expr		{ sym[$1] = $3;}		
		|	VAR ASSIGN expr		{
									int flag = $2;
									int * curr = sym + $1;
									

									switch(flag)
									{
										case (int) '+':
											*curr = *curr + $3;
											break;
										
										case (int) '-':
											*curr = *curr - $3;
											break;

										case (int) '*':
											*curr = (*curr) * $3;
											break;	
										
										case (int) '/':
											*curr = *curr / $3;
											break;
										
										case (int) '%':
											*curr = *curr % $3;
											break;
										
										case (int) '<':
											*curr = *curr << $3;
											break;
										
										case (int) '>':
											*curr = *curr >> $3;
											break;

										case (int) '&':
											*curr = *curr & $3;
											break;

										case (int) '^':
											*curr = *curr ^ $3;
											break;

										case (int) '|':
											*curr = *curr | $3;	
											break;
									}
								}
	;

expr	:	{;}		
		|   NUM                 { $$ = $1; }
		|	VAR					{ $$ = sym[$1]; }
		/*|	VAR '=' expr		{ sym[$1] = $3; }*/
		
		
		// or
		| expr '|' expr			{ int v = $1; $$ = v | $3; }

		// xor
		| expr '^' expr			{ int v = $1; $$ = v ^ $3; }
	
		// and
		|	expr '&' expr		{ int v = $1; $$ = v & $3; }	

		| expr LSHIFT expr		{ int v = $1; $$ = v << $3; }
		| expr RSHIFT expr		 { int v = $1; $$ = v >> $3; }

		|	expr '+' expr		{ int v = $1; $$ = v + $3; }
		|	expr '-' expr		{ int v = $1; $$ = v - $3; }		

		|	expr '*' expr		{ int v = $1;  $$ = v * $3; }
		|	expr '/' expr		{ int v = $1;  $$ = v / $3;	}
		|	expr '%' expr		{ int v = $1;  $$ = v % $3; }

		|	'-'	expr			{ int v = -$2; $$ = v;	}	
		
		|	'~' expr			{ int v = ~$2;	$$ = v; }
		
		| '(' expr ')'			{ $$ = $2; }
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
