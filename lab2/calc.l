%{
#define YYSTYPE double
#include<stdio.h>
#include "y.tab.h"
#include "calc3.h"
extern int lineno;
%}


%%
[1-9][0-9]* {
		yylval=atoi(yytext);
		return NUMBER;

	}
[-()<>=+*/;{}.] {
		 return *yytext;
	} 

[\t] ;

[\n] {lineno++; return yytext[0];}

. return yytext[0];

%%

int yywrap()
{
return 1;
}

