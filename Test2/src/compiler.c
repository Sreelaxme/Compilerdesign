#include <stdio.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>

int decl = 0;
int ex(node *p) {
	 if (!p) return 0;
	 switch(p->type) {
		 case typeCon: /*printf("cons\n");*/return p->con.value;
		 case typeId: return getVal(p->id.id);
		 case typeOpr:
			switch(p->opr.oper) {
				case '+': return ex(p->opr.op[0]) + ex(p->opr.op[1]);
				case '-': return ex(p->opr.op[0]) - ex(p->opr.op[1]);
				case '*': return ex(p->opr.op[0]) * ex(p->opr.op[1]);
				case '/': return ex(p->opr.op[0]) / ex(p->opr.op[1]);
				case '%': return ex(p->opr.op[0]) % ex(p->opr.op[1]);
				case '>': return ex(p->opr.op[0]) > ex(p->opr.op[1]);
				case '<': return ex(p->opr.op[0]) < ex(p->opr.op[1]);
				case '=': 
				{
					//printf("Case = il aanu,%s,%d \n" ,p->opr.op[0]->id.id,ex(p->opr.op[1]));
					return update((p->opr.op[0]->id.id) , ex(p->opr.op[1]));
				}
				case PRINT:printf("%d\n", ex(p->opr.op[0])); return 0;
				case PRINT_List: ex(p->opr.op[0]); ex(p->opr.op[1]) ; return 0;
 							
				case IF : if(ex(p->opr.op[0])==1)
							return ex(p->opr.op[1]) ;
				 		else return ex(p->opr.op[2]); 
				case WHILE: {
					//printf("c file il ah njn epo\n");
						while(ex(p->opr.op[0])==1)
						{

								ex(p->opr.op[1]) ;
						}
						//printf("while work ayilla \n"); 
				 		return 1; 

				}
							
				case DECLARE:
						
								//printf("declare\n");
								declare(p->opr.op[0]->id.id); return 0;
					
				case DECLARE_List:
					
								//printf("Im here\n");
								ex(p->opr.op[0]); ex(p->opr.op[1]) ;return 0;;
							
				case GREATERTHANOREQUAL : return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
				case LESSTHANOREQUAL : return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
				case NOTEQUAL : return ex(p->opr.op[0]) != ex(p->opr.op[1]);
				case EQUALEQUAL : return ex(p->opr.op[0]) == ex(p->opr.op[1]);
				case LOGICAL_NOT : return !(ex(p->opr.op[0]));
				case LOGICAL_AND : return ex(p->opr.op[0]) && ex(p->opr.op[1]);
				case LOGICAL_OR : return ex(p->opr.op[0]) || ex(p->opr.op[1]);
				case STMNT : ex(p->opr.op[0]);ex(p->opr.op[1]) ;return 0;
				case ARRAY_DECLARE : declare_array(p->opr.op[0]->id.id,ex(p->opr.op[1]));
				case ARRAY_ASSIGN : update_arr(p->opr.op[0]->id.id,ex(p->opr.op[1]),ex(p->opr.op[2]));
				case INDEX:
            return fetch_var_ar(p->opr.op[0]->id.id, ex(p->opr.op[1]));

			}
	 }
	 return 0;
 }
