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
#line 1 "task4.y"

# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern FILE *yyin;
int yylex();
int yyerror();


typedef struct symbol {
    char name[100];
    char type[100];
    int value;
    struct symbol* next;
} symbol;

symbol* symbol_table = NULL;


void add_symbol(const char*, const char*);
symbol* find_symbol(const char*);
char * tolowercase(char *);
void printTable();
void reverseTAC();

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


void addTAC(const char*, const char*, const char*, const char*);
void printTAC();
void push(char*);
char* pop();
void printFormatted();



#line 127 "y.tab.c"

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
#line 57 "task4.y"

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

#line 285 "y.tab.c"

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
  YYSYMBOL_while_left = 57,                /* while_left  */
  YYSYMBOL_left_if = 58,                   /* left_if  */
  YYSYMBOL_middle_if = 59,                 /* middle_if  */
  YYSYMBOL_right_if = 60,                  /* right_if  */
  YYSYMBOL_left_array_assignment = 61,     /* left_array_assignment  */
  YYSYMBOL_for_conditionals1 = 62,         /* for_conditionals1  */
  YYSYMBOL_for_conditionals2 = 63,         /* for_conditionals2  */
  YYSYMBOL_for_conditionals3 = 64,         /* for_conditionals3  */
  YYSYMBOL_for_conditionals4 = 65,         /* for_conditionals4  */
  YYSYMBOL_condition = 66,                 /* condition  */
  YYSYMBOL_conditionals = 67,              /* conditionals  */
  YYSYMBOL_condtional_unit = 68,           /* condtional_unit  */
  YYSYMBOL_relational_exp = 69,            /* relational_exp  */
  YYSYMBOL_left_side_vars_write = 70,      /* left_side_vars_write  */
  YYSYMBOL_possible_writes = 71,           /* possible_writes  */
  YYSYMBOL_possible_write_values = 72,     /* possible_write_values  */
  YYSYMBOL_possible_reads = 73,            /* possible_reads  */
  YYSYMBOL_arith_expression = 74,          /* arith_expression  */
  YYSYMBOL_unit = 75,                      /* unit  */
  YYSYMBOL_unit_2 = 76                     /* unit_2  */
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
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

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
       0,    91,    91,    97,    98,    99,   100,   102,   103,   109,
     116,   117,   126,   135,   144,   155,   163,   171,   179,   189,
     190,   192,   193,   195,   196,   197,   200,   208,   209,   210,
     217,   224,   231,   238,   243,   271,   291,   295,   297,   346,
     380,   413,   442,   476,   477,   480,   481,   482,   492,   502,
     512,   522,   534,   545,   556,   557,   558,   560,   561,   563,
     564,   565,   567,   568,   571,   572,   573,   574,   583,   593,
     603,   613,   625,   630,   671,   682,   687,   692
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
  "datatype", "program_declaration", "statements", "statementline",
  "while_left", "left_if", "middle_if", "right_if",
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

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,    16,     7,     2,   -52,   -15,    31,    25,    22,   -52,
      31,    32,    80,    27,    31,   -52,    52,    26,    10,    10,
      66,   -52,    34,    40,    55,    94,    59,    69,    89,   -52,
     -52,   -52,   -52,   -52,   -52,    68,    90,   -52,    51,    51,
      79,    10,   -52,    51,   -52,   -52,    51,   -52,   -52,   -52,
     113,   185,    -5,   -52,   -52,    54,   120,    96,   103,   110,
     111,    14,   137,   -52,   -52,    25,    25,     4,    51,   121,
     -52,   163,   -52,   101,    51,   -52,    -3,    -4,    62,    10,
      51,    51,    51,    51,    51,    51,    10,    51,    51,    25,
      25,    25,    25,    48,   102,   -52,   105,   -52,   109,   108,
     128,   -52,   -52,    25,   129,   174,   115,   -52,   -52,   112,
     -52,   -52,    47,   192,    -4,   -52,   -52,    -4,   -52,   -52,
      53,   142,   149,   131,   143,   144,   146,    92,    51,    14,
     147,    51,   152,   -52,   -52,   -52,   -52,   164,   -52,    51,
      51,    51,    51,   -52,   -52,   -52,   -52,   134,   -52,   -52,
     119,   -52,   -52,   130,   -52,   150,   192,   192,   192,   192,
     -52,   -52,   159,   208,   -52,   -52,   -52,   -52
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     8,     3,
       5,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    21,     0,     0,     0,     2,
       9,    15,    16,    17,    18,     0,     0,    10,     0,     0,
      72,     0,    77,     0,    75,    76,     0,    35,    43,    45,
      46,     0,    65,    64,    34,     0,     0,     0,     0,     0,
       0,    58,     0,    19,    22,     0,     0,     0,     0,     0,
       7,     0,    65,     0,     0,    51,    65,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    56,    59,     0,    57,    62,     0,
       0,    36,    28,     0,     0,     0,     0,    25,    38,     0,
      66,    47,    65,    53,    67,    70,    69,    68,    71,    49,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    37,    27,    26,     0,    73,     0,
       0,     0,     0,    29,    30,    31,    32,    54,    56,    55,
       0,    60,    23,     0,    24,     0,    40,    39,    42,    41,
      61,    63,     0,     0,    11,    12,    13,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   -52,   176,   -52,   170,   -52,   -52,   -51,   171,
     -52,   -52,   -52,   -52,   -52,   175,   -52,   -52,   -52,   -52,
     184,   -31,   -52,   -52,    77,   -52,    81,   -52,   -38,   -16,
     -52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,     9,    10,    11,    36,    37,    13,    24,
      25,    26,    27,    67,   104,    28,    57,    58,    59,    60,
      47,    48,    49,    50,    95,    96,    97,    99,    51,    72,
      53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,    73,    52,    52,    86,    77,    86,     4,    78,     1,
      75,    82,    83,    40,   100,   101,    85,    93,    94,     3,
      41,     6,   -44,    42,   -52,    76,     5,    43,   102,   103,
     105,    44,    45,   -44,     8,   -52,   109,    38,   123,   124,
     125,   126,   113,   114,   115,   116,   117,   118,   111,   121,
     122,    46,   134,    12,    40,   119,    86,    31,    32,    33,
      34,    14,    86,   112,    42,    87,    39,    16,    43,    55,
     120,    29,    44,    45,   -48,    61,    81,    82,    83,    84,
     -50,    62,    85,    17,    63,   -48,    65,   127,   128,    35,
     150,   -50,    46,   153,    39,   147,   148,    17,    18,    19,
      68,   156,   157,   158,   159,   110,    20,    66,    69,    21,
      22,    23,    18,    19,    70,    81,    82,    83,    84,    74,
      20,    85,    79,    89,    22,    23,    81,    82,    83,    84,
      90,    88,    85,    81,    82,    83,    84,    91,    92,    85,
      98,   129,   106,   108,    81,    82,    83,    84,   130,   131,
      85,   132,   133,   135,   138,   143,    81,    82,    83,    84,
     137,   160,    85,    81,    82,    83,    84,   144,   145,    85,
     146,   152,   161,   127,   139,   140,   154,    81,    82,    83,
      84,   141,   142,    85,    30,   155,    15,   107,    81,    82,
      83,    84,   162,   163,    85,    56,    64,    80,   136,    81,
      82,    83,    84,    54,   149,    85,    81,    82,    83,    84,
     151,     0,    85,   164,   165,   166,   167
};

static const yytype_int16 yycheck[] =
{
      38,    39,    18,    19,     9,    43,     9,     0,    46,    23,
      41,    15,    16,     3,    65,    66,    20,     3,     4,     3,
      10,    36,    27,    13,    27,    41,    24,    17,    24,    25,
      68,    21,    22,    38,     3,    38,    74,    11,    89,    90,
      91,    92,    80,    81,    82,    83,    84,    85,    79,    87,
      88,    41,   103,    28,     3,    86,     9,     5,     6,     7,
       8,    39,     9,    79,    13,    11,    40,    35,    17,     3,
      86,    44,    21,    22,    27,    41,    14,    15,    16,    17,
      27,    41,    20,     3,    29,    38,    27,    39,    40,    37,
     128,    38,    41,   131,    40,     3,     4,     3,    18,    19,
      11,   139,   140,   141,   142,    43,    26,    38,    40,    29,
      30,    31,    18,    19,    24,    14,    15,    16,    17,    40,
      26,    20,     9,    27,    30,    31,    14,    15,    16,    17,
      27,    11,    20,    14,    15,    16,    17,    27,    27,    20,
       3,    39,    21,    42,    14,    15,    16,    17,    43,    40,
      20,    43,    24,    24,    42,    24,    14,    15,    16,    17,
      45,    42,    20,    14,    15,    16,    17,    24,    24,    20,
      24,    24,    42,    39,    32,    33,    24,    14,    15,    16,
      17,    32,    33,    20,    14,    21,    10,    24,    14,    15,
      16,    17,    42,    34,    20,    20,    25,    12,    24,    14,
      15,    16,    17,    19,   127,    20,    14,    15,    16,    17,
     129,    -1,    20,     5,     6,     7,     8
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    47,     3,     0,    24,    36,    48,     3,    49,
      50,    51,    28,    54,    39,    49,    35,     3,    18,    19,
      26,    29,    30,    31,    55,    56,    57,    58,    61,    44,
      51,     5,     6,     7,     8,    37,    52,    53,    11,    40,
       3,    10,    13,    17,    21,    22,    41,    66,    67,    68,
      69,    74,    75,    76,    66,     3,    61,    62,    63,    64,
      65,    41,    41,    29,    55,    27,    38,    59,    11,    40,
      24,    74,    75,    74,    40,    67,    75,    74,    74,     9,
      12,    14,    15,    16,    17,    20,     9,    11,    11,    27,
      27,    27,    27,     3,     4,    70,    71,    72,     3,    73,
      54,    54,    24,    25,    60,    74,    21,    24,    42,    74,
      43,    67,    75,    74,    74,    74,    74,    74,    74,    67,
      75,    74,    74,    54,    54,    54,    54,    39,    40,    39,
      43,    40,    43,    24,    54,    24,    24,    45,    42,    32,
      33,    32,    33,    24,    24,    24,    24,     3,     4,    70,
      74,    72,    24,    74,    24,    21,    74,    74,    74,    74,
      42,    42,    42,    34,     5,     6,     7,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    51,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    68,    69,    70,    70,    70,    71,    71,    72,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    75,    75,    75,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     2,     0,     1,     2,     4,     1,     3,
       1,     8,     8,     8,     8,     1,     1,     1,     1,     3,
       2,     1,     2,     5,     5,     4,     4,     4,     3,     5,
       5,     5,     5,     4,     2,     2,     2,     2,     4,     5,
       5,     5,     5,     1,     1,     1,     1,     3,     3,     3,
       3,     2,     2,     3,     1,     3,     1,     1,     0,     1,
       3,     4,     1,     4,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     4,     2,     1,     1,     1
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
#line 91 "task4.y"
                                                                                    {printf("\n");
                                                                                    reverseTAC();
                                                                                    printTAC();
                                                                                    printFormatted();
                                                                                    }
#line 1468 "y.tab.c"
    break;

  case 8: /* left_side_vars: IDENTIFIER  */
#line 103 "task4.y"
                           {
                    char * temp; temp=(char*)malloc(100*sizeof(char));
                    strcpy(temp,(yyvsp[0].sval).val);
                    temp=tolowercase(temp);
                    add_symbol(temp, "undefined");
                }
#line 1479 "y.tab.c"
    break;

  case 9: /* left_side_vars: IDENTIFIER COMMA left_side_vars  */
#line 109 "task4.y"
                                                 {
                    char * temp; temp=(char*)malloc(100*sizeof(char));
                    strcpy(temp,(yyvsp[-2].sval).val);
                    temp=tolowercase(temp);
                    add_symbol(temp, "undefined");
                }
#line 1490 "y.tab.c"
    break;

  case 11: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF INTEGER  */
#line 117 "task4.y"
                                                                                                         {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_INTEGER");
                        }
                        current = current->next;
                    }
                }
#line 1504 "y.tab.c"
    break;

  case 12: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF REAL  */
#line 126 "task4.y"
                                                                                                       {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_REAL");
                        }
                        current = current->next;
                    }
                }
#line 1518 "y.tab.c"
    break;

  case 13: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF BOOLEAN  */
#line 135 "task4.y"
                                                                                                          {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_BOOLEAN");
                        }
                        current = current->next;
                    }
                }
#line 1532 "y.tab.c"
    break;

  case 14: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF CHAR  */
#line 144 "task4.y"
                                                                                                       {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_CHAR");
                        }
                        current = current->next;
                    }
                }
#line 1546 "y.tab.c"
    break;

  case 15: /* datatype: INTEGER  */
#line 155 "task4.y"
                  {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "INTEGER");
                }
                current = current->next;
            }}
#line 1559 "y.tab.c"
    break;

  case 16: /* datatype: REAL  */
#line 163 "task4.y"
              {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "REAL");
                }
                current = current->next;
            }}
#line 1572 "y.tab.c"
    break;

  case 17: /* datatype: BOOLEAN  */
#line 171 "task4.y"
                 {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "BOOLEAN");
                }
                current = current->next;
            }}
#line 1585 "y.tab.c"
    break;

  case 18: /* datatype: CHAR  */
