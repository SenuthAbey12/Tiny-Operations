/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "code.y"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <DLists.h>
#include <Tokenizer.h>
#include <Trees.h>

extern TREENODE *root;
int yylex(void);
void yyerror(const char *msg);
typedef struct {
    DNODE mynode;
    TREENODE *nodeptr;
} T_NODE;


#line 89 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 255 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_FALSE = 5,                      /* FALSE  */
  YYSYMBOL_TO = 6,                         /* TO  */
  YYSYMBOL_VAR = 7,                        /* VAR  */
  YYSYMBOL_IDENTIFIER = 8,                 /* IDENTIFIER  */
  YYSYMBOL_CHR = 9,                        /* CHR  */
  YYSYMBOL_POOL = 10,                      /* POOL  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_REPEAT = 12,                    /* REPEAT  */
  YYSYMBOL_READ = 13,                      /* READ  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_UNTIL = 15,                     /* UNTIL  */
  YYSYMBOL_SWAP = 16,                      /* SWAP  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_THEN = 18,                      /* THEN  */
  YYSYMBOL_DOTDOT = 19,                    /* DOTDOT  */
  YYSYMBOL_OF = 20,                        /* OF  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_MOD = 22,                       /* MOD  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_CHARACTER = 24,                 /* CHARACTER  */
  YYSYMBOL_CASE = 25,                      /* CASE  */
  YYSYMBOL_CHAR = 26,                      /* CHAR  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_OUTPUT = 28,                    /* OUTPUT  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_EXIT = 30,                      /* EXIT  */
  YYSYMBOL_CONST = 31,                     /* CONST  */
  YYSYMBOL_GTE = 32,                       /* GTE  */
  YYSYMBOL_PRED = 33,                      /* PRED  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_DO = 35,                        /* DO  */
  YYSYMBOL_BEGINX = 36,                    /* BEGINX  */
  YYSYMBOL_BOOLEAN = 37,                   /* BOOLEAN  */
  YYSYMBOL_ORD = 38,                       /* ORD  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_TRUE = 40,                      /* TRUE  */
  YYSYMBOL_INTEGER_NUM = 41,               /* INTEGER_NUM  */
  YYSYMBOL_INTEGER = 42,                   /* INTEGER  */
  YYSYMBOL_EOFX = 43,                      /* EOFX  */
  YYSYMBOL_EXP = 44,                       /* EXP  */
  YYSYMBOL_LTE = 45,                       /* LTE  */
  YYSYMBOL_LOOP = 46,                      /* LOOP  */
  YYSYMBOL_SUCC = 47,                      /* SUCC  */
  YYSYMBOL_OR = 48,                        /* OR  */
  YYSYMBOL_LT = 49,                        /* LT  */
  YYSYMBOL_OTHERWISE = 50,                 /* OTHERWISE  */
  YYSYMBOL_ASSIGNMENT = 51,                /* ASSIGNMENT  */
  YYSYMBOL_TYPEX = 52,                     /* TYPEX  */
  YYSYMBOL_PROGRAM = 53,                   /* PROGRAM  */
  YYSYMBOL_DOWNTO = 54,                    /* DOWNTO  */
  YYSYMBOL_55_ = 55,                       /* ':'  */
  YYSYMBOL_56_ = 56,                       /* '.'  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_58_ = 58,                       /* ','  */
  YYSYMBOL_59_ = 59,                       /* '('  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '-'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_Tiny = 66,                      /* Tiny  */
  YYSYMBOL_Consts = 67,                    /* Consts  */
  YYSYMBOL_Consts_1 = 68,                  /* Consts_1  */
  YYSYMBOL_ConstDef = 69,                  /* ConstDef  */
  YYSYMBOL_Types = 70,                     /* Types  */
  YYSYMBOL_Types_1 = 71,                   /* Types_1  */
  YYSYMBOL_TypeDef = 72,                   /* TypeDef  */
  YYSYMBOL_Dclns = 73,                     /* Dclns  */
  YYSYMBOL_Dclns_1 = 74,                   /* Dclns_1  */
  YYSYMBOL_Dcln = 75,                      /* Dcln  */
  YYSYMBOL_Dcln_1 = 76,                    /* Dcln_1  */
  YYSYMBOL_Type = 77,                      /* Type  */
  YYSYMBOL_Type_1 = 78,                    /* Type_1  */
  YYSYMBOL_Body = 79,                      /* Body  */
  YYSYMBOL_Body_1 = 80,                    /* Body_1  */
  YYSYMBOL_Statement = 81,                 /* Statement  */
  YYSYMBOL_Statement_1_1_1_1_1_1_1 = 82,   /* Statement_1_1_1_1_1_1_1  */
  YYSYMBOL_Statement_1_1_1_1_1_1 = 83,     /* Statement_1_1_1_1_1_1  */
  YYSYMBOL_Statement_1_1_1_1_1 = 84,       /* Statement_1_1_1_1_1  */
  YYSYMBOL_Statement_1_1_1_1 = 85,         /* Statement_1_1_1_1  */
  YYSYMBOL_Statement_1_1_1 = 86,           /* Statement_1_1_1  */
  YYSYMBOL_Statement_1_1 = 87,             /* Statement_1_1  */
  YYSYMBOL_Statement_1 = 88,               /* Statement_1  */
  YYSYMBOL_Caseclause = 89,                /* Caseclause  */
  YYSYMBOL_CaseValue = 90,                 /* CaseValue  */
  YYSYMBOL_Constant = 91,                  /* Constant  */
  YYSYMBOL_OutputItem = 92,                /* OutputItem  */
  YYSYMBOL_Expression = 93,                /* Expression  */
  YYSYMBOL_Simp_Expr = 94,                 /* Simp_Expr  */
  YYSYMBOL_Term = 95,                      /* Term  */
  YYSYMBOL_Factor = 96,                    /* Factor  */
  YYSYMBOL_Power = 97,                     /* Power  */
  YYSYMBOL_Primary = 98,                   /* Primary  */
  YYSYMBOL_Name = 99                       /* Name  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      59,    60,    63,    61,    58,    62,    56,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    57,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   164,   201,   223,   231,   248,   289,   326,
     348,   356,   373,   414,   451,   473,   481,   498,   523,   538,
     555,   588,   621,   654,   666,   691,   703,   720,   758,   781,
     798,   837,   873,   909,   973,  1023,  1073,  1151,  1229,  1268,
    1304,  1340,  1373,  1423,  1473,  1523,  1536,  1557,  1591,  1608,
    1642,  1659,  1679,  1696,  1719,  1736,  1762,  1779,  1791,  1808,
    1820,  1837,  1865,  1904,  1918,  1951,  1984,  2017,  2050,  2064,
    2076,  2111,  2123,  2162,  2201,  2240,  2279,  2318,  2359,  2371,
    2397,  2423,  2464,  2476,  2502,  2528,  2567,  2608,  2620,  2643,
    2666,  2704,  2716,  2757,  2790,  2823,  2856,  2889,  2925,  2961,
    2997,  3033,  3045,  3078,  3092
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "END",
  "FALSE", "TO", "VAR", "IDENTIFIER", "CHR", "POOL", "IF", "REPEAT",
  "READ", "ELSE", "UNTIL", "SWAP", "FOR", "THEN", "DOTDOT", "OF", "NE",
  "MOD", "GT", "CHARACTER", "CASE", "CHAR", "WHILE", "OUTPUT", "EQ",
  "EXIT", "CONST", "GTE", "PRED", "NOT", "DO", "BEGINX", "BOOLEAN", "ORD",
  "AND", "TRUE", "INTEGER_NUM", "INTEGER", "EOFX", "EXP", "LTE", "LOOP",
  "SUCC", "OR", "LT", "OTHERWISE", "ASSIGNMENT", "TYPEX", "PROGRAM",
  "DOWNTO", "':'", "'.'", "';'", "','", "'('", "')'", "'+'", "'-'", "'*'",
  "'/'", "$accept", "Tiny", "Consts", "Consts_1", "ConstDef", "Types",
  "Types_1", "TypeDef", "Dclns", "Dclns_1", "Dcln", "Dcln_1", "Type",
  "Type_1", "Body", "Body_1", "Statement", "Statement_1_1_1_1_1_1_1",
  "Statement_1_1_1_1_1_1", "Statement_1_1_1_1_1", "Statement_1_1_1_1",
  "Statement_1_1_1", "Statement_1_1", "Statement_1", "Caseclause",
  "CaseValue", "Constant", "OutputItem", "Expression", "Simp_Expr", "Term",
  "Factor", "Power", "Primary", "Name", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -43,    18,    25,   -99,   -24,   -99,     1,    18,   -17,   -99,
     -19,    12,    18,    42,    18,    76,   -99,    -2,    33,    18,
      34,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    18,    37,
     -99,    19,   -99,   -34,   246,    18,   -99,   -99,   -99,   -99,
      18,   -99,   -99,    18,    37,    18,   194,   246,    31,    18,
     194,   194,    38,   -99,   246,   -99,   -99,     0,    -4,    36,
     -99,    11,   -99,   -99,   -99,   -99,    40,   -99,    45,   194,
      47,   -99,   -99,   -99,    48,   194,   194,   194,    70,   102,
      39,   -99,   -99,    49,   -99,    -7,   -99,    18,    50,    91,
      79,   136,    -5,   -99,   -99,   246,    18,   194,   -99,    18,
     -99,   194,   194,   -99,   194,   194,    55,   -99,   -99,   246,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   205,   194,   246,   -99,    17,   194,    32,
     246,   -99,   -99,    29,   -99,   -99,   246,   -99,   -99,   -99,
     -99,    58,    59,    60,    61,   -99,   112,   -32,   -32,   -32,
     -32,   -32,    39,   -32,    39,    39,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,    18,   -99,    -3,   -99,   246,   -99,   -99,
     -99,    73,    72,   114,   -99,   136,   -99,   -99,   -99,   -99,
     -99,   -99,   246,   -99,   194,   194,     3,    32,   246,    76,
     -99,   -99,   103,   105,   -99,   138,   -99,   -99,   -99,   -99,
     -99,   246,   246,   -99,   -99,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,   104,     0,     1,     4,     5,     9,     3,
       0,     0,    10,    14,     5,     0,     8,     0,     0,    15,
       0,     6,    67,    65,    66,    64,     7,    68,    10,     0,
      13,     0,    17,     0,    46,     0,    11,    22,    21,    20,
       0,    12,    23,    15,     0,     0,     0,    46,     0,     0,
       0,     0,     0,    41,    46,    45,    27,     0,     0,     0,
      24,     0,    16,    18,    19,    95,     0,    96,     0,     0,
       0,    94,   102,    93,     0,     0,     0,     0,     0,    71,
      78,    82,    87,    91,   101,     0,    39,     0,     0,     0,
       0,     0,     0,    40,    28,    46,     0,     0,     2,     0,
      25,     0,     0,    90,     0,     0,     0,    89,    88,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,    32,     0,     0,     0,
      46,    70,    31,     0,    69,    53,    46,    29,    38,    30,
      26,     0,     0,     0,     0,   103,    34,    74,    77,    73,
      75,    72,    81,    76,    79,    80,    86,    85,    83,    84,
      92,    55,    56,     0,    57,     0,    51,    46,    44,    43,
      42,     0,     0,    63,    35,     0,    59,    54,   100,    98,
      99,    97,    46,    58,     0,     0,     0,     0,    46,     0,
      60,    33,     0,     0,    49,     0,    48,    50,    52,    61,
      62,    46,    46,    47,    36,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   132,   -99,   -99,   120,   -99,   -99,   106,
     -99,   107,   109,    56,   134,    63,   -45,   -28,   -26,   -22,
      35,    43,     4,     5,   -99,   -99,   -14,   -99,     8,    95,
     -98,   -54,    62,   -99,    -1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,     9,    10,    13,    16,    17,    20,    30,
      31,    32,    41,    60,    55,    56,    57,   168,   169,   170,
      93,    86,   126,   132,   171,   172,   173,   133,   134,    79,
      80,    81,    82,    83,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       4,    26,    85,   184,    94,   135,    11,   194,   124,    92,
       1,    18,    96,    11,    27,   103,   115,   152,    33,   154,
     155,    44,   107,   108,    45,     5,     3,    18,    42,   117,
     118,     6,     7,    58,    59,    12,   166,    22,    14,    61,
       3,    15,    33,    42,    33,     3,    58,    97,    88,    19,
     125,   185,   136,    58,    78,    28,    23,    95,    89,    90,
     195,   119,    29,    37,   146,   156,   157,   158,   159,    99,
      34,   100,    24,    25,    38,   163,    43,   164,   120,    39,
      85,    22,   167,   106,     3,   174,   127,   175,   109,   176,
      87,    92,    98,   123,    58,   138,    40,    91,    61,   101,
      23,   128,   121,   122,   102,   139,   104,   105,    58,   141,
     142,   129,   143,   144,   130,   145,    24,    25,   178,   179,
     180,   181,   186,   110,    58,   111,   182,   188,    27,    58,
     187,   112,   161,   189,   113,    58,   165,   191,   201,   131,
     202,    65,   203,   199,     3,    66,    21,   114,    36,    62,
     115,   116,    64,    63,    35,   140,   204,   205,   137,   196,
      67,   197,   127,   117,   118,   198,    58,   183,   162,    68,
      69,   177,     0,     0,    70,   200,    71,    72,     0,    73,
     190,    58,     0,    74,     0,   160,    27,    58,    27,     0,
       0,     0,   192,   193,     0,    75,     0,    76,    77,    65,
      58,    58,     3,    66,     0,   147,   148,   149,   150,   151,
      65,   153,     0,     3,    66,     0,     0,     0,    67,     0,
       0,     0,     0,     0,     0,     0,     0,    68,    69,    67,
       0,     0,    70,     0,    71,    72,     0,    73,    68,     0,
       0,    74,     0,    70,     0,    71,    72,     0,    73,     0,
       0,     0,    74,    75,     3,    76,    77,    46,    47,    48,
       0,     0,     0,    49,    75,     0,     0,     0,     0,     0,
       0,    50,     0,    51,    52,     0,    53,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54
};

static const yytype_int16 yycheck[] =
{
       1,    15,    47,     6,     4,    10,     7,     4,    15,    54,
      53,    12,    16,    14,    15,    69,    48,   115,    19,   117,
     118,    55,    76,    77,    58,     0,     8,    28,    29,    61,
      62,    55,    31,    34,    35,    52,     4,     5,    57,    40,
       8,    29,    43,    44,    45,     8,    47,    51,    49,     7,
      57,    54,    57,    54,    46,    57,    24,    57,    50,    51,
      57,    22,    29,    26,   109,   119,   120,   121,   122,    58,
      36,    60,    40,    41,    37,    58,    57,    60,    39,    42,
     125,     5,    50,    75,     8,   130,    87,    58,    18,    60,
      59,   136,    56,    44,    95,    96,    59,    59,    99,    59,
      24,    51,    63,    64,    59,    97,    59,    59,   109,   101,
     102,    20,   104,   105,    35,    60,    40,    41,    60,    60,
      60,    60,   167,    21,   125,    23,    14,    55,   129,   130,
      57,    29,   124,    19,    32,   136,   128,   182,    35,     3,
      35,     5,     4,   188,     8,     9,    14,    45,    28,    43,
      48,    49,    45,    44,    20,    99,   201,   202,    95,   187,
      24,   187,   163,    61,    62,   187,   167,   163,   125,    33,
      34,   136,    -1,    -1,    38,   189,    40,    41,    -1,    43,
     175,   182,    -1,    47,    -1,   123,   187,   188,   189,    -1,
      -1,    -1,   184,   185,    -1,    59,    -1,    61,    62,     5,
     201,   202,     8,     9,    -1,   110,   111,   112,   113,   114,
       5,   116,    -1,     8,     9,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    24,
      -1,    -1,    38,    -1,    40,    41,    -1,    43,    33,    -1,
      -1,    47,    -1,    38,    -1,    40,    41,    -1,    43,    -1,
      -1,    -1,    47,    59,     8,    61,    62,    11,    12,    13,
      -1,    -1,    -1,    17,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    53,    66,     8,    99,     0,    55,    31,    67,    68,
      69,    99,    52,    70,    57,    29,    71,    72,    99,     7,
      73,    68,     5,    24,    40,    41,    91,    99,    57,    29,
      74,    75,    76,    99,    36,    79,    71,    26,    37,    42,
      59,    77,    99,    57,    55,    58,    11,    12,    13,    17,
      25,    27,    28,    30,    46,    79,    80,    81,    99,    99,
      78,    99,    74,    77,    76,     5,     9,    24,    33,    34,
      38,    40,    41,    43,    47,    59,    61,    62,    93,    94,
      95,    96,    97,    98,    99,    81,    86,    59,    99,    93,
      93,    59,    81,    85,     4,    57,    16,    51,    56,    58,
      60,    59,    59,    96,    59,    59,    93,    96,    96,    18,
      21,    23,    29,    32,    45,    48,    49,    61,    62,    22,
      39,    63,    64,    44,    15,    57,    87,    99,    51,    20,
      35,     3,    88,    92,    93,    10,    57,    80,    99,    93,
      78,    93,    93,    93,    93,    60,    81,    94,    94,    94,
      94,    94,    95,    94,    95,    95,    96,    96,    96,    96,
      97,    93,    86,    58,    60,    93,     4,    50,    82,    83,
      84,    89,    90,    91,    81,    58,    60,    85,    60,    60,
      60,    60,    14,    87,     6,    54,    81,    57,    55,    19,
      88,    81,    93,    93,     4,    57,    82,    83,    84,    81,
      91,    35,    35,     4,    81,    81
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    69,    70,    70,
      71,    71,    72,    73,    73,    74,    74,    75,    76,    76,
      77,    77,    77,    77,    77,    78,    78,    79,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    90,    90,    91,    91,    91,    91,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    94,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     9,     2,     0,     0,     3,     3,     2,     0,
       0,     3,     3,     2,     0,     0,     3,     1,     3,     3,
       1,     1,     1,     1,     2,     2,     3,     2,     2,     3,
       3,     3,     3,     6,     4,     4,     8,     8,     3,     2,
       2,     1,     4,     4,     4,     1,     0,     4,     3,     3,
       3,     1,     3,     2,     3,     3,     3,     2,     3,     2,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     2,     2,
       2,     1,     3,     1,     1,     1,     1,     4,     4,     4,
       4,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Tiny: PROGRAM Name ':' Consts Types Dclns Body Name '.'  */
