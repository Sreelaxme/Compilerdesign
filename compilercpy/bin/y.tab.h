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


#line 154 "bin/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */
