#include <stdio.h>
#include "../include/calc3.h"

#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>


//arguments
argListType* singletonArg(retTypeEnum ret, char* var)
{
    argListType *ptr = malloc(sizeof(argListType));
    ptr->type = ret;
    ptr->name = var;
    ptr->next = NULL;
    return ptr;
}
argListType *listArg(retTypeEnum ret, char* var, argListType *old)
{
    argListType *ptr=malloc(sizeof(argListType));
    ptr->type = ret;
    ptr->name = var;
    ptr->next = NULL;
    if(!old)
    {
        return ptr;
    }
    argListType * p = old;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;

    return old;
}

int lengthOfArgList(argListType *list)
{
    argListType * ptr=list;
    int i=0;
    while(ptr!=NULL)
    {
        //printf("ARG VALUE %s",ptr->name);
        i++;
        ptr = ptr->next;
        
    } 
    return i;
    
}

//parameters
nodeItemtype* singletonPara(node * Node)
{
    nodeItemtype *ptr = malloc(sizeof(nodeItemtype));
    ptr->node_ptr=Node;
    ptr->next = NULL;
    return ptr;
}
nodeItemtype *listPara(node * Node, nodeItemtype *list)
{
    nodeItemtype *ptr=malloc(sizeof(nodeItemtype));
    ptr->node_ptr = Node;
    ptr->next = NULL;
    // if(!list)
    // {
    //     return ptr;
    // }
    nodeItemtype * p = list;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;

    return list;
}

int lengthOfParaList(nodeItemtype *list)
{
    nodeItemtype * ptr=list;
    int i=0;
    while(ptr!=NULL)
    {
        i++;
        ptr = ptr->next;
    } 
    return i;
    
}

//variables

varItemtype* singletonVar(char* name, int length)
{
    varItemtype *ptr = malloc(sizeof(varItemtype));
    ptr->name=name;
    ptr->length = length;
    ptr->next = NULL;
    return ptr;
}
//y like this?
varItemtype *listVar(varItemtype *item , varItemtype * list )
{
    varItemtype *ptr=malloc(sizeof(varItemtype));
   
    if(!list)
    {
        return item;
    }
    varItemtype * p = list;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = item;

    return list;
}

int lengthOfVarList(varItemtype *list)
{
    varItemtype * ptr=list;
    int i=0;
    while(ptr!=NULL)
    {
        ptr = ptr->next;
        i++;
    } 
    return i;
    
}
void printarglist(struct arg_item *list) {
    argListType *ptr = list;

    while (ptr != NULL) {
        fprintf(stdout, "int %s",  ptr->name);
        ptr = ptr->next;
        if (ptr != NULL) {
            fprintf(stdout, ", ");
        }
    }
}
