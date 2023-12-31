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
void printSyntaxTree(node* p);
void printSymTab();
struct sym symTab[100];
int update_arr(char * str, int ar_index, int value);
int declare_array(char* name,int size);
node* getFn(char* str);
%}

%union {
	int iValue;  /* integer value */
	char* str;
	node *nPtr; /* node pointer */
};

%token <iValue> NUMBER
%token <str> VARIABLE MAIN
%token INT VOID
%token DECL ENDDECL DECLARE STMNT DECLARE_List DECLARE_Fn CALL Main
%token PRINT  PRINT_List Begin End 
%token MAIN INDEX
%token IF THEN ELSE ENDIF
%token DO WHILE ENDWHILE
%token EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%token LOGICAL_AND LOGICAL_NOT LOGICAL_OR
%token READ WRITE
%token ARRAY_DECLARE ARRAY_ASSIGN

%left '<' '>'
%left EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%left	'+' '-'	  /* left associative, same precedence */
%left	'*' '/'	  /* left assoc., higher precedence */
%left '%'
%left LOGICAL_AND LOGICAL_OR
%left LOGICAL_NOT


%type <nPtr> expr stmt varList pList Fdef stmt_list decl_stmt main array var
%type <nPtr> func_call

%%


// list:	  /* Parser: Productions */
	
// 	list stmt '\n'   {ex($2); freeNode($2);}
// 	|
// 	;
// block:
// 	| decl_stmt endl{ ex($1); }
// 	| Fdef endl
// 	| main endl { ex($1);}
// 	|
// 	;


program:
	|program endl Fdef endl {printf("prgrm 1 \n"); printSyntaxTree($3); ex($3);}
	|program endl decl_stmt endl {printf("\n\nSYNTAX TREE\n"); printSyntaxTree($3); ex($3);}
	|program endl main endl { /*printf("main\n");*/
							printSyntaxTree($3);
							printf("\n\n\nPROGRAM OUTPUT \n"); 
									ex($3);
									printf("\nSymbol Table\n");
									printSymTab();}
	| program endl func_call endl {printSyntaxTree($3);ex($3);}
	;
return_type:
	INT
	|VOID 
	;
main:
	return_type MAIN '(' ')' '{' endl Begin endl stmt_list endl End endl '}' {/*printf("found main\n");*/ $$ = opr(Main,2,id($2),$9);}
	;
endl:
	|endl '\n'
	;

func_call:
	 VARIABLE '(' ')' ';' { $$=opr(CALL,1,$1);}
	;
Fdef:
	return_type VARIABLE '('  ')' '{' endl Begin endl stmt_list endl End endl '}'	{ /*printf("fdef\n");*/ $$ = opr(DECLARE_Fn,2,id($2),$9);	}
	;
varList:
	| var {$$ = $1;}
	//| VARIABLE ',' varList {/*printf("2 in VarList\n");*/$$ = opr(DECLARE_List, 2, opr(DECLARE,1,id($1)), $3);}
	| var ',' varList {$$ = opr(DECLARE_List,2,$1,$3);}

var:
	| VARIABLE '[' NUMBER ']' {$$ = opr(ARRAY_DECLARE,2,id($1),con($3));}
	|VARIABLE  {/*printf("1 in varList\n");*/$$ = opr(DECLARE, 1, id($1));}
	;

pList:
	expr {$$ = opr(PRINT, 1, $1);}
	| expr ',' pList {$$ = opr(PRINT_List, 2, opr(PRINT,1,$1), $3);}
	;
stmt_list:	
		stmt endl {$$ = $1 ;}
		|	stmt endl stmt_list{$$ = opr(STMNT , 2, $1 ,$3) ;}
		
		|	error ';' 		{printf("error\n") ; $$ = con(0)  ;}

decl_stmt:
	DECL endl INT varList ';' endl ENDDECL  {/*printf("Global declaration \n"); */ $$=$4;}
	;
stmt:
	expr ';' { $$=$1;}
	| VARIABLE '[' expr ']' '=' expr ';' {$$ = opr(ARRAY_ASSIGN,3,id($1),$3,$6);}
	| decl_stmt {$$ = $1;}
	| VARIABLE '=' expr ';'{/*printf("variable assignment\n");*/$$ = opr('=', 2, id($1), $3);}
						
	| PRINT pList';' { /*printf("trying to print\n");*/ $$ = $2;} 
	| IF expr THEN endl stmt_list endl ELSE endl stmt_list endl ENDIF ';' { /*printf("ifelse il keri\n") ;*/ $$ = opr(IF,3,$2,$5,$9);}
	| WHILE expr DO endl stmt_list endl ENDWHILE ';' { /*printf("while il keri \n");*/ $$ = opr(WHILE,2,$2,$5);}
	| VARIABLE{/*printf("evdeya\n");*/$$=$1;}
	|func_call {$$=$1;}
	;
expr:	
	NUMBER { $$ = con($1); }
	|VARIABLE {/*printf("thaan evde ano?\n");*/$$ = id($1);}
	| VARIABLE '[' expr ']' {$$ = opr(INDEX,2,id($1),$3);}
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
	//printf("id\n");
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
	//printf("opr\n");
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