void printSyntaxTree(node *p) {

 if (!p) {
	printf("NULL");
	return ;
 } 
 switch(p->type) {
 	case typeCon: printf("NUM "); return ;
	case typeId : printf("VAR "); return ;
 	case typeOpr:
 	switch(p->opr.oper) {
		case '+': printf("PLUS (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")"); return ;
		case '-': printf("MINUS (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
		case '*': printf("MUL (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");return ;
		case '/': printf("DIV (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case '<': printf("LESS (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case '>': printf("GREATER (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");return ;
        case '%': printf("MOD (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");return ;
		case '=': printf("ASSIGN ("); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[0]); printf(")"); return ;
		case PRINT :  printf("PRINT ("); printSyntaxTree(p->opr.op[0]); printf(")"); return ;
		case PRINT_List :  printf("PRINT ("); printSyntaxTree(p->opr.op[0]); printf(",");printSyntaxTree(p->opr.op[1]); printf(")"); return ;
		case IF : 	{ 
						printf("IF "); printSyntaxTree(p->opr.op[0]); printf(","); 
						printSyntaxTree(p->opr.op[1]); printf(",");
						printSyntaxTree(p->opr.op[2]); printf(")");return;
					}
		case WHILE: {
						printf("WHILE "); printSyntaxTree(p->opr.op[0]); 
						printf(","); printSyntaxTree(p->opr.op[1]);
						printf(")"); return;
				}
		case DECLARE_List :  if(!decl)printf("DECL INT "); 
							decl++;
							printSyntaxTree(p->opr.op[0]); 
							printf(", ");
							printSyntaxTree(p->opr.op[1]); 
							decl--;
							if(!decl) printf("\n");
							return ;
		case DECLARE :  printf("VAR "); /*printSyntaxTree(p->opr.op[0]); printf(")");*/ return ;
		
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
		case ARRAY_ASSIGN : printf("ASSIGN (");printSyntaxTree(p->opr.op[0]); printSyntaxTree(p->opr.op[1]); printSyntaxTree(p->opr.op[2]);printf(")");return ;
		case INDEX: printf("ARREF VAR "); return;
		
 	}

 }

} 
int symRead(char* name)
{
	//printf("symR\n");
    char* newName = malloc(sizeof(char)*strlen(name));
	strcpy(newName,name);
	int i;
	for(i=0;i<100 && symTab[i].allocated;i++)
	{
		if(strcmp(symTab[i].name,newName)==0) return i;
	}
	if(i>=100) return -1;
	
	
	return -1;
	// declare (newName);
	// return i;
	
}
int fetch_var_ar(char* name, int ar_index)
{
    int index = symRead(name);

    return symTab[index].int_ar[ar_index];
}
int declare(char* name)
{
	//printf("decl\n");
    //char* newName = malloc(sizeof(char)*strlen(name));
	 char* newName = strdup(name);
	//printf("144\n");
	int i;
	for(i=0;i<100 && symTab[i].allocated;i++)
	{
		if(strcmp(symTab[i].name,newName)==0) return i;
	}
	if(i>=100) return -1;
	symTab[i].name = newName;
	symTab[i].allocated=1;
	symTab[i].type = typeInt ;
	//printf("declared\n");
	return i;
}
int declare_array(char* name,int size)
{
	char* newName = malloc(sizeof(char)*strlen(name));
	strcpy(newName,name);
	int i;
	for(i=0;i<100 && symTab[i].allocated;i++)
	{
		if(strcmp(symTab[i].name,newName)==0) return i;
	}
	if(i>=100) return -1;
	symTab[i].name = newName;
	symTab[i].allocated=size;
	symTab[i].type = typeArr ;
	symTab[i].int_ar=malloc(sizeof(int)*size);
	
	//printf("declared array");

	return i;
}
int updateFunStat(char* str,node* ptr)
{
	int index = symRead(str);
	symTab[index].allocated=1;
	symTab[index].nodeptr=ptr;
	return 1;
}
void printSymTab()
{
  int i=0;
  printf("index\tname\talloc\n");
  for (;i<100 ; i++)
      printf("%d\t%s\t%d\n", i,symTab[i].name,symTab[i].allocated);
	  //if(symTab[i].type == typeInt) printf("%d\n",symTab[i].val );
	  //printf("\n");

}
int declareFn(char* name, node* ptr)
{
	char* newName = malloc(sizeof(char)*strlen(name));
	strcpy(newName,name);

	int i;
	for(i=0;i<100 && symTab[i].allocated;i++)
	{
		if(strcmp(symTab[i].name,newName)==0) return i;
	}
	if(i>=100) return -1;
	symTab[i].name = newName;
	symTab[i].allocated=1;
	symTab[i].type = typeNode;
	updateFunStat(name,ptr);
}

int getVal(char* str)
{
	int index = symRead(str);
	if(!symTab[index].allocated)
	{
		//printf("Something wong...im returning from getVal\n");
		return 0;
	} 
	//printf("Im in getVal and returning %d\n",symTab[index].val);
	return symTab[index].val;
}
node* getFn(char* str)
{
	int index = symRead(str);
	if(!symTab[index].allocated || symTab[index].type!=typeNode) return 0;
	return symTab[index].nodeptr;
}
int update(char* str,int value)
{
	int index = symRead(str);
	//symTab[index].allocated=1;
	symTab[index].val=value;
	//printf("update done ...so variable assigned correctly to %d \n",symTab[index].val);
	return 1;
}
int update_arr(char * str, int ar_index, int value)
{
	int index = symRead(str);
	//symTab[index].allocated=1;
	symTab[index].int_ar[ar_index]=value;
	//printf("update done ...so variable assigned correctly to %d \n",symTab[index].int_ar[ar_index]);
	//printf("array val updated\n");
	return 1;
}

