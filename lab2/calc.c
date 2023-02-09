#include <stdio.h>
#include "calc3.h"
#include "y.tab.h"
static int lbl;
int ex(nodeType *p) {
 int lbl1, lbl2;
 if (!p) return 0;
 switch(p->type) {
 case typeCon:
 return p->con.value;


 case typeOpr:
 switch(p->opr.oper) {
 case '+': return ex(p->opr.op[0]) + ex(p->opr.op[1]);
 case '-': return ex(p->opr.op[0]) - ex(p->opr.op[1]);
 case '*': return ex(p->opr.op[0]) * ex(p->opr.op[1]);
 case '/': return ex(p->opr.op[0]) / ex(p->opr.op[1]);
 }
 }
 return 0;
 }
