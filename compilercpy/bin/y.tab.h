/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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


#line 160 "bin/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */
