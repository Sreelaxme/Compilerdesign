%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc3.h"
/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);
void yyerror(char *s);
int sym[26]; /* symbol table */
%}
%union {
 int iValue; /* integer value */
 char sIndex; /* symbol table index */
 nodeType *nPtr; /* node pointer */
}; 
%token<iValue>NUMBER
%left	'+' '-'	  /* left associative, same precedence */
%left	'*' '/'	  /* left assoc., higher precedence */
%left '(' ')'
%type <nPtr> expr
%%
list:	  /* Parser: Productions */
	| list '\n'
	| list expr '\n'    { printf("\t%.8g\n", $2); }
	;
expr:	  NUMBER	{ $$ = con($1); }
	 expr '+' expr { $$ = opr('+', 2, $1, $3); }
	 | expr '-' expr { $$ = opr('-', 2, $1, $3); }
	 | expr '*' expr { $$ = opr('*', 2, $1, $3); }
	 | expr '/' expr { $$ = opr('/', 2, $1, $3); } 
	| '(' expr ')'	{ $$ = $2; }
	;
%%
	/* end of grammar */

#include <stdio.h>
#include <ctype.h>
char	*progname;	/* for error messages */
int	lineno = 1;
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
nodeType *id(int i) {
 nodeType *p;
 /* allocate node */
 if ((p = malloc(sizeof(nodeType))) == NULL)
 yyerror("out of memory");
 /* copy information */
 p->type = typeId;
 p->id.i = i;
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

main(argc, argv)	
	char *argv[];
{
	progname = argv[0];
	yyparse();
}
/* yylec() deleted*/
yyerror(s)	/* called for yacc syntax error */
	char *s;
{
	warning(s, (char *) 0);
}

warning(s, t)	/* print warning message */
	char *s, *t;
{
	fprintf(stderr, "%s: %s", progname, s);
	if (t)
		fprintf(stderr, " %s", t);
	fprintf(stderr, " near line %d\n", lineno);
}
