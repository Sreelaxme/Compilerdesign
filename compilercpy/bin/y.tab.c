/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/compiler.y"

#include <stdio.h>
#include"../include/calc3.h"
#include <stdarg.h>
int yylex(void);
void yyerror(char *);
node *opr(int oper, int nops, ...);
node *con(int value);
node *id(char* var);
int ex(node *p);
void freeNode(node *p);

int declare_array(char *, int );


int declareFn(char* name, node* ptr);
node* getFn(char* str);
int updateFunStat(char* str,node* ptr);
void printSyntaxTree(node* );
void toC(node *);
void printSymTab();
struct sym symTab[100];
int update_arr(char * str, int ar_index, int value);
int declare_array(char* name,int size);
node* getFn(char* str);

argListType* singletonArg(retTypeEnum ret, char* var);
argListType *listArg(retTypeEnum ret, char* var, argListType *old);
int lengthOfArgList(argListType *list);
nodeItemtype* singletonPara(node * Node);
nodeItemtype *listPara(node * Node, nodeItemtype *list);
int lengthOfParaList(nodeItemtype *list);
varItemtype* singletonVar(char* name, int length);
varItemtype *listVar(varItemtype *item , varItemtype * list );
int lengthOfVarList(varItemtype *list);

node *fNode(node* list, retTypeEnum ret,node * expr,argListType *argList, node * decl);
argListType * singlelineArg(varItemtype * l1,varItemtype *l2);

extern struct sym *saveTab;
extern struct sym symTab[100];
	extern FILE * fp;

#line 114 "bin/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_BIN_Y_TAB_H_INCLUDED
# define YY_YY_BIN_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    VARIABLE = 259,
    STRING = 260,
    INT = 261,
    VOID = 262,
    BOOL = 263,
    DECL = 264,
    ENDDECL = 265,
    DECLARE_L = 266,
    DECLARE = 267,
    DECLARE_G = 268,
    STMNT = 269,
    DECLARE_List = 270,
    DECLARE_Fn = 271,
    CALL = 272,
    Main = 273,
    PRINT = 274,
    PRINTS = 275,
    PRINT_List = 276,
    Begin = 277,
    End = 278,
    MAIN = 279,
    INDEX = 280,
    IF = 281,
    THEN = 282,
    ELSE = 283,
    ENDIF = 284,
    IFL = 285,
    DO = 286,
    WHILE = 287,
    ENDWHILE = 288,
    EQUALEQUAL = 289,
    LESSTHANOREQUAL = 290,
    GREATERTHANOREQUAL = 291,
    NOTEQUAL = 292,
    LOGICAL_AND = 293,
    LOGICAL_NOT = 294,
    LOGICAL_OR = 295,
    READ = 296,
    WRITE = 297,
    ARRAY_DECLARE = 298,
    ARRAY_ASSIGN = 299,
    RETURN = 300,
    UMINUS = 301
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define VARIABLE 259
#define STRING 260
#define INT 261
#define VOID 262
#define BOOL 263
#define DECL 264
#define ENDDECL 265
#define DECLARE_L 266
#define DECLARE 267
#define DECLARE_G 268
#define STMNT 269
#define DECLARE_List 270
#define DECLARE_Fn 271
#define CALL 272
#define Main 273
#define PRINT 274
#define PRINTS 275
#define PRINT_List 276
#define Begin 277
#define End 278
#define MAIN 279
#define INDEX 280
#define IF 281
#define THEN 282
#define ELSE 283
#define ENDIF 284
#define IFL 285
#define DO 286
#define WHILE 287
#define ENDWHILE 288
#define EQUALEQUAL 289
#define LESSTHANOREQUAL 290
#define GREATERTHANOREQUAL 291
#define NOTEQUAL 292
#define LOGICAL_AND 293
#define LOGICAL_NOT 294
#define LOGICAL_OR 295
#define READ 296
#define WRITE 297
#define ARRAY_DECLARE 298
#define ARRAY_ASSIGN 299
#define RETURN 300
#define UMINUS 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "src/compiler.y"

	int iValue;  /* integer value */
	char* str;
	argListType *argType;
	node *nPtr; /* node pointer */
	argListType *argList;
	nodeItemtype *paramList;
	varItemtype *varList;