#line 111 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-8].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-8].info).string,
		                                TREETAG_LINE,(yyvsp[-8].info).line,
		                                TREETAG_COLUMN,(yyvsp[-8].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-7].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-7].dlist)));

		while (DCount(&(yyvsp[-5].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-5].dlist)));

		while (DCount(&(yyvsp[-4].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-4].dlist)));

		while (DCount(&(yyvsp[-3].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-3].dlist)));

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"program",
		                                TREETAG_LINE,(yyvsp[-8].info).line,
		                                TREETAG_COLUMN,(yyvsp[-8].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		t->mynode = *(DHead(&r));
		root = t->nodeptr;

             }
#line 1541 "y.tab.c"
    break;

  case 3: /* Consts: CONST Consts_1  */
#line 165 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"consts",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1581 "y.tab.c"
    break;

  case 4: /* Consts: %empty  */
#line 201 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"consts",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1605 "y.tab.c"
    break;

  case 5: /* Consts_1: %empty  */
#line 223 "code.y"
             {
		DLIST r;

		InitDList(&r);

		(yyval.dlist) = r;

             }
#line 1618 "y.tab.c"
    break;

  case 6: /* Consts_1: ConstDef ';' Consts_1  */
#line 232 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1637 "y.tab.c"
    break;

  case 7: /* ConstDef: Name EQ Constant  */
