#include <stdio.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>
node* getFn(char* str);
int decl = 0;

void printSyntaxTree(node *p) {
//printf("Im in printSYntax");
 if (!p) {
	printf("NULL");
	return ;
 } 
 switch(p->type) {
 	case typeCon: printf("NUM "); printf("\n");return ;
	case typeId : printf("VAR "); /*printf("\n")*/;return ;
 	case typeOpr:
 	switch(p->opr.oper) {
		case '+': printf("PLUS (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");printf("\n"); return ;
		case '-': printf("MINUS (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");printf("\n");return ;
		case '*': printf("MUL (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");printf("\n");return ;
		case '/': printf("DIV (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");printf("\n");return ;
        case '<': printf("LESS (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");printf("\n");return ;
        case '>': printf("GREATER (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");printf("\n");return ;
        case '%': printf("MOD (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");printf("\n");return ;
		case '=': printf("ASSIGN ("); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")"); /*printf("\n");*/return ;
		case PRINT :  printf("PRINT "); printSyntaxTree(p->opr.op[0]); /*printf(")");*/ printf("\n");return ;
		case PRINT_List :  printf("PRINT ("); printSyntaxTree(p->opr.op[0]); printf(",");printSyntaxTree(p->opr.op[1]); printf(")"); printf("\n");return ;
		case IF : 	{ 
						printf("IF "); printSyntaxTree(p->opr.op[0]); printf("\n"); 
						printSyntaxTree(p->opr.op[1]); printf("\nELSE ");
						printSyntaxTree(p->opr.op[2]); printf("\nENDIF");
						printf("\n");return;
					}
		case WHILE: {
						printf("WHILE "); printSyntaxTree(p->opr.op[0]); 
						printf("\n"); printSyntaxTree(p->opr.op[1]); printf("\nEND WHILE");
						printf("\n");
						return;
				}
		case DECLARE_List :  if(!decl)printf("DECL INT "); 
							decl++;
							printSyntaxTree(p->opr.op[0]); 
							printf(", ");
							printSyntaxTree(p->opr.op[1]); 
							decl--;
							if(!decl) printf("\n");
							return ;
		case DECLARE :  if(!decl)printf("DECL "); 
							decl++;
							printSyntaxTree(p->opr.op[0]);
							decl--;
							if(!decl)
							printf("\n");

							return ;
		case DECLARE_Fn: printf("FUN INT %s\n",p->opr.op[0]->id.id);
						printSyntaxTree(p->opr.op[1]);
						printf("END FUN\n");
						return ;
		case Main: printf("\n");printf("FUN INT MAIN \n"); printSyntaxTree(p->opr.op[1]);
							printf("END MAIN\n"); 
							return ;
		case CALL : 
					printf("FUN CALL %s", p->opr.op[0]);
					return ;
		
        case GREATERTHANOREQUAL: printf("GREATERTHANOREQUAL "); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")"); return ;
        case LESSTHANOREQUAL: printf("LESSTHANOREQUAL "); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case NOTEQUAL: printf("NOTEQUAL "); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");return ;
        case EQUALEQUAL: printf("EQUALEQUAL "); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");return ;
        case LOGICAL_NOT: printf("LOGICAL_NOT "); printSyntaxTree(p->opr.op[0]); printf(")"); return ;
		case LOGICAL_AND: printf("LOGICAL_AND "); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");return ;
        case LOGICAL_OR: printf("LOGICAL_OR "); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");return ;
		
		
		case STMNT: { 
						printSyntaxTree(p->opr.op[0]); 
						printf("\n"); printSyntaxTree(p->opr.op[1]);return; 
					}
		case ARRAY_DECLARE : printf("ARR VAR "); printf(" %d", p->opr.op[1]->con.value);/*printSyntaxTree(p->opr.op[0]);printf(")");*/return ;
		case ARRAY_ASSIGN : printf("ASSIGN ARREF ");printSyntaxTree(p->opr.op[0]); printSyntaxTree(p->opr.op[1]); printSyntaxTree(p->opr.op[2]);printf(")");return ;
		case INDEX: printf("ARREF VAR "); printSyntaxTree(p->opr.op[0]); return;
		
 	}

 }

} 