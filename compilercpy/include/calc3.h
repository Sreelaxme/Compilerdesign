#define SYM_G 100
#define SYM_L 25

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
    struct node * ret_node;
    struct node * fun_block;
    struct node* decl;
    struct arg_list *arg_list;
    
    int n_args;
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

//symtab
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
        int* int_ar;
    };
};
//changed int_ar inside union

//type of arglist
typedef struct arg_list{
    retTypeEnum type;
    char * name;
    struct arg_list *next;
    int val;
}argListType;

///////////////////////
typedef struct node_item{
    node * node_ptr;
    struct node_item *next;
    
}nodeItemtype;

typedef struct var_item
{
   char * name;
   int length;
   struct var_item *next;
}varItemtype;

///////////////////////






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