#line 249 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"const",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1680 "y.tab.c"
    break;

  case 8: /* Types: TYPEX Types_1  */
#line 290 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"types",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1720 "y.tab.c"
    break;

  case 9: /* Types: %empty  */
#line 326 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"types",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1744 "y.tab.c"
    break;

  case 10: /* Types_1: %empty  */
#line 348 "code.y"
             {
		DLIST r;

		InitDList(&r);

		(yyval.dlist) = r;

             }
#line 1757 "y.tab.c"
    break;

  case 11: /* Types_1: TypeDef ';' Types_1  */
#line 357 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1776 "y.tab.c"
    break;

  case 12: /* TypeDef: Name EQ Type  */
#line 374 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"type",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1819 "y.tab.c"
    break;

  case 13: /* Dclns: VAR Dclns_1  */
#line 415 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dclns",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1859 "y.tab.c"
    break;

  case 14: /* Dclns: %empty  */
#line 451 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dclns",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1883 "y.tab.c"
    break;

  case 15: /* Dclns_1: %empty  */
#line 473 "code.y"
             {
		DLIST r;

		InitDList(&r);

		(yyval.dlist) = r;

             }
#line 1896 "y.tab.c"
    break;

  case 16: /* Dclns_1: Dcln ';' Dclns_1  */
