%{
#include "y.tab.h"
%}
%%
[0-9]+    { sscanf(yytext, "%d", &yylval.num);
            return NUM; }

[a-z]	  { yylval.num = *yytext - 'a';	return VAR; }



[+\-*/%&\^|]"="|"<<="|">>=" { yylval.num = (int) yytext[0]; return ASSIGN;}


[=]*	 { return *yytext; }

[+\-/*]  { return *yytext; }


[\^&|~]	  { return *yytext; }


"<<" { return LSHIFT; }

">>" { return RSHIFT; }

[Dd][Uu][Mm][Pp]		{ return DUMP;	}
	
[Cc][Ll][Ee][Aa][Rr]	{ return CLEAR;	}

[ \t]*				

.         { return yytext[0]; }
