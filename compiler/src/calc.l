%{

#include<stdio.h>
#include <stdlib.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
void yyerror(char *);
struct sym symTab[100];
%}


%%
[0-9]+ {
		yylval.iValue=atoi(yytext);
		//printf("%s,%d\n",yytext,yylval);
		return NUMBER;

	}
[-()<>=+*/;{}.\n] {
 return *yytext;
 }

[a-z]+ {
	yylval.iValue = symRead(yytext);
	return VARIABLE;
}
[ \t] ; /* ignore whitespace */
. yyerror("Unknown character");

%%

int yywrap()
{
return 1;
}


// %{
// #include <stdlib.h>
// #include "../include/calc3.h"
// #include "../bin/y.tab.h"
// void yyerror(char *);
// %}
// %%
// [\n] {lineno++; return yytext[0];}

// [1-9][0-9]* {
//  yylval.iValue = atoi(yytext);
//  return INTEGER;
//  }
// [-()<>=+*/;{}.] {
//  return *yytext;
//  }
// [ \n] {return '\n';}

// [ \t]+ ; /* ignore whitespace */
// . yyerror("Unknown character");
// %%
// int yywrap(void) {
//  return 1;
// } 

