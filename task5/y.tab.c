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
#line 1 "task5.y"

# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern FILE *yyin;
int yylex();
int yyerror();

typedef struct array_vals{
    char* val;
    struct array_vals* next;
} array_vals;

typedef struct symbol {
    char name[100];
    char type[100];
    char value[100];
    array_vals* vals;
    struct symbol* next;
} symbol;

symbol* symbol_table = NULL;


void add_symbol(const char*, const char*);
symbol* find_symbol(const char*);
char * tolowercase(char *);
void printTable();
void reverseTAC();
void printFormatted();
void reverseWrite();
void printTempTable();
void setSymbolTable();  
void initialiseArrayValsList(int, symbol*);
void addTemp(const char*, const char*, const char*);


typedef struct TAC{
    char op[100];
    char arg1[100];
    char arg2[100];
    char result[100];
    struct TAC* next;
} TAC;

TAC* TAC_table = NULL;

typedef struct Stack{
    char* data;
    struct Stack* next;
}stack;

stack* top = NULL;

int qindex=0;
int lindex=0;
int wcount=1;

typedef struct stringConstants{
    char* sc;
    struct stringConstants* next;
} sc;

typedef struct variables{
    char* var;
    struct variables* next;
} var;

typedef struct writeTable{
    sc* sc;
    var* var;
    char* order;
    struct writeTable* next;
} wt;

wt* write_table=NULL;

typedef struct readTable{
    char* var;
    int isArrayEl;
    struct readTable* next;
} rt;

rt* read_table=NULL;

typedef struct temporaryVariables{
    char temp[100];
    char type[100];
    char value[100];
    array_vals* vals;
    struct temporaryVariables* next;
} temp;

temp* temp_table=NULL;

int rcount=1;


void addTAC(const char*, const char*, const char*, const char*);
void printTAC();
void push(char*);
char* pop();
void printFormatted();
void initialiseWriteTableElement();
void addSC(const char*);
void addVar(const char*);
void printWriteTable();
void parseTAC();
temp* findTemp(const char*);
void initialiseReadTableElement();


