#include <stdio.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>
node* getFn(char* str);

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
								ex(p->opr.op[0]); ex(p->opr.op[1]) ;return 0;
				case DECLARE_Fn:
								//printf("Declare fn in c \n");
								declareFn(p->opr.op[0]->id.id,p->opr.op[1]);
								
								return 0;
				case CALL :
							//node * x =getFn(p->opr.op[0]);
							//printf("njanah %s",p->opr.op[0]);
							ex(getFn(p->opr.op[0]));
							return ;
				case Main: //printf("%s",p->opr.op[0]->id.id);
				
							declareFn("main",p->opr.op[1]);
							//printf("njn evde vanno?\n");
							ex(p->opr.op[1]);
							
							return ;

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
 int count = 0;

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
int declareFn(char* name, node* ptr)
{
	
	//char* newName = malloc(sizeof(char)*strlen(name));
	//strcpy(newName,name);
	 //printf("%s",name);
	
	char *newName=strdup(name);
	 //printf("keri\n");
	
	int i;
	for(i=0;i<100 && symTab[i].allocated;i++)
	{
		if(strcmp(symTab[i].name,newName)==0) {
			
			return i;
		}

		
	}
	
	if(i>=100) return -1;
	symTab[i].name = newName;
	symTab[i].allocated=1;
	symTab[i].type = typeNode;
	updateFunStat(name,ptr);
	//printf("njn evde vanno?\n");printf("Erangi\n");
	return i;
}
//int declareMain(char* name,)
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
  printf("index\tname\talloc\tval\n");
  for (;i<100 ; i++)
	if(symTab[i].name)
	{
		printf("%d\t%s\t%d\t", i,symTab[i].name,symTab[i].allocated);
	  if(symTab[i].type == typeInt) printf("%d",symTab[i].val );
	  else if(symTab[i].type == typeNode)printf("%p",symTab[i].nodeptr );
	  else if(symTab[i].type == typeArr)
	  {
		for(int j=0;j<symTab[i].allocated;j++)
		printf("%p ",symTab[i].int_ar[j]);
	  }
	  printf("\n");
	}
      

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

