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
// extern int sym[26]; 
