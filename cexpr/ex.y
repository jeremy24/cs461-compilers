/*
 * This file defines an example yacc grammar for simple C expressions.
 */

%{
	#include <stdio.h>
	#include <limits.h>

	#define ADD		0
	#define SUB		1
	#define MULT	2
	
	int sym[26] =  {0};
	int error = 0;
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


%type <num> EXPR
%type <num> EXPR_ADD_SUB
%type <num>	EXPR_MULT_DIV

%type <num> EXPR_ASSIGN
%type <num> EXPR_ASSIGN_SIMPLE
%type <num> EXPR_ASSIGN_LOOP

%type <num> EXPR_BIT_NOT
%type <num> EXPR_NEGATE

%type <num> EXPR_SHIFT

%type <num> EXPR_BIT_AND

%type <num> EXPR_BIT_XOR

%type <num> EXPR_BIT_OR

%type <num> EXPR_PARENS

%type <num> command;
//%left '+' '*'


%%
commands:	command	';'
		|	commands command ';'
		;

command	:	EXPR			{  if(error==0) { printf("%d\n", $1); } error=0; }
		|	VAR				{  }
		|	DUMP				{	
									size_t i = 0;
									for( i = 0 ; i < 26 ; ++i) 
									{
										char toke = i + 'a';
										printf("%c: %d\n",  toke, + sym[i]);
									}
								}
		|	CLEAR				{	memset(sym, 0x0, sizeof(int)*26); }




EXPR :	EXPR_ASSIGN;
	
EXPR_ASSIGN		:	EXPR_ASSIGN_SIMPLE			
				|	VAR ASSIGN EXPR_ADD_SUB			{
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
									printf("%d\n", *curr);
								}
	;


EXPR_ASSIGN_LOOP	:	EXPR_ASSIGN_LOOP '=' VAR { sym[$3] = sym[$1]; }
					;

EXPR_ASSIGN_SIMPLE	:	EXPR_BIT_OR				{ if ( error == 0 ) { /*printf("E: %d", $1);*/ } error = 0; }
					/*|	VAR '=' NUM				{ sym[$1] = $3; printf("ASN SMP %d\n", sym[$1]); }
					|	VAR '=' VAR				{ sym[$1] = sym[$3]; printf("%d\n", sym[$1]); }
					*/
					|	VAR '=' EXPR_BIT_NOT	{ sym[$1] = $3; if(error==0) { printf("%c: %d", (char)$1+'a', $3); error=1; }else{ error=0; } }
					;


EXPR_BIT_OR		:	EXPR_BIT_XOR	
				|	EXPR_BIT_OR	'|' EXPR_BIT_XOR { $$ = $1 | $3; }

EXPR_BIT_XOR	:	EXPR_BIT_AND	
				|	EXPR_BIT_XOR '^' EXPR_BIT_AND { $$ = $1 ^ $3; }
				;


EXPR_BIT_AND	:	EXPR_SHIFT
				|	EXPR_BIT_AND '&' EXPR_SHIFT { $$ = $1 & $3; }
				;



EXPR_SHIFT	:	EXPR_ADD_SUB	
			|	EXPR_SHIFT LSHIFT EXPR_ADD_SUB	{ $$ = $1 << $3; }
			|	EXPR_SHIFT RSHIFT EXPR_ADD_SUB	{ $$ = $1 >> $3; }
			;



EXPR_ADD_SUB	:	EXPR_MULT_DIV	
				|	EXPR_ADD_SUB	'+' EXPR_MULT_DIV	{ if (is_safe($1, $3, ADD)) { $$ = $1 + $3; } else { printf("overflow"); error=1; }	}
				|	EXPR_ADD_SUB	'-'	EXPR_MULT_DIV	{ if (is_safe($1, $3, SUB)) { $$ = $1 - $3; } else { printf("overflow"); error=1; }    }
				;


EXPR_MULT_DIV	:	EXPR_NEGATE	
				|	EXPR_MULT_DIV '*' EXPR_NEGATE		{ if (is_safe($1, $3, MULT)) { $$ = $1 * $3; } else { printf("overflow"); error=1; }    }
				|	EXPR_MULT_DIV '/' EXPR_NEGATE		{ if ( $3 == 0 ) { yyerror("dividebyzero"); error=1; } else { $$ = $1 / $3; }	}
				|	EXPR_MULT_DIV '%' EXPR_NEGATE		{ $$ = $1 % $3; }
				;


EXPR_NEGATE	:	EXPR_BIT_NOT 
			|	'-' EXPR_BIT_NOT	{ $$ = -($2); }
			;



EXPR_BIT_NOT	:	EXPR_PARENS
				|	'~' EXPR_PARENS	{ $$ = ~($2); }
				;


EXPR_PARENS	:	'(' EXPR ')'	{ $$ = $2;	}
			|	VAR				{ $$ = sym[$1]; }
			|	NUM	
			;


%%

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
