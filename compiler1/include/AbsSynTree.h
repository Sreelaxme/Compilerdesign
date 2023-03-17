typedef enum { typeCon,typeId, typeOpr } nodeEnum;

/* constants */
typedef struct {
    int value; /* value of constant */
} conNodeType;
/* identifiers */
typedef struct {
    char* id; /* subscript to sym array */
} idNodeType; 
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
        idNodeType id;
    };
} node;
struct sym{
    char* name;
    int val;
    int allocated;
};
extern struct sym symTab[100];
int symRead(char*);
int getVal(char *);
int update(char*,int);
int declare(char*);

// extern int sym[26]; 
