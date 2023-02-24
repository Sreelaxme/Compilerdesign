%{
#define YYSTYPE double
#include<stdio.h>
#include "y.tab.h"
extern int lineno;
%}


%%
[1-9][0-9]* {
		yylval=atoi(yytext);
		return NUMBER;

	}


[\t] ;

[\n] {lineno++; return yytext[0];}

. return yytext[0];

%%

int yywrap()
{
return 1;
}

