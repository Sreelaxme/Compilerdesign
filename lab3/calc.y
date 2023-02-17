%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc3.h"
/* prototypes */
nodeType *opr(int oper, int nops, ...);

nodeType *con(int value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);
void yyerror(char *s);

%}
%union {
 int iValue; /* integer value */
 char sIndex; /* symbol table index */
 nodeType *nPtr; /* node pointer */
};
%token <iValue> INTEGER
%token <sIndex> VARIABLE

%left '+' '-'
%left '*' '/'

%type <nPtr> expr
%%
list:	  /* Parser: Productions */
	| list '\n'
	| list expr '\n'    { printf("\t%d\n", ex($2)); }
	;
expr:
 INTEGER { $$ = con($1); }
 | VARIABLE { $$ = id($1); } 
 | expr '+' expr { $$ = opr('+', 2, $1, $3); }
 | expr '-' expr { $$ = opr('-', 2, $1, $3); }
 | expr '*' expr { $$ = opr('*', 2, $1, $3); }
 | expr '/' expr { $$ = opr('/', 2, $1, $3); }
 
 | '(' expr ')' { $$ = $2; }
 ;
 %%
#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)
nodeType *con(int value) {
 nodeType *p;
 /* allocate node */
 if ((p = malloc(sizeof(nodeType))) == NULL)
 yyerror("out of memory");
 /* copy information */
 p->type = typeCon;
 p->con.value = value;
 return p;
}

nodeType *opr(int oper, int nops, ...) {
 va_list ap;
 nodeType *p;
 int i;
 /* allocate node */
 if ((p = malloc(sizeof(nodeType))) == NULL)
 yyerror("out of memory");
 if ((p->opr.op = malloc(nops * sizeof(nodeType))) == NULL)
 yyerror("out of memory");
 /* copy information */
 p->type = typeOpr;
 p->opr.oper = oper;
 p->opr.nops = nops;
 va_start(ap, nops);
 for (i = 0; i < nops; i++)
 p->opr.op[i] = va_arg(ap, nodeType*);
 va_end(ap);
 return p;
}
void freeNode(nodeType *p) {
 int i;
 if (!p) return;
 if (p->type == typeOpr) {
 for (i = 0; i < p->opr.nops; i++)
 freeNode(p->opr.op[i]);
 free(p->opr.op);
 }
 free (p);
}
void yyerror(char *s) {
 fprintf(stdout, "%s\n", s);
}
int main(void) {
 yyparse();
 return 0;
} 
