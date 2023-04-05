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
    PRINT = 260,
    DECL = 261,
    ENDDECL = 262,
    INT = 263,
    DECLARE = 264,
    STMNT = 265,
    DECLARE_List = 266,
    PRINT_List = 267,
    Begin = 268,
    End = 269,
    MAIN = 270,
    INDEX = 271,
    IF = 272,
    THEN = 273,
    ELSE = 274,
    ENDIF = 275,
    DO = 276,
    WHILE = 277,
    ENDWHILE = 278,
    EQUALEQUAL = 279,
    LESSTHANOREQUAL = 280,
    GREATERTHANOREQUAL = 281,
    NOTEQUAL = 282,
    LOGICAL_AND = 283,
    LOGICAL_NOT = 284,
    LOGICAL_OR = 285,
    READ = 286,
    WRITE = 287,
    ARRAY_DECLARE = 288,
    ARRAY_ASSIGN = 289
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define VARIABLE 259
#define PRINT 260
#define DECL 261
#define ENDDECL 262
#define INT 263
#define DECLARE 264
#define STMNT 265
#define DECLARE_List 266
#define PRINT_List 267
#define Begin 268
#define End 269
#define MAIN 270
#define INDEX 271
#define IF 272
#define THEN 273
#define ELSE 274
#define ENDIF 275
#define DO 276
#define WHILE 277
#define ENDWHILE 278
#define EQUALEQUAL 279
#define LESSTHANOREQUAL 280
#define GREATERTHANOREQUAL 281
#define NOTEQUAL 282
#define LOGICAL_AND 283
#define LOGICAL_NOT 284
#define LOGICAL_OR 285
#define READ 286
#define WRITE 287
#define ARRAY_DECLARE 288
#define ARRAY_ASSIGN 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "src/compiler.y"

	int iValue;  /* integer value */
	char* str;
	node *nPtr; /* node pointer */

#line 131 "bin/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */
