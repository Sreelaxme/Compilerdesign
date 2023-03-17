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
    BEG = 258,
    END = 259,
    T_INT = 260,
    T_BOOL = 261,
    READ = 262,
    WRITE = 263,
    DECL = 264,
    ENDDECL = 265,
    VAR = 266,
    NUM = 267,
    IF = 268,
    THEN = 269,
    ELSE = 270,
    ENDIF = 271,
    LOGICAL_AND = 272,
    LOGICAL_NOT = 273,
    LOGICAL_OR = 274,
    EQUALEQUAL = 275,
    LESSTHANOREQUAL = 276,
    GREATERTHANOREQUAL = 277,
    NOTEQUAL = 278,
    WHILE = 279,
    DO = 280,
    ENDWHILE = 281,
    FOR = 282,
    T = 283,
    F = 284,
    MAIN = 285,
    RETURN = 286
  };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define T_INT 260
#define T_BOOL 261
#define READ 262
#define WRITE 263
#define DECL 264
#define ENDDECL 265
#define VAR 266
#define NUM 267
#define IF 268
#define THEN 269
#define ELSE 270
#define ENDIF 271
#define LOGICAL_AND 272
#define LOGICAL_NOT 273
#define LOGICAL_OR 274
#define EQUALEQUAL 275
#define LESSTHANOREQUAL 276
#define GREATERTHANOREQUAL 277
#define NOTEQUAL 278
#define WHILE 279
#define DO 280
#define ENDWHILE 281
#define FOR 282
#define T 283
#define F 284
#define MAIN 285
#define RETURN 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */
