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
    DECL = 262,
    ENDDECL = 263,
    DECLARE = 264,
    STMNT = 265,
    DECLARE_List = 266,
    DECLARE_Fn = 267,
    CALL = 268,
    Main = 269,
    PRINT = 270,
    PRINT_List = 271,
    Begin = 272,
    End = 273,
    MAIN = 274,
    INDEX = 275,
    IF = 276,
    THEN = 277,
    ELSE = 278,
    ENDIF = 279,
    DO = 280,
    WHILE = 281,
    ENDWHILE = 282,
    EQUALEQUAL = 283,
    LESSTHANOREQUAL = 284,
    GREATERTHANOREQUAL = 285,
    NOTEQUAL = 286,
    LOGICAL_AND = 287,
    LOGICAL_NOT = 288,
    LOGICAL_OR = 289,
    READ = 290,
    WRITE = 291,
    ARRAY_DECLARE = 292,
    ARRAY_ASSIGN = 293
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define VARIABLE 259
#define INT 260
#define VOID 261
#define DECL 262
#define ENDDECL 263
#define DECLARE 264
#define STMNT 265
#define DECLARE_List 266
#define DECLARE_Fn 267
#define CALL 268
#define Main 269
#define PRINT 270
#define PRINT_List 271
#define Begin 272
#define End 273
#define MAIN 274
#define INDEX 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ENDIF 279
#define DO 280
#define WHILE 281
#define ENDWHILE 282
#define EQUALEQUAL 283
#define LESSTHANOREQUAL 284
#define GREATERTHANOREQUAL 285
#define NOTEQUAL 286
#define LOGICAL_AND 287
#define LOGICAL_NOT 288
#define LOGICAL_OR 289
#define READ 290
#define WRITE 291
#define ARRAY_DECLARE 292
#define ARRAY_ASSIGN 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "src/compiler.y"

	int iValue;  /* integer value */
	char* str;
	node *nPtr; /* node pointer */

#line 139 "bin/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */
