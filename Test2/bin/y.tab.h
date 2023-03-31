/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    IF = 268,
    THEN = 269,
    ELSE = 270,
    ENDIF = 271,
    DO = 272,
    WHILE = 273,
    ENDWHILE = 274,
    EQUALEQUAL = 275,
    LESSTHANOREQUAL = 276,
    GREATERTHANOREQUAL = 277,
    NOTEQUAL = 278,
    LOGICAL_AND = 279,
    LOGICAL_NOT = 280,
    LOGICAL_OR = 281,
    READ = 282,
    WRITE = 283
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
#define IF 268
#define THEN 269
#define ELSE 270
#define ENDIF 271
#define DO 272
#define WHILE 273
#define ENDWHILE 274
#define EQUALEQUAL 275
#define LESSTHANOREQUAL 276
#define GREATERTHANOREQUAL 277
#define NOTEQUAL 278
#define LOGICAL_AND 279
#define LOGICAL_NOT 280
#define LOGICAL_OR 281
#define READ 282
#define WRITE 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "src/compiler.y" /* yacc.c:1909  */

	int iValue;  /* integer value */
	char* str;
	node *nPtr; /* node pointer */

#line 116 "bin/y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */
