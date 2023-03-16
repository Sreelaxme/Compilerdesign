/*
 *   This file is part of SIL Compiler.
 *
 *  SIL Compiler is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SIL Compiler is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SIL Compiler.  If not, see <http://www.gnu.org/licenses/>.
 */

%{	
	#include <stdio.h>
	#include "AbsSynTree.h"
#define YYSTYPE double
	int yylex();
	void yyerror( char* );
        int i;	
%}

%token BEG END
%token T_INT T_BOOL
%token READ WRITE
%token DECL ENDDECL
%token VAR NUM
%token IF THEN ELSE ENDIF
%token LOGICAL_AND LOGICAL_NOT LOGICAL_OR
%token EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%token WHILE DO ENDWHILE FOR 
%token T F 
%token MAIN RETURN


%left '<' '>'
%left EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%left '+' '-'
%left '*' '/'
%left '%'
%left LOGICAL_AND LOGICAL_OR
%left LOGICAL_NOT
%%

	Prog	:	Gdecl_sec Fdef_sec MainBlock
		;
		
	Gdecl_sec:	DECL Gdecl_list ENDDECL{}
		;
		
	Gdecl_list: 
		| 	Gdecl Gdecl_list
		;
		
	Gdecl 	:	ret_type Glist ';'
		;
		
	ret_type:	T_INT		{ }
		|	T_BOOL 		{ }
		;
		
	Glist 	:	Gid
		| 	func 
		|	Gid ',' Glist 
		|	func ',' Glist
		;
	
	Gid	:	VAR		{$$ = opr(DECLARE, 1, id($1));}
		|	Gid '[' NUM ']'	{                                                   }

		;
		
	func 	:	VAR '(' arg_list ')' 					{ 					}
		;
			
	arg_list:	
		|	arg_list1
		;
		
	arg_list1:	arg_list1 ';' arg
		|	arg
		;
		
	arg 	:	arg_type var_list	
		;
		
	arg_type:	T_INT		 {  }
		|	T_BOOL 		 { }
		;

	var_list:	VAR 		 { }
		|	VAR ',' var_list { 	}
		;
		
	Fdef_sec:	
		|	Fdef_sec Fdef
		;
		
	Fdef	:	func_ret_type func_name '(' FargList ')' '{' Ldecl_sec BEG stmt_list ret_stmt END '}'	{	 				}
		;
		
	func_ret_type:	T_INT		{ }
		|	T_BOOL		{ }
		;
			
	func_name:	VAR		{ 					}
		;
		
	FargList:	arg_list	{ 					}
		;

	ret_stmt:	RETURN expr ';'	{ 					}
		;
			
	MainBlock: 	func_ret_type main '('')''{' Ldecl_sec BEG stmt_list ret_stmt END  '}'		{ 				  	  }
					  
		;
		
	main	:	MAIN		{ 					}
		;
		
	Ldecl_sec:	DECL Ldecl_list ENDDECL	{}
		;

	Ldecl_list:		
		|	Ldecl Ldecl_list
		;

	Ldecl	:	type Lid_list ';'		
		;

	type	:	T_INT			{ }
		|	T_BOOL			{ }
		;

	Lid_list:	Lid
		|	Lid ',' Lid_list
		;
		
	Lid	:	VAR			{ 						}
		;

	stmt_list:	/* NULL */		{  }
		|	statement stmt_list	{						}
		|	error ';' 		{  }
		;

	statement:	assign_stmt  ';'		{ 							 }
		|	read_stmt ';'		{ }
		|	write_stmt ';'		{ }
		|	cond_stmt 		{ }
		|	func_stmt ';'		{ }
		;

	read_stmt:	READ '(' var_expr ')' {						 }
		;

	write_stmt:	WRITE '(' expr ')' 	{  }
		 | WRITE '(''"' str_expr '"'')'      { }

		;
	
	assign_stmt:	var_expr '=' expr 	{ 			}
		;

	cond_stmt:	IF expr THEN stmt_list ENDIF 	{ 						}
		|	IF expr THEN stmt_list ELSE stmt_list ENDIF 	{ 						}
		|	WHILE expr DO stmt_list ENDWHILE ';'{ 						}
		 |    FOR '(' assign_stmt  ';'  expr ';'  assign_stmt ')' '{' stmt_list '}'                                             {                                                 }

		;
	
	func_stmt:	func_call 		{ 						}
		;
		
	func_call:	VAR '(' param_list ')'	{ 						   }
		;
		
	param_list:				
		|	param_list1		
		;
		
	param_list1:	para			
		|	para ',' param_list1	
		;

	para	:	expr			{ 						}
		;

	expr	:	NUM 			{ 			}
		|	'-' NUM			{  						   }
		|	var_expr		{ 			}
		|	T			{ 						  	}
		|	F			{ 	}
		|	'(' expr ')'		{ $$ = $2;}

		|	expr '+' expr 		{ 	$$ = opr('+', 2, $1, $3);}
		|	expr '-' expr	 	{ $$ = opr('-', 2, $1, $3);	}
		|	expr '*' expr 		{$$ = opr('*', 2, $1, $3); }
		|	expr '/' expr 		{  $$ = opr('/', 2, $1, $3);}
		|	expr '%' expr 		{  $$ = opr('%', 2, $1, $3);}
		|	expr '<' expr		{  $$ = opr('<', 2, $1, $3);}
		|	expr '>' expr		{ $$ = opr('>', 2, $1, $3); }
		|	expr GREATERTHANOREQUAL expr				{ 						}
		|	expr LESSTHANOREQUAL expr	{  						}
		|	expr NOTEQUAL expr			{ 						}
		|	expr EQUALEQUAL expr	{ 						}
		|	LOGICAL_NOT expr	{ 						}
		|	expr LOGICAL_AND expr	{ 						}
		|	expr LOGICAL_OR expr	{ 						}
		|	func_call		{  }

		;
	str_expr :  VAR                       {}
                  | str_expr VAR   { }
                ;
	
	var_expr:	VAR	{ 				  }
		|	var_expr '[' expr ']'	{                                                 }
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

