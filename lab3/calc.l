%{
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
void yyerror(char *);
%}
%%

[a-z] {
 yylval.sIndex = *yytext - 'a';
 return VARIABLE;
 } 
[1-9][0-9]* {
 yylval.iValue = atoi(yytext);
 return INTEGER;
 }
[-()<>=+*/;{}.] {
 return *yytext;
 }
[ \n] {return '\n';}

"begindecl" {return begin;}
"enddecl" {return end;}
"print" {return PRINT;}

[ \t]+ ; /* ignore whitespace */

. yyerror("Unknown character");
%%
int yywrap(void) {
 return 1;
} 


