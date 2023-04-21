#include <stdio.h>
#include "../include/calc3.h"
#include "../include/list.h"
#include "../bin/y.tab.h"
#include <string.h>
#include <stdlib.h>

argListType* singleton(retTypeEnum ret, char* var)
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
    ptr->next = old;
    return ptr;
}
