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
    BEGIN = 268,
    END = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    ENDIF = 273,
    DO = 274,
    WHILE = 275,
    ENDWHILE = 276,
    EQUALEQUAL = 277,
    LESSTHANOREQUAL = 278,
    GREATERTHANOREQUAL = 279,
    NOTEQUAL = 280,
    LOGICAL_AND = 281,
    LOGICAL_NOT = 282,
    LOGICAL_OR = 283,
    READ = 284,
    WRITE = 285
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
#define BEGIN 268
#define END 269
#define IF 270
#define THEN 271
#define ELSE 272
#define ENDIF 273
#define DO 274
#define WHILE 275
#define ENDWHILE 276
#define EQUALEQUAL 277
#define LESSTHANOREQUAL 278
#define GREATERTHANOREQUAL 279
#define NOTEQUAL 280
#define LOGICAL_AND 281
#define LOGICAL_NOT 282
#define LOGICAL_OR 283
#define READ 284
#define WRITE 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "src/compiler.y" /* yacc.c:1909  */

	int iValue;  /* integer value */
	char* str;
	node *nPtr; /* node pointer */

#line 120 "bin/y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */
