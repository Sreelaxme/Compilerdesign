%{
#include <stdio.h>
#include"../include/calc3.h"
#include <stdarg.h>
int yylex(void);
void yyerror(char *s);
node *opr(int oper, int nops, ...);
node *con(int value);
node *id(char* var);
int ex(node *p);
void freeNode(node *p);
int declareFn(char* name, node* ptr);
node* getFn(char* str);
int updateFunStat(char* str,node* ptr);
//struct sym symTab[100];
%}

%union {
	int iValue;  /* integer value */
	char* str;
	node *nPtr; /* node pointer */
};

%token <iValue> NUMBER
%token <str> VARIABLE
%token PRINT DECL ENDDECL INT DECLARE STMNT
%token IF THEN ELSE ENDIF
%token DO WHILE ENDWHILE
%token EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%token LOGICAL_AND LOGICAL_NOT LOGICAL_OR


%left '<' '>'
%left EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%left	'+' '-'	  /* left associative, same precedence */
%left	'*' '/'	  /* left assoc., higher precedence */
%left '%'
%left LOGICAL_AND LOGICAL_OR
%left LOGICAL_NOT


%type <nPtr> expr stmt varList pList Fdef stmt_list
%%


// list:	  /* Parser: Productions */
	
// 	list stmt '\n'   {ex($2); freeNode($2);}
// 	|
// 	;
program :
	program func_call '\n'
	| program Fdef
	|
	;
func_call :
	 VARIABLE '(' ')' {node * n = getFn($1);ex(n);}
	|
	;
Fdef:
	VARIABLE '('  ')' '{' stmt_list '}'	{ declareFn($1,$5);	}
	;
varList:
	VARIABLE  {$$ = opr(DECLARE, 1, id($1));}
	| varList ',' VARIABLE {$$ = opr(DECLARE, 2, id($3), $1);}
	|
	;
pList :
	expr {$$ = opr(PRINT, 1, ($1));}
	| expr ',' pList {$$ = opr(PRINT, 2, $1, $3);}
	|
	;
stmt_list:	/* NULL */		{ $$ =con(0) ;}
		|	stmt stmt_list	{$$ = opr(STMNT , 2, $1 ,$2) ;}
		| 	stmt {$$ = $1 ;}
		|	error ';' 		{printf("error\n") ; $$ = con(0)  ;}


stmt:
	expr ';' { $$=$1;/*printf("%d\n",ex($1));*/ }
	| DECL '\n' INT varList ';' '\n' ENDDECL { $$=$4;}
	| VARIABLE '=' expr ';'{$$ = opr('=', 2, id($1), $3);}
						
	| PRINT pList';' { $$ = $2;} 
	| IF expr THEN stmt_list ELSE stmt_list ENDIF { printf("ifelse il keri\n") ; $$ = opr(IF,3,$2,$4,$6);}
	| WHILE expr DO stmt_list ENDWHILE ';' { printf("while il keri \n"); $$ = opr(WHILE,2,$2,$4);}
	;
expr:	
	NUMBER { $$ = con($1); }
	|VARIABLE {$$ = con(getVal($1));}
	| expr '+' expr { $$ = opr('+', 2, $1, $3); }
	| expr '-' expr { $$ = opr('-', 2, $1, $3); }
	| expr '*' expr { $$ = opr('*', 2, $1, $3); }
	| expr '/' expr { $$ = opr('/', 2, $1, $3); }
	| expr '%' expr 		{  $$ = opr('%', 2, $1, $3);}
	| expr '<' expr		{  $$ = opr('<', 2, $1, $3);}
	| expr '>' expr		{ $$ = opr('>', 2, $1, $3); }
	| '(' expr ')' { $$ = $2; }
	|	expr GREATERTHANOREQUAL expr { $$ = opr(GREATERTHANOREQUAL, 2, $1, $3);}
	|	expr LESSTHANOREQUAL expr	{$$ = opr(LESSTHANOREQUAL, 2, $1, $3); }
	|	expr NOTEQUAL expr			{ $$ = opr(NOTEQUAL, 2, $1, $3);}
	|	expr EQUALEQUAL expr	{ $$ = opr(EQUALEQUAL, 2, $1, $3);}
	|	LOGICAL_NOT expr	{ $$ = opr(LOGICAL_NOT, 1, $2);	}
	|	expr LOGICAL_AND expr	{$$ = opr(LOGICAL_AND, 2, $1, $3);	}
	|	expr LOGICAL_OR expr	{ $$ = opr(LOGICAL_OR, 2, $1, $3);	}
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
node *id(char* var) {
	node *p;
	if ((p = malloc(sizeof(node))) == NULL)
		yyerror("out of memory");
	p->type = typeId; /*type is set*/
	p->id.id = var; /*type is con and copied value to it*/
	return p;
}
node *opr(int oper, int nops, ...) {
	//printf("opr\n");
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