#line 179 "task4.y"
              {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "CHAR");
                }
                current = current->next;
            }}
#line 1598 "y.tab.c"
    break;

  case 25: /* statementline: IDENTIFIER ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 197 "task4.y"
                                                                    {
                    addTAC((yyvsp[-2].sval).val,pop(), "", (yyvsp[-3].sval).val);
                }
#line 1606 "y.tab.c"
    break;

  case 26: /* statementline: left_array_assignment ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 200 "task4.y"
                                                                                {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    char *id2=(char*)malloc(100*sizeof(char));
                    strcpy(id2,pop());
                    pop();
                    addTAC((yyvsp[-2].sval).val,id,"",id2);
                }
#line 1619 "y.tab.c"
    break;

  case 29: /* statementline: FOR for_conditionals1 DO program_declaration SEMICOLON  */
#line 210 "task4.y"
                                                                        {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("+",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
#line 1631 "y.tab.c"
    break;

  case 30: /* statementline: FOR for_conditionals2 DO program_declaration SEMICOLON  */
#line 217 "task4.y"
                                                                        {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("-",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
#line 1643 "y.tab.c"
    break;

  case 31: /* statementline: FOR for_conditionals3 DO program_declaration SEMICOLON  */
#line 224 "task4.y"
                                                                        {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("+",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
#line 1655 "y.tab.c"
    break;

  case 32: /* statementline: FOR for_conditionals4 DO program_declaration SEMICOLON  */
#line 231 "task4.y"
                                                                        {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("-",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
#line 1667 "y.tab.c"
    break;

  case 33: /* statementline: while_left DO program_declaration SEMICOLON  */
#line 238 "task4.y"
                                                             {
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
#line 1676 "y.tab.c"
    break;

  case 34: /* while_left: WHILE condition  */
#line 243 "task4.y"
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
#line 1708 "y.tab.c"
    break;

  case 35: /* left_if: IF condition  */
#line 271 "task4.y"
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
#line 1732 "y.tab.c"
    break;

  case 36: /* middle_if: THEN program_declaration  */
#line 291 "task4.y"
                                   {
    addTAC("LABEL",pop(),"","");
}
#line 1740 "y.tab.c"
    break;

  case 38: /* left_array_assignment: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 297 "task4.y"
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
#line 1793 "y.tab.c"
    break;

  case 39: /* for_conditionals1: IDENTIFIER ASSIGNMENT_OP arith_expression TO arith_expression  */
#line 346 "task4.y"
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
    printf("%s\n%s\n",str,str3);
    push((yyvsp[-4].sval).val);
    lindex++;
}
#line 1831 "y.tab.c"
    break;

  case 40: /* for_conditionals2: IDENTIFIER ASSIGNMENT_OP arith_expression DOWNTO arith_expression  */
#line 380 "task4.y"
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
#line 1868 "y.tab.c"
    break;

  case 41: /* for_conditionals3: left_array_assignment ASSIGNMENT_OP arith_expression TO arith_expression  */
#line 413 "task4.y"
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
#line 1901 "y.tab.c"
    break;

  case 42: /* for_conditionals4: left_array_assignment ASSIGNMENT_OP arith_expression DOWNTO arith_expression  */
#line 442 "task4.y"
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
#line 1939 "y.tab.c"
    break;

  case 47: /* conditionals: relational_exp BOOLEAN_OP conditionals  */
#line 482 "task4.y"
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
#line 1954 "y.tab.c"
    break;

  case 48: /* conditionals: relational_exp BOOLEAN_OP unit  */
#line 492 "task4.y"
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
#line 1969 "y.tab.c"
    break;

  case 49: /* conditionals: unit BOOLEAN_OP conditionals  */
#line 502 "task4.y"
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
#line 1984 "y.tab.c"
    break;

  case 50: /* conditionals: unit BOOLEAN_OP unit  */
#line 512 "task4.y"
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
#line 1999 "y.tab.c"
    break;

  case 51: /* conditionals: BOOLEAN_OP_NOT conditionals  */
#line 522 "task4.y"
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
#line 2014 "y.tab.c"
    break;

  case 52: /* condtional_unit: BOOLEAN_OP_NOT unit  */
#line 534 "task4.y"
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
#line 2029 "y.tab.c"
    break;

  case 53: /* relational_exp: arith_expression RELATIONAL_OP arith_expression  */
#line 545 "task4.y"
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
#line 2044 "y.tab.c"
    break;

  case 61: /* possible_write_values: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 565 "task4.y"
                                                                                 {pop();}
#line 2050 "y.tab.c"
    break;

  case 63: /* possible_reads: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 568 "task4.y"
                                                                        {pop();}
#line 2056 "y.tab.c"
    break;

  case 67: /* arith_expression: arith_expression ARITHEMATIC_OP_PLUS arith_expression  */
#line 574 "task4.y"
                                                                        { 
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC((yyvsp[-1].sval).val,pop(), pop(), str);
                    qindex++;
                    push(str);}
#line 2070 "y.tab.c"
    break;

  case 68: /* arith_expression: arith_expression ARITHEMATIC_OP_MINUS arith_expression  */
#line 583 "task4.y"
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
#line 2085 "y.tab.c"
    break;

  case 69: /* arith_expression: arith_expression ARITHEMATIC_OP_MUL arith_expression  */
#line 593 "task4.y"
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
#line 2100 "y.tab.c"
    break;

  case 70: /* arith_expression: arith_expression ARITHEMATIC_OP_DIV arith_expression  */
#line 603 "task4.y"
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
#line 2115 "y.tab.c"
    break;

  case 71: /* arith_expression: arith_expression ARITHEMATIC_OP_MOD arith_expression  */
#line 613 "task4.y"
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
#line 2130 "y.tab.c"
    break;

  case 72: /* unit: IDENTIFIER  */
#line 625 "task4.y"
                 {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%s",(yyvsp[0].sval).val);
            push(str);
    }
#line 2140 "y.tab.c"
    break;

  case 73: /* unit: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 630 "task4.y"
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
#line 2185 "y.tab.c"
    break;

  case 74: /* unit: ARITHEMATIC_OP_MINUS arith_expression  */
#line 671 "task4.y"
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
#line 2200 "y.tab.c"
    break;

  case 75: /* unit_2: INTEGER_CONSTANT  */
#line 682 "task4.y"
                         {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%d",(yyvsp[0].ival).val);
            push(str);
    }
#line 2210 "y.tab.c"
    break;

  case 76: /* unit_2: FLOAT_CONSTANT  */
#line 687 "task4.y"
                     {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%f",(yyvsp[0].dval).val);
            push(str);
    }
#line 2220 "y.tab.c"
    break;

  case 77: /* unit_2: CHAR_CONSTANT  */
#line 692 "task4.y"
                    {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%s",(yyvsp[0].sval).val);
            push(str);
    }
#line 2230 "y.tab.c"
    break;


#line 2234 "y.tab.c"

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

#line 698 "task4.y"


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
    printf("\n\nSymbol Table\n");
    printf("Name\tType\n");
    while (current != NULL) {
        printf("%s\t%s\n", current->name, current->type);
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
    printf("\n\nThree Address Code in Quadruple Format\n");
    printf("------------------------------------------------------\n");
    printf("\nOp\t\t\tArg1\t\t\tArg2\t\t\tResult\n");
    while (current != NULL) {
        printf("%s\t\t\t%s\t\t\t%s\t\t\t%s\n", current->op, current->arg1, current->arg2, current->result);
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
    printf("\n\nIntermediate Three Address Code:\n");
    printf("----------------------------------------------------\n");
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
    printf("\n\n");
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
