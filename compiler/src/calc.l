%{
#include <stdlib.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
void yyerror(char *);
%}
%%


[1-9][0-9]* {
 yylval.iValue = atoi(yytext);
 return INTEGER;
 }
[-()<>=+*/;{}.] {
 return *yytext;
 }
[ \n] {return '\n';}

[ \t]+ ; /* ignore whitespace */
. yyerror("Unknown character");
%%
int yywrap(void) {
 return 1;
} 


