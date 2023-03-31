#include <stdio.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>


int ex(node *p) {
	 if (!p) return 0;
	 switch(p->type) {
		 case typeCon: /*printf("cons\n",p->con.value);*/return p->con.value;
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
				case PRINT: printf("%d\n", ex(p->opr.op[0])); return 0 ;
				case PRINT_List: printf("%d\n", ex(p->opr.op[0]));ex(p->opr.op[1]) ;return 0;
 							
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
							{
								
								declare(p->opr.op[0]->id.id); return 0;
							} 
				case DECLARE_List:
							{
								
								declare(p->opr.op[0]->id.id); return ex(p->opr.op[1]);
							} 
				case GREATERTHANOREQUAL : return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
				case LESSTHANOREQUAL : return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
				case NOTEQUAL : return ex(p->opr.op[0]) != ex(p->opr.op[1]);
				case EQUALEQUAL : return ex(p->opr.op[0]) == ex(p->opr.op[1]);
				case LOGICAL_NOT : return !(ex(p->opr.op[0]));
				case LOGICAL_AND : return ex(p->opr.op[0]) && ex(p->opr.op[1]);
				case LOGICAL_OR : return ex(p->opr.op[0]) || ex(p->opr.op[1]);
				case STMNT : ex(p->opr.op[0]);ex(p->opr.op[1]) ;return 0;
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
 	case typeCon: printf("CONSTANT"); return ;
	case typeId : printf("VARIABLE"); return ;
 	case typeOpr:
 	switch(p->opr.oper) {
		case '+': printf("+ (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")"); return ;
		case '-': printf("- (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
		case '*': printf("* (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
		case '/': printf("/ (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case '<': printf("< (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case '>': printf("> (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case '%': printf("% (");printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
		case '=': printf("ASSIGNMENT ("); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[0]); printf(")"); return ;
		case PRINT :  printf("PRINT ("); printSyntaxTree(p->opr.op[0]); printf(")"); return ;
		case PRINT_List :  printf("PRINT ("); printSyntaxTree(p->opr.op[0]); printSyntaxTree(p->opr.op[1]); printf(")"); return ;
		case IF : 	{ 
						printf("IF ("); printSyntaxTree(p->opr.op[0]); printf(","); 
						printSyntaxTree(p->opr.op[1]); printf(",");
						printSyntaxTree(p->opr.op[2]); printf(")");return;
					}
		case WHILE: {
						printf("WHILE ("); printSyntaxTree(p->opr.op[0]); 
						printf(","); printSyntaxTree(p->opr.op[1]);
						printf(")"); return;
				}
		case DECLARE_List :  printf("DECLARE ("); printSyntaxTree(p->opr.op[0]); printSyntaxTree(p->opr.op[1]); printf(")"); return ;
		case DECLARE :  printf("DECLARE ("); printSyntaxTree(p->opr.op[0]); printf(")"); return ;
		
        case GREATERTHANOREQUAL: printf("GREATERTHANOREQUAL ("); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case LESSTHANOREQUAL: printf("LESSTHANOREQUAL ("); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case NOTEQUAL: printf("NOTEQUAL ("); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case EQUALEQUAL: printf("EQUALEQUAL ("); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case LOGICAL_NOT: printf("LOGICAL_NOT ("); printSyntaxTree(p->opr.op[0]); printf(")"); return ;
		case LOGICAL_AND: printf("LOGICAL_AND ("); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return ;
        case LOGICAL_OR: printf("LOGICAL_OR ("); printSyntaxTree(p->opr.op[0]); printf(","); printSyntaxTree(p->opr.op[1]);printf(")");return ;
		
		
		case STMNT: { 
						printf("STATEMENT ("); printSyntaxTree(p->opr.op[0]); 
						printf(","); printSyntaxTree(p->opr.op[1]); printf(")");return; }
		
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
	// char* newName = malloc(sizeof(char)*strlen(name));
	
	//printf("symRexit\n");
	
	return -1;
	// declare (newName);
	// return i;
	
}
int declare(char* name)
{
	//printf("decl\n");
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
	symTab[i].type = typeInt ;
	//printf("declared\n");
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
	symTab[index].allocated=1;
	symTab[index].val=value;
	//printf("update done ...so variable assigned correctly to %d \n",symTab[index].val);
	return 1;
}
