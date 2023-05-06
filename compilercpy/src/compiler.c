#include <stdio.h>
#include "../include/calc3.h"
#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>

struct sym symTab[100]; //global
struct sym* saveTab;

node *getFn(char *str);

node *evalF(funNodeType fn);
char *passParameters(node *fNode, struct node_item *list);

int ex(node *p)
{
	if (!p)
	{
		//printError("SIGSEV", 0, p);
		return 0;
	}
	switch (p->type)
	{
	case typeCon: /*printf("cons\n");*/
		return p->con.value;
	case typeId:
		return getVal(p->id.id);
	case typeFun:
		return evalF(p->fn);
	case typeOpr:
		switch (p->opr.oper)
		{
		case '+':
			return ex(p->opr.op[0]) + ex(p->opr.op[1]);
		case '-':
			return ex(p->opr.op[0]) - ex(p->opr.op[1]);
		case '*':
			return ex(p->opr.op[0]) * ex(p->opr.op[1]);
		case '/':
			return ex(p->opr.op[0]) / ex(p->opr.op[1]);
		case '%':
			return ex(p->opr.op[0]) % ex(p->opr.op[1]);
		case '>':
			return ex(p->opr.op[0]) > ex(p->opr.op[1]);
		case '<':
			return ex(p->opr.op[0]) < ex(p->opr.op[1]);
		case '=':
		{
			// printf("Case = il aanu,%s,%d \n" ,p->opr.op[0]->id.id,ex(p->opr.op[1]));
			return update((p->opr.op[0]->id.id), ex(p->opr.op[1]));
		}
		case PRINT:
			printf("%d\n", ex(p->opr.op[0]));
			return 0;
		case PRINT_List:
			ex(p->opr.op[0]);
			ex(p->opr.op[1]);
			return 0;

		case IF:
			if (ex(p->opr.op[0]) == 1)
				return ex(p->opr.op[1]);
			else
				return ex(p->opr.op[2]);

		/// IFL????
		case IFL:
			printf("IFL\n");
			if (ex(p->opr.op[0]) == 1)
			{
				printf("hello\n");
				return ex(p->opr.op[1]);
			}
			else
				return 0;
		case WHILE:
		{
			// printf("c file il ah njn epo\n");
			while (ex(p->opr.op[0]) == 1)
			{

				ex(p->opr.op[1]);
			}
			// printf("while work ayilla \n");
			return 1;
		}
		case DECLARE_L:
			declareVar(p->opr.op[0], 0);
			return 0;
		case DECLARE_G:
			declareVar(p->opr.op[0], 1);
			return 0;

		case DECLARE_List:

			// printf("Im here\n");
			ex(p->opr.op[0]);
			ex(p->opr.op[1]);
			return 0;
		case DECLARE_Fn:
			// printf("Declare fn in c \n");
			declareFn(p->opr.op[0], p->opr.op[1]);

			return 0;
		case CALL:
		{

			node *ptr = getFn(p->opr.op[0]);
			if (ptr == NULL || ptr == __UINTPTR_MAX__)
			{
				printError("Function definition missing", 1, p);
			}
			else
			{
				char *er = passParameters(ptr, p->opr.op[1]);
				if (strcmp(er, "done") == 0)
				{
					return ex(ptr);
				}
				else
					printError(er, 2, p);
			}
		}
		case Main: 
			declareFn("MAIN",p->opr.op[0]);
			return ex(p->opr.op[0]);

			return 0;

		case GREATERTHANOREQUAL:
			return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
		case LESSTHANOREQUAL:
			return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
		case NOTEQUAL:
			return ex(p->opr.op[0]) != ex(p->opr.op[1]);
		case EQUALEQUAL:
			return (ex(p->opr.op[0]) == ex(p->opr.op[1]));
		case LOGICAL_NOT:
			return !(ex(p->opr.op[0]));
		case LOGICAL_AND:
			return ex(p->opr.op[0]) && ex(p->opr.op[1]);
		case LOGICAL_OR:
			return ex(p->opr.op[0]) || ex(p->opr.op[1]);
		case STMNT:
			ex(p->opr.op[0]);
			ex(p->opr.op[1]);
			return 0;
		case ARRAY_DECLARE:
			declare_array(p->opr.op[0]->id.id, ex(p->opr.op[1]));
		case ARRAY_ASSIGN:
			update_arr(p->opr.op[0]->id.id, ex(p->opr.op[1]), ex(p->opr.op[2]));
		case INDEX:
			return fetch_var_ar(p->opr.op[0]->id.id, ex(p->opr.op[1]));
		}
	}
	return 0;
}
int count = 0;

// for global
int symRead(char *name)
{
	// printf("symR\n");
	char *newName = malloc(sizeof(char) * strlen(name));
	strcpy(newName, name);
	int i;
	for (i = 0; i < 100 && symTab[i].declared; i++)
	{
		if (strcmp(symTab[i].name, newName) == 0)
			return i;
	}
	if (i >= 100)
		return -1;

	return -1;
	// declare (newName);
	// return i;
}
int fetch_var_ar(char *name, int ar_index)
{
	int index;
	if (saveTab != NULL)
	{
		index = symReadL(name);
		if (saveTab[index].declared < 1)
		{
			return -1;
		}
		return saveTab[index].int_ar[ar_index];
	}
	index = symRead(name);
	if (symTab[index].declared < 1)
	{
		return -1;
	}
	return symTab[index].int_ar[ar_index];
}
// int declare(char* name)
// {
// 	//printf("decl\n");
//     //char* newName = malloc(sizeof(char)*strlen(name));
// 	 char* newName = strdup(name);
// 	//printf("144\n");
// 	int i;
// 	for(i=0;i<100 && symTab[i].allocated;i++)
// 	{
// 		if(strcmp(symTab[i].name,newName)==0) return i;
// 	}
// 	if(i>=100) return -1;
// 	symTab[i].name = newName;
// 	symTab[i].allocated=1;
// 	symTab[i].type = typeInt ;
// 	//printf("declared\n");
// 	return i;
// }
int declare_array(char *name, int size)
{
	char *newName = malloc(sizeof(char) * strlen(name));
	strcpy(newName, name);
	int i;
	for (i = 0; i < 100 && symTab[i].allocated; i++)
	{
		if (strcmp(symTab[i].name, newName) == 0)
			return i;
	}
	if (i >= 100)
		return -1;
	symTab[i].name = newName;
	symTab[i].allocated = size;
	symTab[i].type = typeArr;
	symTab[i].int_ar = malloc(sizeof(int) * size);

	// printf("declared array");

	return i;
}
int declareFn(char *name, node *ptr)
{

	// char* newName = malloc(sizeof(char)*strlen(name));
	// strcpy(newName,name);
	// printf("%s",name);
	int i = declareG(name, 0);
	symTab[i].type = typeNode;
	if (i == -1)
	{
		return -1;
	}
	symTab[i].allocated = 1;
	// symTab[i].type = typeNode;
	symTab[i].nodeptr = ptr;
	// updateFunStat(name,ptr);
	// printf("njn evde vanno?\n");printf("Erangi\n");
	return i;
}

int updateFunStat(char *str, node *ptr)
{
	int index = symRead(str);
	symTab[index].allocated = 1;
	symTab[index].nodeptr = ptr;
	return 1;
}
void printSymTab()
{
	int i = 0;
	printf("index\tname\talloc\tval\n");
	for (; i < 100; i++)
		if (symTab[i].name)
		{
			printf("%d\t%s\t%d\t%d", i, symTab[i].name, symTab[i].allocated, symTab[i].declared);
			if (symTab[i].type == typeInt)
				printf("\t%d", symTab[i].val);
			else if (symTab[i].type == typeNode)
				printf("\t%p", symTab[i].nodeptr);
			else if (symTab[i].type == typeArr)
			{
				for (int j = 0; j < symTab[i].allocated; j++)
					printf("\t%p ", symTab[i].int_ar[j]);
			}
			printf("\n");
		}
}

int getVal(char *str)
{
	int index;
	if (saveTab != NULL)
	{
		index = symReadL(str);
		if (saveTab[index].declared >= 1)
		{

			return saveTab[index].val;
		}
	}
	index = symRead(str);
	if (symTab[index].declared != 1)
	{
		// printf("Something wong...im returning from getVal\n");
		return 0;
	}
	// printf("Im in getVal and returning %d\n",symTab[index].val);
	return symTab[index].val;
}
node *getFn(char *str)
{
	int index = symRead(str);
	if (!symTab[index].allocated || symTab[index].type != typeNode)
		return 0;
	return symTab[index].nodeptr;
}
int update(char *str, int value)
{
	int index;
	if (saveTab != NULL)
	{
		index = symReadL(str);
		if (index >= 0 && saveTab[index].declared)
		{
			saveTab[index].type = typeInt;
			saveTab[index].val = value;
			saveTab[index].allocated = 1;
		}
	}
	index = symRead(str);
	symTab[index].type = typeInt;
	symTab[index].allocated = 1;
	symTab[index].val = value;
	// printf("update done ...so variable assigned correctly to %d \n",symTab[index].val);
	return 1;
}
int update_arr(char *str, int ar_index, int value)
{
	int index;
	if (saveTab != NULL)
	{
		index = symReadL(str);
		if (index >= 0 && saveTab[index].declared)
		{
			saveTab[index].allocated = 1;
			saveTab[index].int_ar[ar_index] = value;
			return 1;
		}
	}
	index = symRead(str);
	symTab[index].allocated = 1;
	symTab[index].int_ar[ar_index] = value;
	// printf("update done ...so variable assigned correctly to %d \n",symTab[index].int_ar[ar_index]);
	// printf("array val updated\n");
	return 1;
}

