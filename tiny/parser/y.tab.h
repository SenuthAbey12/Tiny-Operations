/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    END = 258,                     /* END  */
    VAR = 259,                     /* VAR  */
    IDENTIFIER = 260,              /* IDENTIFIER  */
    IF = 261,                      /* IF  */
    READ = 262,                    /* READ  */
    ELSE = 263,                    /* ELSE  */
    THEN = 264,                    /* THEN  */
    NE = 265,                      /* NE  */
    MOD = 266,                     /* MOD  */
    WHILE = 267,                   /* WHILE  */
    OUTPUT = 268,                  /* OUTPUT  */
    NOT = 269,                     /* NOT  */
    DO = 270,                      /* DO  */
    BEGINX = 271,                  /* BEGINX  */
    BOOLEAN = 272,                 /* BOOLEAN  */
    INTEGER_NUM = 273,             /* INTEGER_NUM  */
    AND = 274,                     /* AND  */
    INTEGER = 275,                 /* INTEGER  */
    EXP = 276,                     /* EXP  */
    LTE = 277,                     /* LTE  */
    GE = 278,                      /* GE  */
    OR = 279,                      /* OR  */
    ASSIGNMENT = 280,              /* ASSIGNMENT  */
    PROGRAM = 281                  /* PROGRAM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define END 258
#define VAR 259
#define IDENTIFIER 260
#define IF 261
#define READ 262
#define ELSE 263
#define THEN 264
#define NE 265
#define MOD 266
#define WHILE 267
#define OUTPUT 268
#define NOT 269
#define DO 270
#define BEGINX 271
#define BOOLEAN 272
#define INTEGER_NUM 273
#define AND 274
#define INTEGER 275
#define EXP 276
#define LTE 277
#define GE 278
#define OR 279
#define ASSIGNMENT 280
#define PROGRAM 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "code.y"

   TOKEN_INFO info;
   DLIST dlist;

#line 124 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
