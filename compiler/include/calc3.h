typedef enum { typeCon, typeOpr } nodeEnum;

/* constants */
typedef struct {
    int value; /* value of constant */
} conNodeType;
/* identifiers */

/* operators */
typedef struct {
    int oper; /* operator */
    int nops ;//no. of operands
    struct nodeTypeTag **op; /* operands */
} oprNodeType;

typedef struct nodeTypeTag {
    nodeEnum type; /* type of node */
    union {
        conNodeType con; /* constants */
        oprNodeType opr; /* operators */
    };
} node;
struct sym{
    char* name;
    int val;
    int allocated;
};
extern struct sym symTab[100];
int symRead(char*);
int getVal(int );
int update(int,int);
int declare(char*);
char strr[100];
// extern int sym[26]; 
