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
    STRING = 258,                  /* STRING  */
    END = 259,                     /* END  */
    FALSE = 260,                   /* FALSE  */
    TO = 261,                      /* TO  */
    VAR = 262,                     /* VAR  */
    IDENTIFIER = 263,              /* IDENTIFIER  */
    CHR = 264,                     /* CHR  */
    POOL = 265,                    /* POOL  */
    IF = 266,                      /* IF  */
    REPEAT = 267,                  /* REPEAT  */
    READ = 268,                    /* READ  */
    ELSE = 269,                    /* ELSE  */
    UNTIL = 270,                   /* UNTIL  */
    SWAP = 271,                    /* SWAP  */
    FOR = 272,                     /* FOR  */
    THEN = 273,                    /* THEN  */
    DOTDOT = 274,                  /* DOTDOT  */
    OF = 275,                      /* OF  */
    NE = 276,                      /* NE  */
    MOD = 277,                     /* MOD  */
    GT = 278,                      /* GT  */
    CHARACTER = 279,               /* CHARACTER  */
    CASE = 280,                    /* CASE  */
    CHAR = 281,                    /* CHAR  */
    WHILE = 282,                   /* WHILE  */
    OUTPUT = 283,                  /* OUTPUT  */
    EQ = 284,                      /* EQ  */
    EXIT = 285,                    /* EXIT  */
    CONST = 286,                   /* CONST  */
    GTE = 287,                     /* GTE  */
    PRED = 288,                    /* PRED  */
    NOT = 289,                     /* NOT  */
    DO = 290,                      /* DO  */
    BEGINX = 291,                  /* BEGINX  */
    BOOLEAN = 292,                 /* BOOLEAN  */
    ORD = 293,                     /* ORD  */
    AND = 294,                     /* AND  */
    TRUE = 295,                    /* TRUE  */
    INTEGER_NUM = 296,             /* INTEGER_NUM  */
    INTEGER = 297,                 /* INTEGER  */
    EOFX = 298,                    /* EOFX  */
    EXP = 299,                     /* EXP  */
    LTE = 300,                     /* LTE  */
    LOOP = 301,                    /* LOOP  */
    SUCC = 302,                    /* SUCC  */
    OR = 303,                      /* OR  */
    LT = 304,                      /* LT  */
    OTHERWISE = 305,               /* OTHERWISE  */
    ASSIGNMENT = 306,              /* ASSIGNMENT  */
    TYPEX = 307,                   /* TYPEX  */
    PROGRAM = 308,                 /* PROGRAM  */
    DOWNTO = 309                   /* DOWNTO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define STRING 258
#define END 259
#define FALSE 260
#define TO 261
#define VAR 262
#define IDENTIFIER 263
#define CHR 264
#define POOL 265
#define IF 266
#define REPEAT 267
#define READ 268
#define ELSE 269
#define UNTIL 270
#define SWAP 271
#define FOR 272
#define THEN 273
#define DOTDOT 274
#define OF 275
#define NE 276
#define MOD 277
#define GT 278
#define CHARACTER 279
#define CASE 280
#define CHAR 281
#define WHILE 282
#define OUTPUT 283
#define EQ 284
#define EXIT 285
#define CONST 286
#define GTE 287
#define PRED 288
#define NOT 289
#define DO 290
#define BEGINX 291
#define BOOLEAN 292
#define ORD 293
#define AND 294
#define TRUE 295
#define INTEGER_NUM 296
#define INTEGER 297
#define EOFX 298
#define EXP 299
#define LTE 300
#define LOOP 301
#define SUCC 302
#define OR 303
#define LT 304
#define OTHERWISE 305
#define ASSIGNMENT 306
#define TYPEX 307
#define PROGRAM 308
#define DOWNTO 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "code.y"

   TOKEN_INFO info;
   DLIST dlist;

#line 180 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
