#include <stdio.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>

static int lbl;
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
				case '=': return update(ex(p->opr.op[0]) , ex(p->opr.op[1]));
				case PRINT: printf("%d\n", ex(p->opr.op[0]));
 							return 0;
				case DECLARE:return declare(strr);
			}
	 }
	 return 0;
 }

int symRead(char* name)
{
	printf("symR\n");
    char* newName = malloc(sizeof(char)*strlen(name));
	strcpy(newName,name);
	int i;
	for(i=0;i<100 && symTab[i].allocated;i++)
	{
		if(strcmp(symTab[i].name,newName)==0) return i;
	}
	if(i>=100) return -1;
	// char* newName = malloc(sizeof(char)*strlen(name));
	strcpy(strr,name);
	printf("symRexit\n");
	
	return -1;
	// declare (newName);
	// return i;
	
}
int declare(char* name)
{
	printf("decl\n");
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
	printf("declend\n");
	return i;
}
int getVal(int index)
{
	if(!symTab[index].allocated) return 0;
	return symTab[index].val;
}
int update(int index,int value)
{
	symTab[index].allocated=1;
	symTab[index].val=value;
	return 1;
}