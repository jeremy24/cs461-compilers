%{
#include "y.tab.h"
%}
%%
[0-9]+    { sscanf(yytext, "%d", &yylval.num);
            return NUM; }
.         { return yytext[0]; }