#line 269 "bin/y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   473

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      58,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    52,     2,     2,
      53,    54,    50,    48,    59,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
      46,    62,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    57,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    93,    93,    94,    95,   102,   103,   106,   107,   108,
     111,   115,   116,   120,   123,   128,   129,   133,   134,   138,
     139,   140,   144,   145,   146,   150,   151,   156,   157,   159,
     163,   164,   165,   166,   169,   170,   174,   175,   179,   182,
     183,   184,   186,   187,   188,   189,   190,   191,   192,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "VARIABLE", "STRING", "INT",
  "VOID", "BOOL", "DECL", "ENDDECL", "DECLARE_L", "DECLARE", "DECLARE_G",
  "STMNT", "DECLARE_List", "DECLARE_Fn", "CALL", "Main", "PRINT", "PRINTS",
  "PRINT_List", "Begin", "End", "MAIN", "INDEX", "IF", "THEN", "ELSE",
  "ENDIF", "IFL", "DO", "WHILE", "ENDWHILE", "EQUALEQUAL",
  "LESSTHANOREQUAL", "GREATERTHANOREQUAL", "NOTEQUAL", "LOGICAL_AND",
  "LOGICAL_NOT", "LOGICAL_OR", "READ", "WRITE", "ARRAY_DECLARE",
  "ARRAY_ASSIGN", "RETURN", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'('", "')'", "'{'", "';'", "'}'", "'\\n'", "','", "'['", "']'",
  "'='", "UMINUS", "$accept", "program", "return_type", "main", "endl",
  "func_call", "Fdef", "varList", "var", "arg_list", "param_list", "pList",
  "stmt_list", "decl_line", "decl_stmt_g", "decl_stmt_l", "read", "stmt",
  "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    60,    62,    43,    45,
      42,    47,    37,    40,    41,   123,    59,   125,    10,    44,
      91,    93,    61,   301
};
# endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -111,    50,  -111,     9,     1,  -111,  -111,  -111,  -111,  -111,
      21,  -111,  -111,  -111,  -111,   108,     2,    25,    52,    16,
      16,    16,    16,  -111,    26,   108,   108,   108,  -111,    30,
     219,   109,  -111,   138,    69,   108,  -111,   245,   406,  -111,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,    68,    83,    66,    10,   152,   104,
    -111,   180,  -111,   421,   421,   421,   421,  -111,  -111,   100,
     100,   283,   283,   103,   103,    59,  -111,   138,   156,  -111,
     160,  -111,   101,  -111,   -27,  -111,   116,   110,     2,   117,
    -111,   138,    36,  -111,   132,  -111,  -111,  -111,  -111,     5,
    -111,    16,     5,  -111,  -111,     2,  -111,     2,   -12,  -111,
      -3,  -111,  -111,    16,  -111,    11,    61,    61,  -111,   134,
     125,   172,   108,   108,   139,   135,  -111,   137,  -111,   291,
    -111,  -111,   108,   108,    78,   153,   265,   245,   245,   160,
    -111,   -19,  -111,     8,  -111,    31,   199,   314,   158,  -111,
     108,   -26,    -2,   159,   108,  -111,   108,   146,  -111,   163,
    -111,  -111,  -111,  -111,   337,   360,   108,  -111,    61,    61,
    -111,  -111,   383,  -111,  -111,    12,    15,  -111,    14,   -10,
    -111,  -111,  -111,   166,   167,    51,    75,    61,  -111,  -111,
    -111,  -111,  -111,    16,    16,    -7,   168,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    11,     1,    34,     0,     7,     8,     9,    11,    12,
       0,    11,    11,    11,    11,    22,    30,     0,     0,     4,
       5,     3,     6,    49,    50,     0,     0,     0,    68,     0,
      23,     0,    11,    19,     0,     0,    65,    52,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    18,     0,    15,     0,     0,     0,
      11,     0,    60,    64,    62,    61,    63,    66,    67,    58,
      59,    53,    54,    55,    56,    57,    24,    19,     0,    11,
       0,    35,    20,    11,     0,    51,     0,     0,    30,    18,
      16,    19,     0,    11,     0,    17,    11,    21,    11,    36,
      11,    32,    36,    11,    11,    30,    11,    30,     0,    11,
       0,    11,    11,    33,    11,     0,     0,     0,    37,     0,
      50,     0,     0,     0,     0,    68,    11,     0,    11,     0,
      11,    29,     0,     0,     0,     0,    26,    11,    11,     0,
      47,     0,    48,     0,    39,     0,     0,     0,     0,    42,
       0,     0,     0,     0,     0,    28,     0,    51,    41,     0,
      25,    11,    11,    38,     0,     0,     0,    43,     0,     0,
      11,    11,     0,    11,    11,     0,     0,    40,     0,     0,
      11,    11,    11,     0,     0,     0,     0,     0,    45,    46,
      11,    11,    11,    10,    14,     0,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,   207,  -111,    -8,    -1,  -111,   162,    99,   -47,
     187,    93,  -110,    19,  -111,   142,  -111,  -111,   154
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    58,    11,     3,    28,    13,    55,    56,    59,
      29,   135,   126,    32,    14,   104,   127,   128,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,   161,    12,    19,    20,    21,    22,   130,    31,   119,
     112,    23,   120,     4,   103,     5,     6,     7,     8,   114,
      81,   118,   196,   184,    57,    17,   154,   121,    93,   162,
      86,     9,     9,   155,   122,   180,   -27,   -27,   181,     9,
     123,   -27,   182,   183,    97,    18,     9,    25,     9,   124,
       2,     9,    84,   -27,    15,     9,     9,    26,   173,   174,
       9,    27,   119,     9,    23,   120,     9,     9,     9,     9,
       9,    88,     9,     9,     9,    92,   156,   192,    33,    15,
     121,    23,    24,   148,    39,    99,    35,   122,   101,     9,
     102,    98,   105,   123,     9,   107,   108,    44,   110,    45,
      25,   113,   124,   115,   116,    34,   117,    96,   190,     9,
      26,    23,    24,    54,    27,   125,   125,    25,   141,     9,
     143,    77,   145,    60,   109,    80,   111,    26,    78,   151,
     152,    27,   191,     9,    40,    41,    42,    43,    44,    79,
      45,    44,   125,    45,     5,     6,     7,    25,    48,    49,
      50,    51,    52,   168,   169,    52,    82,    26,    83,    87,
      91,    27,   175,   176,    89,   178,   179,   125,   125,    30,
      94,    95,   185,   186,   187,    23,    24,    78,    15,    36,
      37,    38,   193,   194,   195,   132,   125,   133,   100,    61,
     131,   140,   139,   142,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    30,   166,   149,
      10,    25,   159,   163,    40,    41,    42,    43,    44,   167,
      45,    26,   188,   189,   197,   134,    46,    47,    48,    49,
      50,    51,    52,    40,    41,    42,    43,    44,   153,    45,
      76,    85,    90,   160,   106,    46,    47,    48,    49,    50,
      51,    52,     0,    40,    41,    42,    43,    44,     0,    45,
     157,     0,     0,     0,     0,    46,    47,    48,    49,    50,
      51,    52,     0,     0,     0,   136,   137,   138,    53,    40,
      41,    42,    43,    44,     0,    45,   146,   147,    38,     0,
       0,    46,    47,    48,    49,    50,    51,    52,     0,    40,
      41,    42,    43,    44,   136,    45,     0,     0,   164,     0,
     165,    46,    47,    48,    49,    50,    51,    52,     0,     0,
     172,    44,     0,    45,   150,    40,    41,    42,    43,    44,
       0,    45,     0,    50,    51,    52,     0,    46,    47,    48,
      49,    50,    51,    52,     0,     0,     0,   144,    40,    41,
      42,    43,    44,     0,    45,     0,     0,     0,     0,     0,
      46,    47,    48,    49,    50,    51,    52,     0,     0,     0,
     158,    40,    41,    42,    43,    44,     0,    45,     0,     0,
       0,     0,     0,    46,    47,    48,    49,    50,    51,    52,
       0,     0,     0,   170,    40,    41,    42,    43,    44,     0,
      45,     0,     0,     0,     0,     0,    46,    47,    48,    49,
      50,    51,    52,     0,     0,     0,   171,    40,    41,    42,
      43,    44,     0,    45,     0,     0,     0,     0,     0,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,   177,
      40,    41,    42,    43,    44,     0,    45,     0,     0,     0,
       0,     0,    46,    47,    48,    49,    50,    51,    52,    44,
      62,    45,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52
};