#line 185 "y.tab.c"

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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    STRING_CONSTANT = 259,         /* STRING_CONSTANT  */
    INTEGER = 260,                 /* INTEGER  */
    REAL = 261,                    /* REAL  */
    BOOLEAN = 262,                 /* BOOLEAN  */
    CHAR = 263,                    /* CHAR  */
    BOOLEAN_OP = 264,              /* BOOLEAN_OP  */
    BOOLEAN_OP_NOT = 265,          /* BOOLEAN_OP_NOT  */
    ASSIGNMENT_OP = 266,           /* ASSIGNMENT_OP  */
    RELATIONAL_OP = 267,           /* RELATIONAL_OP  */
    CHAR_CONSTANT = 268,           /* CHAR_CONSTANT  */
    ARITHEMATIC_OP_PLUS = 269,     /* ARITHEMATIC_OP_PLUS  */
    ARITHEMATIC_OP_DIV = 270,      /* ARITHEMATIC_OP_DIV  */
    ARITHEMATIC_OP_MUL = 271,      /* ARITHEMATIC_OP_MUL  */
    ARITHEMATIC_OP_MINUS = 272,    /* ARITHEMATIC_OP_MINUS  */
    IF = 273,                      /* IF  */
    WHILE = 274,                   /* WHILE  */
    ARITHEMATIC_OP_MOD = 275,      /* ARITHEMATIC_OP_MOD  */
    INTEGER_CONSTANT = 276,        /* INTEGER_CONSTANT  */
    FLOAT_CONSTANT = 277,          /* FLOAT_CONSTANT  */
    PROGRAM = 278,                 /* PROGRAM  */
    SEMICOLON = 279,               /* SEMICOLON  */
    ELSE = 280,                    /* ELSE  */
    FOR = 281,                     /* FOR  */
    DO = 282,                      /* DO  */
    BEGIN_TAG = 283,               /* BEGIN_TAG  */
    END = 284,                     /* END  */
    WRITE = 285,                   /* WRITE  */
    READ = 286,                    /* READ  */
    DOWNTO = 287,                  /* DOWNTO  */
    TO = 288,                      /* TO  */
    OF = 289,                      /* OF  */
    COLON = 290,                   /* COLON  */
    VAR = 291,                     /* VAR  */
    ARRAY = 292,                   /* ARRAY  */
    THEN = 293,                    /* THEN  */
    COMMA = 294,                   /* COMMA  */
    OPEN_BRACKET = 295,            /* OPEN_BRACKET  */
    OPEN_PARANTHESIS = 296,        /* OPEN_PARANTHESIS  */
    CLOSE_BRACKET = 297,           /* CLOSE_BRACKET  */
    CLOSE_PARANTHESIS = 298,       /* CLOSE_PARANTHESIS  */
    PERIOD = 299,                  /* PERIOD  */
    RANGE_DOTS = 300               /* RANGE_DOTS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define STRING_CONSTANT 259
#define INTEGER 260
#define REAL 261
#define BOOLEAN 262
#define CHAR 263
#define BOOLEAN_OP 264
#define BOOLEAN_OP_NOT 265
#define ASSIGNMENT_OP 266
#define RELATIONAL_OP 267
#define CHAR_CONSTANT 268
#define ARITHEMATIC_OP_PLUS 269
#define ARITHEMATIC_OP_DIV 270
#define ARITHEMATIC_OP_MUL 271
#define ARITHEMATIC_OP_MINUS 272
#define IF 273
#define WHILE 274
#define ARITHEMATIC_OP_MOD 275
#define INTEGER_CONSTANT 276
#define FLOAT_CONSTANT 277
#define PROGRAM 278
#define SEMICOLON 279
#define ELSE 280
#define FOR 281
#define DO 282
#define BEGIN_TAG 283
#define END 284
#define WRITE 285
#define READ 286
#define DOWNTO 287
#define TO 288
#define OF 289
#define COLON 290
#define VAR 291
#define ARRAY 292
#define THEN 293
#define COMMA 294
#define OPEN_BRACKET 295
#define OPEN_PARANTHESIS 296
#define CLOSE_BRACKET 297
#define CLOSE_PARANTHESIS 298
#define PERIOD 299
#define RANGE_DOTS 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 115 "task5.y"

    struct sval{
        char *val;
        int line;
    }sval;
    struct ival{
        int val;
        int line;
    }ival;
    struct dval{
        double val;
        int line;
    }dval;

#line 343 "y.tab.c"

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
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_CONSTANT = 4,            /* STRING_CONSTANT  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_BOOLEAN = 7,                    /* BOOLEAN  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_BOOLEAN_OP = 9,                 /* BOOLEAN_OP  */
  YYSYMBOL_BOOLEAN_OP_NOT = 10,            /* BOOLEAN_OP_NOT  */
  YYSYMBOL_ASSIGNMENT_OP = 11,             /* ASSIGNMENT_OP  */
  YYSYMBOL_RELATIONAL_OP = 12,             /* RELATIONAL_OP  */
  YYSYMBOL_CHAR_CONSTANT = 13,             /* CHAR_CONSTANT  */
  YYSYMBOL_ARITHEMATIC_OP_PLUS = 14,       /* ARITHEMATIC_OP_PLUS  */
  YYSYMBOL_ARITHEMATIC_OP_DIV = 15,        /* ARITHEMATIC_OP_DIV  */
  YYSYMBOL_ARITHEMATIC_OP_MUL = 16,        /* ARITHEMATIC_OP_MUL  */
  YYSYMBOL_ARITHEMATIC_OP_MINUS = 17,      /* ARITHEMATIC_OP_MINUS  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_ARITHEMATIC_OP_MOD = 20,        /* ARITHEMATIC_OP_MOD  */
  YYSYMBOL_INTEGER_CONSTANT = 21,          /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 22,            /* FLOAT_CONSTANT  */
  YYSYMBOL_PROGRAM = 23,                   /* PROGRAM  */
  YYSYMBOL_SEMICOLON = 24,                 /* SEMICOLON  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_DO = 27,                        /* DO  */
  YYSYMBOL_BEGIN_TAG = 28,                 /* BEGIN_TAG  */
  YYSYMBOL_END = 29,                       /* END  */
  YYSYMBOL_WRITE = 30,                     /* WRITE  */
  YYSYMBOL_READ = 31,                      /* READ  */
  YYSYMBOL_DOWNTO = 32,                    /* DOWNTO  */
  YYSYMBOL_TO = 33,                        /* TO  */
  YYSYMBOL_OF = 34,                        /* OF  */
  YYSYMBOL_COLON = 35,                     /* COLON  */
  YYSYMBOL_VAR = 36,                       /* VAR  */
  YYSYMBOL_ARRAY = 37,                     /* ARRAY  */
  YYSYMBOL_THEN = 38,                      /* THEN  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_OPEN_BRACKET = 40,              /* OPEN_BRACKET  */
  YYSYMBOL_OPEN_PARANTHESIS = 41,          /* OPEN_PARANTHESIS  */
  YYSYMBOL_CLOSE_BRACKET = 42,             /* CLOSE_BRACKET  */
  YYSYMBOL_CLOSE_PARANTHESIS = 43,         /* CLOSE_PARANTHESIS  */
  YYSYMBOL_PERIOD = 44,                    /* PERIOD  */
  YYSYMBOL_RANGE_DOTS = 45,                /* RANGE_DOTS  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_start = 47,                     /* start  */
  YYSYMBOL_variable_declaration = 48,      /* variable_declaration  */
  YYSYMBOL_variable_list = 49,             /* variable_list  */
  YYSYMBOL_variable_line = 50,             /* variable_line  */
  YYSYMBOL_left_side_vars = 51,            /* left_side_vars  */
  YYSYMBOL_rigth_side_type = 52,           /* rigth_side_type  */
  YYSYMBOL_datatype = 53,                  /* datatype  */
  YYSYMBOL_program_declaration = 54,       /* program_declaration  */
  YYSYMBOL_statements = 55,                /* statements  */
  YYSYMBOL_statementline = 56,             /* statementline  */
  YYSYMBOL_57_1 = 57,                      /* $@1  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_while_left = 59,                /* while_left  */
  YYSYMBOL_left_if = 60,                   /* left_if  */
  YYSYMBOL_middle_if = 61,                 /* middle_if  */
  YYSYMBOL_right_if = 62,                  /* right_if  */
  YYSYMBOL_left_array_assignment = 63,     /* left_array_assignment  */
  YYSYMBOL_for_conditionals1 = 64,         /* for_conditionals1  */
  YYSYMBOL_for_conditionals2 = 65,         /* for_conditionals2  */
  YYSYMBOL_for_conditionals3 = 66,         /* for_conditionals3  */
  YYSYMBOL_for_conditionals4 = 67,         /* for_conditionals4  */
  YYSYMBOL_condition = 68,                 /* condition  */
  YYSYMBOL_conditionals = 69,              /* conditionals  */
  YYSYMBOL_condtional_unit = 70,           /* condtional_unit  */
  YYSYMBOL_relational_exp = 71,            /* relational_exp  */
  YYSYMBOL_left_side_vars_write = 72,      /* left_side_vars_write  */
  YYSYMBOL_possible_writes = 73,           /* possible_writes  */
  YYSYMBOL_possible_write_values = 74,     /* possible_write_values  */
  YYSYMBOL_possible_reads = 75,            /* possible_reads  */
  YYSYMBOL_arith_expression = 76,          /* arith_expression  */
  YYSYMBOL_unit = 77,                      /* unit  */
  YYSYMBOL_unit_2 = 78                     /* unit_2  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   149,   149,   161,   162,   163,   164,   166,   167,   173,
     180,   181,   191,   201,   211,   223,   231,   239,   247,   257,
     258,   260,   261,   263,   263,   268,   268,   274,   277,   285,
     286,   287,   294,   301,   308,   315,   320,   348,   368,   372,
     374,   423,   455,   487,   516,   550,   551,   554,   555,   556,
     567,   578,   589,   600,   613,   625,   636,   637,   638,   642,
     643,   645,   646,   649,   651,   656,   672,   673,   674,   675,
     684,   694,   704,   714,   726,   731,   772,   783,   788,   793
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "STRING_CONSTANT", "INTEGER", "REAL", "BOOLEAN", "CHAR", "BOOLEAN_OP",
  "BOOLEAN_OP_NOT", "ASSIGNMENT_OP", "RELATIONAL_OP", "CHAR_CONSTANT",
  "ARITHEMATIC_OP_PLUS", "ARITHEMATIC_OP_DIV", "ARITHEMATIC_OP_MUL",
  "ARITHEMATIC_OP_MINUS", "IF", "WHILE", "ARITHEMATIC_OP_MOD",
  "INTEGER_CONSTANT", "FLOAT_CONSTANT", "PROGRAM", "SEMICOLON", "ELSE",
  "FOR", "DO", "BEGIN_TAG", "END", "WRITE", "READ", "DOWNTO", "TO", "OF",
  "COLON", "VAR", "ARRAY", "THEN", "COMMA", "OPEN_BRACKET",
  "OPEN_PARANTHESIS", "CLOSE_BRACKET", "CLOSE_PARANTHESIS", "PERIOD",
  "RANGE_DOTS", "$accept", "start", "variable_declaration",
  "variable_list", "variable_line", "left_side_vars", "rigth_side_type",
  "datatype", "program_declaration", "statements", "statementline", "$@1",
  "$@2", "while_left", "left_if", "middle_if", "right_if",
  "left_array_assignment", "for_conditionals1", "for_conditionals2",
  "for_conditionals3", "for_conditionals4", "condition", "conditionals",
  "condtional_unit", "relational_exp", "left_side_vars_write",
  "possible_writes", "possible_write_values", "possible_reads",
  "arith_expression", "unit", "unit_2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-39)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,     4,     9,   -10,   -39,   -14,    23,     0,    -5,   -39,
      23,    21,    86,    18,    23,   -39,    53,    28,    10,    10,
      66,   -39,   -39,   -39,    50,    92,    57,    56,    97,   -39,
     -39,   -39,   -39,   -39,   -39,    74,   104,   -39,    16,    16,
      81,    10,   -39,    16,   -39,   -39,    16,   -39,   -39,   -39,
     120,   176,    -3,   -39,   -39,    41,   125,   108,   115,   122,
     123,   102,   112,   -39,   -39,     0,     0,   -13,    16,   137,
     -39,   154,   -39,    71,    16,   -39,    44,   179,    60,    10,
      16,    16,    16,    16,    16,    16,    10,    16,    16,     0,
       0,     0,     0,    89,   158,   138,   -39,   -39,     0,   141,
     165,   130,   -39,   -39,   110,   -39,   -39,    45,     1,   179,
     -39,   -39,   179,   -39,   -39,    69,   131,   140,   143,   152,
     153,   159,    62,   145,   -39,   144,   -39,   146,   155,   -39,
     -39,   -39,   -39,   183,   -39,    16,    16,    16,    16,   -39,
     -39,   -39,   -39,   116,    16,    89,   173,    16,   181,   164,
       1,     1,     1,     1,   168,   -39,   -39,   117,   -39,   -39,
     124,   -39,   174,   -39,   -39,   195,   -39,   -39,   -39,   -39
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     8,     3,
       5,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,    20,    23,    25,     0,    21,     0,     0,     0,     2,
       9,    15,    16,    17,    18,     0,     0,    10,     0,     0,
      74,     0,    79,     0,    77,    78,     0,    37,    45,    47,
      48,     0,    67,    66,    36,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    22,     0,     0,     0,     0,     0,
       7,     0,    67,     0,     0,    53,    67,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,     0,    38,    30,     0,     0,
       0,     0,    27,    40,     0,    68,    49,    67,    55,    69,
      72,    71,    70,    73,    51,    67,     0,     0,     0,     0,
       0,     0,    56,    58,    61,     0,    59,    64,     0,    35,
      39,    29,    28,     0,    75,     0,     0,     0,     0,    31,
      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
      42,    41,    44,    43,    56,    58,    57,     0,    62,    24,
       0,    26,     0,    63,    65,     0,    11,    12,    13,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -39,   -39,   -39,   199,   -39,   196,   -39,   -39,   -25,   186,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   192,   -39,   -39,
     -39,   -39,   194,   -31,   -39,   -39,    72,   -39,    73,   -39,
     -38,   -16,   -39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,     9,    10,    11,    36,    37,    13,    24,
      25,    61,    62,    26,    27,    67,    99,    28,    57,    58,
      59,    60,    47,    48,    49,    50,   124,   125,   126,   128,
      51,    72,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,    73,    52,    52,     1,    77,    86,     3,    78,     4,
      75,    97,    98,    40,     5,    81,    82,    83,    84,    40,
      41,    85,     6,    42,   -46,    76,     8,    43,    12,    42,
     100,    44,    45,    43,    14,   -46,   104,    44,    45,    38,
      95,    96,   108,   109,   110,   111,   112,   113,   106,   116,
     117,    46,    87,    86,    86,   114,    16,    46,    31,    32,
      33,    34,    29,   107,   118,   119,   120,   121,    39,    55,
     115,   -54,   -50,   130,    81,    82,    83,    84,    86,    63,
      85,    39,   -54,   -50,    65,    81,    82,    83,    84,    17,
      35,    85,   122,   123,    66,    17,   -52,   150,   151,   152,
     153,   143,   144,   105,    18,    19,   157,   -52,    68,   160,
      18,    19,    20,   103,    69,    21,    22,    23,    20,   154,
     155,    74,    22,    23,    81,    82,    83,    84,    70,    79,
      85,    81,    82,    83,    84,    89,    88,    85,    81,    82,
      83,    84,    90,    93,    85,    81,    82,    83,    84,    91,
      92,    85,   134,    94,    81,    82,    83,    84,   101,   163,
      85,   127,   129,   135,   136,   131,   164,   139,    81,    82,
      83,    84,   137,   138,    85,   133,   140,   141,   102,    81,
      82,    83,    84,   142,   145,    85,   147,   146,    80,   132,
      81,    82,    83,    84,    82,    83,    85,   159,   148,    85,
     166,   167,   168,   169,   149,   161,   162,   143,   165,    15,
      30,    64,    56,    54,     0,   156,     0,     0,   158
};

static const yytype_int16 yycheck[] =
{
      38,    39,    18,    19,    23,    43,     9,     3,    46,     0,
      41,    24,    25,     3,    24,    14,    15,    16,    17,     3,
      10,    20,    36,    13,    27,    41,     3,    17,    28,    13,
      68,    21,    22,    17,    39,    38,    74,    21,    22,    11,
      65,    66,    80,    81,    82,    83,    84,    85,    79,    87,
      88,    41,    11,     9,     9,    86,    35,    41,     5,     6,
       7,     8,    44,    79,    89,    90,    91,    92,    40,     3,
      86,    27,    27,    98,    14,    15,    16,    17,     9,    29,
      20,    40,    38,    38,    27,    14,    15,    16,    17,     3,
      37,    20,     3,     4,    38,     3,    27,   135,   136,   137,
     138,    39,    40,    43,    18,    19,   144,    38,    11,   147,
      18,    19,    26,    42,    40,    29,    30,    31,    26,     3,
       4,    40,    30,    31,    14,    15,    16,    17,    24,     9,
      20,    14,    15,    16,    17,    27,    11,    20,    14,    15,
      16,    17,    27,    41,    20,    14,    15,    16,    17,    27,
      27,    20,    42,    41,    14,    15,    16,    17,    21,    42,
      20,     3,    24,    32,    33,    24,    42,    24,    14,    15,
      16,    17,    32,    33,    20,    45,    24,    24,    24,    14,
      15,    16,    17,    24,    39,    20,    40,    43,    12,    24,
      14,    15,    16,    17,    15,    16,    20,    24,    43,    20,
       5,     6,     7,     8,    21,    24,    42,    39,    34,    10,
      14,    25,    20,    19,    -1,   143,    -1,    -1,   145
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    47,     3,     0,    24,    36,    48,     3,    49,
      50,    51,    28,    54,    39,    49,    35,     3,    18,    19,
      26,    29,    30,    31,    55,    56,    59,    60,    63,    44,
      51,     5,     6,     7,     8,    37,    52,    53,    11,    40,
       3,    10,    13,    17,    21,    22,    41,    68,    69,    70,
      71,    76,    77,    78,    68,     3,    63,    64,    65,    66,
      67,    57,    58,    29,    55,    27,    38,    61,    11,    40,
      24,    76,    77,    76,    40,    69,    77,    76,    76,     9,
      12,    14,    15,    16,    17,    20,     9,    11,    11,    27,
      27,    27,    27,    41,    41,    54,    54,    24,    25,    62,
      76,    21,    24,    42,    76,    43,    69,    77,    76,    76,
      76,    76,    76,    76,    69,    77,    76,    76,    54,    54,
      54,    54,     3,     4,    72,    73,    74,     3,    75,    24,
      54,    24,    24,    45,    42,    32,    33,    32,    33,    24,
      24,    24,    24,    39,    40,    39,    43,    40,    43,    21,
      76,    76,    76,    76,     3,     4,    72,    76,    74,    24,
      76,    24,    42,    42,    42,    34,     5,     6,     7,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    51,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    54,
      54,    55,    55,    57,    56,    58,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    70,    71,    72,    72,    72,    73,
      73,    74,    74,    74,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     2,     0,     1,     2,     4,     1,     3,
       1,     8,     8,     8,     8,     1,     1,     1,     1,     3,
       2,     1,     2,     0,     6,     0,     6,     4,     4,     4,
       3,     5,     5,     5,     5,     4,     2,     2,     2,     2,
       4,     5,     5,     5,     5,     1,     1,     1,     1,     3,
       3,     3,     3,     2,     2,     3,     1,     3,     1,     1,
       0,     1,     3,     4,     1,     4,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     4,     2,     1,     1,     1
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
  case 2: /* start: PROGRAM IDENTIFIER SEMICOLON variable_declaration program_declaration PERIOD  */
#line 149 "task5.y"
                                                                                    {printf("\n");
                                                                                    parseTAC();
                                                                                    // reverseTAC();
                                                                                    // printTAC();
                                                                                    // reverseWrite();
                                                                                    // printWriteTable();
                                                                                    // printTempTable();
                                                                                    printf("\n\n Final Symbol Table");
                                                                                    setSymbolTable();
                                                                                    printTable();
                                                                                    }
#line 1534 "y.tab.c"
    break;

  case 8: /* left_side_vars: IDENTIFIER  */
#line 167 "task5.y"
                           {
                    char * temp; temp=(char*)malloc(100*sizeof(char));
                    strcpy(temp,(yyvsp[0].sval).val);
                    temp=tolowercase(temp);
                    add_symbol(temp, "undefined");
                }
#line 1545 "y.tab.c"
    break;

  case 9: /* left_side_vars: IDENTIFIER COMMA left_side_vars  */
#line 173 "task5.y"
                                                 {
                    char * temp; temp=(char*)malloc(100*sizeof(char));
                    strcpy(temp,(yyvsp[-2].sval).val);
                    temp=tolowercase(temp);
                    add_symbol(temp, "undefined");
                }
#line 1556 "y.tab.c"
    break;

  case 11: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF INTEGER  */
#line 181 "task5.y"
                                                                                                         {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_INTEGER");
                            initialiseArrayValsList((yyvsp[-3].ival).val-(yyvsp[-5].ival).val+1,current);
                        }
                        current = current->next;
                    }
                }
#line 1571 "y.tab.c"
    break;

  case 12: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF REAL  */
#line 191 "task5.y"
                                                                                                       {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_REAL");
                            initialiseArrayValsList((yyvsp[-3].ival).val-(yyvsp[-5].ival).val+1,current);
                        }
                        current = current->next;
                    }
                }
