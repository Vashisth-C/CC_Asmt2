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
#line 1 "task3.y"

# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern FILE *yyin;
int yylex();
int yyerror();

typedef struct node{
    char lexeme[100];
    int NumChild;
    char type[100];
    struct node **child;
} node;

typedef struct symbol {
    char name[100];
    char type[100];
    int value;
    struct symbol* next;
} symbol;

symbol* symbol_table = NULL;

struct node* make_binary_node(char*, node*, node*);
struct node* make_leaf(char* );
struct node* make_ternary_node(char* , node* , node* ,node* );
struct node* make_unary_node(char* , node* );
void AST_print(struct node* );
void writeToFile(struct node* );
void preOrderTraversal(struct node* , char* );
void add_symbol(const char*, const char*);
symbol* find_symbol(const char*);
char * tolowercase(char *);
void printTable();

typedef struct error{
    char error[100];
    struct error* next;
} error;

error* error_table = NULL;

void addError(const char*);
void printErrors();


#line 120 "y.tab.c"

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
    BOOLEAN_OP_NOT = 258,          /* BOOLEAN_OP_NOT  */
    ASSIGNMENT_OP = 259,           /* ASSIGNMENT_OP  */
    RELATIONAL_OP = 260,           /* RELATIONAL_OP  */
    ARITHEMATIC_OP_PLUS = 261,     /* ARITHEMATIC_OP_PLUS  */
    ARITHEMATIC_OP_MINUS = 262,    /* ARITHEMATIC_OP_MINUS  */
    IF = 263,                      /* IF  */
    WHILE = 264,                   /* WHILE  */
    CHAR_CONSTANT = 265,           /* CHAR_CONSTANT  */
    IDENTIFIER = 266,              /* IDENTIFIER  */
    STRING_CONSTANT = 267,         /* STRING_CONSTANT  */
    INTEGER = 268,                 /* INTEGER  */
    REAL = 269,                    /* REAL  */
    BOOLEAN = 270,                 /* BOOLEAN  */
    CHAR = 271,                    /* CHAR  */
    BOOLEAN_OP = 272,              /* BOOLEAN_OP  */
    ARITHEMATIC_OP_MUL = 273,      /* ARITHEMATIC_OP_MUL  */
    ARITHEMATIC_OP_DIV = 274,      /* ARITHEMATIC_OP_DIV  */
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
#define BOOLEAN_OP_NOT 258
#define ASSIGNMENT_OP 259
#define RELATIONAL_OP 260
#define ARITHEMATIC_OP_PLUS 261
#define ARITHEMATIC_OP_MINUS 262
#define IF 263
#define WHILE 264
#define CHAR_CONSTANT 265
#define IDENTIFIER 266
#define STRING_CONSTANT 267
#define INTEGER 268
#define REAL 269
#define BOOLEAN 270
#define CHAR 271
#define BOOLEAN_OP 272
#define ARITHEMATIC_OP_MUL 273
#define ARITHEMATIC_OP_DIV 274
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
#line 50 "task3.y"

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
    struct node* node;

#line 279 "y.tab.c"

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
  YYSYMBOL_BOOLEAN_OP_NOT = 3,             /* BOOLEAN_OP_NOT  */
  YYSYMBOL_ASSIGNMENT_OP = 4,              /* ASSIGNMENT_OP  */
  YYSYMBOL_RELATIONAL_OP = 5,              /* RELATIONAL_OP  */
  YYSYMBOL_ARITHEMATIC_OP_PLUS = 6,        /* ARITHEMATIC_OP_PLUS  */
  YYSYMBOL_ARITHEMATIC_OP_MINUS = 7,       /* ARITHEMATIC_OP_MINUS  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_CHAR_CONSTANT = 10,             /* CHAR_CONSTANT  */
  YYSYMBOL_IDENTIFIER = 11,                /* IDENTIFIER  */
  YYSYMBOL_STRING_CONSTANT = 12,           /* STRING_CONSTANT  */
  YYSYMBOL_INTEGER = 13,                   /* INTEGER  */
  YYSYMBOL_REAL = 14,                      /* REAL  */
  YYSYMBOL_BOOLEAN = 15,                   /* BOOLEAN  */
  YYSYMBOL_CHAR = 16,                      /* CHAR  */
  YYSYMBOL_BOOLEAN_OP = 17,                /* BOOLEAN_OP  */
  YYSYMBOL_ARITHEMATIC_OP_MUL = 18,        /* ARITHEMATIC_OP_MUL  */
  YYSYMBOL_ARITHEMATIC_OP_DIV = 19,        /* ARITHEMATIC_OP_DIV  */
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
  YYSYMBOL_for_conditionals1 = 57,         /* for_conditionals1  */
  YYSYMBOL_for_conditionals2 = 58,         /* for_conditionals2  */
  YYSYMBOL_for_conditionals3 = 59,         /* for_conditionals3  */
  YYSYMBOL_for_conditionals4 = 60,         /* for_conditionals4  */
  YYSYMBOL_left_array_assignment = 61,     /* left_array_assignment  */
  YYSYMBOL_condition = 62,                 /* condition  */
  YYSYMBOL_conditionals = 63,              /* conditionals  */
  YYSYMBOL_condtional_unit = 64,           /* condtional_unit  */
  YYSYMBOL_relational_exp = 65,            /* relational_exp  */
  YYSYMBOL_left_side_vars_write = 66,      /* left_side_vars_write  */
  YYSYMBOL_possible_writes = 67,           /* possible_writes  */
  YYSYMBOL_possible_write_values = 68,     /* possible_write_values  */
  YYSYMBOL_possible_reads = 69,            /* possible_reads  */
  YYSYMBOL_arith_expression = 70,          /* arith_expression  */
  YYSYMBOL_unit = 71,                      /* unit  */
  YYSYMBOL_unit_2 = 72                     /* unit_2  */
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
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
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
       0,    87,    87,   112,   113,   114,   115,   126,   128,   141,
     156,   157,   178,   199,   220,   243,   252,   261,   270,   281,
     284,   287,   288,   299,   303,   307,   328,   358,   373,   387,
     398,   409,   420,   431,   447,   467,   487,   492,   497,   525,
     527,   531,   533,   535,   545,   555,   565,   575,   588,   599,
     651,   655,   669,   684,   686,   687,   689,   690,   692,   714,
     726,   745,   746,   747,   750,   778,   806,   834,   862,   880,
     904,   939,   952,   956,   960
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
  "\"end of file\"", "error", "\"invalid token\"", "BOOLEAN_OP_NOT",
  "ASSIGNMENT_OP", "RELATIONAL_OP", "ARITHEMATIC_OP_PLUS",
  "ARITHEMATIC_OP_MINUS", "IF", "WHILE", "CHAR_CONSTANT", "IDENTIFIER",
  "STRING_CONSTANT", "INTEGER", "REAL", "BOOLEAN", "CHAR", "BOOLEAN_OP",
  "ARITHEMATIC_OP_MUL", "ARITHEMATIC_OP_DIV", "ARITHEMATIC_OP_MOD",
  "INTEGER_CONSTANT", "FLOAT_CONSTANT", "PROGRAM", "SEMICOLON", "ELSE",
  "FOR", "DO", "BEGIN_TAG", "END", "WRITE", "READ", "DOWNTO", "TO", "OF",
  "COLON", "VAR", "ARRAY", "THEN", "COMMA", "OPEN_BRACKET",
  "OPEN_PARANTHESIS", "CLOSE_BRACKET", "CLOSE_PARANTHESIS", "PERIOD",
  "RANGE_DOTS", "$accept", "start", "variable_declaration",
  "variable_list", "variable_line", "left_side_vars", "rigth_side_type",
  "datatype", "program_declaration", "statements", "statementline",
  "for_conditionals1", "for_conditionals2", "for_conditionals3",
  "for_conditionals4", "left_array_assignment", "condition",
  "conditionals", "condtional_unit", "relational_exp",
  "left_side_vars_write", "possible_writes", "possible_write_values",
  "possible_reads", "arith_expression", "unit", "unit_2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    17,    32,    12,   -66,     1,    39,    27,    22,   -66,
      39,    21,   156,     8,    39,   -66,   164,    24,    24,     7,
      66,   -66,    43,    45,    58,   180,   -66,   -66,   -66,   -66,
     -66,   -66,    48,    67,   -66,    24,   125,   -66,    50,   -66,
     -66,   131,    55,   -66,   -66,    77,   216,    -9,   -66,    70,
     125,   125,    13,    75,    84,    87,   107,   100,    -8,   119,
     -66,   -66,   110,   -66,   -66,    68,   125,   140,   -66,   125,
      90,    53,    27,    24,   125,   125,   125,   125,   125,   125,
      24,    27,   196,    56,   125,   125,    27,    27,    27,    27,
     125,   -30,    98,   -66,    96,   -66,   114,    97,   123,    60,
      63,   -66,   -66,   -12,   -66,   154,   221,   140,   140,   -66,
     -66,   -66,   -66,   157,   149,   -66,   179,   137,   103,   166,
     169,   170,   172,   143,    14,   125,    -8,   173,   125,   174,
     178,   -66,   -66,    27,   -66,   125,   125,   125,   -66,   -66,
     -66,   -66,   -66,   125,   125,   161,   -66,   -66,   106,   -66,
     -66,   109,   -66,   162,   181,   206,   221,   221,   221,   221,
     -66,   -66,   175,   -66,   -66,   104,   -66,   -66,   -66,   -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     8,     3,
       5,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    21,     2,     9,    15,    16,
      17,    18,     0,     0,    10,     0,     0,    74,    69,    72,
      73,     0,     0,    39,    41,    42,     0,    62,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      19,    22,     0,     7,    47,    62,     0,    71,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,    53,    56,     0,    54,    59,     0,     0,     0,
       0,    50,    63,     0,    43,    62,    49,    64,    65,    66,
      67,    68,    45,    62,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    28,     0,    33,     0,     0,     0,    38,    29,
      30,    31,    32,     0,     0,    51,    53,    52,     0,    57,
      23,     0,    24,     0,     0,     0,    35,    34,    37,    36,
      58,    60,     0,    27,    26,     0,    11,    12,    13,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   197,   -66,   194,   -66,   -66,   -65,   192,
     -66,   -66,   -66,   -66,   -66,   -66,   200,   -29,   -66,   188,
      95,   -66,   105,   -66,   -36,   -16,   -66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,     9,    10,    11,    33,    34,    13,    24,
      25,    53,    54,    55,    56,    57,    42,    43,    44,    45,
      93,    94,    95,    97,    46,    68,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    47,    47,    91,    92,    71,    64,   103,    80,   124,
     125,    50,   132,   133,    82,    83,   114,    84,   -40,    65,
       1,   119,   120,   121,   122,   145,   146,    35,     3,   -40,
      99,    36,     4,   100,    37,    38,     5,     6,   106,   107,
     108,   109,   110,   111,   104,    39,    40,    51,   117,   118,
       8,   112,    26,    85,   123,    12,    16,   105,    74,    75,
      76,    14,    75,    76,   113,    41,    75,    76,   154,    75,
      76,    77,    78,    79,    77,    78,    79,    52,    77,    78,
      79,    77,    78,    79,    58,    80,    59,    60,    62,   148,
      69,    63,   151,    72,    73,   -48,   102,    81,   116,   155,
     156,   157,    86,   102,    90,   131,   -48,   158,   159,    75,
      76,    87,    75,    76,    88,    75,    76,   166,   167,   168,
     169,    77,    78,    79,    77,    78,    79,    77,    78,    79,
      96,    98,    36,   101,    89,    37,    38,   126,    36,   127,
     129,    37,    38,    75,    76,   138,    39,    40,   160,    75,
      76,   161,    39,    40,   128,    77,    78,    79,    77,    78,
      79,    77,    78,    79,    17,    18,    66,    19,   130,   136,
     137,    80,    41,   134,    80,   143,   144,    28,    29,    30,
      31,   -44,    20,   135,   -46,    21,    22,    23,    17,    18,
     139,    19,   -44,   140,   141,   -46,   142,   150,   152,   153,
     124,    32,    75,    76,   162,   163,    20,    15,    27,   165,
      22,    23,    75,    76,    77,    78,    79,    61,    49,   147,
     115,    74,    75,    76,    77,    78,    79,    75,    76,    70,
     164,   149,     0,     0,    77,    78,    79,     0,     0,    77,
      78,    79
};

static const yytype_int16 yycheck[] =
{
      36,    17,    18,    11,    12,    41,    35,    72,    17,    39,
      40,     4,    24,    25,    50,    51,    81,     4,    27,    35,
      23,    86,    87,    88,    89,    11,    12,     3,    11,    38,
      66,     7,     0,    69,    10,    11,    24,    36,    74,    75,
      76,    77,    78,    79,    73,    21,    22,    40,    84,    85,
      11,    80,    44,    40,    90,    28,    35,    73,     5,     6,
       7,    39,     6,     7,    80,    41,     6,     7,   133,     6,
       7,    18,    19,    20,    18,    19,    20,    11,    18,    19,
      20,    18,    19,    20,    41,    17,    41,    29,    40,   125,
      40,    24,   128,    38,    17,    27,    43,    27,    42,   135,
     136,   137,    27,    43,     4,    42,    38,   143,   144,     6,
       7,    27,     6,     7,    27,     6,     7,    13,    14,    15,
      16,    18,    19,    20,    18,    19,    20,    18,    19,    20,
      11,    21,     7,    43,    27,    10,    11,    39,     7,    43,
      43,    10,    11,     6,     7,    42,    21,    22,    42,     6,
       7,    42,    21,    22,    40,    18,    19,    20,    18,    19,
      20,    18,    19,    20,     8,     9,    41,    11,    45,    32,
      33,    17,    41,    24,    17,    32,    33,    13,    14,    15,
      16,    27,    26,     4,    27,    29,    30,    31,     8,     9,
      24,    11,    38,    24,    24,    38,    24,    24,    24,    21,
      39,    37,     6,     7,    42,    24,    26,    10,    14,    34,
      30,    31,     6,     7,    18,    19,    20,    25,    18,   124,
      24,     5,     6,     7,    18,    19,    20,     6,     7,    41,
      24,   126,    -1,    -1,    18,    19,    20,    -1,    -1,    18,
      19,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    47,    11,     0,    24,    36,    48,    11,    49,
      50,    51,    28,    54,    39,    49,    35,     8,     9,    11,
      26,    29,    30,    31,    55,    56,    44,    51,    13,    14,
      15,    16,    37,    52,    53,     3,     7,    10,    11,    21,
      22,    41,    62,    63,    64,    65,    70,    71,    72,    62,
       4,    40,    11,    57,    58,    59,    60,    61,    41,    41,
      29,    55,    40,    24,    63,    71,    41,    70,    71,    40,
      65,    70,    38,    17,     5,     6,     7,    18,    19,    20,
      17,    27,    70,    70,     4,    40,    27,    27,    27,    27,
       4,    11,    12,    66,    67,    68,    11,    69,    21,    70,
      70,    43,    43,    54,    63,    71,    70,    70,    70,    70,
      70,    70,    63,    71,    54,    24,    42,    70,    70,    54,
      54,    54,    54,    70,    39,    40,    39,    43,    40,    43,
      45,    42,    24,    25,    24,     4,    32,    33,    42,    24,
      24,    24,    24,    32,    33,    11,    12,    66,    70,    68,
      24,    70,    24,    21,    54,    70,    70,    70,    70,    70,
      42,    42,    42,    24,    24,    34,    13,    14,    15,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    51,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    58,    59,    60,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    64,    65,
      65,    66,    66,    66,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     2,     0,     1,     2,     4,     1,     3,
       1,     8,     8,     8,     8,     1,     1,     1,     1,     3,
       2,     1,     2,     5,     5,     4,     7,     7,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     4,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     2,     3,
       3,     1,     3,     1,     1,     0,     1,     3,     4,     1,
       4,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       4,     2,     1,     1,     1
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
#line 87 "task3.y"
                                                                                    {(yyvsp[-5].node)=make_leaf("PROGRAM");
                                                                                    (yyvsp[0].node)=make_binary_node(";",(yyvsp[-2].node),(yyvsp[-1].node));
                                                                                    (yyval.node)=make_binary_node((yyvsp[-4].sval).val,(yyvsp[-5].node),(yyvsp[0].node));
                                                                                    node* t=(yyval.node);
                                                                                    add_symbol((yyvsp[-4].sval).val,"PROGRAM");
                                                                                    symbol_table->value=1;
                                                                                    while(t->child!=NULL){
                                                                                        t=t->child[t->NumChild-1];
                                                                                    }
                                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                                    t->child[0]=make_leaf(".");
                                                                                    t->NumChild++;
                                                                                    if(error_table!=NULL){
                                                                                        printf("\nRun the Python file to see AST\n\n");
                                                                                        printf("\n\n");
                                                                                        printErrors();
                                                                                    }
                                                                                    else{
                                                                                        printf("\n");
                                                                                        printf("No Errors\nRun the Python file to see AST");
                                                                                        printf("\n");
                                                                                    }
                                                                                    writeToFile((yyval.node));
                                                                                      }
#line 1480 "y.tab.c"
    break;

  case 3: /* variable_declaration: VAR variable_list  */
#line 112 "task3.y"
                                        {(yyval.node)=make_unary_node("VAR",(yyvsp[0].node));}
#line 1486 "y.tab.c"
    break;

  case 4: /* variable_declaration: %empty  */
#line 113 "task3.y"
                      {(yyval.node)=NULL;}
#line 1492 "y.tab.c"
    break;

  case 5: /* variable_list: variable_line  */
#line 114 "task3.y"
                             { (yyval.node)=(yyvsp[0].node);}
#line 1498 "y.tab.c"
    break;

  case 6: /* variable_list: variable_line variable_list  */
#line 115 "task3.y"
                                             {
                    node* ptr=(yyvsp[-1].node);
                    while(ptr->child!=NULL){
                        ptr=ptr->child[ptr->NumChild-1];
                    }
                    ptr->child=(struct node**)malloc(sizeof(struct node*));
                    ptr->child[0]=(yyvsp[0].node);
                    ptr->NumChild++;
                    (yyval.node)=(yyvsp[-1].node);
                    }
#line 1513 "y.tab.c"
    break;

  case 7: /* variable_line: left_side_vars COLON rigth_side_type SEMICOLON  */
#line 126 "task3.y"
                                                              { struct node * temp1=make_leaf(";");
                                                                (yyval.node)=make_binary_node(":",(yyvsp[-3].node),(yyvsp[-1].node));}
#line 1520 "y.tab.c"
    break;

  case 8: /* left_side_vars: IDENTIFIER  */
#line 128 "task3.y"
                           { char * temp; temp=(char*)malloc(100*sizeof(char));
                            strcpy(temp,(yyvsp[0].sval).val);
                            temp=tolowercase(temp);
                            if(find_symbol(temp)==NULL){
                                add_symbol(temp,"undefined");
                                symbol_table->value=0;
                                }
                            else{
                                char *errormsg=(char*)malloc(100*sizeof(char));
                                sprintf(errormsg,"Multiple Declarations of the variable: %s at line number: %d",(yyvsp[0].sval).val,(yyvsp[0].sval).line);
                                addError(errormsg);
                                }
                            (yyval.node)=make_leaf((yyvsp[0].sval).val);}
#line 1538 "y.tab.c"
    break;

  case 9: /* left_side_vars: IDENTIFIER COMMA left_side_vars  */
#line 141 "task3.y"
                                                 { char * temp; temp=(char*)malloc(100*sizeof(char));
                                                strcpy(temp,(yyvsp[-2].sval).val);
                                                temp=tolowercase(temp);
                                                if(find_symbol(temp)==NULL){
                                                    add_symbol(temp,"undefined");
                                                    symbol_table->value=0;
                                                    }
                                                    else{
                                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                                        sprintf(errormsg,"Multiple Declarations of the variable: %s at line number: %d",(yyvsp[-2].sval).val,(yyvsp[-2].sval).line);
                                                        addError(errormsg);
                                                    };
                                                    struct node * temp1=make_leaf((yyvsp[-2].sval).val);
                                                    (yyval.node)=make_binary_node(",",temp1,(yyvsp[0].node));}
#line 1557 "y.tab.c"
    break;

  case 10: /* rigth_side_type: datatype  */
#line 156 "task3.y"
                          { (yyval.node)=(yyvsp[0].node);}
#line 1563 "y.tab.c"
    break;

  case 11: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF INTEGER  */
#line 157 "task3.y"
                                                                                                          {
                        symbol* current = symbol_table;
                        while (current != NULL) {
                            if (strcmp(current->type, "undefined") == 0) {
                                strcpy(current->type, "ARRAY_INTEGER");
                            }
                            current = current->next;
                        }
                        (yyvsp[-7].node)= make_leaf("ARRAY");
                        (yyvsp[-6].node)=make_unary_node("l_brace",(yyvsp[-7].node));
                        char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%d",(yyvsp[-5].ival).val);
                        node* temp1=make_unary_node(temp,(yyvsp[-6].node));
                        node * sc=make_leaf(";");
                        node* dt=make_unary_node("INTEGER",sc);
                        (yyvsp[-1].node)=make_unary_node("OF",dt);
                        (yyvsp[-2].node)=make_unary_node("r_brace",(yyvsp[-1].node));
                        char* temp3; temp3=(char*)malloc(100*sizeof(char));
                        sprintf(temp3,"%d",(yyvsp[-3].ival).val);
                        node* temp2=make_unary_node(temp3,(yyvsp[-2].node));
                        (yyval.node)=make_binary_node("..",temp1,temp2);}
#line 1589 "y.tab.c"
    break;

  case 12: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF REAL  */
#line 178 "task3.y"
                                                                                                       {
                        symbol* current = symbol_table;
                        while (current != NULL) {
                            if (strcmp(current->type, "undefined") == 0) {
                                strcpy(current->type, "ARRAY_REAL");
                            }
                            current = current->next;
                        }
                        (yyvsp[-7].node)= make_leaf("ARRAY");
                        (yyvsp[-6].node)=make_unary_node("l_brace",(yyvsp[-7].node));
                        char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%d",(yyvsp[-5].ival).val);
                        node* temp1=make_unary_node(temp,(yyvsp[-6].node));
                        node * sc=make_leaf(";");
                        node* dt=make_unary_node("REAL",sc);
                        (yyvsp[-1].node)=make_unary_node("OF",dt);
                        (yyvsp[-2].node)=make_unary_node("r_brace",(yyvsp[-1].node));
                        char* temp3; temp3=(char*)malloc(100*sizeof(char));
                        sprintf(temp3,"%d",(yyvsp[-3].ival).val);
                        node* temp2=make_unary_node(temp3,(yyvsp[-2].node));
                        (yyval.node)=make_binary_node("..",temp1,temp2);}
#line 1615 "y.tab.c"
    break;

  case 13: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF BOOLEAN  */
#line 199 "task3.y"
                                                                                                          {
                        symbol* current = symbol_table;
                        while (current != NULL) {
                            if (strcmp(current->type, "undefined") == 0) {
                                strcpy(current->type, "ARRAY_BOOLEAN");
                            }
                            current = current->next;
                        }
                        (yyvsp[-7].node)= make_leaf("ARRAY");
                        (yyvsp[-6].node)=make_unary_node("l_brace",(yyvsp[-7].node));
                        char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%d",(yyvsp[-5].ival).val);
                        node* temp1=make_unary_node(temp,(yyvsp[-6].node));
                        node * sc=make_leaf(";");
                        node* dt=make_unary_node("BOOLEAN",sc);
                        (yyvsp[-1].node)=make_unary_node("OF",dt);
                        (yyvsp[-2].node)=make_unary_node("r_brace",(yyvsp[-1].node));
                        char* temp3; temp3=(char*)malloc(100*sizeof(char));
                        sprintf(temp3,"%d",(yyvsp[-3].ival).val);
                        node* temp2=make_unary_node(temp3,(yyvsp[-2].node));
                        (yyval.node)=make_binary_node("..",temp1,temp2);}
#line 1641 "y.tab.c"
    break;

  case 14: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF CHAR  */
#line 220 "task3.y"
                                                                                                       {
                        symbol* current = symbol_table;
                        while (current != NULL) {
                            if (strcmp(current->type, "undefined") == 0) {
                                strcpy(current->type, "ARRAY_CHAR");
                            }
                            current = current->next;
                        }
                        (yyvsp[-7].node)= make_leaf("ARRAY");
                        (yyvsp[-6].node)=make_unary_node("l_brace",(yyvsp[-7].node));
                        char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%d",(yyvsp[-5].ival).val);
                        node* temp1=make_unary_node(temp,(yyvsp[-6].node));
                        node * sc=make_leaf(";");
                        node* dt=make_unary_node("CHAR",sc);
                        (yyvsp[-1].node)=make_unary_node("OF",dt);
                        (yyvsp[-2].node)=make_unary_node("r_brace",(yyvsp[-1].node));
                        char* temp3; temp3=(char*)malloc(100*sizeof(char));
                        sprintf(temp3,"%d",(yyvsp[-3].ival).val);
                        node* temp2=make_unary_node(temp3,(yyvsp[-2].node));
                        (yyval.node)=make_binary_node("..",temp1,temp2);}
#line 1667 "y.tab.c"
    break;

  case 15: /* datatype: INTEGER  */
#line 243 "task3.y"
                  {struct node* temp= make_leaf(";");
                    (yyval.node)=make_unary_node("INTEGER",temp);
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0 ) {
                            strcpy(current->type, "INTEGER");
                        }
                        current = current->next;
                    }}
#line 1681 "y.tab.c"
    break;

  case 16: /* datatype: REAL  */
#line 252 "task3.y"
              {struct node* temp= make_leaf(";");
                (yyval.node)=make_unary_node("REAL",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0){
                        strcpy(current->type, "REAL");
                    }
                    current = current->next;
                }}
#line 1695 "y.tab.c"
    break;

  case 17: /* datatype: BOOLEAN  */
#line 261 "task3.y"
                 {struct node* temp= make_leaf(";");
                (yyval.node)=make_unary_node("BOOLEAN",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0) {
                        strcpy(current->type, "BOOLEAN");
                    }
                    current = current->next;
                }}
#line 1709 "y.tab.c"
    break;

  case 18: /* datatype: CHAR  */
#line 270 "task3.y"
              {struct node* temp= make_leaf(";");
                (yyval.node)=make_unary_node("CHAR",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0) {
                        strcpy(current->type, "CHAR");
                    }
                    current = current->next;
                }}
#line 1723 "y.tab.c"
    break;

  case 19: /* program_declaration: BEGIN_TAG statements END  */
#line 281 "task3.y"
                                              { struct node* temp=make_leaf("END");
                                                (yyval.node)=make_binary_node("BEGIN",(yyvsp[-1].node),temp);
                                                }
#line 1731 "y.tab.c"
    break;

  case 20: /* program_declaration: BEGIN_TAG END  */
#line 284 "task3.y"
                        { struct node* temp=make_leaf("END");
            (yyval.node)=make_unary_node("BEGIN",temp);}
#line 1738 "y.tab.c"
    break;

  case 21: /* statements: statementline  */
#line 287 "task3.y"
                          { (yyval.node)=(yyvsp[0].node);}
#line 1744 "y.tab.c"
    break;

  case 22: /* statements: statementline statements  */
#line 288 "task3.y"
                                      {
                node* ptr=(yyvsp[-1].node);
                while(ptr->child!=NULL){
                    ptr=ptr->child[ptr->NumChild-1];
                }
                ptr->child=(struct node**)malloc(sizeof(struct node*));
                ptr->child[0]=(yyvsp[0].node);
                ptr->NumChild++;
                (yyval.node)=(yyvsp[-1].node);
            }
#line 1759 "y.tab.c"
    break;

  case 23: /* statementline: WRITE OPEN_PARANTHESIS possible_writes CLOSE_PARANTHESIS SEMICOLON  */
#line 299 "task3.y"
                                                                                  { (yyvsp[-3].node)=make_leaf("(");
                                                                                    (yyvsp[0].node)=make_leaf(";");
                                                                                    (yyvsp[-1].node)=make_unary_node(")",(yyvsp[0].node));
                                                                                    (yyval.node)=make_ternary_node("WRITE",(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1768 "y.tab.c"
    break;

  case 24: /* statementline: READ OPEN_PARANTHESIS possible_reads CLOSE_PARANTHESIS SEMICOLON  */
#line 303 "task3.y"
                                                                                  { (yyvsp[-3].node)=make_leaf("(");
                                                                                    (yyvsp[0].node)=make_leaf(";");
                                                                                    (yyvsp[-1].node)=make_unary_node(")",(yyvsp[0].node));
                                                                                    (yyval.node)=make_ternary_node("READ",(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1777 "y.tab.c"
    break;

  case 25: /* statementline: IDENTIFIER ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 307 "task3.y"
                                                                     { char * x; x=(char*)malloc(100*sizeof(char));
                                                                        strcpy(x,(yyvsp[-3].sval).val);
                                                                        x=tolowercase(x);
                                                                        node* temp=make_leaf(";");
                                                                        node* temp1=make_leaf((yyvsp[-3].sval).val);
                                                                        (yyval.node)=make_ternary_node((yyvsp[-2].sval).val,temp1,(yyvsp[-1].node),temp);
                                                                        if(find_symbol(x)==NULL ){
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-3].sval).val,(yyvsp[-3].sval).line);
                                                                            addError(errormsg);
                                                                            
                                                                        }else{
                                                                            if(strcmp((yyvsp[-1].node)->type,"undefined")==0){
                                                                                
                                                                            }
                                                                            else if(strcmp(find_symbol(x)->type,(yyvsp[-1].node)->type)!=0){
                                                                                char *errormsg=(char*)malloc(100*sizeof(char));
                                                                                sprintf(errormsg,"Assignment of mismatched types at line number: %d",(yyvsp[-3].sval).line);
                                                                                addError(errormsg);}
                                                                            find_symbol(x)->value=1;}}
#line 1802 "y.tab.c"
    break;

  case 26: /* statementline: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 328 "task3.y"
                                                                                                                 {
                    char * x; x=(char*)malloc(100*sizeof(char));
                    strcpy(x,(yyvsp[-6].sval).val);
                    x=tolowercase(x);
                    if(find_symbol(x)==NULL){
                        char *errormsg=(char*)malloc(100*sizeof(char) );
                        sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-6].sval).val,(yyvsp[-6].sval).line);
                        addError(errormsg);
                    }
                    if(strcmp((yyvsp[-4].node)->type,"INTEGER")!=0){
                        char *errormsg=(char*)malloc(100*sizeof(char));
                        sprintf(errormsg,"Array Indices should be Integer at line number: %d",(yyvsp[-6].sval).line);
                        addError(errormsg);
                    }
                    char *typ=(char*)malloc(100*sizeof(char));
                    strcpy(typ,find_symbol(x)->type);
                    char *subStr = NULL;
                    char *underscorePos = strchr(typ, '_');
                    subStr = underscorePos + 1;
                    if(strcmp(subStr,(yyvsp[-1].node)->type)!=0){
                        char *errormsg=(char*)malloc(100*sizeof(char));
                        sprintf(errormsg,"Assignment of mismatched types at line number: %d",(yyvsp[-6].sval).line);
                        addError(errormsg);
                    }
                    node* temp=make_leaf(";");
                    node* temp1=make_leaf((yyvsp[-6].sval).val);
                    node* temp2=make_leaf("r_brace");
                    (yyvsp[-5].node)=make_ternary_node("l_brace",temp1,(yyvsp[-4].node),temp2);
                    (yyval.node)=make_ternary_node((yyvsp[-2].sval).val,(yyvsp[-5].node),(yyvsp[-1].node),temp);
                    find_symbol(x)->value=1;}
#line 1837 "y.tab.c"
    break;

  case 27: /* statementline: IF condition THEN program_declaration ELSE program_declaration SEMICOLON  */
#line 358 "task3.y"
                                                                                          { node* then= make_unary_node("THEN",(yyvsp[-3].node));
                                                                                        node* elset= make_unary_node("ELSE",(yyvsp[-1].node));
                                                                                        (yyval.node)=make_ternary_node("IF",(yyvsp[-5].node),then,elset);
                                                                                        node* t=(yyval.node);
                                                                                        while(t->child!=NULL){
                                                                                        t=t->child[t->NumChild-1];
                                                                                        }
                                                                                        t->child=(struct node**)malloc(sizeof(struct node*));
                                                                                        t->child[0]=make_leaf(";");
                                                                                        t->NumChild++;
                                                                                        if(strcmp((yyvsp[-5].node)->type,"BOOLEAN")!=0){
                                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                                            sprintf(errormsg,"If-condition should be boolean at line number: %d",(yyvsp[-6].sval).line);
                                                                                            addError(errormsg);
                                                                                        }}
#line 1857 "y.tab.c"
    break;

  case 28: /* statementline: IF condition THEN program_declaration SEMICOLON  */
#line 373 "task3.y"
                                                                 { node* then= make_unary_node("THEN",(yyvsp[-1].node));
                                                                    (yyval.node)=make_binary_node("IF",(yyvsp[-3].node),then);
                                                                    node* t=(yyval.node);
                                                                    while(t->child!=NULL){
                                                                        t=t->child[t->NumChild-1];
                                                                    }
                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                    t->child[0]=make_leaf(";");
                                                                    t->NumChild++;
                                                                    if(strcmp((yyvsp[-3].node)->type,"BOOLEAN")!=0){
                                                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                                                        sprintf(errormsg,"If-condition should be boolean at line number: %d",(yyvsp[-4].sval).line);
                                                                        addError(errormsg);
                                                                    }}
#line 1876 "y.tab.c"
    break;

  case 29: /* statementline: FOR for_conditionals1 DO program_declaration SEMICOLON  */
#line 387 "task3.y"
                                                                        {
                    node* dotemp=make_unary_node("DO",(yyvsp[-1].node));
                    (yyval.node)=make_binary_node("FOR",(yyvsp[-3].node),dotemp);
                    node* t=(yyval.node);
                    while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
#line 1892 "y.tab.c"
    break;

  case 30: /* statementline: FOR for_conditionals2 DO program_declaration SEMICOLON  */
#line 398 "task3.y"
                                                                        {
                    node* dotemp=make_unary_node("DO",(yyvsp[-1].node));
                    (yyval.node)=make_binary_node("FOR",(yyvsp[-3].node),dotemp);
                    node* t=(yyval.node);
                    while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
#line 1908 "y.tab.c"
    break;

  case 31: /* statementline: FOR for_conditionals3 DO program_declaration SEMICOLON  */
#line 409 "task3.y"
                                                                        {
                    node* dotemp=make_unary_node("DO",(yyvsp[-1].node));
                    (yyval.node)=make_binary_node("FOR",(yyvsp[-3].node),dotemp);
                    node* t=(yyval.node);
                    while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
#line 1924 "y.tab.c"
    break;

  case 32: /* statementline: FOR for_conditionals4 DO program_declaration SEMICOLON  */
#line 420 "task3.y"
                                                                         {
                    node* dotemp=make_unary_node("DO",(yyvsp[-1].node));
                    (yyval.node)=make_binary_node("FOR",(yyvsp[-3].node),dotemp);
                    node* t=(yyval.node);
                    while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
#line 1940 "y.tab.c"
    break;

  case 33: /* statementline: WHILE condition DO program_declaration SEMICOLON  */
#line 431 "task3.y"
                                                                  { node* temp=make_unary_node("DO",(yyvsp[-1].node));
                                                                    (yyval.node)=make_binary_node("WHILE",(yyvsp[-3].node),temp);
                                                                    node* t=(yyval.node);
                                                                     while(t->child!=NULL){
                                                                        t=t->child[t->NumChild-1];
                                                                    }
                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                    t->child[0]=make_leaf(";");
                                                                    t->NumChild++;
                                                                    if(strcmp((yyvsp[-3].node)->type,"BOOLEAN")!=0){
                                                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                                                        sprintf(errormsg,"While-condition should be boolean at line number: %d",(yyvsp[-4].sval).line);
                                                                        addError(errormsg);
                                                                    }
                                                                    }
#line 1960 "y.tab.c"
    break;

  case 34: /* for_conditionals1: IDENTIFIER ASSIGNMENT_OP arith_expression TO arith_expression  */
#line 447 "task3.y"
                                                                                {
    char * x; x=(char*)malloc(100*sizeof(char));
    strcpy(x,(yyvsp[-4].sval).val);
    x=tolowercase(x);
    if(find_symbol(x)==NULL){
        char *errormsg=(char*)malloc(100*sizeof(char));
        sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-4].sval).val,(yyvsp[-4].sval).line);
        addError(errormsg);
    }
    else if(!(strcmp(find_symbol(x)->type,"INTEGER")==0 && strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0)){
        char *errormsg=(char*)malloc(100*sizeof(char));
        sprintf(errormsg,"For loop variables and constraints should be integer at line number: %d",(yyvsp[-4].sval).line);
        addError(errormsg);
    }
    find_symbol(x)->value=1;
    node * temp=make_leaf((yyvsp[-4].sval).val);
    node * temp1=make_binary_node("TO",(yyvsp[-2].node),(yyvsp[0].node));
    (yyval.node)=make_binary_node(":=",temp,temp1);
}
#line 1984 "y.tab.c"
    break;

  case 35: /* for_conditionals2: IDENTIFIER ASSIGNMENT_OP arith_expression DOWNTO arith_expression  */
#line 467 "task3.y"
                                                                                    {
    char * x; x=(char*)malloc(100*sizeof(char));
    strcpy(x,(yyvsp[-4].sval).val);
    x=tolowercase(x);
    if(find_symbol(x)==NULL){
        char *errormsg=(char*)malloc(100*sizeof(char));
        sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-4].sval).val,(yyvsp[-4].sval).line);
        addError(errormsg);
    }
    if(!(strcmp(find_symbol(x)->type,"INTEGER")==0 && strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0)){
        char *errormsg=(char*)malloc(100*sizeof(char));
        sprintf(errormsg,"For loop variables and constraints should be integer at line number: %d",(yyvsp[-4].sval).line);
        addError(errormsg);
    }
    find_symbol(x)->value=1;
    node * temp=make_leaf((yyvsp[-4].sval).val);
    node * temp1=make_binary_node("DOWNTO",(yyvsp[-2].node),(yyvsp[0].node));
    (yyval.node)=make_binary_node(":=",temp,temp1);
}
#line 2008 "y.tab.c"
    break;

  case 36: /* for_conditionals3: left_array_assignment ASSIGNMENT_OP arith_expression TO arith_expression  */
#line 487 "task3.y"
                                                                                           {
    node * temp1=make_binary_node("TO",(yyvsp[-2].node),(yyvsp[0].node));
   (yyval.node)=make_binary_node((yyvsp[-3].sval).val,(yyvsp[-4].node),temp1);
}
#line 2017 "y.tab.c"
    break;

  case 37: /* for_conditionals4: left_array_assignment ASSIGNMENT_OP arith_expression DOWNTO arith_expression  */
#line 492 "task3.y"
                                                                                               {
    node * temp1=make_binary_node("DOWNTO",(yyvsp[-2].node),(yyvsp[0].node));
   (yyval.node)=make_binary_node((yyvsp[-3].sval).val,(yyvsp[-4].node),temp1);
}
#line 2026 "y.tab.c"
    break;

  case 38: /* left_array_assignment: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 497 "task3.y"
                                                                              {
    char * x; x=(char*)malloc(100*sizeof(char));
    strcpy(x,(yyvsp[-3].sval).val);
    x=tolowercase(x);
    node* temp=make_leaf((yyvsp[-3].sval).val);
    (yyvsp[0].node)=make_leaf("r_brace");
    (yyval.node)=make_ternary_node("l_brace",temp,(yyvsp[-1].node),(yyvsp[0].node));
    if(find_symbol(x)==NULL || strcmp(find_symbol(x)->type,"undefined")==0){
        char *errormsg=(char*)malloc(100*sizeof(char) );
        sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-3].sval).val,(yyvsp[-3].sval).line);
        addError(errormsg);
    }
    else{
        char *typ=(char*)malloc(100*sizeof(char));
        strcpy(typ,find_symbol(x)->type);
        char *subStr = NULL;
        char *underscorePos = strchr(typ, '_');
        subStr = underscorePos + 1;
        strcpy((yyval.node)->type,subStr);
        find_symbol(x)->value=1;
    }
    if(strcmp((yyvsp[-1].node)->type,"INTEGER")!=0){
        char *errormsg=(char*)malloc(100*sizeof(char));
        sprintf(errormsg,"Array Indices should be Integer at line number: %d",(yyvsp[-3].sval).line);
        addError(errormsg);
    }
    }
#line 2058 "y.tab.c"
    break;

  case 39: /* condition: conditionals  */
#line 525 "task3.y"
                       {(yyval.node)=(yyvsp[0].node);
                            strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 2065 "y.tab.c"
    break;

  case 40: /* condition: unit  */
#line 527 "task3.y"
                  {(yyval.node)=(yyvsp[0].node);
                   strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 2072 "y.tab.c"
    break;

  case 41: /* conditionals: condtional_unit  */
#line 531 "task3.y"
                                {(yyval.node)=(yyvsp[0].node);
                                strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 2079 "y.tab.c"
    break;

  case 42: /* conditionals: relational_exp  */
#line 533 "task3.y"
                                {(yyval.node)=(yyvsp[0].node); 
                                strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 2086 "y.tab.c"
    break;

  case 43: /* conditionals: relational_exp BOOLEAN_OP conditionals  */
#line 535 "task3.y"
                                                        { (yyval.node)=make_binary_node((yyvsp[-1].sval).val,(yyvsp[-2].node),(yyvsp[0].node));
                                                            if(strcmp((yyvsp[-2].node)->type,"BOOLEAN")==0 && strcmp((yyvsp[0].node)->type,"BOOLEAN")==0){
                                                                strcpy((yyval.node)->type,"BOOLEAN");
                                                            }
                                                            else{
                                                                char *errormsg=(char*)malloc(100*sizeof(char));
                                                                sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                                addError(errormsg);
                                                                strcpy((yyval.node)->type,"BOOLEAN");
                                                            }}
#line 2101 "y.tab.c"
    break;

  case 44: /* conditionals: relational_exp BOOLEAN_OP unit  */
#line 545 "task3.y"
                                                 { (yyval.node)=make_binary_node((yyvsp[-1].sval).val,(yyvsp[-2].node),(yyvsp[0].node));
                                                    if(strcmp((yyvsp[-2].node)->type,"BOOLEAN")==0 && strcmp((yyvsp[0].node)->type,"BOOLEAN")==0){
                                                        strcpy((yyval.node)->type,"BOOLEAN");
                                                    }
                                                    else{
                                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                                        sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                        addError(errormsg);
                                                        strcpy((yyval.node)->type,"BOOLEAN");
                                                    }}
#line 2116 "y.tab.c"
    break;

  case 45: /* conditionals: unit BOOLEAN_OP conditionals  */
#line 555 "task3.y"
                                               { (yyval.node)=make_binary_node((yyvsp[-1].sval).val,(yyvsp[-2].node),(yyvsp[0].node));
                                                if(strcmp((yyvsp[-2].node)->type,"BOOLEAN")==0 && strcmp((yyvsp[0].node)->type,"BOOLEAN")==0){
                                                    strcpy((yyval.node)->type,"BOOLEAN");
                                                }
                                                else{
                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                    sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                    addError(errormsg);
                                                    strcpy((yyval.node)->type,"BOOLEAN");
                                                }}
#line 2131 "y.tab.c"
    break;

  case 46: /* conditionals: unit BOOLEAN_OP unit  */
#line 565 "task3.y"
                                        { (yyval.node)=make_binary_node((yyvsp[-1].sval).val,(yyvsp[-2].node),(yyvsp[0].node));
                                        if(strcmp((yyvsp[-2].node)->type,"BOOLEAN")==0 && strcmp((yyvsp[0].node)->type,"BOOLEAN")==0){
                                            strcpy((yyval.node)->type,"BOOLEAN");
                                        }
                                        else{
                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                            sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                            addError(errormsg);
                                            strcpy((yyval.node)->type,"BOOLEAN");
                                        }}
#line 2146 "y.tab.c"
    break;

  case 47: /* conditionals: BOOLEAN_OP_NOT conditionals  */
#line 575 "task3.y"
                                              { (yyval.node)=make_unary_node((yyvsp[-1].sval).val,(yyvsp[0].node));
                                                if(strcmp((yyvsp[0].node)->type,"BOOLEAN")==0){
                                                    strcpy((yyval.node)->type,"BOOLEAN");
                                                }
                                                else{
                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                    sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                    addError(errormsg);
                                                    strcpy((yyval.node)->type,"BOOLEAN");
                                                }}
#line 2161 "y.tab.c"
    break;

  case 48: /* condtional_unit: BOOLEAN_OP_NOT unit  */
#line 588 "task3.y"
                                    {(yyval.node)=make_unary_node((yyvsp[-1].sval).val,(yyvsp[0].node));
                                    if(strcmp((yyvsp[0].node)->type,"BOOLEAN")==0){
                                        strcpy((yyval.node)->type,"BOOLEAN");
                                    }
                                    else{
                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                        sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                        addError(errormsg);
                                        strcpy((yyval.node)->type,"BOOLEAN");
                                    }}
#line 2176 "y.tab.c"
    break;

  case 49: /* relational_exp: arith_expression RELATIONAL_OP arith_expression  */
#line 599 "task3.y"
                                                                { (yyval.node)=make_binary_node((yyvsp[-1].sval).val,(yyvsp[-2].node),(yyvsp[0].node));

                                                                    if(strcmp((yyvsp[-1].sval).val,"<>")==0 || strcmp((yyvsp[-1].sval).val,"=")==0){
                                                                        if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"CHAR")==0 && strcmp((yyvsp[0].node)->type,"CHAR")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"BOOLEAN")==0 && strcmp((yyvsp[0].node)->type,"BOOLEAN")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"ARRAY_INTEGER")==0 && strcmp((yyvsp[0].node)->type,"ARRAY_INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"ARRAY_REAL")==0 && strcmp((yyvsp[0].node)->type,"ARRAY_REAL")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");}
                                                                        else if(strcmp((yyvsp[-2].node)->type,"ARRAY_BOOLEAN")==0 && strcmp((yyvsp[0].node)->type,"ARRAY_BOOLEAN")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");}
                                                                        else if(strcmp((yyvsp[-2].node)->type,"ARRAY_CHAR")==0 && strcmp((yyvsp[0].node)->type,"ARRAY_CHAR")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");}
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                                            addError(errormsg);
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }
                                                                    }else{
                                                                        if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                                            addError(errormsg);
                                                                            strcpy((yyval.node)->type,"BOOLEAN");
                                                                        }
                                                                    }}
#line 2233 "y.tab.c"
    break;

  case 50: /* relational_exp: OPEN_PARANTHESIS relational_exp CLOSE_PARANTHESIS  */
#line 651 "task3.y"
                                                                   {node * temp=make_leaf(")");
                                                                    (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);
                                                                    strcpy((yyval.node)->type,(yyvsp[-1].node)->type);}
#line 2241 "y.tab.c"
    break;

  case 51: /* left_side_vars_write: IDENTIFIER  */
#line 655 "task3.y"
                                 {char * temp; temp=(char*)malloc(100*sizeof(char));
                                    strcpy(temp,(yyvsp[0].sval).val);
                                    temp=tolowercase(temp);
                                    if(find_symbol(temp)==NULL || strcmp(find_symbol(temp)->type,"undefined")==0){
                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                        sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[0].sval).val,(yyvsp[0].sval).line);
                                        addError(errormsg);
                                    }
                                    else if(find_symbol(temp)->value==0){
                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                        sprintf(errormsg,"Variable not initialized: %s at line number: %d",(yyvsp[0].sval).val,(yyvsp[0].sval).line);
                                        addError(errormsg);
                                    }
                                (yyval.node)=make_leaf((yyvsp[0].sval).val);}
#line 2260 "y.tab.c"
    break;

  case 52: /* left_side_vars_write: IDENTIFIER COMMA left_side_vars_write  */
#line 669 "task3.y"
                                                       { char * temp; temp=(char*)malloc(100*sizeof(char));
                                                strcpy(temp,(yyvsp[-2].sval).val);
                                                temp=tolowercase(temp);
                                                if(find_symbol(temp)==NULL){
                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                    sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-2].sval).val,(yyvsp[-2].sval).line);
                                                    addError(errormsg);
                                                }
                                                else if(find_symbol(temp)->value==0){
                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                    sprintf(errormsg,"Variable not initialized: %s at line number: %d",(yyvsp[-2].sval).val,(yyvsp[-2].sval).line);
                                                    addError(errormsg);
                                                }
                                                struct node * temp1=make_leaf((yyvsp[-2].sval).val);
                                                (yyval.node)=make_binary_node(",",temp1,(yyvsp[0].node));}
#line 2280 "y.tab.c"
    break;

  case 53: /* left_side_vars_write: STRING_CONSTANT  */
#line 684 "task3.y"
                                 { (yyval.node)=make_leaf((yyvsp[0].sval).val);}
#line 2286 "y.tab.c"
    break;

  case 54: /* possible_writes: possible_write_values  */
#line 686 "task3.y"
                                       { (yyval.node)=(yyvsp[0].node);}
#line 2292 "y.tab.c"
    break;

  case 55: /* possible_writes: %empty  */
#line 687 "task3.y"
      {(yyval.node)=NULL;}
#line 2298 "y.tab.c"
    break;

  case 56: /* possible_write_values: left_side_vars_write  */
#line 689 "task3.y"
                                            {(yyval.node)=(yyvsp[0].node);}
#line 2304 "y.tab.c"
    break;

  case 57: /* possible_write_values: STRING_CONSTANT COMMA possible_write_values  */
#line 690 "task3.y"
                                                                     {node* temp=make_leaf((yyvsp[-2].sval).val);
                                                                        (yyval.node)=make_binary_node(",",temp,(yyvsp[0].node));}
#line 2311 "y.tab.c"
    break;

  case 58: /* possible_write_values: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 692 "task3.y"
                                                                                 {char * x; x=(char*)malloc(100*sizeof(char));
                                                                                strcpy(x,(yyvsp[-3].sval).val);
                                                                                x=tolowercase(x);
                                                                                if(find_symbol(x)==NULL){
                                                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                                                    sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-3].sval).val,(yyvsp[-3].sval).line);
                                                                                    addError(errormsg);
                                                                                }
                                                                                else if(find_symbol(x)->value==0){
                                                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                                                    sprintf(errormsg,"Variable not initialized: %s at line number: %d",(yyvsp[-3].sval).val,(yyvsp[-3].sval).line);
                                                                                    addError(errormsg);
                                                                                }
                                                                                if(strcmp((yyvsp[-1].node)->type,"INTEGER")!=0){
                                                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                                                    sprintf(errormsg,"Array Indices should be Integer at line number: %d",(yyvsp[-3].sval).line);
                                                                                    addError(errormsg);
                                                                                }
                                                                                node* temp=make_leaf((yyvsp[-3].sval).val);
                                                                                (yyvsp[0].node)=make_leaf("r_brace");
                                                                                (yyval.node)=make_ternary_node("l_brace",temp,(yyvsp[-2].node),(yyvsp[-1].node));}
#line 2337 "y.tab.c"
    break;

  case 59: /* possible_reads: IDENTIFIER  */
#line 714 "task3.y"
                           {char * temp; temp=(char*)malloc(100*sizeof(char));
                            strcpy(temp,(yyvsp[0].sval).val);
                            temp=tolowercase(temp);
                            if(find_symbol(temp)==NULL){
                                char *errormsg=(char*)malloc(100*sizeof(char));
                                sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[0].sval).val,(yyvsp[0].sval).line);
                                addError(errormsg);
                            }else{
                                find_symbol(temp)->value=1;
                            }
                            printf("Value of %s: \n",temp);
                            (yyval.node)=make_leaf((yyvsp[0].sval).val);}
#line 2354 "y.tab.c"
    break;

  case 60: /* possible_reads: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 726 "task3.y"
                                                                        {char * x; x=(char*)malloc(100*sizeof(char));
                                                                        strcpy(x,(yyvsp[-3].sval).val);
                                                                        x=tolowercase(x);
                                                                        if(find_symbol(x)==NULL){
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-3].sval).val,(yyvsp[-3].sval).line);
                                                                            addError(errormsg);   
                                                                        }
                                                                        find_symbol(x)->value=1;
                                                                        node* temp=make_leaf((yyvsp[-3].sval).val);
                                                                        (yyvsp[0].node)=make_leaf("r_brace");
                                                                        (yyval.node)=make_ternary_node("l_brace",temp,(yyvsp[-1].node),(yyvsp[0].node));
                                                                        if(strcmp((yyvsp[-1].node)->type,"INTEGER")!=0){
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Array Indices should be Integer at line number: %d",(yyvsp[-3].sval).line);
                                                                            addError(errormsg);
                                                                        }}
#line 2376 "y.tab.c"
    break;

  case 61: /* arith_expression: unit_2  */
#line 745 "task3.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2382 "y.tab.c"
    break;

  case 62: /* arith_expression: unit  */
#line 746 "task3.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2388 "y.tab.c"
    break;

  case 63: /* arith_expression: OPEN_PARANTHESIS arith_expression CLOSE_PARANTHESIS  */
#line 747 "task3.y"
                                                                      {node * temp=make_leaf(")");
                                                                        (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);
                                                                        strcpy((yyval.node)->type,(yyvsp[-1].node)->type);}
#line 2396 "y.tab.c"
    break;

  case 64: /* arith_expression: arith_expression ARITHEMATIC_OP_PLUS arith_expression  */
#line 750 "task3.y"
                                                                        { (yyval.node)=make_binary_node((yyvsp[-1].sval).val,(yyvsp[-2].node),(yyvsp[0].node));
                                                                    if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                        strcpy((yyval.node)->type,"INTEGER");
                                                                    }
                                                                    else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                        strcpy((yyval.node)->type,"REAL");
                                                                    }
                                                                    else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                        strcpy((yyval.node)->type,"REAL");
                                                                    }
                                                                    else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                        strcpy((yyval.node)->type,"REAL");
                                                                    }else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                        strcpy((yyval.node)->type,"INTEGER");
                                                                    }else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                        strcpy((yyval.node)->type,"REAL");
                                                                    }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                        strcpy((yyval.node)->type,"INTEGER");
                                                                    }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                        strcpy((yyval.node)->type,"REAL");
                                                                    }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                        strcpy((yyval.node)->type,"undefined");
                                                                    }
                                                                    else{
                                                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                                                        sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                                        addError(errormsg);
                                                                    }}
#line 2429 "y.tab.c"
    break;

  case 65: /* arith_expression: arith_expression ARITHEMATIC_OP_MINUS arith_expression  */
#line 778 "task3.y"
                                                                         { (yyval.node)=make_binary_node("-",(yyvsp[-2].node),(yyvsp[0].node));
                                                                            if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"INTEGER");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"INTEGER");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"INTEGER");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"undefined");
                                                                        }
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                                            addError(errormsg);
                                                                        }}
#line 2462 "y.tab.c"
    break;

  case 66: /* arith_expression: arith_expression ARITHEMATIC_OP_MUL arith_expression  */
#line 806 "task3.y"
                                                                       { (yyval.node)=make_binary_node("*",(yyvsp[-2].node),(yyvsp[0].node));
                                                                        if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"INTEGER");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"INTEGER");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"INTEGER");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"undefined");
                                                                        }
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                                            addError(errormsg);
                                                                        }}
#line 2495 "y.tab.c"
    break;

  case 67: /* arith_expression: arith_expression ARITHEMATIC_OP_DIV arith_expression  */
#line 834 "task3.y"
                                                                       { (yyval.node)=make_binary_node("/",(yyvsp[-2].node),(yyvsp[0].node));
                                                                        if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"REAL")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                                            strcpy((yyval.node)->type,"REAL");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"undefined");
                                                                        }
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                                            addError(errormsg);
                                                                        }}
#line 2528 "y.tab.c"
    break;

  case 68: /* arith_expression: arith_expression ARITHEMATIC_OP_MOD arith_expression  */
#line 862 "task3.y"
                                                                       { (yyval.node)=make_binary_node("%",(yyvsp[-2].node),(yyvsp[0].node));
                                                                        if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"INTEGER");
                                                                        }
                                                                        else if(strcmp((yyvsp[-2].node)->type,"INTEGER")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"INTEGER");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                                            strcpy((yyval.node)->type,"INTEGER");
                                                                        }else if(strcmp((yyvsp[-2].node)->type,"undefined")==0 && strcmp((yyvsp[0].node)->type,"undefined")==0){
                                                                            strcpy((yyval.node)->type,"undefined");
                                                                        }
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                                            addError(errormsg);
                                                                        }}
#line 2549 "y.tab.c"
    break;

  case 69: /* unit: IDENTIFIER  */
#line 880 "task3.y"
                 {char * temp; temp=(char*)malloc(100*sizeof(char));
                strcpy(temp,(yyvsp[0].sval).val);
                temp=tolowercase(temp);
                (yyval.node)=make_leaf((yyvsp[0].sval).val);
                if(find_symbol(temp)==NULL){
                    char *errormsg=(char*)malloc(100*sizeof(char));
                    sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[0].sval).val,(yyvsp[0].sval).line);
                    addError(errormsg);
                    strcpy((yyval.node)->type,"undefined");
                }
                else if(find_symbol(temp)->value==0){
                    char *errormsg=(char*)malloc(100*sizeof(char));
                    sprintf(errormsg,"Variable not initialized: %s at line number: %d",(yyvsp[0].sval).val,(yyvsp[0].sval).line);
                    addError(errormsg);
                    char *typ=(char*)malloc(100*sizeof(char));
                    strcpy(typ,find_symbol(temp)->type);
                    strcpy((yyval.node)->type,typ);
                }else{
                    char *typ=(char*)malloc(100*sizeof(char));
                    strcpy(typ,find_symbol(temp)->type);
                    strcpy((yyval.node)->type,typ);}
                }
#line 2576 "y.tab.c"
    break;

  case 70: /* unit: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 904 "task3.y"
                                                             {char * x; x=(char*)malloc(100*sizeof(char));
                                                            strcpy(x,(yyvsp[-3].sval).val);
                                                            x=tolowercase(x);
                                                            node* temp=make_leaf((yyvsp[-3].sval).val);
                                                            (yyvsp[0].node)=make_leaf("r_brace");
                                                            (yyval.node)=make_ternary_node("l_brace",temp,(yyvsp[-1].node),(yyvsp[0].node));
                                                            if(find_symbol(x)==NULL){
                                                                char *errormsg=(char*)malloc(100*sizeof(char) );
                                                                sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-3].sval).val,(yyvsp[-3].sval).line);
                                                                addError(errormsg);
                                                            }
                                                            else if(find_symbol(x)->value==0){
                                                                char *errormsg=(char*)malloc(100*sizeof(char));
                                                                sprintf(errormsg,"Variable not initialized: %s at line number: %d",(yyvsp[-3].sval).val,(yyvsp[-3].sval).line);
                                                                addError(errormsg);
                                                                char *typ=(char*)malloc(100*sizeof(char));
                                                                strcpy(typ,find_symbol(x)->type);
                                                                char *subStr = NULL;
                                                                char *underscorePos = strchr(typ, '_');
                                                                subStr = underscorePos + 1;
                                                                strcpy((yyval.node)->type,subStr);
                                                            }
                                                            else{
                                                                char *typ=(char*)malloc(100*sizeof(char));
                                                                strcpy(typ,find_symbol(x)->type);
                                                                char *subStr = NULL;
                                                                char *underscorePos = strchr(typ, '_');
                                                                subStr = underscorePos + 1;
                                                                strcpy((yyval.node)->type,subStr);
                                                            }
                                                            if(strcmp((yyvsp[-1].node)->type,"INTEGER")!=0){
                                                                char *errormsg=(char*)malloc(100*sizeof(char));
                                                                sprintf(errormsg,"Array Indices should be Integer at line number: %d",(yyvsp[-3].sval).line);
                                                                addError(errormsg);
                                                            }}
#line 2616 "y.tab.c"
    break;

  case 71: /* unit: ARITHEMATIC_OP_MINUS arith_expression  */
#line 939 "task3.y"
                                           {(yyval.node)=make_unary_node("-",(yyvsp[0].node));
                                            if(strcmp((yyvsp[0].node)->type,"INTEGER")==0){
                                                strcpy((yyval.node)->type,"INTEGER");
                                            }
                                            else if(strcmp((yyvsp[0].node)->type,"REAL")==0){
                                                strcpy((yyval.node)->type,"REAL");
                                            }
                                            else{
                                                char *errormsg=(char*)malloc(100*sizeof(char));
                                                sprintf(errormsg,"Type Mismatch at line number: %d",(yyvsp[-1].sval).line);
                                                addError(errormsg);
                                            }}
#line 2633 "y.tab.c"
    break;

  case 72: /* unit_2: INTEGER_CONSTANT  */
#line 952 "task3.y"
                         { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                            sprintf(temp,"%d",(yyvsp[0].ival).val);
                            (yyval.node)=make_leaf(temp);
                            sprintf((yyval.node)->type,"INTEGER");}
#line 2642 "y.tab.c"
    break;

  case 73: /* unit_2: FLOAT_CONSTANT  */
#line 956 "task3.y"
                     { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%f",(yyvsp[0].dval).val);
                        (yyval.node)=make_leaf(temp);
                        sprintf((yyval.node)->type,"REAL");}
#line 2651 "y.tab.c"
    break;

  case 74: /* unit_2: CHAR_CONSTANT  */
#line 960 "task3.y"
                    { char * temp; temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%s",(yyvsp[0].sval).val);
                        (yyval.node)=make_leaf(temp);
                        sprintf((yyval.node)->type,"CHAR");}
#line 2660 "y.tab.c"
    break;


#line 2664 "y.tab.c"

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

#line 965 "task3.y"


struct node* make_binary_node(char* root, node* left, node* right){
    struct node* ASTnode = (struct node*)malloc(sizeof(struct node));
    ASTnode->child = (struct node**)malloc(2*sizeof(struct node *));
    ASTnode->NumChild = 2;
    strcpy(ASTnode->lexeme,root);
    ASTnode->child[0] = left;
    ASTnode->child[1] = right;
    return ASTnode;
}

struct node* make_ternary_node(char* root, node* left, node* middle, node* right){
    struct node* ASTnode = (struct node*)malloc(sizeof(struct node));
    ASTnode->child = (struct node**)malloc(3*sizeof(struct node *));
    ASTnode->NumChild = 3;
    strcpy(ASTnode->lexeme,root);
    ASTnode->child[0] = left;
    ASTnode->child[1] = middle;
    ASTnode->child[2] = right;
    return ASTnode;
}

struct node* make_unary_node(char* root, node* child){
    struct node* ASTnode = (struct node*)malloc(sizeof(struct node));
    ASTnode->child = (struct node**)malloc(sizeof(struct node *));
    ASTnode->NumChild = 1;
    strcpy(ASTnode->lexeme,root);
    ASTnode->child[0] = child;
    return ASTnode;
}

struct node* make_leaf(char* root){
	struct node* ASTnode = (struct node*)malloc(sizeof(struct node));
	strcpy(ASTnode->lexeme,root);
	ASTnode->NumChild = 0;
	ASTnode->child = NULL;
	return ASTnode;
}

void AST_print(struct node* t){
	static int ctr=0;
	int i;
	if(t->NumChild==0) 
		return;
	struct node* t2=t;
	printf("\n%s  -->",t2->lexeme);
	for(i=0;i<t2->NumChild;++i) {
        if(t2->child[i]!=NULL)
		    printf("%s ",t2->child[i]->lexeme);
	}
	for(i=0;i<t2->NumChild;++i){
        if(t->child[i]!=NULL)
		    AST_print(t->child[i]);
	}
}

void preOrderTraversal(struct node* n, char* text){
    if (n == NULL) {
        return;
    }
    strcat(text,"[");
    strcat(text, n->lexeme);
    // Recursively visit each child
    for (int i = 0; i < n->NumChild; i++) {
        preOrderTraversal(n->child[i],text);
    }
    strcat(text,"]");
}

void writeToFile(struct node* n){
    FILE *file = fopen("syntaxtree.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    char text[100000];
    preOrderTraversal(n,text);
    // Write the string to the file
    fprintf(file, "%s", text);
}

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

void addError(const char* e) {
    error* new_error = (error*)malloc(sizeof(error));
    strcpy(new_error->error, e);
    new_error->next = error_table;
    error_table = new_error;
}

void printErrors() {
    error* current = error_table;
    printf("Errors\n\n");
    while (current != NULL) {
        printf("%s\n", current->error);
        current = current->next;
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
