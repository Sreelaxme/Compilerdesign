typedef enum { typeCon,typeId, typeOpr,typeFun } nodeEnum;
typedef enum {typeInt, typeNode,typeArr, unallocated} symTabEnum;
typedef enum{Int,Bool,Void} retTypeEnum;
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
typedef struct{
    retTypeEnum return_type;
    struct nodeTypeTag* ret_node;
    struct nodeTypeTag* fun_block;
    struct sym *symTab;
}funNodeType;

typedef struct nodeTypeTag {
    nodeEnum type; /* type of node */
    union {
        conNodeType con; /* constants */
        oprNodeType opr; /* operators */
        idNodeType id;
        funNodeType fn;
    };
} node;
struct sym{
    char* name;
    int allocated;
    int declared ; 
    symTabEnum  type;
    union{
        int val;
        char * string;
        node* nodeptr;
        node* funcptr; 
    };
    int* int_ar;
};

//type of arglist
typedef struct {
    retTypeEnum type;
    char * name;
    argListType *nect;
}argListType;


//symtab for function

extern struct sym symTab[100];
extern struct sym *saveTab; //local symtab
int symRead(char*);
int getVal(char *);
int update(char*,int);
int declare(char*);

// extern int sym[26]; 
	extern int yylineno;
	extern char* yytext;