// eval function

node *evalF(funNodeType fn)
{
	struct sym *oldSym = saveTab;
	saveTab=malloc(sizeof(struct sym)*25);
	// saveTab = fn.symTab;
	// retTypeEnum ret;
	// ex(fn.fun_block);
	
	if(saveTab == NULL)
		yyerror("Out of mem");
	argListType * ptr = fn.arg_list;
	int i = 0;
	while (ptr!=NULL)
	{
		saveTab[i].name = ptr->name;
		if(ptr->type == Int)
			saveTab[i].type = typeInt;
		saveTab[i].declared=1;
		saveTab[i].allocated = 1;
		saveTab[i].val = ptr->val;
		i++;
		ptr=ptr->next;
	}
	ex(fn.decl);
	ex(fn.fun_block);

	int result = ex(fn.ret_node);
	saveTab = oldSym;
	return result;
	
}

///////////////////////////////////////////
// For local
int symReadL(char *name)
{
	// printf("symR\n");
	char *newName = malloc(sizeof(char) * strlen(name));
	strcpy(newName, name);
	int i;
	for (i = 0; i < SYM_L && saveTab[i].declared; i++)
	{
		if (strcmp(saveTab[i].name, newName) == 0)
			return i;
	}
	if (i >= 100)
		return -1;

	return -1;
	// declare (newName);
	// return i;
}

void printSymTabL()
{
	int i = 0;
	printf("index\tname\talloc\tval\n");
	for (; i < 100; i++)
		if (symTab[i].name)
		{
			printf("%d\t%s\t%d\t%d", i, symTab[i].name, saveTab[i].allocated, saveTab[i].declared);
			if (saveTab[i].type == typeInt)
				printf("\t%d", saveTab[i].val);
			else if (symTab[i].type == typeNode)
				printf("\t%p", symTab[i].nodeptr);
			else if (symTab[i].type == typeArr)
			{
				for (int j = 0; j < symTab[i].allocated; j++)
					printf("\t%p ", symTab[i].int_ar[j]);
			}
			printf("\n");
		}
}

/// variables
int declareVar(varItemtype *varList, int global)
{
	int flag = 0;
	varItemtype *ptr = varList;
	if (global == 1)
	{
		while (ptr != NULL)
		{
			flag = declareG(ptr->name, ptr->length);
			if (flag == -1)
			{
				return -1;
			}
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr != NULL)
		{
			flag = declareL(ptr->name, ptr->length);
			if (flag == -1)
			{
				return -1;
			}
			ptr = ptr->next;
		}
	}
	return 1;
}

int declareG(char *name, int size)
{

	 char *newName = strdup(name);
	// char* newName = malloc(sizeof(char)*strlen(name));
	// strcpy(newName,name);

	int i;
	for (i = 0; i < SYM_G && symTab[i].declared; i++)
	{
		if (strcmp(symTab[i].name, newName) == 0)
			return i;
	}
	if (i >= 100)
		return -1;
	symTab[i].name=newName;
	if (size == 0)
	{
		symTab[i].type = typeInt;
		symTab[i].declared = 1;
	}
	else
	{
		symTab[i].type = typeArr;
		symTab[i].declared = size;
		symTab[i].int_ar = malloc(sizeof(int) * size);
	}

	return i;
}

int declareL(char *name, int size)
{

	char *newName = strdup(name);

	int i;
	for (i = 0; i < SYM_G && saveTab[i].declared; i++)
	{
		if (strcmp(saveTab[i].name, newName) == 0)
			return i;
	}
	if (i >= 100)
		return -1;
	saveTab[i].name=newName;
	if (size == 0)
	{
		saveTab[i].type = typeInt;
		saveTab[i].declared = 1;
	}
	else
	{
		saveTab[i].type = typeArr;
		saveTab[i].declared = size;
		saveTab[i].int_ar = malloc(sizeof(int) * size);
	}

	return i;
}

char *passParameters(node *fNode, struct node_item *list)
{
	if (fNode->type == typeFun)
	{
		if (lengthOfParaList(list) != fNode->fn.n_args)
		{
			return "Parameters missing";
		}
	}
	int i = 0;
	nodeItemtype *ptr = list;
	argListType * a = fNode->fn.arg_list;
	while (ptr != NULL)
	{
		a->val = ex(ptr->node_ptr);
		// fNode->fn.symTab[i].declared = 1;
		// i++;
		a = a->next;
		ptr = ptr->next;
	}
	return "done";
}
void printError(char *str, int ops, node *p)
{
	fprintf(stderr, "ERROR: ");
	fprintf(stderr, "%s", str);
	for (int i = 0; i < ops; i++)
	{
		printf(stderr, "%s", p->opr.op[i]);
	}
	fprintf(stderr, "\n");
	return;
}