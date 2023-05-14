#include <stdio.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>
node* getFn(char* str);
int decl = 0;
FILE * fp ;

FILE * startcodegeneration(char * dir)
{
	FILE * f = fopen(dir,"w+");
	fprintf(f,"#include<stdio.h>\n\n");
	return f;
	//return stdout;
}
void toC(node *p) {
//printf("Im in printSYntax");
 if (!p) {
    printf("\n");
	return ;
 } 
 switch(p->type) {
 	case typeCon: fprintf(stdout,"%d",p->con.value); /*fprintf(stdout,"\n");*/return ;
	case typeId : fprintf(stdout," %s",p->id.id); /*fprintf("\n")*/;return ;
	case typeFun:{
        fprintf(stdout,"{\n");
        toC(p->fn.decl);
        toC(p->fn.fun_block);
        fprintf(stdout,"\nreturn ");
        toC(p->fn.ret_node); 
        fprintf(stdout,";");
        fprintf(stdout,"\n}\n");
        return ;
    }
 	case typeOpr:
 	switch(p->opr.oper) {
		case '+': fprintf(stdout,"(");toC(p->opr.op[0]); fprintf(stdout," + "); toC(p->opr.op[1]);fprintf(stdout,")");/* fprintf(")");*/return ;
		case '-':/*fprintf(stdout,"("); */toC(p->opr.op[0]); fprintf(stdout," - "); toC(p->opr.op[1]);/*fprintf(stdout,")");*/return ;
		case '*': fprintf(stdout,"(");toC(p->opr.op[0]); fprintf(stdout," * "); toC(p->opr.op[1]);fprintf(stdout,")");return ;
		case '/': fprintf(stdout,"(");toC(p->opr.op[0]); fprintf(stdout," / "); toC(p->opr.op[1]);fprintf(stdout,")"); return ;
        case '<': fprintf(stdout,"(");toC(p->opr.op[0]); fprintf(stdout," < "); toC(p->opr.op[1]);fprintf(stdout,")"); return ;
        case '>': fprintf(stdout,"(");toC(p->opr.op[0]);fprintf(stdout," > "); toC(p->opr.op[1]);fprintf(stdout,")");return ;
        case '%': fprintf(stdout,"(");toC(p->opr.op[0]);  fprintf(stdout," %% ");toC(p->opr.op[1]);fprintf(stdout,")");return ;
   
		case '=':  toC(p->opr.op[0]); fprintf(stdout," = ");toC(p->opr.op[1]);/* fprintf(stdout,";"); *//*fprintf("\n");*/return ;
		case PRINT :  {
            fprintf(stdout,"printf(\"\ ");
            //int n =lengthOfArgList(p->opr.op[0]);
            int n =1;
            // while(p->opr.op[0])
            // {
            //     n++;
            //     p->opr.op[0]=p->
            // }
            char * str ="%";
            //fprintf(stdout,"%d\n",n);
            for(int i =0;i<n;i++)
            {
                fprintf(stdout,"%sd",str);
            }
            fprintf(stdout,"\"\,");
            toC(p->opr.op[0]);fprintf(stdout,")"); /*fprintf(")");*/ fprintf(stdout,";");return ;
            }
		case PRINT_List :  /*fprintf(stdout,"printf("); */toC(p->opr.op[0]); /*fprintf(stdout,");\n");*/toC(p->opr.op[1]); /*fprintf(stdout,")"); fprintf(stdout,"\n");*/return ;
        case PRINTS : fprintf(stdout,"printf(\"%s",p->opr.op[0]); toC(p->opr.op[0]); fprintf(stdout,"\");\n"); return ;
		case IF : 	{ 
						fprintf(stdout,"if("); toC(p->opr.op[0]); fprintf(stdout,"){\n"); 
						toC(p->opr.op[1]); fprintf(stdout,"\n}\nelse {\n");
						toC(p->opr.op[2]); fprintf(stdout,"}");
						return;
					}
        case IFL : 	{ 
						fprintf(stdout,"if("); toC(p->opr.op[0]); fprintf(stdout,"){\n"); 
						toC(p->opr.op[1]);  fprintf(stdout,"\n}");
						return;
					}
		case WHILE: {
						fprintf(stdout,"while("); toC(p->opr.op[0]); 
						fprintf(stdout,"){\n"); toC(p->opr.op[1]); fprintf(stdout,"\n}");
						return;
				}
		
		case DECLARE_L: {
            varItemtype * list = p->opr.op[0];
            fprintf(stdout, "int ");
            if (!list) {
                fprintf(stdout, "");
            }
           
            while (list != NULL) {
                
                fprintf(stdout, "%s", list->name);
                if (list->length > 0) {
                    fprintf(stdout, "[%d]", list->length);
                }
                list = list->next;
              if (list!=NULL) {
                    fprintf(stdout, ", ");
                }
            }
            fprintf(stdout, ";\n");
            return;
        }

        case DECLARE_G: {
            fprintf(stdout, "int ");
            varItemtype *current = p->opr.op[0];

            if (!current) {
                fprintf(stdout, "");
            }

            while (current != NULL) {
                fprintf(stdout, "%s", current->name);

                if (current->length > 0) {
                    fprintf(stdout, "[%d]", current->length);
                }

                current = current->next;

                if (current != NULL) {
                    fprintf(stdout, ",");
                }
            }

            fprintf(stdout, ";\n");
            return;
        }

        
	
		case DECLARE_Fn: {
            fprintf(stdout,"\nint %s(",p->opr.op[0]);
                printarglist(p->opr.op[1]->fn.arg_list);
                fprintf(stdout,")\n");
                                toC(p->opr.op[1]);
						return ;
        }
		case Main: fprintf(stdout,"int main()\n"); toC(p->opr.op[0]);
							return ;
		case CALL: {
            //printf("here?");
            fprintf(stdout,"%s(", p->opr.op[0]); 
            
            nodeItemtype * ptr = p->opr.op[1];
            
            while(ptr != NULL)
            {
                //fprintf(stdout,"%s",ptr->node_ptr->type);
                toC(ptr->node_ptr);
                ptr = ptr->next;
                if(ptr != NULL)
                {
                    fprintf(stdout,", ");
                }
            }

            fprintf(stdout,")");
            
            return;
        }

		
        case GREATERTHANOREQUAL: toC(p->opr.op[0]);fprintf(stdout," >= ");  toC(p->opr.op[1]);  return ;
        case LESSTHANOREQUAL:  toC(p->opr.op[0]); fprintf(stdout," <= "); toC(p->opr.op[1]); return ;
        case NOTEQUAL:  toC(p->opr.op[0]);fprintf(stdout," != "); toC(p->opr.op[1]);return ;
        case EQUALEQUAL: toC(p->opr.op[0]);  fprintf(stdout," == "); toC(p->opr.op[1]);return ;
        case LOGICAL_NOT:  fprintf(stdout,"!");toC(p->opr.op[0]);return ;
		case LOGICAL_AND: toC(p->opr.op[0]);fprintf(stdout," && ");toC(p->opr.op[1]);return ;
        case LOGICAL_OR: toC(p->opr.op[0]); fprintf(stdout," || "); toC(p->opr.op[1]);return ;
		
		
		case STMNT: { 
						toC(p->opr.op[0]); 
						fprintf(stdout,"\n"); toC(p->opr.op[1]);
                        toC()return; 
					}
		// case ARRAY_DECLARE : fprintf("ARR VAR "); fprintf(" %d", p->opr.op[1]->con.value);/*toC(p->opr.op[0]);fprintf(")");*/return ;
		case ARRAY_ASSIGN : toC(p->opr.op[0]); fprintf(stdout,"[");toC(p->opr.op[1]);fprintf(stdout,"] = "); toC(p->opr.op[2]);fprintf(stdout,";\n");return ;
		case INDEX:  toC(p->opr.op[0]);fprintf(stdout,"["); toC(p->opr.op[1]);fprintf(stdout,"]");return;
        case READ: {
            varItemtype* var_ptr = p->opr.op[0];
            fprintf(stdout, "scanf(\"%%d\", &%s);", var_ptr->name);
            return;
        }

		
 	}

 }

} 