#line 482 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1915 "y.tab.c"
    break;

  case 17: /* Dcln: Dcln_1  */
#line 499 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dcln",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 1942 "y.tab.c"
    break;

  case 18: /* Dcln_1: Name ':' Type  */
#line 524 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1961 "y.tab.c"
    break;

  case 19: /* Dcln_1: Name ',' Dcln_1  */
#line 539 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 1980 "y.tab.c"
    break;

  case 20: /* Type: INTEGER  */
#line 556 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"integer",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2017 "y.tab.c"
    break;

  case 21: /* Type: BOOLEAN  */
#line 589 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"boolean",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2054 "y.tab.c"
    break;

  case 22: /* Type: CHAR  */
#line 622 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"char",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2091 "y.tab.c"
    break;

  case 23: /* Type: Name  */
#line 655 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 2107 "y.tab.c"
    break;

  case 24: /* Type: '(' Type_1  */
#line 667 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"enum",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2134 "y.tab.c"
    break;

  case 25: /* Type_1: Name ')'  */
#line 692 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		(yyval.dlist) = r;

             }
#line 2150 "y.tab.c"
    break;

  case 26: /* Type_1: Name ',' Type_1  */
#line 704 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 2169 "y.tab.c"
    break;

  case 27: /* Body: BEGINX Body_1  */
#line 721 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"block",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2209 "y.tab.c"
    break;

  case 28: /* Body_1: Statement END  */
#line 759 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		(yyval.dlist) = r;

             }
#line 2236 "y.tab.c"
    break;

  case 29: /* Body_1: Statement ';' Body_1  */
#line 782 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 2255 "y.tab.c"
    break;

  case 30: /* Statement: Name ASSIGNMENT Expression  */
#line 799 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"assign",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2298 "y.tab.c"
    break;

  case 31: /* Statement: OUTPUT '(' Statement_1  */
#line 838 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-2].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-2].info).string,
		                                TREETAG_LINE,(yyvsp[-2].info).line,
		                                TREETAG_COLUMN,(yyvsp[-2].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"output",
		                                TREETAG_LINE,(yyvsp[-2].info).line,
		                                TREETAG_COLUMN,(yyvsp[-2].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2338 "y.tab.c"
    break;

  case 32: /* Statement: READ '(' Statement_1_1  */
#line 874 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-2].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-2].info).string,
		                                TREETAG_LINE,(yyvsp[-2].info).line,
		                                TREETAG_COLUMN,(yyvsp[-2].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"read",
		                                TREETAG_LINE,(yyvsp[-2].info).line,
		                                TREETAG_COLUMN,(yyvsp[-2].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2378 "y.tab.c"
    break;

  case 33: /* Statement: IF Expression THEN Statement ELSE Statement  */
#line 910 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-5].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-5].info).string,
		                                TREETAG_LINE,(yyvsp[-5].info).line,
		                                TREETAG_COLUMN,(yyvsp[-5].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-4].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-4].dlist)));

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"if",
		                                TREETAG_LINE,(yyvsp[-5].info).line,
		                                TREETAG_COLUMN,(yyvsp[-5].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2446 "y.tab.c"
    break;

  case 34: /* Statement: IF Expression THEN Statement  */
#line 974 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"if",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2500 "y.tab.c"
    break;

  case 35: /* Statement: WHILE Expression DO Statement  */
#line 1024 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"while",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2554 "y.tab.c"
    break;

  case 36: /* Statement: FOR Name ASSIGNMENT Expression TO Expression DO Statement  */
#line 1074 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-7].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-7].info).string,
		                                TREETAG_LINE,(yyvsp[-7].info).line,
		                                TREETAG_COLUMN,(yyvsp[-7].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-6].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-6].dlist)));

		if ((yyvsp[-5].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-5].info).string,
		                                TREETAG_LINE,(yyvsp[-5].info).line,
		                                TREETAG_COLUMN,(yyvsp[-5].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-4].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-4].dlist)));

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"for",
		                                TREETAG_LINE,(yyvsp[-7].info).line,
		                                TREETAG_COLUMN,(yyvsp[-7].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2636 "y.tab.c"
    break;

  case 37: /* Statement: FOR Name ASSIGNMENT Expression DOWNTO Expression DO Statement  */
#line 1152 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-7].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-7].info).string,
		                                TREETAG_LINE,(yyvsp[-7].info).line,
		                                TREETAG_COLUMN,(yyvsp[-7].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-6].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-6].dlist)));

		if ((yyvsp[-5].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-5].info).string,
		                                TREETAG_LINE,(yyvsp[-5].info).line,
		                                TREETAG_COLUMN,(yyvsp[-5].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-4].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-4].dlist)));

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"downto",
		                                TREETAG_LINE,(yyvsp[-7].info).line,
		                                TREETAG_COLUMN,(yyvsp[-7].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2718 "y.tab.c"
    break;

  case 38: /* Statement: Name SWAP Name  */
#line 1230 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"swap",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2761 "y.tab.c"
    break;

  case 39: /* Statement: REPEAT Statement_1_1_1  */
#line 1269 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"repeat",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2801 "y.tab.c"
    break;

  case 40: /* Statement: LOOP Statement_1_1_1_1  */
#line 1305 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"loop",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2841 "y.tab.c"
    break;

  case 41: /* Statement: EXIT  */
#line 1341 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"exit",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2878 "y.tab.c"
    break;

  case 42: /* Statement: CASE Expression OF Statement_1_1_1_1_1  */
#line 1374 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"case",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2932 "y.tab.c"
    break;

  case 43: /* Statement: CASE Expression OF Statement_1_1_1_1_1_1  */
#line 1424 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"case",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 2986 "y.tab.c"
    break;

  case 44: /* Statement: CASE Expression OF Statement_1_1_1_1_1_1_1  */
#line 1474 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"case",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3040 "y.tab.c"
    break;

  case 45: /* Statement: Body  */
#line 1524 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3056 "y.tab.c"
    break;

  case 46: /* Statement: %empty  */
#line 1536 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<null>",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3080 "y.tab.c"
    break;

  case 47: /* Statement_1_1_1_1_1_1_1: OTHERWISE Statement ';' END  */
#line 1558 "code.y"
             {
		DLIST r;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		(yyval.dlist) = r;

             }
#line 3118 "y.tab.c"
    break;

  case 48: /* Statement_1_1_1_1_1_1_1: Caseclause ';' Statement_1_1_1_1_1_1_1  */
#line 1592 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3137 "y.tab.c"
    break;

  case 49: /* Statement_1_1_1_1_1_1: OTHERWISE Statement END  */
#line 1609 "code.y"
             {
		DLIST r;

		InitDList(&r);

		if ((yyvsp[-2].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-2].info).string,
		                                TREETAG_LINE,(yyvsp[-2].info).line,
		                                TREETAG_COLUMN,(yyvsp[-2].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		(yyval.dlist) = r;

             }
#line 3175 "y.tab.c"
    break;

  case 50: /* Statement_1_1_1_1_1_1: Caseclause ';' Statement_1_1_1_1_1_1  */
#line 1643 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3194 "y.tab.c"
    break;

  case 51: /* Statement_1_1_1_1_1: END  */
#line 1660 "code.y"
             {
		DLIST r;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		(yyval.dlist) = r;

             }
#line 3218 "y.tab.c"
    break;

  case 52: /* Statement_1_1_1_1_1: Caseclause ';' Statement_1_1_1_1_1  */
#line 1680 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3237 "y.tab.c"
    break;

  case 53: /* Statement_1_1_1_1: Statement POOL  */
#line 1697 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		(yyval.dlist) = r;

             }
#line 3264 "y.tab.c"
    break;

  case 54: /* Statement_1_1_1_1: Statement ';' Statement_1_1_1_1  */
#line 1720 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3283 "y.tab.c"
    break;

  case 55: /* Statement_1_1_1: Statement UNTIL Expression  */
#line 1737 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3313 "y.tab.c"
    break;

  case 56: /* Statement_1_1_1: Statement ';' Statement_1_1_1  */
#line 1763 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3332 "y.tab.c"
    break;

  case 57: /* Statement_1_1: Name ')'  */
#line 1780 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		(yyval.dlist) = r;

             }
#line 3348 "y.tab.c"
    break;

  case 58: /* Statement_1_1: Name ',' Statement_1_1  */
#line 1792 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3367 "y.tab.c"
    break;

  case 59: /* Statement_1: OutputItem ')'  */
#line 1809 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		(yyval.dlist) = r;

             }
#line 3383 "y.tab.c"
    break;

  case 60: /* Statement_1: OutputItem ',' Statement_1  */
#line 1821 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3402 "y.tab.c"
    break;

  case 61: /* Caseclause: CaseValue ':' Statement  */
#line 1838 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"caseclause",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3432 "y.tab.c"
    break;

  case 62: /* CaseValue: Constant DOTDOT Constant  */
#line 1866 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"..",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3475 "y.tab.c"
    break;

  case 63: /* CaseValue: Constant  */
#line 1905 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3491 "y.tab.c"
    break;

  case 64: /* Constant: INTEGER_NUM  */
#line 1919 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<integer>",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3528 "y.tab.c"
    break;

  case 65: /* Constant: CHARACTER  */
#line 1952 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<char>",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3565 "y.tab.c"
    break;

  case 66: /* Constant: TRUE  */
#line 1985 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"true",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3602 "y.tab.c"
    break;

  case 67: /* Constant: FALSE  */
#line 2018 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"false",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3639 "y.tab.c"
    break;

  case 68: /* Constant: Name  */
