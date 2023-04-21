%{

#include<stdio.h>
#include <stdlib.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
void yyerror(char *);
struct sym symTab[100];

%}


digit	[0-9]
letter	[a-zA-Z]

%%
"print" {return PRINT;}
"decl" return DECL;
"enddecl" return ENDDECL;
"integer" return INT;
"void"	return VOID;
if				{return IF;}
then				{return THEN ;	}	
else				{return ELSE ;	}	
endif				{return ENDIF;}
do				{return DO;}
while 			{return WHILE;}
endwhile 		{ return ENDWHILE ;}
begin {return Begin;}
end {return End;}
write {return PRINT;} 
main {return MAIN ;}
{digit}+ {
		yylval.iValue=atoi(yytext);
		//printf("%s,%d\n",yytext,yylval);
		return NUMBER;

	}
"=="				{ return EQUALEQUAL;
					}	
"<="				{ return LESSTHANOREQUAL ;
				}
">="				{return GREATERTHANOREQUAL ;
				}
"!="				{return NOTEQUAL;
					}
AND				{return LOGICAL_AND ;	}	
OR				{return LOGICAL_OR ;}
NOT			{return LOGICAL_NOT ;}
[-+*/=()><;,\{\}\[\]\%\n] {
 					return *yytext;
 }

{letter}({letter}|{digit})* {
	yylval.str = strdup(yytext);
	return VARIABLE;
}
[ \t] ; /* ignore whitespace */
. yyerror("Unknown character");

%%

int yywrap()
{
return 1;
}