#line 1586 "y.tab.c"
    break;

  case 13: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF BOOLEAN  */
#line 201 "task5.y"
                                                                                                          {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_BOOLEAN");
                            initialiseArrayValsList((yyvsp[-3].ival).val-(yyvsp[-5].ival).val+1,current);
                        }
                        current = current->next;
                    }
                }
#line 1601 "y.tab.c"
    break;

  case 14: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF CHAR  */
#line 211 "task5.y"
                                                                                                       {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_CHAR");
                            initialiseArrayValsList((yyvsp[-3].ival).val-(yyvsp[-5].ival).val+1,current);
                        }
                        current = current->next;
                    }
                }
#line 1616 "y.tab.c"
    break;

  case 15: /* datatype: INTEGER  */
#line 223 "task5.y"
                  {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "INTEGER");
                }
                current = current->next;
            }}
#line 1629 "y.tab.c"
    break;

  case 16: /* datatype: REAL  */
#line 231 "task5.y"
              {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "REAL");
                }
                current = current->next;
            }}
#line 1642 "y.tab.c"
    break;

  case 17: /* datatype: BOOLEAN  */
#line 239 "task5.y"
                 {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "BOOLEAN");
                }
                current = current->next;
            }}
#line 1655 "y.tab.c"
    break;

  case 18: /* datatype: CHAR  */
#line 247 "task5.y"
              {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "CHAR");
                }
                current = current->next;
            }}
#line 1668 "y.tab.c"
    break;

  case 23: /* $@1: %empty  */
#line 263 "task5.y"
                     {initialiseWriteTableElement();}
#line 1674 "y.tab.c"
    break;

  case 24: /* statementline: WRITE $@1 OPEN_PARANTHESIS possible_writes CLOSE_PARANTHESIS SEMICOLON  */
#line 263 "task5.y"
                                                                                                                   {
    char * str=(char *)malloc(100*sizeof(char));
    sprintf(str,"%d",wcount);
    addTAC("WRITE",str,"","");
    wcount++;}
#line 1684 "y.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 268 "task5.y"
                      {initialiseReadTableElement();}
#line 1690 "y.tab.c"
    break;

  case 26: /* statementline: READ $@2 OPEN_PARANTHESIS possible_reads CLOSE_PARANTHESIS SEMICOLON  */
#line 268 "task5.y"
                                                                                                                  {
                    char * str=(char *)malloc(100*sizeof(char));
                    sprintf(str,"%d",rcount);
                    addTAC("READ",str,"","");
                    rcount++;
                }
#line 1701 "y.tab.c"
    break;

  case 27: /* statementline: IDENTIFIER ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 274 "task5.y"
                                                                    {
                    addTAC((yyvsp[-2].sval).val,pop(), "", (yyvsp[-3].sval).val);
                }
#line 1709 "y.tab.c"
    break;

  case 28: /* statementline: left_array_assignment ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 277 "task5.y"
                                                                                {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    char *id2=(char*)malloc(100*sizeof(char));
                    strcpy(id2,pop());
                    pop();
                    addTAC((yyvsp[-2].sval).val,id,"",id2);
                }
#line 1722 "y.tab.c"
    break;

  case 31: /* statementline: FOR for_conditionals1 DO program_declaration SEMICOLON  */
