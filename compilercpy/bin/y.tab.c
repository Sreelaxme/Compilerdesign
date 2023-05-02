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
int declareFn(char* name, node* ptr);
node* getFn(char* str);
int updateFunStat(char* str,node* ptr);
void printSyntaxTree(node* p);
void printSymTab();
struct sym symTab[100];
int update_arr(char * str, int ar_index, int value);
int declare_array(char* name,int size);
node* getFn(char* str);
node *fNode(node* list, retTypeEnum ret,node * expr,argListType *argList);
argListType* singletonArg(retTypeEnum ret, char* var);
argListType *listArg(retTypeEnum ret, char* var, argListType *old);
int lengthOfArgList(argListType *list);
nodeItemtype* singletonPara(node * Node);
nodeItemtype *listPara(node * Node, nodeItemtype *list);
int lengthOfParaList(nodeItemtype *list);
varItemtype* singletonVar(char* name, int length);
varItemtype *listVar(varItemtype *item , varItemtype * list );
int lengthOfVarList(varItemtype *list);

#line 102 "bin/y.tab.c"

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
    INT = 260,
    VOID = 261,
    BOOL = 262,
    DECL = 263,
    ENDDECL = 264,
    DECLARE_L = 265,
    DECLARE = 266,
    DECLARE_G = 267,
    STMNT = 268,
    DECLARE_List = 269,
    DECLARE_Fn = 270,
    CALL = 271,
    Main = 272,
    PRINT = 273,
    PRINT_List = 274,
    Begin = 275,
    End = 276,
    MAIN = 277,
    INDEX = 278,
    IF = 279,
    THEN = 280,
    ELSE = 281,
    ENDIF = 282,
    IFL = 283,
    DO = 284,
    WHILE = 285,
    ENDWHILE = 286,
    EQUALEQUAL = 287,
    LESSTHANOREQUAL = 288,
    GREATERTHANOREQUAL = 289,
    NOTEQUAL = 290,
    LOGICAL_AND = 291,
    LOGICAL_NOT = 292,
    LOGICAL_OR = 293,
    READ = 294,
    WRITE = 295,
    ARRAY_DECLARE = 296,
    ARRAY_ASSIGN = 297,
    RETURN = 298
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define VARIABLE 259
#define INT 260
#define VOID 261
#define BOOL 262
#define DECL 263
#define ENDDECL 264
#define DECLARE_L 265
#define DECLARE 266
#define DECLARE_G 267
#define STMNT 268
#define DECLARE_List 269
#define DECLARE_Fn 270
#define CALL 271
#define Main 272
#define PRINT 273
#define PRINT_List 274
#define Begin 275
#define End 276
#define MAIN 277
#define INDEX 278
#define IF 279
#define THEN 280
#define ELSE 281
#define ENDIF 282
#define IFL 283
#define DO 284
#define WHILE 285
#define ENDWHILE 286
#define EQUALEQUAL 287
#define LESSTHANOREQUAL 288
#define GREATERTHANOREQUAL 289
#define NOTEQUAL 290
#define LOGICAL_AND 291
#define LOGICAL_NOT 292
#define LOGICAL_OR 293
#define READ 294
#define WRITE 295
#define ARRAY_DECLARE 296
#define ARRAY_ASSIGN 297
#define RETURN 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "src/compiler.y"

	int iValue;  /* integer value */
	char* str;
	argListType *argType;
	node *nPtr; /* node pointer */
	argListType *argList;
	nodeItemtype *paramList;
	varItemtype *varList;


