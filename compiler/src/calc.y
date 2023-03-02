%{
#include <stdio.h>
#include"../include/calc3.h"
#include <stdarg.h>
int yylex(void);
void yyerror(char *s);
node *opr(int oper, int nops, ...);
node *con(int value);
int ex(node *p);
void freeNode(node *p);
//struct sym symTab[100];
%}

%union {
	int iValue;  /* integer value */
	node *nPtr; /* node pointer */
};

%token <iValue> NUMBER
%token <iValue> VARIABLE
%left	'+' '-'	  /* left associative, same precedence */
%left	'*' '/'	  /* left assoc., higher precedence */
%type <nPtr> expr
%%


list:	  /* Parser: Productions */
	
	list stmt '\n'   
	|
	;
stmt:
	expr { printf("%d\n",ex($1)); }
	| VARIABLE '=' expr {update($1,ex($3));}
	;
expr:	
	NUMBER { $$ = con($1); }
	|VARIABLE {$$ = con(getVal($1));}
	| expr '+' expr { $$ = opr('+', 2, $1, $3); }
	| expr '-' expr { $$ = opr('-', 2, $1, $3); }
	| expr '*' expr { $$ = opr('*', 2, $1, $3); }
	| expr '/' expr { $$ = opr('/', 2, $1, $3); }
	
	| '(' expr ')' { $$ = $2; }
	;
%%
node *con(int value) {
	node *p;
	if ((p = malloc(sizeof(node))) == NULL)
		yyerror("out of memory");
	p->type = typeCon; /*type is set*/
	p->con.value = value; /*type is con and copied value to it*/
	return p;
}
node *opr(int oper, int nops, ...) {
	va_list ap;
	node *p;
	int i;
	/* allocate node */
	if ((p = malloc(sizeof(node))) == NULL)
		yyerror("out of memory");
	if ((p->opr.op = malloc(nops * sizeof(node))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
	p->opr.op[i] = va_arg(ap, node*);
	va_end(ap);
	return p;
}
void freeNode(node *p) {
	int i;
	if (!p) return;
	if (p->type == typeOpr) {
		for (i = 0; i < p->opr.nops; i++)
			freeNode(p->opr.op[i]);
		free(p->opr.op);
 	}
 	free (p);
}
	/* end of grammar */
void yyerror(char *s) {
 fprintf(stdout, "%s\n", s);
}
int main(void) {
 yyparse();
 return 0;
} 

// #include <stdio.h>
// #include <ctype.h>
// char	*progname;	/* for error messages */
// int	lineno = 1;

// main(argc, argv)	
// 	char *argv[];
// {
// 	progname = argv[0];
// 	yyparse();
// }
// /* yylec() deleted*/
// yyerror(s)	/* called for yacc syntax error */
// 	char *s;
// {
// 	warning(s, (char *) 0);
// }

// warning(s, t)	/* print warning message */
// 	char *s, *t;
// {
// 	fprintf(stderr, "%s: %s", progname, s);
// 	if (t)
// 		fprintf(stderr, " %s", t);
// 	fprintf(stderr, " near line %d\n", lineno);
// }
// %{
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdarg.h>
// #include "../include/calc3.h"
// /* prototypes */
// nodeType *opr(int oper, int nops, ...);

// nodeType *con(int value);
// void freeNode(nodeType *p);
// int ex(nodeType *p);
// int yylex(void);
// void yyerror(char *s);

// %}
// %union {
//  int iValue;  /* integer value */
//  char sIndex;  /* symbol table index */
//  nodeType *nPtr; /* node pointer */
// };
// %token <iValue> INTEGER

// %left '+' '-'
// %left '*' '/'

// %type <nPtr> expr
// %%
// list:	  /* Parser: Productions */
// 	| list '\n'
// 	| list expr '\n'    { printf("\t%d\n", ex($2)); }
// 	;
// expr:
//  INTEGER { $$ = con($1); }
 
//  | expr '+' expr { $$ = opr('+', 2, $1, $3); }
//  | expr '-' expr { $$ = opr('-', 2, $1, $3); }
//  | expr '*' expr { $$ = opr('*', 2, $1, $3); }
//  | expr '/' expr { $$ = opr('/', 2, $1, $3); }
 
//  | '(' expr ')' { $$ = $2; }
//  ;
//  %%
// #define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)
// nodeType *con(int value) {
//  nodeType *p;
//  /* allocate node */
//  if ((p = malloc(sizeof(nodeType))) == NULL)
//  yyerror("out of memory");
//  /* copy information */
//  p->type = typeCon;
//  p->con.value = value;
//  return p;
// }

// nodeType *opr(int oper, int nops, ...) {
//  va_list ap;
//  nodeType *p;
//  int i;
//  /* allocate node */
//  if ((p = malloc(sizeof(nodeType))) == NULL)
//  yyerror("out of memory");
//  if ((p->opr.op = malloc(nops * sizeof(nodeType))) == NULL)
//  yyerror("out of memory");
//  /* copy information */
//  p->type = typeOpr;
//  p->opr.oper = oper;
//  p->opr.nops = nops;
//  va_start(ap, nops);
//  for (i = 0; i < nops; i++)
//  p->opr.op[i] = va_arg(ap, nodeType*);
//  va_end(ap);
//  return p;
// }
// void freeNode(nodeType *p) {
//  int i;
//  if (!p) return;
//  if (p->type == typeOpr) {
//  for (i = 0; i < p->opr.nops; i++)
//  freeNode(p->opr.op[i]);
//  free(p->opr.op);
//  }
//  free (p);
// }
// void yyerror(char *s) {
//  fprintf(stdout, "%s\n", s);
// }
// int main(void) {
//  yyparse();
//  return 0;
// } 