#line 2051 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3655 "y.tab.c"
    break;

  case 69: /* OutputItem: Expression  */
#line 2065 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3671 "y.tab.c"
    break;

  case 70: /* OutputItem: STRING  */
#line 2077 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<string>",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3708 "y.tab.c"
    break;

  case 71: /* Expression: Simp_Expr  */
#line 2112 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3724 "y.tab.c"
    break;

  case 72: /* Expression: Simp_Expr LTE Simp_Expr  */
#line 2124 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<=",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3767 "y.tab.c"
    break;

  case 73: /* Expression: Simp_Expr EQ Simp_Expr  */
#line 2163 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"=",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3810 "y.tab.c"
    break;

  case 74: /* Expression: Simp_Expr NE Simp_Expr  */
#line 2202 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<>",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3853 "y.tab.c"
    break;

  case 75: /* Expression: Simp_Expr GTE Simp_Expr  */
#line 2241 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,">=",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3896 "y.tab.c"
    break;

  case 76: /* Expression: Simp_Expr LT Simp_Expr  */
#line 2280 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3939 "y.tab.c"
    break;

  case 77: /* Expression: Simp_Expr GT Simp_Expr  */
#line 2319 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,">",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 3982 "y.tab.c"
    break;

  case 78: /* Simp_Expr: Term  */