#line 251 "bin/y.tab.c"

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
#define YYLAST   570

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      55,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    50,     2,     2,
      51,    52,    48,    46,    57,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
      44,    60,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    80,    81,    87,    88,    91,    92,    93,
      96,   100,   101,   105,   108,   112,   113,   115,   117,   118,
     119,   123,   124,   125,   129,   130,   131,   135,   136,   139,
     140,   142,   143,   147,   151,   153,   154,   155,   156,   158,
     159,   160,   161,   162,   163,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "VARIABLE", "INT", "VOID",
  "BOOL", "DECL", "ENDDECL", "DECLARE_L", "DECLARE", "DECLARE_G", "STMNT",
  "DECLARE_List", "DECLARE_Fn", "CALL", "Main", "PRINT", "PRINT_List",
  "Begin", "End", "MAIN", "INDEX", "IF", "THEN", "ELSE", "ENDIF", "IFL",
  "DO", "WHILE", "ENDWHILE", "EQUALEQUAL", "LESSTHANOREQUAL",
  "GREATERTHANOREQUAL", "NOTEQUAL", "LOGICAL_AND", "LOGICAL_NOT",
  "LOGICAL_OR", "READ", "WRITE", "ARRAY_DECLARE", "ARRAY_ASSIGN", "RETURN",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'{'",
  "'}'", "'\\n'", "';'", "','", "'['", "']'", "'='", "$accept", "program",
  "return_type", "main", "endl", "func_call", "Fdef", "varList", "var",
  "arg_list", "param_list", "pList", "stmt_list", "decl_stmt_g",
  "decl_stmt_l", "stmt", "expr", YY_NULLPTR
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
     295,   296,   297,   298,    60,    62,    43,    45,    42,    47,
      37,    40,    41,   123,   125,    10,    59,    44,    91,    93,
      61
};
# endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-47)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -72,    22,   -72,   248,   -49,    40,   -72,   -72,   -72,   -72,
      53,   -72,   -72,   -72,   -72,    14,    28,     4,    31,    44,
      44,    44,    44,   -72,    -4,    14,    14,   -72,    50,   339,
      57,    -1,   129,    14,   -72,   480,   -72,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,   -72,    59,    84,    56,   -72,   139,    94,   301,   -72,
     236,   236,   236,   236,   -72,   -72,   520,   520,    70,    70,
      76,    76,    39,   -72,    68,   147,   -72,    -1,    96,   -72,
     -72,   -72,    95,    -5,   -72,   129,    86,   -13,   -72,   -72,
     -72,   -72,   -72,   -12,   172,   -72,    99,   272,   -72,    14,
      14,    14,   102,   -72,   -72,   -72,   379,   183,   -72,    14,
      14,    15,   103,   359,   501,   461,   -72,   -16,    37,   -72,
     -72,   320,   398,    -1,   -72,    14,    21,   -72,   -72,   -72,
      55,   101,   -72,   107,   -72,   -72,   211,    73,    14,    14,
     -72,   144,   -72,   -72,   417,   436,    35,   -72,    29,   -72,
     -72,   -72,    46,   110,    48,   -72,   111,   -72,   -72,   243,
     -72,    77,   -72,   -72,    -6,    44,   113,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    11,     1,     0,     0,     7,     8,     9,    11,    12,
       0,    11,    11,    11,    11,    24,     0,     0,     0,     4,
       5,     3,     6,    45,    46,     0,     0,    63,     0,    25,
       0,    15,    21,     0,    60,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    11,    20,     0,    16,     7,     0,     0,     0,    55,
      59,    57,    56,    58,    61,    62,    53,    54,    48,    49,
      50,    51,    52,    26,     0,     0,    11,    15,    22,    11,
      47,    11,     0,     0,    17,    21,     0,     0,    19,    33,
      23,    11,    11,     0,     0,    11,     0,    43,    11,     0,
       0,     0,    63,    11,    37,    11,     0,     0,    31,     0,
       0,     0,     0,    27,    11,     0,    44,     0,     0,    35,
      11,     0,     0,    15,    39,     0,     0,    11,    11,    30,
       0,    47,    38,     0,    28,    11,     0,     0,     0,     0,
      11,     0,    11,    10,     0,     0,     0,    11,     0,    11,
      36,    34,     0,     0,     0,    11,     0,    42,    11,     0,
      41,     0,    11,    11,     0,    14,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   169,   -72,     2,    -3,   -72,   -71,   -72,    92,
     128,    54,   -70,   -72,   -72,   -72,   -14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    56,    11,     3,    27,    13,    53,    54,    57,
      28,   112,   103,    14,   104,   105,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    29,    15,    52,    89,   128,    84,    92,    95,    31,
      17,    34,    35,    19,    20,    21,    22,    23,    24,    58,
     123,   166,     2,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    29,   120,    96,     9,
      23,    97,     9,     9,   151,    98,   135,    15,   129,     9,
       9,    25,   133,    74,    33,    99,   -18,    18,   -29,     9,
     153,   100,    16,   -29,   -29,    26,   142,   101,   -29,   158,
       9,   147,   155,   156,    25,    41,     9,    42,    83,    30,
     -29,    86,    32,    87,     9,   113,   114,   115,    26,   162,
       9,   102,     9,    93,    94,   121,   122,   107,   138,     9,
     111,     9,    36,     9,   102,   117,    41,   118,    42,    51,
       9,   113,    41,    77,    42,   102,   126,    75,    47,    48,
      49,    81,   130,     9,   144,   145,    49,   143,     9,   136,
     137,   163,     9,   102,    55,     6,     7,   141,   102,    91,
      76,     9,   146,    78,   148,    96,    79,    23,    97,   152,
      82,   154,    98,    85,    88,   108,   102,   159,   116,   124,
     161,   139,    99,   140,   164,   165,   157,   160,   100,   167,
     -32,   -32,    10,    96,   101,    23,    97,    90,    73,   134,
      98,    25,     0,     0,    96,     0,    23,    97,     0,     0,
      99,    98,     0,   -32,     0,    26,   100,     0,     0,     9,
       0,    99,   101,     0,     0,     0,     0,   100,     0,    25,
       0,     0,    96,   101,    23,    97,     0,     0,     0,    98,
      25,     0,     0,    26,     0,     0,   -32,     9,     0,    99,
       0,     0,     0,     0,    26,   100,     0,     0,     9,     0,
       0,   101,   -32,     0,    96,     0,    23,    97,    25,     0,
       0,    98,     4,     5,     6,     7,     8,     0,     0,     0,
       0,    99,    26,     0,     0,     0,     9,   100,     0,     0,
     -32,     0,    41,   101,    42,     0,     0,     0,     0,     0,
      25,     0,    45,    46,    47,    48,    49,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     9,     0,
       0,     0,     0,     9,   -46,   -46,   -46,   -46,   -46,     0,
     -46,     0,     0,     0,     0,     0,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,    15,     0,     0,     0,     0,   -46,     0,
     109,     0,   110,    37,    38,    39,    40,    41,     0,    42,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
      48,    49,    37,    38,    39,    40,    41,     0,    42,     0,
      80,     0,     0,     0,    43,    44,    45,    46,    47,    48,
      49,    37,    38,    39,    40,    41,     0,    42,     0,   131,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    49,
       0,    37,    38,    39,    40,    41,    50,    42,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    49,
       0,    37,    38,    39,    40,    41,   125,    42,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    49,
      37,    38,    39,    40,    41,   119,    42,     0,     0,     0,
       0,     0,    43,    44,    45,    46,    47,    48,    49,    37,
      38,    39,    40,    41,   132,    42,     0,     0,     0,     0,
       0,    43,    44,    45,    46,    47,    48,    49,    37,    38,
      39,    40,    41,   149,    42,     0,     0,     0,     0,     0,
      43,    44,    45,    46,    47,    48,    49,     0,     0,     0,
     127,     0,   150,    37,    38,    39,    40,    41,     0,    42,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
      48,    49,    37,    38,    39,    40,    41,     0,    42,     0,
       0,     0,     0,     0,    43,    44,    45,    46,    47,    48,
      49,     0,    59,    37,    38,    39,    40,    41,     0,    42,
       0,     0,     0,     0,     0,    43,    44,    45,    46,    47,
      48,    49,    37,    38,    39,    40,    41,     0,    42,     0,
       0,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49
};

static const yytype_int16 yycheck[] =
{
       3,    15,    51,     4,     9,    21,    77,    20,    20,     5,
       8,    25,    26,    11,    12,    13,    14,     3,     4,    33,
       5,    27,     0,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,   107,     1,    55,
       3,     4,    55,    55,     9,     8,    25,    51,   118,    55,
      55,    37,   123,    51,    58,    18,    57,     4,    21,    55,
      31,    24,    22,    26,    27,    51,   136,    30,    31,    21,
      55,   141,    26,    27,    37,    36,    55,    38,    76,    51,
      43,    79,    51,    81,    55,    99,   100,   101,    51,   159,
      55,    94,    55,    91,    92,   109,   110,    95,    43,    55,
      98,    55,    52,    55,   107,   103,    36,   105,    38,    52,
      55,   125,    36,    57,    38,   118,   114,    58,    48,    49,
      50,    53,   120,    55,   138,   139,    50,    54,    55,   127,
     128,    54,    55,   136,     5,     6,     7,   135,   141,    53,
      56,    55,   140,     4,   142,     1,    52,     3,     4,   147,
       3,   149,     8,    57,    59,    56,   159,   155,    56,    56,
     158,    60,    18,    56,   162,   163,    56,    56,    24,    56,
      26,    27,     3,     1,    30,     3,     4,    85,    50,   125,
       8,    37,    -1,    -1,     1,    -1,     3,     4,    -1,    -1,
      18,     8,    -1,    21,    -1,    51,    24,    -1,    -1,    55,
      -1,    18,    30,    -1,    -1,    -1,    -1,    24,    -1,    37,
      -1,    -1,     1,    30,     3,     4,    -1,    -1,    -1,     8,
      37,    -1,    -1,    51,    -1,    -1,    43,    55,    -1,    18,
      -1,    -1,    -1,    -1,    51,    24,    -1,    -1,    55,    -1,
      -1,    30,    31,    -1,     1,    -1,     3,     4,    37,    -1,
      -1,     8,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    18,    51,    -1,    -1,    -1,    55,    24,    -1,    -1,
      27,    -1,    36,    30,    38,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    55,    32,    33,    34,    35,    36,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,
      58,    -1,    60,    32,    33,    34,    35,    36,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    32,    33,    34,    35,    36,    -1,    38,    -1,
      59,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    32,    33,    34,    35,    36,    -1,    38,    -1,    59,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    32,    33,    34,    35,    36,    57,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    32,    33,    34,    35,    36,    57,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      32,    33,    34,    35,    36,    56,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    32,
      33,    34,    35,    36,    56,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    32,    33,
      34,    35,    36,    56,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      29,    -1,    56,    32,    33,    34,    35,    36,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    32,    33,    34,    35,    36,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    32,    33,    34,    35,    36,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    32,    33,    34,    35,    36,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    62,     0,    65,     4,     5,     6,     7,     8,    55,
      63,    64,    66,    67,    74,    51,    22,    65,     4,    65,
      65,    65,    65,     3,     4,    37,    51,    66,    71,    77,
      51,     5,    51,    58,    77,    77,    52,    32,    33,    34,
      35,    36,    38,    44,    45,    46,    47,    48,    49,    50,
      57,    52,     4,    68,    69,     5,    63,    70,    77,    52,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    71,    65,    58,    56,    57,     4,    52,
      59,    53,     3,    65,    68,    57,    65,    65,    59,     9,
      70,    53,    20,    65,    65,    20,     1,     4,     8,    18,
      24,    30,    66,    73,    75,    76,    77,    65,    56,    58,
      60,    65,    72,    77,    77,    77,    56,    65,    65,    56,
      73,    77,    77,     5,    56,    57,    65,    29,    21,    73,
      65,    59,    56,    68,    72,    25,    65,    65,    43,    60,
      56,    65,    73,    54,    77,    77,    65,    73,    65,    56,
      56,     9,    65,    31,    65,    26,    27,    56,    21,    65,
      56,    65,    73,    54,    65,    65,    27,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    62,    63,    63,    63,
      64,    65,    65,    66,    67,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    72,    72,    73,
      73,    73,    73,    74,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     4,     4,     4,     1,     1,     1,
      14,     0,     2,     4,    20,     0,     1,     3,     0,     4,
       1,     0,     2,     4,     0,     1,     3,     1,     3,     2,
       3,     2,     0,     7,     7,     2,     7,     1,     4,     3,
      13,     9,     8,     1,     2,     1,     1,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     1
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
#line 80 "src/compiler.y"
                                {/*printf("prgrm 1 \n"*);*/ printSyntaxTree((yyvsp[-1].nPtr)); ex((yyvsp[-1].nPtr));}
#line 1615 "bin/y.tab.c"
    break;

  case 4:
#line 81 "src/compiler.y"
                                { /*printf("main\n");*/
							printSyntaxTree((yyvsp[-1].nPtr));
							printf("\n\n\nPROGRAM OUTPUT \n"); 
									ex((yyvsp[-1].nPtr));
									printf("\nSymbol Table\n");
									printSymTab();}
#line 1626 "bin/y.tab.c"
    break;

  case 5:
#line 87 "src/compiler.y"
                                      {printSyntaxTree((yyvsp[-1].nPtr));ex((yyvsp[-1].nPtr));}
#line 1632 "bin/y.tab.c"
    break;

  case 6:
#line 88 "src/compiler.y"
                                        {printf("\n\nSYNTAX TREE\n"); printSyntaxTree((yyvsp[-1].nPtr)); ex((yyvsp[-1].nPtr));printSymTab();}
#line 1638 "bin/y.tab.c"
    break;

  case 7:
#line 91 "src/compiler.y"
            {(yyval.iValue)=Int;}
#line 1644 "bin/y.tab.c"
    break;

  case 8:
#line 92 "src/compiler.y"
              {(yyval.iValue) = Void;}
#line 1650 "bin/y.tab.c"
    break;

  case 9:
#line 93 "src/compiler.y"
               {(yyval.iValue) = Bool;}
#line 1656 "bin/y.tab.c"
    break;

  case 10:
#line 98 "src/compiler.y"
        { (yyval.nPtr) = opr(Main,1,(yyvsp[-4].nPtr)) ;}
#line 1662 "bin/y.tab.c"
    break;

  case 13:
#line 105 "src/compiler.y"
                                      { (yyval.nPtr)=opr(CALL,2,(yyvsp[-3].str),(yyvsp[-1].paramList));}
#line 1668 "bin/y.tab.c"
    break;

  case 14:
#line 109 "src/compiler.y"
        {  (yyval.nPtr) = opr(DECLARE_Fn,2,(yyvsp[-18].str),fNode((yyvsp[-9].nPtr),(yyvsp[-19].iValue),(yyvsp[-6].nPtr),(yyvsp[-16].argList)));}
#line 1674 "bin/y.tab.c"
    break;

  case 16:
#line 113 "src/compiler.y"
              {(yyval.varList) = (yyvsp[0].varList);}
#line 1680 "bin/y.tab.c"
    break;

  case 17:
#line 115 "src/compiler.y"
                          {(yyval.varList) = listVar((yyvsp[-2].varList),(yyvsp[0].varList));}
#line 1686 "bin/y.tab.c"
    break;

  case 19:
#line 118 "src/compiler.y"
                                  {(yyval.varList) = singletonVar((yyvsp[-3].str),(yyvsp[-1].iValue));}
#line 1692 "bin/y.tab.c"
    break;

  case 20:
#line 119 "src/compiler.y"
                   {/*printf("1 in varList\n");*/(yyval.varList) = singletonVar((yyvsp[0].str),0);}
#line 1698 "bin/y.tab.c"
    break;

  case 21:
#line 123 "src/compiler.y"
         {(yyval.argList) =NULL;}
#line 1704 "bin/y.tab.c"
    break;

  case 22:
#line 124 "src/compiler.y"
                               {(yyval.argList) = singletonArg((yyvsp[-1].iValue),(yyvsp[0].str));}
#line 1710 "bin/y.tab.c"
    break;

  case 23:
#line 125 "src/compiler.y"
                                            { (yyval.argList) = listArg((yyvsp[-3].iValue),(yyvsp[-2].str),(yyvsp[0].argList));}
#line 1716 "bin/y.tab.c"
    break;

  case 24:
#line 129 "src/compiler.y"
         {(yyval.paramList) = NULL;}
#line 1722 "bin/y.tab.c"
    break;

  case 25:
#line 130 "src/compiler.y"
              {(yyval.paramList) = singletonPara((yyvsp[0].nPtr));}
#line 1728 "bin/y.tab.c"
    break;

  case 26:
#line 131 "src/compiler.y"
                              {(yyval.paramList) = listPara((yyvsp[-2].nPtr),(yyvsp[0].paramList));}
#line 1734 "bin/y.tab.c"
    break;

  case 27:
#line 135 "src/compiler.y"
             {(yyval.nPtr) = opr(PRINT, 1, (yyvsp[0].nPtr));}
#line 1740 "bin/y.tab.c"
    break;

  case 28:
#line 136 "src/compiler.y"
                         {(yyval.nPtr) = opr(PRINT_List, 2, opr(PRINT,1,(yyvsp[-2].nPtr)), (yyvsp[0].nPtr));}
#line 1746 "bin/y.tab.c"
    break;

  case 29:
#line 139 "src/compiler.y"
                          {(yyval.nPtr) = (yyvsp[-1].nPtr) ;}
#line 1752 "bin/y.tab.c"
    break;

  case 30:
#line 140 "src/compiler.y"
                                           {(yyval.nPtr) = opr(STMNT , 2, (yyvsp[-2].nPtr) ,(yyvsp[0].nPtr)) ;}
#line 1758 "bin/y.tab.c"
    break;

  case 31:
#line 142 "src/compiler.y"
                                                {printf("error\n") ; (yyval.nPtr) = con(0)  ;}
#line 1764 "bin/y.tab.c"
    break;

  case 33:
#line 147 "src/compiler.y"
                                                { (yyval.nPtr)=opr(DECLARE_G,1,(yyvsp[-3].varList));}
#line 1770 "bin/y.tab.c"
    break;

  case 34:
#line 151 "src/compiler.y"
                                                {(yyval.nPtr) = opr(DECLARE_L,1,(yyvsp[-3].varList));}
#line 1776 "bin/y.tab.c"
    break;

  case 35:
#line 153 "src/compiler.y"
                 { (yyval.nPtr)=(yyvsp[-1].nPtr);}
#line 1782 "bin/y.tab.c"
    break;

  case 36:
#line 154 "src/compiler.y"
                                             {(yyval.nPtr) = opr(ARRAY_ASSIGN,3,id((yyvsp[-6].str)),(yyvsp[-4].nPtr),(yyvsp[-1].nPtr));}
#line 1788 "bin/y.tab.c"
    break;

  case 37:
#line 155 "src/compiler.y"
                      {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1794 "bin/y.tab.c"
    break;

  case 38:
#line 156 "src/compiler.y"
                               {/*printf("variable assignment\n");*/(yyval.nPtr) = opr('=', 2, id((yyvsp[-3].str)), (yyvsp[-1].nPtr));}
#line 1800 "bin/y.tab.c"
    break;

  case 39:
#line 158 "src/compiler.y"
                         { /*printf("trying to print\n");*/ (yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1806 "bin/y.tab.c"
    break;

  case 40:
#line 159 "src/compiler.y"
                                                                                   { /*printf("ifelse il keri\n") ;*/ (yyval.nPtr) = opr(IF,3,(yyvsp[-11].nPtr),(yyvsp[-7].nPtr),(yyvsp[-3].nPtr));}
#line 1812 "bin/y.tab.c"
    break;

  case 41:
#line 160 "src/compiler.y"
                                                           {  (yyval.nPtr) = opr(IFL,2,(yyvsp[-7].nPtr),(yyvsp[-3].nPtr));}
#line 1818 "bin/y.tab.c"
    break;

  case 42:
#line 161 "src/compiler.y"
                                                         { /*printf("while il keri \n");*/ (yyval.nPtr) = opr(WHILE,2,(yyvsp[-6].nPtr),(yyvsp[-3].nPtr));}
#line 1824 "bin/y.tab.c"
    break;

  case 43:
#line 162 "src/compiler.y"
                  {/*printf("evdeya\n");*/(yyval.nPtr)=(yyvsp[0].str);}
#line 1830 "bin/y.tab.c"
    break;

  case 44:
#line 163 "src/compiler.y"
                      {(yyval.nPtr)=(yyvsp[-1].nPtr);}
#line 1836 "bin/y.tab.c"
    break;

  case 45:
#line 166 "src/compiler.y"
               { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 1842 "bin/y.tab.c"
    break;

  case 46:
#line 167 "src/compiler.y"
                  {/*printf("thaan evde ano?\n");*/(yyval.nPtr) = id((yyvsp[0].str));}
#line 1848 "bin/y.tab.c"
    break;

  case 47:
#line 168 "src/compiler.y"
                                {(yyval.nPtr) = opr(INDEX,2,id((yyvsp[-3].str)),(yyvsp[-1].nPtr));}
#line 1854 "bin/y.tab.c"
    break;

  case 48:
#line 169 "src/compiler.y"
                        { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1860 "bin/y.tab.c"
    break;

  case 49:
#line 170 "src/compiler.y"
                        { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1866 "bin/y.tab.c"
    break;

  case 50:
#line 171 "src/compiler.y"
                        { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1872 "bin/y.tab.c"
    break;

  case 51:
#line 172 "src/compiler.y"
                        { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1878 "bin/y.tab.c"
    break;

  case 52:
#line 173 "src/compiler.y"
                                        {  (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1884 "bin/y.tab.c"
    break;

  case 53:
#line 174 "src/compiler.y"
                                {  (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1890 "bin/y.tab.c"
    break;

  case 54:
#line 175 "src/compiler.y"
                                { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1896 "bin/y.tab.c"
    break;

  case 55:
#line 176 "src/compiler.y"
                       { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1902 "bin/y.tab.c"
    break;

  case 56:
#line 177 "src/compiler.y"
                                             { (yyval.nPtr) = opr(GREATERTHANOREQUAL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1908 "bin/y.tab.c"
    break;

  case 57:
#line 178 "src/compiler.y"
                                                {(yyval.nPtr) = opr(LESSTHANOREQUAL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1914 "bin/y.tab.c"
    break;

  case 58:
#line 179 "src/compiler.y"
                                                        { (yyval.nPtr) = opr(NOTEQUAL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1920 "bin/y.tab.c"
    break;

  case 59:
#line 180 "src/compiler.y"
                                        { (yyval.nPtr) = opr(EQUALEQUAL, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1926 "bin/y.tab.c"
    break;

  case 60:
#line 181 "src/compiler.y"
                                        { (yyval.nPtr) = opr(LOGICAL_NOT, 1, (yyvsp[0].nPtr));	}
#line 1932 "bin/y.tab.c"
    break;

  case 61:
#line 182 "src/compiler.y"
                                        {(yyval.nPtr) = opr(LOGICAL_AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));	}
#line 1938 "bin/y.tab.c"
    break;

  case 62:
#line 183 "src/compiler.y"
                                        { (yyval.nPtr) = opr(LOGICAL_OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));	}
#line 1944 "bin/y.tab.c"
    break;

  case 63:
#line 184 "src/compiler.y"
                   {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1950 "bin/y.tab.c"
    break;


#line 1954 "bin/y.tab.c"

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
#line 186 "src/compiler.y"

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
node *fNode(node* list, retTypeEnum ret,node * expr,argListType *argList)
{
	node *p;
	if ((p = malloc(sizeof(node))) == NULL)
		yyerror("out of memory");
	
	int n = lengthOfArgList(argList);
	if((p->fn.symTab = malloc(sizeof(symTab)*SYM_L))==NULL)
		yyerror("out of memory");
	/* copy information */
	
	p->type = typeFun;
	p->fn.return_type = ret;
	p->fn.fun_block = list;
	p->fn.ret_node = expr;
	p->fn.n_args = n;

	argListType * ptr = argList;
	int i =0;
	while(ptr!=NULL)
	{
		p->fn.symTab[i].name=ptr->name;
		if(ptr->type == Int)
		{
			p->fn.symTab[i].type == typeInt;
		}
		p->fn.symTab[i].declared = 1;
		p->fn.symTab[i].allocated = 1;
		i++;
		ptr = ptr -> next;
	}
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
	/* end of grammar */
void yyerror(char *s) {
	 fprintf(stdout, "%s\n", s);
	 fprintf(stdout,"linenumber %d\n", yylineno);
	  fprintf(stdout,"token %s\n", yytext);
}
int main(void) {
 yyparse();
 return 0;
} 

