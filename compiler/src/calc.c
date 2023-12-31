#include <stdio.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>


int ex(node *p) {
	 if (!p) return 0;
	 switch(p->type) {
		 case typeCon:return p->con.value;
		 case typeOpr:
			switch(p->opr.oper) {
				case '+': return ex(p->opr.op[0]) + ex(p->opr.op[1]);
				case '-': return ex(p->opr.op[0]) - ex(p->opr.op[1]);
				case '*': return ex(p->opr.op[0]) * ex(p->opr.op[1]);
				case '/': return ex(p->opr.op[0]) / ex(p->opr.op[1]);
				case '=': return update((p->opr.op[0]->id.id) , ex(p->opr.op[1]));
				case PRINT: printf("%d\n", ex(p->opr.op[0]));return ex(p->opr.op[1]);
 							return 0;
				case DECLARE: declare(p->opr.op[0]->id.id); return ex(p->opr.op[1]);
			}
	 }
	 return 0;
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
	//printf("declend\n");
	return i;
}
int getVal(char* str)
{
	int index = symRead(str);
	if(!symTab[index].allocated) return 0;
	return symTab[index].val;
}
int update(char* str,int value)
{
	int index = symRead(str);
	symTab[index].allocated=1;
	symTab[index].val=value;
	return 1;
}