static const yytype_int16 yycheck[] =
{
       8,    27,     3,    11,    12,    13,    14,   117,     6,     1,
      22,     3,     4,     4,     9,     6,     7,     8,     9,    22,
      10,    10,    29,    33,    32,     4,    45,    19,    55,    31,
      77,    58,    58,   143,    26,    23,    28,    29,    23,    58,
      32,    33,    28,    29,    91,    24,    58,    39,    58,    41,
       0,    58,    60,    45,    53,    58,    58,    49,   168,   169,
      58,    53,     1,    58,     3,     4,    58,    58,    58,    58,
      58,    79,    58,    58,    58,    83,    45,   187,    53,    53,
      19,     3,     4,     5,    54,    93,    60,    26,    96,    58,
      98,    55,   100,    32,    58,   103,   104,    38,   106,    40,
      39,   109,    41,   111,   112,    53,   114,    88,    57,    58,
      49,     3,     4,     4,    53,   116,   117,    39,   126,    58,
     128,    53,   130,    54,   105,    59,   107,    49,    60,   137,
     138,    53,    57,    58,    34,    35,    36,    37,    38,    56,
      40,    38,   143,    40,     6,     7,     8,    39,    48,    49,
      50,    51,    52,   161,   162,    52,     4,    49,    54,     3,
      59,    53,   170,   171,     4,   173,   174,   168,   169,    15,
      54,    61,   180,   181,   182,     3,     4,    60,    53,    25,
      26,    27,   190,   191,   192,    60,   187,    62,    56,    35,
      56,    56,    53,    56,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    62,    56,
       3,    39,    54,    54,    34,    35,    36,    37,    38,    56,
      40,    49,    56,    56,    56,    53,    46,    47,    48,    49,
      50,    51,    52,    34,    35,    36,    37,    38,   139,    40,
      53,    61,    80,   150,   102,    46,    47,    48,    49,    50,
      51,    52,    -1,    34,    35,    36,    37,    38,    -1,    40,
      61,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,   121,   122,   123,    59,    34,
      35,    36,    37,    38,    -1,    40,   132,   133,   134,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    -1,    34,
      35,    36,    37,    38,   150,    40,    -1,    -1,   154,    -1,
     156,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
     166,    38,    -1,    40,    59,    34,    35,    36,    37,    38,
      -1,    40,    -1,    50,    51,    52,    -1,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    34,    35,
      36,    37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      56,    34,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    56,    34,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    56,    34,    35,    36,
      37,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    56,
      34,    35,    36,    37,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    38,
      54,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,     0,    68,     4,     6,     7,     8,     9,    58,
      66,    67,    69,    70,    78,    53,    68,     4,    24,    68,
      68,    68,    68,     3,     4,    39,    49,    53,    69,    74,
      82,     6,    77,    53,    53,    60,    82,    82,    82,    54,
      34,    35,    36,    37,    38,    40,    46,    47,    48,    49,
      50,    51,    52,    59,     4,    71,    72,    68,    66,    73,
      54,    82,    54,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    74,    53,    60,    56,
      59,    10,     4,    54,    68,    61,    73,     3,    68,     4,
      71,    59,    68,    55,    54,    61,    77,    73,    55,    68,
      56,    68,    68,     9,    79,    68,    79,    68,    68,    77,
      68,    77,    22,    68,    22,    68,    68,    68,    10,     1,
       4,    19,    26,    32,    41,    69,    76,    80,    81,    82,
      76,    56,    60,    62,    53,    75,    82,    82,    82,    53,
      56,    68,    56,    68,    56,    68,    82,    82,     5,    56,
      59,    68,    68,    72,    45,    76,    45,    61,    56,    54,
      75,    27,    31,    54,    82,    82,    62,    56,    68,    68,
      56,    56,    82,    76,    76,    68,    68,    56,    68,    68,
      23,    23,    28,    29,    33,    68,    68,    68,    56,    56,
      57,    57,    76,    68,    68,    68,    29,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    65,    65,    65,    66,    66,    66,
      67,    68,    68,    69,    70,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    79,    79,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     4,     4,     4,     1,     1,     1,
      21,     0,     2,     4,    22,     1,     3,     4,     1,     0,
       2,     4,     0,     1,     3,     3,     1,     2,     3,     2,
       0,     4,     6,     9,     0,     5,     0,     5,     4,     2,
       7,     4,     3,     5,    13,     9,     9,     2,     2,     1,
       1,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3:
#line 94 "src/compiler.y"
                                {/*printf("prgrm 1 \n"*);printSyntaxTree($3); */ toC((yyvsp[-1].nPtr));ex((yyvsp[-1].nPtr));}
#line 1624 "bin/y.tab.c"
    break;

  case 4:
#line 95 "src/compiler.y"
                                { /*printf("main\n");*/
							//printSyntaxTree($3);
							toC((yyvsp[-1].nPtr));
							printf("\n\n\nPROGRAM OUTPUT \n"); 
									ex((yyvsp[-1].nPtr));
									printf("\nSymbol Table\n");
									printSymTab();}
#line 1636 "bin/y.tab.c"
    break;

  case 6:
#line 103 "src/compiler.y"
                                        { /*printSyntaxTree($3); */toC((yyvsp[-1].nPtr)); ex((yyvsp[-1].nPtr));}
#line 1642 "bin/y.tab.c"
    break;

  case 7:
#line 106 "src/compiler.y"
            {(yyval.iValue)=Int;}
#line 1648 "bin/y.tab.c"
    break;

  case 8:
#line 107 "src/compiler.y"
              {(yyval.iValue) = Void;}
#line 1654 "bin/y.tab.c"
    break;

  case 9:
#line 108 "src/compiler.y"
               {(yyval.iValue) = Bool;}
#line 1660 "bin/y.tab.c"
    break;

  case 10:
#line 113 "src/compiler.y"
        { (yyval.nPtr) = opr(Main,1,fNode((yyvsp[-9].nPtr),(yyvsp[-20].iValue),(yyvsp[-6].nPtr),NULL,(yyvsp[-13].nPtr))) ;}
#line 1666 "bin/y.tab.c"
    break;

  case 13:
#line 120 "src/compiler.y"
                                      { (yyval.nPtr)=opr(CALL,2,(yyvsp[-3].str),(yyvsp[-1].paramList)); /*printf("funcall aane\n");*/}
#line 1672 "bin/y.tab.c"
    break;

  case 14:
#line 124 "src/compiler.y"
        {  (yyval.nPtr) = opr(DECLARE_Fn,2,(yyvsp[-20].str),fNode((yyvsp[-9].nPtr),(yyvsp[-21].iValue),(yyvsp[-6].nPtr),(yyvsp[-18].argList),(yyvsp[-13].nPtr)));}
#line 1678 "bin/y.tab.c"
    break;

  case 15:
#line 128 "src/compiler.y"
             {(yyval.varList) = (yyvsp[0].varList);}
#line 1684 "bin/y.tab.c"
    break;

  case 16:
#line 129 "src/compiler.y"
                          {(yyval.varList) = listVar((yyvsp[-2].varList),(yyvsp[0].varList));}
#line 1690 "bin/y.tab.c"
    break;

  case 17:
#line 133 "src/compiler.y"
                                 {(yyval.varList) = singletonVar((yyvsp[-3].str),(yyvsp[-1].iValue));}
#line 1696 "bin/y.tab.c"
    break;

  case 18:
#line 134 "src/compiler.y"
                   {/*printf("1 in varList\n");*/(yyval.varList) = singletonVar((yyvsp[0].str),0);}
#line 1702 "bin/y.tab.c"
    break;

  case 19:
#line 138 "src/compiler.y"
         {(yyval.argList) =NULL;}
#line 1708 "bin/y.tab.c"
    break;

  case 20:
#line 139 "src/compiler.y"
                               {(yyval.argList) = singletonArg((yyvsp[-1].iValue),(yyvsp[0].str));}
#line 1714 "bin/y.tab.c"
    break;

  case 21:
#line 140 "src/compiler.y"
                                            { (yyval.argList) = listArg((yyvsp[-3].iValue),(yyvsp[-2].str),(yyvsp[0].argList));}
#line 1720 "bin/y.tab.c"
    break;

  case 22:
#line 144 "src/compiler.y"
         {(yyval.paramList) = NULL;}
#line 1726 "bin/y.tab.c"
    break;

  case 23:
#line 145 "src/compiler.y"
              {(yyval.paramList) = singletonPara((yyvsp[0].nPtr));/*printf("evdem vannu\n");*/}
#line 1732 "bin/y.tab.c"
    break;

  case 24:
#line 146 "src/compiler.y"
                              {(yyval.paramList) = listPara((yyvsp[-2].nPtr),(yyvsp[0].paramList));}
#line 1738 "bin/y.tab.c"
    break;

  case 25:
#line 150 "src/compiler.y"
                       {(yyval.nPtr) = opr(PRINT_List, 2, opr(PRINT,1,(yyvsp[-2].nPtr)), (yyvsp[0].nPtr));}
#line 1744 "bin/y.tab.c"
    break;

  case 26:
#line 151 "src/compiler.y"
              {(yyval.nPtr) = opr(PRINT, 1, (yyvsp[0].nPtr));}
#line 1750 "bin/y.tab.c"
    break;

  case 27:
#line 156 "src/compiler.y"
                          {(yyval.nPtr) = (yyvsp[-1].nPtr) ;}
#line 1756 "bin/y.tab.c"
    break;

  case 28:
#line 157 "src/compiler.y"
                                           {(yyval.nPtr) = opr(STMNT , 2, (yyvsp[-2].nPtr) ,(yyvsp[0].nPtr)) ;}
#line 1762 "bin/y.tab.c"
    break;

  case 29:
#line 159 "src/compiler.y"
                                                {printf("statement invalid\n") ; (yyval.nPtr) = con(0)  ;}
#line 1768 "bin/y.tab.c"
    break;

  case 30:
#line 163 "src/compiler.y"
        {(yyval.nPtr) = NULL;}
#line 1774 "bin/y.tab.c"
    break;

  case 31:
#line 164 "src/compiler.y"
                               {(yyval.nPtr) = (yyvsp[-2].varList);}
#line 1780 "bin/y.tab.c"
    break;

  case 32:
#line 165 "src/compiler.y"
                                              {(yyval.nPtr) = singlelineArg((yyvsp[-4].varList),(yyvsp[-1].nPtr));}
#line 1786 "bin/y.tab.c"
    break;

  case 33:
#line 166 "src/compiler.y"
                                                                {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1792 "bin/y.tab.c"
    break;

  case 34:
#line 169 "src/compiler.y"
        {(yyval.nPtr)=NULL;}
#line 1798 "bin/y.tab.c"
    break;

  case 35:
#line 170 "src/compiler.y"
                                            { (yyval.nPtr)=opr(DECLARE_G,1,(yyvsp[-2].nPtr));}
#line 1804 "bin/y.tab.c"
    break;

  case 36:
#line 174 "src/compiler.y"
        {(yyval.nPtr)=NULL;}
#line 1810 "bin/y.tab.c"
    break;

  case 37:
#line 175 "src/compiler.y"
                                            {(yyval.nPtr) = opr(DECLARE_L,1,(yyvsp[-2].nPtr));}
#line 1816 "bin/y.tab.c"
    break;

  case 38:
#line 179 "src/compiler.y"
                         {(yyval.nPtr) = opr(READ,1,(yyvsp[-1].varList));}
#line 1822 "bin/y.tab.c"
    break;

  case 39:
#line 182 "src/compiler.y"
                 { (yyval.nPtr)=(yyvsp[-1].nPtr);}
#line 1828 "bin/y.tab.c"
    break;

  case 40:
#line 183 "src/compiler.y"
                                             {(yyval.nPtr) = opr(ARRAY_ASSIGN,3,id((yyvsp[-6].str)),(yyvsp[-4].nPtr),(yyvsp[-1].nPtr));}
#line 1834 "bin/y.tab.c"
    break;

  case 41:
#line 184 "src/compiler.y"
                               {(yyval.nPtr) = opr('=', 2, id((yyvsp[-3].str)), (yyvsp[-1].nPtr));}
#line 1840 "bin/y.tab.c"
    break;

  case 42:
#line 186 "src/compiler.y"
                         { /*printf("trying to print\n");*/ (yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1846 "bin/y.tab.c"
    break;

  case 43:
#line 187 "src/compiler.y"
                                   { /*printf("trying to print string\n");*/(yyval.nPtr) = opr(PRINTS,1,(yyvsp[-2].str)); }
#line 1852 "bin/y.tab.c"
    break;

  case 44:
#line 188 "src/compiler.y"
                                                                                   { /*printf("ifelse il keri\n") ;*/ (yyval.nPtr) = opr(IF,3,(yyvsp[-11].nPtr),(yyvsp[-7].nPtr),(yyvsp[-3].nPtr));}
#line 1858 "bin/y.tab.c"
    break;

  case 45:
#line 189 "src/compiler.y"
                                                           {   (yyval.nPtr) = opr(IFL,2,(yyvsp[-7].nPtr),(yyvsp[-3].nPtr));}
#line 1864 "bin/y.tab.c"
    break;

  case 46:
#line 190 "src/compiler.y"
                                                              { /*printf("while il keri \n");*/ (yyval.nPtr) = opr(WHILE,2,(yyvsp[-7].nPtr),(yyvsp[-3].nPtr));}
#line 1870 "bin/y.tab.c"
    break;

  case 47:
#line 191 "src/compiler.y"
                      {(yyval.nPtr)=(yyvsp[-1].nPtr);}
#line 1876 "bin/y.tab.c"
    break;

  case 48:
#line 192 "src/compiler.y"
                   {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1882 "bin/y.tab.c"
    break;

  case 49:
#line 195 "src/compiler.y"
               { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 1888 "bin/y.tab.c"
    break;

  case 50:
#line 196 "src/compiler.y"
                  {(yyval.nPtr) = id((yyvsp[0].str));}
#line 1894 "bin/y.tab.c"
    break;

  case 51:
#line 197 "src/compiler.y"
                                {(yyval.nPtr) = opr(INDEX,2,id((yyvsp[-3].str)),(yyvsp[-1].nPtr));}
#line 1900 "bin/y.tab.c"
    break;

  case 52:
#line 198 "src/compiler.y"
                                { (yyval.nPtr) = opr('-', 2, con(0), (yyvsp[0].nPtr)); }
#line 1906 "bin/y.tab.c"
    break;

  case 53:
#line 199 "src/compiler.y"
                        { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1912 "bin/y.tab.c"
    break;

  case 54:
#line 200 "src/compiler.y"
                        { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1918 "bin/y.tab.c"
    break;

  case 55:
#line 201 "src/compiler.y"
                        { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1924 "bin/y.tab.c"
    break;

  case 56:
#line 202 "src/compiler.y"
                        { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1930 "bin/y.tab.c"
    break;

  case 57:
#line 203 "src/compiler.y"
                                        {  (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1936 "bin/y.tab.c"
    break;

  case 58:
#line 204 "src/compiler.y"
                                {  (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1942 "bin/y.tab.c"
    break;

  case 59:
#line 205 "src/compiler.y"
                                { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1948 "bin/y.tab.c"
    break;

  case 60:
#line 206 "src/compiler.y"
                       {(yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1954 "bin/y.tab.c"
    break;

  case 61:
#line 207 "src/compiler.y"
                                             { (yyval.nPtr) = opr(GREATERTHANOREQUAL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1960 "bin/y.tab.c"
    break;

  case 62:
#line 208 "src/compiler.y"
                                                {(yyval.nPtr) = opr(LESSTHANOREQUAL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1966 "bin/y.tab.c"
    break;

  case 63:
#line 209 "src/compiler.y"
                                                        { (yyval.nPtr) = opr(NOTEQUAL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1972 "bin/y.tab.c"
    break;

  case 64:
#line 210 "src/compiler.y"
                                        { (yyval.nPtr) = opr(EQUALEQUAL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1978 "bin/y.tab.c"
    break;

  case 65:
#line 211 "src/compiler.y"
                                        { (yyval.nPtr) = opr(LOGICAL_NOT, 1, (yyvsp[0].nPtr));	}
#line 1984 "bin/y.tab.c"
    break;

  case 66:
#line 212 "src/compiler.y"
                                        {(yyval.nPtr) = opr(LOGICAL_AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));	}
#line 1990 "bin/y.tab.c"
    break;

  case 67:
#line 213 "src/compiler.y"
                                        { (yyval.nPtr) = opr(LOGICAL_OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));	}
#line 1996 "bin/y.tab.c"
    break;

  case 68:
#line 214 "src/compiler.y"
                   {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 2002 "bin/y.tab.c"
    break;


#line 2006 "bin/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 216 "src/compiler.y"

node *con(int value) {
	node *p;
	if ((p = malloc(sizeof(node))) == NULL)
		yyerror("out of memory");
	p->type = typeCon; /*type is set*/
	p->con.value = value; /*type is con and copied value to it*/
	return p;
}
node *id(char* var) {
	node *p;
	if ((p = malloc(sizeof(node))) == NULL)
		yyerror("out of memory");
	p->type = typeId; /*type is set*/
	p->id.id = var; /*type is con and copied value to it*/
	//printf("id\n");
	return p;
}
node *opr(int oper, int nops, ...) {
	//printf("opr\n");
	va_list ap;
	node *p;
	int i;
	/* allocate node */
	if ((p = malloc(sizeof(node))) == NULL)
		yyerror("out of memory");
	if ((p->opr.op = malloc(nops * sizeof(node))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, node*);
	va_end(ap);
	//printf("opr\n");
	return p;
}
node *fNode(node* list, retTypeEnum ret,node * expr,argListType *argList, node * decl)
{
	node *p;
	if ((p = malloc(sizeof(node))) == NULL)
		yyerror("out of memory");
	
	int n = lengthOfArgList(argList);
	// if((p->fn.symTab = malloc(sizeof(symTab)*SYM_L))==NULL)
	// 	yyerror("out of memory");
	/* copy information */
	
	p->type = typeFun;
	p->fn.return_type = ret;
	p->fn.fun_block = list;
	p->fn.ret_node = expr;
	p->fn.n_args = n;
	p->fn.arg_list = argList;
	p->fn.decl=decl;

	// argListType * ptr = argList;
	// int i =0;
	// while(ptr!=NULL)
	// {
	// 	p->fn.symTab[i].name=ptr->name;
	// 	if(ptr->type == Int)
	// 	{
	// 		p->fn.symTab[i].type == typeInt;
	// 	}
	// 	p->fn.symTab[i].declared = 1;
	// 	p->fn.symTab[i].allocated = 1;
	// 	i++;
	// 	ptr = ptr -> next;
	// }
	return p;
}
void freeNode(node *p) {
	int i;
	if (!p) return;
	if (p->type == typeOpr) {
		for (i = 0; i < p->opr.nops; i++)
			freeNode(p->opr.op[i]);
		free(p->opr.op);
 	}
 	free (p);
}
argListType * singlelineArg(varItemtype * l1,varItemtype *l2)
{
	if(!l1) return l2;
	if(!l2) return l1;
	varItemtype * curr = l1;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next = l2;
	return l1;
}
	/* end of grammar */
void yyerror(char *s) {
	 fprintf(stdout, "%s\n", s);
	 fprintf(stdout,"linenumber %d\n", yylineno);
	  fprintf(stdout,"token %s\n", yytext);
}


//int main(int argc, char* argv[]) {
int main(void){
		// if (argc > 1)
		// {
		// 	if (argv[1][1] == 'c')
		// 	{
		// 		fp = startcodegeneration(argv[2]);
		// 	}
			
		// }
		// else
		// {
		// 	fp = startcodegeneration("src/code.c");
		// }
		yyparse();
		return 0;
}