#line 287 "task5.y"
                                                                        {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("+",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
#line 1734 "y.tab.c"
    break;

  case 32: /* statementline: FOR for_conditionals2 DO program_declaration SEMICOLON  */
#line 294 "task5.y"
                                                                        {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("-",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
#line 1746 "y.tab.c"
    break;

  case 33: /* statementline: FOR for_conditionals3 DO program_declaration SEMICOLON  */
#line 301 "task5.y"
                                                                        {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("+",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
#line 1758 "y.tab.c"
    break;

  case 34: /* statementline: FOR for_conditionals4 DO program_declaration SEMICOLON  */
#line 308 "task5.y"
                                                                        {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("-",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
#line 1770 "y.tab.c"
    break;

  case 35: /* statementline: while_left DO program_declaration SEMICOLON  */
#line 315 "task5.y"
                                                             {
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
#line 1779 "y.tab.c"
    break;

  case 36: /* while_left: WHILE condition  */
#line 320 "task5.y"
                            {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp1[10];
    sprintf(temp1, "%d", lindex);
    strcat(str,temp1);
    lindex++;
    addTAC("LABEL",str,"","");
    char * str1= (char *)malloc(100*sizeof(char));
    strcpy(str1,"L");
    char temp2[10];
    sprintf(temp2,"%d",lindex);
    strcat(str1,temp2);
    lindex++;
    char * str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,"L");
    char temp3[10];
    sprintf(temp3, "%d", lindex);
    strcat(str2,temp3);
    lindex++;
    addTAC("IF",pop(),"GOTO",str1);
    push(str2);
    push(str);
    addTAC("GOTO",str2,"","");
    addTAC("LABEL",str1,"","");
    
}
#line 1811 "y.tab.c"
    break;

  case 37: /* left_if: IF condition  */
#line 348 "task5.y"
                     {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp[10];
    sprintf(temp, "%d", lindex);
    strcat(str,temp);
    lindex++;
    addTAC("IF",pop(),"GOTO",str);
    char* str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,"L");
    char temp2[10];
    sprintf(temp2, "%d", lindex);
    strcat(str2,temp2);
    addTAC("GOTO",str2,"","");
    addTAC("LABEL",str,"","");
    push(str2);
    lindex++;
    
}
#line 1835 "y.tab.c"
    break;

  case 38: /* middle_if: THEN program_declaration  */
#line 368 "task5.y"
                                   {
    addTAC("LABEL",pop(),"","");
}
#line 1843 "y.tab.c"
    break;

  case 40: /* left_array_assignment: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 374 "task5.y"
                                                                              {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp1[10];
    sprintf(temp1, "%d", lindex);
    strcat(str,temp1);
    lindex++;
    addTAC("LABEL",str,"","");
    char *id=(char*)malloc(100*sizeof(char));
    strcpy(id,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(id,temp);
    addTAC("&",(yyvsp[-3].sval).val,"",id);
    qindex++;
    char *dt=(char*)malloc(100*sizeof(char));
    strcpy(dt,"t");
    char temp2[10];
    sprintf(temp2, "%d", qindex);
    strcat(dt,temp2);
    char*typ=(char *)malloc(100*sizeof(char));
    (yyvsp[-3].sval).val=tolowercase((yyvsp[-3].sval).val);
    strcpy(typ,find_symbol((yyvsp[-3].sval).val)->type);
    char *subStr = NULL;
    char *underscorePos = strchr(typ, '_');
    subStr = underscorePos + 1;
    addTAC("sizeof",subStr,"",dt);
    qindex++;
    char *id2=(char*)malloc(100*sizeof(char));
    strcpy(id2,"t");
    char temp3[10];
    sprintf(temp3, "%d", qindex);
    strcat(id2,temp3);
    addTAC("*",dt,pop(),id2);
    qindex++;
    char *id3=(char*)malloc(100*sizeof(char));
    strcpy(id3,"t");
    char temp4[10];
    sprintf(temp4, "%d", qindex);
    strcat(id3,temp4);
    addTAC("+",id,id2,id3);
    qindex++;
    char * start=(char*)malloc(100*sizeof(char));
    strcpy(start,"*");
    strcat(start,id3);
    push(str);
    push(start);
}
#line 1896 "y.tab.c"
    break;

  case 41: /* for_conditionals1: IDENTIFIER ASSIGNMENT_OP arith_expression TO arith_expression  */
#line 423 "task5.y"
                                                                                {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp1[10];
    sprintf(temp1, "%d", lindex);
    strcat(str,temp1);
    lindex++;
    char * str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,pop());
    char * str1=(char *)malloc(100*sizeof(char));
    strcpy(str1,pop());
    addTAC((yyvsp[-3].sval).val,str1,"",(yyvsp[-4].sval).val);
    addTAC("LABEL",str,"","");
    char* cond=(char *)malloc(100*sizeof(char));
    strcpy(cond,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(cond,temp);
    addTAC(">",(yyvsp[-4].sval).val,str2,cond);
    qindex++;
    char* str3=(char *)malloc(100*sizeof(char));
    strcpy(str3,"L");
    char temp2[10];
    sprintf(temp2, "%d", lindex);
    strcat(str3,temp2);
    addTAC("IF",cond,"GOTO",str3);
    push(str3);
    push(str);
    push((yyvsp[-4].sval).val);
    lindex++;
}
#line 1932 "y.tab.c"
    break;

  case 42: /* for_conditionals2: IDENTIFIER ASSIGNMENT_OP arith_expression DOWNTO arith_expression  */
#line 455 "task5.y"
                                                                                    {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp1[10];
    sprintf(temp1, "%d", lindex);
    strcat(str,temp1);
    lindex++;
    char * str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,pop());
    char * str1=(char *)malloc(100*sizeof(char));
    strcpy(str1,pop());
    addTAC((yyvsp[-3].sval).val,str1,"",(yyvsp[-4].sval).val);
    addTAC("LABEL",str,"","");
    char* cond=(char *)malloc(100*sizeof(char));
    strcpy(cond,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(cond,temp);
    addTAC("<",(yyvsp[-4].sval).val,str2,cond);
    qindex++;
    char* str3=(char *)malloc(100*sizeof(char));
    strcpy(str3,"L");
    char temp2[10];
    sprintf(temp2, "%d", lindex);
    strcat(str3,temp2);
    addTAC("IF",cond,"GOTO",str3);
    push(str3);
    push(str);
    push((yyvsp[-4].sval).val);
    lindex++;
}
#line 1968 "y.tab.c"
    break;

  case 43: /* for_conditionals3: left_array_assignment ASSIGNMENT_OP arith_expression TO arith_expression  */
#line 487 "task5.y"
                                                                                           {
    char * str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,pop());
    char * str1=(char *)malloc(100*sizeof(char));
    strcpy(str1,pop());
    char* str4=(char *)malloc(100*sizeof(char));
    strcpy(str4,pop());
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,pop());
    addTAC((yyvsp[-3].sval).val,str1,"",str4);
    char* cond=(char *)malloc(100*sizeof(char));
    strcpy(cond,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(cond,temp);
    addTAC(">=",str4,str2,cond);
    qindex++;
    char* str3=(char *)malloc(100*sizeof(char));
    strcpy(str3,"L");
    char temp2[10];
    sprintf(temp2, "%d", lindex);
    strcat(str3,temp2);
    addTAC("IF",cond,"GOTO",str3);
    push(str3);
    push(str);
    push(str4);
    lindex++;
}
#line 2001 "y.tab.c"
    break;

  case 44: /* for_conditionals4: left_array_assignment ASSIGNMENT_OP arith_expression DOWNTO arith_expression  */
#line 516 "task5.y"
                                                                                               {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp1[10];
    sprintf(temp1, "%d", lindex);
    strcat(str,temp1);
    lindex++;
    addTAC("LABEL",str,"","");
    char * str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,pop());
    char * str1=(char *)malloc(100*sizeof(char));
    strcpy(str1,pop());
    char* str4=(char *)malloc(100*sizeof(char));
    strcpy(str4,pop());
    addTAC((yyvsp[-3].sval).val,str1,"",str4);
    char* cond=(char *)malloc(100*sizeof(char));
    strcpy(cond,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(cond,temp);
    addTAC("<=",str4,str2,cond);
    qindex++;
    char* str3=(char *)malloc(100*sizeof(char));
    strcpy(str3,"L");
    char temp2[10];
    sprintf(temp2, "%d", lindex);
    strcat(str3,temp2);
    addTAC("IF",cond,"GOTO",str3);
    push(str3);
    push(str);
    push(str1);
    lindex++;
}
#line 2039 "y.tab.c"
    break;

  case 49: /* conditionals: relational_exp BOOLEAN_OP conditionals  */
#line 556 "task5.y"
                                                        {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    (yyvsp[-1].sval).val=tolowercase((yyvsp[-1].sval).val);
                    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
#line 2055 "y.tab.c"
    break;

  case 50: /* conditionals: relational_exp BOOLEAN_OP unit  */
#line 567 "task5.y"
                                                 {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    (yyvsp[-1].sval).val=tolowercase((yyvsp[-1].sval).val);
                    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
#line 2071 "y.tab.c"
    break;

  case 51: /* conditionals: unit BOOLEAN_OP conditionals  */
#line 578 "task5.y"
                                              {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    (yyvsp[-1].sval).val=tolowercase((yyvsp[-1].sval).val);
                    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
#line 2087 "y.tab.c"
    break;

  case 52: /* conditionals: unit BOOLEAN_OP unit  */
#line 589 "task5.y"
                                       {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    (yyvsp[-1].sval).val=tolowercase((yyvsp[-1].sval).val);
                    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
#line 2103 "y.tab.c"
    break;

  case 53: /* conditionals: BOOLEAN_OP_NOT conditionals  */
#line 600 "task5.y"
                                              {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    (yyvsp[-1].sval).val=tolowercase((yyvsp[-1].sval).val);
                    addTAC((yyvsp[-1].sval).val,pop(), "", str);
                    qindex++;
                    push(str);
                }
#line 2119 "y.tab.c"
    break;

  case 54: /* condtional_unit: BOOLEAN_OP_NOT unit  */
#line 613 "task5.y"
                                    {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(str,temp);
    (yyvsp[-1].sval).val=tolowercase((yyvsp[-1].sval).val);
    addTAC((yyvsp[-1].sval).val,pop(),"", str);
    qindex++;
    push(str);
}
#line 2135 "y.tab.c"
    break;

  case 55: /* relational_exp: arith_expression RELATIONAL_OP arith_expression  */
#line 625 "task5.y"
                                                                {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(str,temp);
    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
    qindex++;
    push(str);
    }
#line 2150 "y.tab.c"
    break;

  case 56: /* left_side_vars_write: IDENTIFIER  */
#line 636 "task5.y"
                                 {addVar((yyvsp[0].sval).val);}
#line 2156 "y.tab.c"
    break;

  case 57: /* left_side_vars_write: IDENTIFIER COMMA left_side_vars_write  */
#line 637 "task5.y"
                                                       {addVar((yyvsp[-2].sval).val);}
#line 2162 "y.tab.c"
    break;

  case 58: /* left_side_vars_write: STRING_CONSTANT  */
#line 638 "task5.y"
                                 {
                            addSC((yyvsp[0].sval).val);
                        }
#line 2170 "y.tab.c"
    break;

  case 62: /* possible_write_values: STRING_CONSTANT COMMA possible_write_values  */
#line 646 "task5.y"
                                                                     {
                            addSC((yyvsp[-2].sval).val);
                        }
#line 2178 "y.tab.c"
    break;

  case 63: /* possible_write_values: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 649 "task5.y"
                                                                                 {pop();}
#line 2184 "y.tab.c"
    break;

  case 64: /* possible_reads: IDENTIFIER  */
#line 651 "task5.y"
                           {
                    read_table->isArrayEl=0;
                    strcpy(read_table->var,(yyvsp[0].sval).val);

                }
#line 2194 "y.tab.c"
    break;

  case 65: /* possible_reads: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 656 "task5.y"
                                                                        {
                    
                    char* indices=(char*)malloc(100*sizeof(char));
                    strcpy(indices,pop());
                    char* id=(char*)malloc(100*sizeof(char));
                    strcpy(id,(yyvsp[-3].sval).val);
                    strcat(id,"[");
                    strcat(id,indices);
                    strcat(id,"]");
                    id=tolowercase(id);
                    strcpy(read_table->var,id);
                    read_table->isArrayEl=1;
                    
                }
#line 2213 "y.tab.c"
    break;

  case 69: /* arith_expression: arith_expression ARITHEMATIC_OP_PLUS arith_expression  */
#line 675 "task5.y"
                                                                        { 
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
                    qindex++;
                    push(str);}
#line 2227 "y.tab.c"
    break;

  case 70: /* arith_expression: arith_expression ARITHEMATIC_OP_MINUS arith_expression  */
#line 684 "task5.y"
                                                                        {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
#line 2242 "y.tab.c"
    break;

  case 71: /* arith_expression: arith_expression ARITHEMATIC_OP_MUL arith_expression  */
#line 694 "task5.y"
                                                                      {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
#line 2257 "y.tab.c"
    break;

  case 72: /* arith_expression: arith_expression ARITHEMATIC_OP_DIV arith_expression  */
#line 704 "task5.y"
                                                                      {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
#line 2272 "y.tab.c"
    break;

  case 73: /* arith_expression: arith_expression ARITHEMATIC_OP_MOD arith_expression  */
#line 714 "task5.y"
                                                                       {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
#line 2287 "y.tab.c"
    break;

  case 74: /* unit: IDENTIFIER  */
#line 726 "task5.y"
                 {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%s",(yyvsp[0].sval).val);
            push(str);
    }
#line 2297 "y.tab.c"
    break;

  case 75: /* unit: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 731 "task5.y"
                                                             {
            char *id=(char*)malloc(100*sizeof(char));
            strcpy(id,"t");
            char temp[10];
            sprintf(temp, "%d", qindex);
            strcat(id,temp);
            addTAC("&",(yyvsp[-3].sval).val,"",id);
            qindex++;
            char *dt=(char*)malloc(100*sizeof(char));
            strcpy(dt,"t");
            char temp2[10];
            sprintf(temp2, "%d", qindex);
            strcat(dt,temp2);
            char*typ=(char *)malloc(100*sizeof(char));
            (yyvsp[-3].sval).val=tolowercase((yyvsp[-3].sval).val);
            strcpy(typ,find_symbol((yyvsp[-3].sval).val)->type);
            char *subStr = NULL;
            char *underscorePos = strchr(typ, '_');
            subStr = underscorePos + 1;
            addTAC("sizeof",subStr,"",dt);
            qindex++;
            char *id2=(char*)malloc(100*sizeof(char));
            strcpy(id2,"t");
            char temp3[10];
            sprintf(temp3, "%d", qindex);
            strcat(id2,temp3);
            addTAC("*",dt,pop(),id2);
            qindex++;
            char *id3=(char*)malloc(100*sizeof(char));
            strcpy(id3,"t");
            char temp4[10];
            sprintf(temp4, "%d", qindex);
            strcat(id3,temp4);
            addTAC("+",id,id2,id3);
            qindex++;
            char * start=(char*)malloc(100*sizeof(char));
            strcpy(start,"*");
            strcat(start,id3);
            push(start);
        }
#line 2342 "y.tab.c"
    break;

  case 76: /* unit: ARITHEMATIC_OP_MINUS arith_expression  */
#line 772 "task5.y"
                                           {
            char * str=(char *)malloc(100*sizeof(char));
            strcpy(str,"t");
            char temp[10];
            sprintf(temp, "%d", qindex);
            strcat(str,temp);
            addTAC((yyvsp[-1].sval).val,pop(), "", str);
            qindex++;
            push(str);
    }
#line 2357 "y.tab.c"
    break;

  case 77: /* unit_2: INTEGER_CONSTANT  */
#line 783 "task5.y"
                         {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%d",(yyvsp[0].ival).val);
            push(str);
    }
#line 2367 "y.tab.c"
    break;

  case 78: /* unit_2: FLOAT_CONSTANT  */
#line 788 "task5.y"
                     {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%f",(yyvsp[0].dval).val);
            push(str);
    }
#line 2377 "y.tab.c"
    break;

  case 79: /* unit_2: CHAR_CONSTANT  */
#line 793 "task5.y"
                    {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%s",(yyvsp[0].sval).val);
            push(str);
    }
#line 2387 "y.tab.c"
    break;


#line 2391 "y.tab.c"

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

#line 799 "task5.y"


void add_symbol(const char* name, const char* type) {
    symbol* new_symbol = (symbol*)malloc(sizeof(symbol));
    strcpy(new_symbol->name, name);
    strcpy(new_symbol->type, type);
    new_symbol->next = symbol_table;
    symbol_table = new_symbol;
}

symbol* find_symbol(const char* name) {
    symbol* current = symbol_table;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printTable() {
    symbol* current = symbol_table;
    printf("\n\n\tSymbol Table\n");
    printf("--------------------------------------------------------\n\n");
    printf("Name\t\t\tType\t\t\tValue\n");
    while (current != NULL) {
        char * str=(char*)malloc(100*sizeof(char));
        if(strcmp(current->type,"ARRAY_INTEGER")==0 || strcmp(current->type,"ARRAY_REAL")==0 || strcmp(current->type,"ARRAY_BOOLEAN")==0 || strcmp(current->type,"ARRAY_CHAR")==0){
            
            strcpy(str,"[");
            array_vals* current_val=current->vals;
            while(current_val!=NULL){
                strcat(str,current_val->val);
                current_val=current_val->next;
                if(current_val!=NULL){
                    strcat(str,",");
                }
            }
            strcat(str,"]");
        }else{
            strcpy(str,current->value);
        }
        printf("%s\t\t\t%s\t\t\t%s\n", current->name, current->type,str);
        current = current->next;
    }
}

char * tolowercase(char *s){
    for(int i=0;i<strlen(s);i++){
        s[i]=tolower(s[i]);
    }
    return s;
}


void addTAC(const char* op, const char* arg1, const char* arg2, const char* result) {
    TAC* new_tac = (TAC*)malloc(sizeof(TAC));
    strcpy(new_tac->op, op);
    strcpy(new_tac->arg1, arg1);
    strcpy(new_tac->arg2, arg2);
    strcpy(new_tac->result, result);
    new_tac->next = TAC_table;
    TAC_table = new_tac;
}

void printTAC() {
    TAC* current = TAC_table;
    printf("\n\nThree Address Code\n");
    printf("Op\tArg1\tArg2\tResult\n");
    while (current != NULL) {
        printf("%s\t%s\t%s\t%s\n", current->op, current->arg1, current->arg2, current->result);
        current = current->next;
    }
}

void reverseTAC() {
    TAC* current = TAC_table;
    TAC* prev = NULL;
    TAC* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    TAC_table = prev;
}

void printFormatted(){
    TAC* current=TAC_table;
    printf("\n\nIntermediate Code:\n\n");
    while(current!=NULL){
        if(strcmp(current->op,"LABEL")==0){
            printf("%s:\n",current->arg1);
        }else if(strcmp(current->op,"GOTO")==0){
            printf("GOTO %s\n",current->arg1);
        }else if(strcmp(current->op,"IF")==0){
            printf("%s %s %s %s\n",current->op,current->arg1,current->arg2,current->result);
        }else if(strcmp(current->op,":=")==0){
            printf("%s = %s\n",current->result,current->arg1);
        }else if(strcmp(current->op,"sizeof")==0){
            printf("%s = sizeof(%s)\n",current->result,current->arg1);
        }else if(strcmp(current->op,"&")==0){
            printf("%s = &%s\n",current->result,current->arg1);
        }else{
            printf("%s = %s %s %s\n",current->result,current->arg1,current->op,current->arg2);
        }
        current=current->next;
    }
}

void push(char* data){
    stack* new_stack = (stack*)malloc(sizeof(stack));
    new_stack->data = data;
    new_stack->next = top;
    top = new_stack;
}

char* pop(){
    if(top == NULL){
        return NULL;
    }
    stack* temp = top;
    top = top->next;
    return temp->data;
}

void initialiseWriteTableElement(){
    wt* new_wt = (wt*)malloc(sizeof(wt));
    new_wt->sc = NULL;
    new_wt->var = NULL;
    new_wt->order= (char*)malloc(100*sizeof(char));
    new_wt->next = write_table;
    write_table = new_wt;
}

void initialiseReadTableElement(){
    rt* new_rt = (rt*)malloc(sizeof(rt));
    new_rt->var = (char*)malloc(100*sizeof(char));
    new_rt->next = read_table;
    read_table = new_rt;
}


void addSC(const char* str){
    sc* new_sc = (sc*)malloc(sizeof(sc));
    new_sc->sc=(char*)malloc(100*sizeof(char));
    strcpy(new_sc->sc,str);
    new_sc->next = write_table->sc;
    strcat(write_table->order,"s");
    write_table->sc = new_sc;
}

void addVar(const char* v){
    var* new_var = (var*)malloc(sizeof(var));
    new_var->var=(char*)malloc(100*sizeof(char));
    strcpy(new_var->var ,v);
    new_var->next = write_table->var;
    strcat(write_table->order,"v");
    write_table->var = new_var;
}

void printWriteTable(){
    wt* current = write_table;
    printf("\n\nWrite Table\n");
    printf("Order\tString Constants\tVariables\n");
    while (current != NULL) {
        printf("%s\t", current->order);
        sc* sc_current = current->sc;
        while (sc_current != NULL) {
            printf("%s ", sc_current->sc);
            sc_current = sc_current->next;
        }
        printf("\t");
        var* var_current = current->var;
        while (var_current != NULL) {
            printf("%s ", var_current->var);
            var_current = var_current->next;
        }
        printf("\n");
        current = current->next;
    }
}

void addTemp(const char* name, const char* typ, const char* val) {
    temp* new_temp = (temp*)malloc(sizeof(temp));
    temp* current = temp_table;
    while (current != NULL) {
        if (strcmp(current->temp, name) == 0) {
            strcpy(current->value, val);
            return;
        }
        current = current->next;
    }
    if (!new_temp) {
        fprintf(stderr, "Memory allocation failed for new_temp.\n");
        return;
    }

    strcpy(new_temp->temp, name);
    strcpy(new_temp->type, typ);
    strcpy(new_temp->value, val);

    if (!temp_table) { // If the list is empty, set the new node as the head
        temp_table = new_temp;
        new_temp->next = NULL;
    } else {
        // Insert at the end of the list
        temp* current = temp_table;
        while (current->next) { // Traverse to the end of the list
            current = current->next;
        }
        current->next = new_temp;
        new_temp->next = NULL;
    }
}

TAC* findLabelLocation(char* label){
    TAC* current = TAC_table;
    while (current != NULL) {
        if (strcmp(current->op, "LABEL") == 0 && strcmp(current->arg1, label) == 0) {
            break;
        }
        current = current->next;
    }
    return current;
}

void reverseWrite(){
    wt* current = write_table;
    wt* prev = NULL;
    wt* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    write_table = prev;
}

void reverseRead(){
    rt* current = read_table;
    rt* prev = NULL;
    rt* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    read_table = prev;
}

void executeRead(int d){
    int counter=1;
    rt* current = read_table;
    while(counter!=d){
        current=current->next;
        counter++;
    }
    char* var_current = (char *)malloc(100*sizeof(char));
    strcpy(var_current,current->var);
    
    var_current=tolowercase(var_current);
    char* str=(char*)malloc(100*sizeof(char));
    if(current->isArrayEl==0){
        if(strcmp(find_symbol(var_current)->type,"INTEGER")==0){
                        int x;
                        scanf("%d",&x);
                        sprintf(str,"%d",x);        
        }else if(strcmp(find_symbol(var_current)->type,"REAL")==0){
            float x;
            scanf("%f",&x);
            sprintf(str,"%f",x);
        }else if(strcmp(find_symbol(var_current)->type,"CHAR")==0){
            char x;
            scanf("%c",&x);
            sprintf(str,"%c",x);
        }
    strcpy(find_symbol(var_current)->value,str);
    addTemp(var_current,find_symbol(var_current)->type,str);
    }else{
        int bp;
        char* result=(char*)malloc(100*sizeof(char));
        for(int i=0;i<strlen(var_current);i++){
            if(var_current[i]=='['){
                bp=i;
                break;
            }
            result[i]=var_current[i];
        }
        if(strcmp(find_symbol(result)->type,"ARRAY_INTEGER")==0){
            int x;
            scanf("%d",&x);
            sprintf(str,"%d",x);        
        }else if(strcmp(find_symbol(result)->type,"ARRAY_REAL")==0){
            float x;
            scanf("%f",&x);
            sprintf(str,"%f",x);
        }else if(strcmp(find_symbol(result)->type,"ARRAY_CHAR")==0){
            char x;
            scanf("%c",&x);
            sprintf(str,"%c",x);
        }
        char* ind=(char*)malloc(100*sizeof(char));
        for(int i=bp+1;i<strlen(var_current);i++){
            if(var_current[i]==']'){
                break;
            }
            ind[i-bp-1]=var_current[i];
        }
        int x;
        if(findTemp(ind)==NULL){
            x=atoi(ind);
        }else{
            x=atoi(findTemp(ind)->value);
        }
        int counter=1;
        array_vals* current_val = find_symbol(result)->vals;
        while(current!=NULL){
            if(counter==x){
                strcpy(current_val->val,str);
                break;
            }
            current_val=current_val->next;
            counter++;
        }
    }
    

}

temp* findTemp(const char* name){
    temp* current = temp_table;
    while (current != NULL) {
        if (strcmp(current->temp, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int ifFloat(char* str){
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='.'){
            return 1;
        }
    }
    return 0;
}

void executeWrite(int x){
    // setSymbolTable();
    int counter=1;
    wt* current = write_table;
    while(counter!=x){
        current=current->next;
        counter++;
    }
    sc* sc_current = current->sc;
    var* var_current = current->var;
    for(int i=0;i<strlen(current->order);i++){
        if(current->order[i]=='s'){
            printf("%s\n",sc_current->sc);
            sc_current=sc_current->next;
        }else{
            printf("%s\n",findTemp(var_current->var)->value);
            var_current=var_current->next;
        }
    }
}

void printTempTable(){
    temp* current = temp_table;
    printf("\n\nTemporary Variables Table\n");
    printf("Temp\tType\tValue\n");
    while (current != NULL) {
        printf("%s\t%s\t%s\n", current->temp, current->type, current->value);
        current = current->next;
    }
}

void setSymbolTable(){
    symbol* current = symbol_table;
    while(current!=NULL){
        if(findTemp(current->name)==NULL){
            
        }else{
            strcpy(current->value,findTemp(current->name)->value);
        }
        current=current->next;
    }
}

array_vals* createNewArrayValNode() {
    array_vals* new_node = (array_vals*)malloc(sizeof(array_vals));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed for array_vals node.\n");
        exit(EXIT_FAILURE); // Handle memory allocation failure
    }
    new_node->val = (char*)malloc(100 * sizeof(char)); // Initialize with a default size
    if (new_node->val == NULL) {
        fprintf(stderr, "Memory allocation failed for array_vals->val.\n");
        exit(EXIT_FAILURE); // Handle memory allocation failure
    }
    strcpy(new_node->val, "undefined"); // Set a default value
    new_node->next = NULL;
    return new_node;
}

void initialiseArrayValsList(int x,symbol* sym){
    if(x==0){
        return;
    }
    sym->vals = createNewArrayValNode();
    array_vals* current = sym->vals;

    // Loop to create and link the rest of the nodes
    for (int i = 1; i < x; i++) {
        current->next = createNewArrayValNode(); // Create and link a new node
        current = current->next; // Move to the next node
    }

}

void parseTAC(){
    reverseTAC();
    // printTAC();
    reverseWrite();
    reverseRead();
    printf("\nCode Output:\n\n");

    TAC *current = TAC_table;
    while(current!=NULL){
        if(strcmp(current->op,"GOTO")==0){
            current=findLabelLocation(current->arg1);
        }else if(strcmp(current->op,"IF")==0){
            if(strcmp(findTemp(current->arg1)->value,"0")==1){
                current=findLabelLocation(current->result);
            }
        }else if(strcmp(current->op,":=")==0){
            if(current->arg1[0]!='t'){
                if (strlen(current->arg1)==3 && (current->arg1[0]=='\'' && current->arg1[2]=='\'')){
                    addTemp(current->result,"CHAR",current->arg1);
                }else if(ifFloat(current->arg1)){
                    addTemp(current->result,"REAL",current->arg1);
                }else if(find_symbol(current->arg1)==NULL){
                    addTemp(current->result,"INTEGER",current->arg1);
                }else{
                    addTemp(current->result,findTemp(current->arg1)->type,findTemp(current->arg1)->value);
                }   
            }else{
                addTemp(current->result,findTemp(current->arg1)->type,findTemp(current->arg1)->value);
            }                                                                                                                                                                                                  
        }else if(strcmp(current->op,"+")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    if(ifFloat(current->arg1) || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)+atof(current->arg2));
                        addTemp(current->result,"REAL",temp);    
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)+atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)+atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)+atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)+atof(current->arg2));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)+atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)+atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)+atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)+atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)+atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)+atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)+atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)+atof(current->arg2));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)+atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)+atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)+atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else{
                if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(findTemp(current->arg1)->value)+atof(findTemp(current->arg2)->value));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)+atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }
        }else if(strcmp(current->op,"-")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    if(ifFloat(current->arg1) || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)-atof(current->arg2));
                        addTemp(current->result,"REAL",temp);    
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)-atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)-atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)-atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)-atof(current->arg2));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)-atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)-atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)-atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)-atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)-atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)-atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)-atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)-atof(current->arg2));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)-atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)-atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)-atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else{
                if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(findTemp(current->arg1)->value)-atof(findTemp(current->arg2)->value));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)-atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }
        }else if(strcmp(current->op,"*")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    if(ifFloat(current->arg1) || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)*atof(current->arg2));
                        addTemp(current->result,"REAL",temp);    
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)*atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)*atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)*atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)*atof(current->arg2));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)*atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)*atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)*atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)*atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)*atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)*atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)*atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)*atof(current->arg2));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)*atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)*atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)*atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else{
                if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(findTemp(current->arg1)->value)*atof(findTemp(current->arg2)->value));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)*atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }
        }else if(strcmp(current->op,"/")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    if(ifFloat(current->arg1) || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)/atof(current->arg2));
                        addTemp(current->result,"REAL",temp);    
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)/atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)/atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)/atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)/atof(current->arg2));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)/atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)/atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)/atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(current->arg1)/atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(current->arg1)/atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)/atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)/atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)/atof(current->arg2));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)/atoi(current->arg2));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }else{
                    if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%f",atof(findTemp(current->arg1)->value)/atof(findTemp(current->arg2)->value));
                        addTemp(current->result,"REAL",temp);
                    }else{
                        char* temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)/atoi(findTemp(current->arg2)->value));
                        addTemp(current->result,"INTEGER",temp);
                    }
                }
            }else{
                if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(findTemp(current->arg1)->value)/atof(findTemp(current->arg2)->value));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)/atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }

        }else if(strcmp(current->op,"%")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(current->arg1)%atoi(current->arg2));
                    addTemp(current->result,"INTEGER",temp);
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(current->arg1)%atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)%atoi(current->arg2));
                    addTemp(current->result,"INTEGER",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)%atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(current->arg1)%atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)%atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)%atoi(current->arg2));
                    addTemp(current->result,"INTEGER",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)%atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else{
                char* temp=(char*)malloc(100*sizeof(char));
                sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)%atoi(findTemp(current->arg2)->value));
                addTemp(current->result,"INTEGER",temp);
            }
        }else if(strcmp(current->op,"<>")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    if(atof(current->arg1)!=atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    if(atof(current->arg1)!=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)!=atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)!=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    if(atof(current->arg1)!=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(current->arg1)!=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)!=atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)!=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else{
                if(atof(findTemp(current->arg1)->value)!=atof(findTemp(current->arg2)->value)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }
        }else if(strcmp(current->op,"<")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    if(atof(current->arg1)<atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    if(atof(current->arg1)<atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)<atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)<atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    if(atof(current->arg1)<atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(current->arg1)<atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)<atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)<atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else{
                if(atof(findTemp(current->arg1)->value)<atof(findTemp(current->arg2)->value)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }
                
        }else if(strcmp(current->op,">")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    if(atof(current->arg1)>atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    if(atof(current->arg1)>atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)>atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)>atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    if(atof(current->arg1)>atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(current->arg1)>atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)>atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)>atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else{
                if(atof(findTemp(current->arg1)->value)>atof(findTemp(current->arg2)->value)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }
        }else if(strcmp(current->op,"<=")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    if(atof(current->arg1)<=atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    if(atof(current->arg1)<=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)<=atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)<=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    if(atof(current->arg1)<=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(current->arg1)<=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)<=atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)<=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else{
                if(atof(findTemp(current->arg1)->value)<=atof(findTemp(current->arg2)->value)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }
        }else if(strcmp(current->op,">=")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    if(atof(current->arg1)>=atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    if(atof(current->arg1)>=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)>=atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)>=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    if(atof(current->arg1)>=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(current->arg1)>=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)>=atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)>=atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else{
                if(atof(findTemp(current->arg1)->value)>=atof(findTemp(current->arg2)->value)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }
        }else if(strcmp(current->op,"=")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg1)==NULL && findTemp(current->arg2)==NULL){
                    if(atof(current->arg1)==atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)==NULL && findTemp(current->arg2)!=NULL){
                    if(atof(current->arg1)==atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else if(findTemp(current->arg1)!=NULL && findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)==atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)==atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(findTemp(current->arg1)==NULL){
                    if(atof(current->arg1)==atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(current->arg1)==atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(findTemp(current->arg2)==NULL){
                    if(atof(findTemp(current->arg1)->value)==atof(current->arg2)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }else{
                    if(atof(findTemp(current->arg1)->value)==atof(findTemp(current->arg2)->value)){
                        addTemp(current->result,"BOOLEAN","1");
                    }else{
                        addTemp(current->result,"BOOLEAN","0");
                    }
                }
            }else{
                if(atof(findTemp(current->arg1)->value)==atof(findTemp(current->arg2)->value)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }
        }else if(strcmp(current->op,"and")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(atoi(current->arg1) && atoi(current->arg2)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(atoi(current->arg1) && atoi(findTemp(current->arg2)->value)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(atoi(findTemp(current->arg1)->value) && atoi(current->arg2)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }else{
                if(atoi(findTemp(current->arg1)->value) && atoi(findTemp(current->arg2)->value)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }
        }else if(strcmp(current->op,"or")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(atoi(current->arg1) || atoi(current->arg2)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(atoi(current->arg1) || atoi(findTemp(current->arg2)->value)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(atoi(findTemp(current->arg1)->value) || atoi(current->arg2)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }else{
                if(atoi(findTemp(current->arg1)->value) || atoi(findTemp(current->arg2)->value)){
                    addTemp(current->result,"BOOLEAN","1");
                }else{
                    addTemp(current->result,"BOOLEAN","0");
                }
            }
        }else if(strcmp(current->op,"not")==0){
            if(current->arg1[0]!='t'){
                if(atoi(current->arg1)){
                    addTemp(current->result,"BOOLEAN","0");
                }else{
                    addTemp(current->result,"BOOLEAN","1");
                }
            }else{
                if(atoi(findTemp(current->arg1)->value)){
                    addTemp(current->result,"BOOLEAN","0");
                }else{
                    addTemp(current->result,"BOOLEAN","1");
                }
            }
        }else if(strcmp(current->op,"WRITE")==0){
            executeWrite(atoi(current->arg1));
        }else if(strcmp(current->op,"READ")==0){
            executeRead(atoi(current->arg1));
        }
        current=current->next;
    }
}



int main(int argc, char *argv[]){
    char* filename;
    filename=argv[1];
    yyin=fopen(filename, "r");
    yyparse();
    return 0;
}

int yyerror(){
    printf("Syntax Error\n\n");
    return 0;
}