#line 2360 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 3998 "y.tab.c"
    break;

  case 79: /* Simp_Expr: Simp_Expr '+' Term  */
#line 2372 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"+",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4028 "y.tab.c"
    break;

  case 80: /* Simp_Expr: Simp_Expr '-' Term  */
#line 2398 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"-",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4058 "y.tab.c"
    break;

  case 81: /* Simp_Expr: Simp_Expr OR Term  */
#line 2424 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"or",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4101 "y.tab.c"
    break;

  case 82: /* Term: Factor  */
#line 2465 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 4117 "y.tab.c"
    break;

  case 83: /* Term: Term '*' Factor  */
#line 2477 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"*",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4147 "y.tab.c"
    break;

  case 84: /* Term: Term '/' Factor  */
#line 2503 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"/",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4177 "y.tab.c"
    break;

  case 85: /* Term: Term AND Factor  */
#line 2529 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"and",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4220 "y.tab.c"
    break;

  case 86: /* Term: Term MOD Factor  */
#line 2568 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"mod",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4263 "y.tab.c"
    break;

  case 87: /* Factor: Power  */
#line 2609 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 4279 "y.tab.c"
    break;

  case 88: /* Factor: '-' Factor  */
#line 2621 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"-",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4306 "y.tab.c"
    break;

  case 89: /* Factor: '+' Factor  */
#line 2644 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"+",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4333 "y.tab.c"
    break;

  case 90: /* Factor: NOT Factor  */
#line 2667 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"not",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4373 "y.tab.c"
    break;

  case 91: /* Power: Primary  */
#line 2705 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 4389 "y.tab.c"
    break;

  case 92: /* Power: Primary EXP Power  */
#line 2717 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&(yyvsp[-2].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-2].dlist)));

		if ((yyvsp[-1].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-1].info).string,
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"**",
		                                TREETAG_LINE,(yyvsp[-1].info).line,
		                                TREETAG_COLUMN,(yyvsp[-1].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4432 "y.tab.c"
    break;

  case 93: /* Primary: EOFX  */
#line 2758 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"eof",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4469 "y.tab.c"
    break;

  case 94: /* Primary: TRUE  */
#line 2791 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"true",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4506 "y.tab.c"
    break;

  case 95: /* Primary: FALSE  */
#line 2824 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"false",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4543 "y.tab.c"
    break;

  case 96: /* Primary: CHARACTER  */
#line 2857 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<char>",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4580 "y.tab.c"
    break;

  case 97: /* Primary: SUCC '(' Expression ')'  */
#line 2890 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"succ",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4620 "y.tab.c"
    break;

  case 98: /* Primary: PRED '(' Expression ')'  */
#line 2926 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"pred",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4660 "y.tab.c"
    break;

  case 99: /* Primary: ORD '(' Expression ')'  */
#line 2962 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"ord",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4700 "y.tab.c"
    break;

  case 100: /* Primary: CHR '(' Expression ')'  */
#line 2998 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[-3].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[-3].info).string,
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"chr",
		                                TREETAG_LINE,(yyvsp[-3].info).line,
		                                TREETAG_COLUMN,(yyvsp[-3].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4740 "y.tab.c"
    break;

  case 101: /* Primary: Name  */
#line 3034 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[0].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[0].dlist)));

		(yyval.dlist) = r;

             }
#line 4756 "y.tab.c"
    break;

  case 102: /* Primary: INTEGER_NUM  */
#line 3046 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<integer>",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4793 "y.tab.c"
    break;

  case 103: /* Primary: '(' Expression ')'  */
#line 3079 "code.y"
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&(yyvsp[-1].dlist)) > 0)
		    DAddTail(&r,DRemHead(&(yyvsp[-1].dlist)));

		(yyval.dlist) = r;

             }
#line 4809 "y.tab.c"
    break;

  case 104: /* Name: IDENTIFIER  */
#line 3093 "code.y"
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ((yyvsp[0].info).makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,(yyvsp[0].info).string,
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<identifier>",
		                                TREETAG_LINE,(yyvsp[0].info).line,
		                                TREETAG_COLUMN,(yyvsp[0].info).column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		(yyval.dlist) = r;

             }
#line 4846 "y.tab.c"
    break;


#line 4850 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

