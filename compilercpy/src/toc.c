#include <stdio.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>
node* getFn(char* str);
int decl = 0;

void toC(node *p) {
//printf("Im in printSYntax");
 if (!p) {
	return ;
 } 
 switch(p->type) {
 	case typeCon: fprintf(stdout," %d",p->con.value); /*fprintf(stdout,"\n");*/return ;
	case typeId : fprintf(stdout," %s",p->id.id); /*fprintf("\n")*/;return ;
	case typeFun:{
        fprintf(stdout,"{\n");
        toC(p->fn.decl);
        toC(p->fn.fun_block);
        fprintf(stdout,"return ");
        toC(p->fn.ret_node); 
        fprintf(stdout,";");
        fprintf(stdout,"\n}");
        return ;
    }
 	case typeOpr:
 	switch(p->opr.oper) {
		case '+': toC(p->opr.op[0]); fprintf(stdout,"+"); toC(p->opr.op[1]);/* fprintf(")");*/ fprintf(stdout,";\n"); return ;
		case '-': toC(p->opr.op[0]); fprintf(stdout,"-"); toC(p->opr.op[1]); fprintf(stdout,";\n");return ;
		case '*': toC(p->opr.op[0]); fprintf(stdout,"*"); toC(p->opr.op[1]);fprintf(stdout,";\n");return ;
		case '/': toC(p->opr.op[0]); fprintf(stdout,"/"); toC(p->opr.op[1]); fprintf(stdout,";\n");return ;
        case '<': toC(p->opr.op[0]); fprintf(stdout,"<LESS (>"); toC(p->opr.op[1]); fprintf(stdout,";\n");return ;
        case '>': toC(p->opr.op[0]);fprintf(stdout,">"); toC(p->opr.op[1]);fprintf(stdout,";\n");return ;
        case '%': toC(p->opr.op[0]);  fprintf(stdout,"%");toC(p->opr.op[1]);fprintf(stdout,";\n");return ;
		case '=':  toC(p->opr.op[0]); fprintf(stdout,"=");toC(p->opr.op[1]); fprintf(stdout,";\n"); /*fprintf("\n");*/return ;
		case PRINT :  fprintf(stdout,"printf("); toC(p->opr.op[0]);fprintf(stdout," )"); /*fprintf(")");*/ fprintf(stdout,";\n");return ;
		case PRINT_List :  /*fprintf(stdout,"printf("); */toC(p->opr.op[0]); /*fprintf(stdout,");\n");*/toC(p->opr.op[1]); /*fprintf(stdout,")"); fprintf(stdout,"\n");*/return ;
        case PRINTS : fprintf(stdout,"printf(\""); toC(p->opr.op[0]); fprintf(stdout,"\");\n"); return ;
		// case IF : 	{ 
		// 				fprintf("IF "); toC(p->opr.op[0]); printf("\n"); 
		// 				toC(p->opr.op[1]); fprintf(";\nELSE ");
		// 				toC(p->opr.op[2]); fprintf("\nENDIF");
		// 				fprintf("\n");return;
		// 			}
		// case WHILE: {
		// 				fprintf("WHILE "); toC(p->opr.op[0]); 
		// 				fprintf("\n"); toC(p->opr.op[1]); fprintf("\nEND WHILE");
		// 				fprintf(";\n");
		// 				return;
		// 		}
		// 
		case DECLARE_L: {fprintf(stdout,"DECLARE_L\n");return ;}
        case DECLARE_G: {fprintf(stdout,"DECLARE_G\n");return ;}
		// case DECLARE :  if(!decl)fprintf("DECL "); 
		// 					decl++;
		// 					toC(p->opr.op[0]);
		// 					decl--;
		// 					if(!decl)
		// 					fprintf("\n");

		// 					return ;
		// case DECLARE_Fn: fprintf("FUN INT %s\n",p->opr.op[0]->id.id);
		// 				toC(p->opr.op[1]);
		// 				//fprintf("END FUN\n");
		// 				return ;
		case Main: fprintf(stdout,"MAIN\n"); toC(p->opr.op[0]);
							/*fprintf(stdout,"END MAIN\n"); */
							return ;
		// case CALL : 
		// 			fprintf("FUN CALL %s", p->opr.op[0]);
		// 			return ;
		
        // case GREATERTHANOREQUAL: fprintf("GREATERTHANOREQUAL ("); toC(p->opr.op[0]); fprintf(","); toC(p->opr.op[1]); fprintf(")"); return ;
        // case LESSTHANOREQUAL: fprintf("LESSTHANOREQUAL ("); toC(p->opr.op[0]); fprintf(","); toC(p->opr.op[1]); fprintf(")");return ;
        // case NOTEQUAL: fprintf("NOTEQUAL ("); toC(p->opr.op[0]); fprintf(","); toC(p->opr.op[1]);fprintf(")");return ;
        // case EQUALEQUAL: fprintf("EQUALEQUAL ("); toC(p->opr.op[0]); fprintf(","); toC(p->opr.op[1]);fprintf(")");return ;
        // case LOGICAL_NOT: fprintf("LOGICAL_NOT ("); toC(p->opr.op[0]); fprintf(")"); return ;
		// case LOGICAL_AND: fprintf("LOGICAL_AND ("); toC(p->opr.op[0]); fprintf(","); toC(p->opr.op[1]);fprintf(")");return ;
        // case LOGICAL_OR: fprintf("LOGICAL_OR ("); toC(p->opr.op[0]); fprintf(","); toC(p->opr.op[1]);fprintf(")");return ;
		
		
		case STMNT: { 
						toC(p->opr.op[0]); 
						fprintf(stdout,"\n"); toC(p->opr.op[1]);return; 
					}
		// case ARRAY_DECLARE : fprintf("ARR VAR "); fprintf(" %d", p->opr.op[1]->con.value);/*toC(p->opr.op[0]);fprintf(")");*/return ;
		// case ARRAY_ASSIGN : fprintf("ASSIGN ARREF ");toC(p->opr.op[0]); toC(p->opr.op[1]); toC(p->opr.op[2]);fprintf(")");return ;
		// case INDEX: fprintf("ARREF VAR "); toC(p->opr.op[0]); return;
		
 	}

 }

} 