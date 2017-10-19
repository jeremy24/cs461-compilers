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

%token<num> LSHIFT
%token<num> RSHIFT

%token<num> DUMP
%token<num> CLEAR

%token<num> ASSIGN

%type <num> token

%type <num> expr
%type <num> expr1
//%type <num>	expr2
//%type <num> expr3
//%type <num> expr4
//%type <num> expr5
//%type <num> expr6
%type <num> expr7
%type <num> expr8
%type <num> expr9
//%left '+' '*'


%%
commands:
	|	commands command ';'
	;

command	:	expr				{ printf("%d\n", $1); }
		|	DUMP				{	
									size_t i = 0;
									for( i = 0 ; i < 26 ; ++i) 
									{
										char toke = i + 'a';
										printf("%c: %d\n",  toke, + sym[i]);
									}
								}
		|	CLEAR				{	memset(sym, 0x0, sizeof(int)*26); }

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





expr	:	VAR					{ $$ = sym[$1]; }
		|	NUM					{ $$ = $1;		}
		|   expr1				{ $$ = $1;		}
		|	expr1 '+' expr		{ $$ = $1 + $3; }
		|	expr1 '-' expr		{ $$ = $1 - $3;	}
		;
	
expr1	:	expr9				{ $$ = $1;		}
		|	expr9 '*' token		{ $$ = $1 * $3; }
		|	expr9 '/' token		{ $$ = $1 / $3; }
		;




// negation
expr7	:	expr8
		|	'-' expr			{ $$ = -($2);	}
		;

// bitwise not
expr8	:	expr9				{ $$ = $1;	}
		|	'~' expr			{ $$ = ~$2;	}
		;

// parens
expr9	:	token				{ $$ = $1;		}
		|	'(' expr ')'		{ $$ = $2;		}
		
	

/*
				
		// or
		| expr '|' NUM			{ int v = $1; $$ = v | $3; }

		// xor
		| expr '^' NUM		{ int v = $1; $$ = v ^ $3; }
	
		// and
		|	expr '&' NUM		{ int v = $1; $$ = v & $3; }	

		| expr LSHIFT NUM		{ int v = $1; $$ = v << $3; }
		| expr RSHIFT NUM		 { int v = $1; $$ = v >> $3; }

		|	expr '*' NUM		{ int v = $1; $$ = v * $3; }
		|	expr '-' NUM		{ int v = $1; $$ = v - $3; }		

		|	expr '+' NUM		{ int v = $1;  $$ = v + $3; }
		|	expr '/' NUM		{ int v = $1;  $$ = v / $3;	}
		|	expr '%' NUM		{ int v = $1;  $$ = v % $3; }

		|	'-'	expr			{ int v = -$2; $$ = v;	}	
		
		|	'~' expr		{ int v = ~$2;	$$ = v; }
		
		| '(' expr ')'			{ $$ = $2; }

*/
		;

token	:	NUM		{ $$ = $1;		}
		|	VAR		{ $$ = sym[$1]; }
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
