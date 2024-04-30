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
    ARITHEMATIC_OP = 268,          /* ARITHEMATIC_OP  */
    ARITHEMATIC_OP_MINUS = 269,    /* ARITHEMATIC_OP_MINUS  */
    IF = 270,                      /* IF  */
    WHILE = 271,                   /* WHILE  */
    INTEGER_CONSTANT = 272,        /* INTEGER_CONSTANT  */
    FLOAT_CONSTANT = 273,          /* FLOAT_CONSTANT  */
    PROGRAM = 274,                 /* PROGRAM  */
    SEMICOLON = 275,               /* SEMICOLON  */
    ELSE = 276,                    /* ELSE  */
    FOR = 277,                     /* FOR  */
    DO = 278,                      /* DO  */
    BEGIN_TAG = 279,               /* BEGIN_TAG  */
    END = 280,                     /* END  */
    WRITE = 281,                   /* WRITE  */
    READ = 282,                    /* READ  */
    DOWNTO = 283,                  /* DOWNTO  */
    TO = 284,                      /* TO  */
    OF = 285,                      /* OF  */
    COLON = 286,                   /* COLON  */
    VAR = 287,                     /* VAR  */
    ARRAY = 288,                   /* ARRAY  */
    THEN = 289,                    /* THEN  */
    COMMA = 290,                   /* COMMA  */
    OPEN_BRACKET = 291,            /* OPEN_BRACKET  */
    OPEN_PARANTHESIS = 292,        /* OPEN_PARANTHESIS  */
    CLOSE_BRACKET = 293,           /* CLOSE_BRACKET  */
    CLOSE_PARANTHESIS = 294,       /* CLOSE_PARANTHESIS  */
    PERIOD = 295,                  /* PERIOD  */
    RANGE_DOTS = 296               /* RANGE_DOTS  */
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
#define ARITHEMATIC_OP 268
#define ARITHEMATIC_OP_MINUS 269
#define IF 270
#define WHILE 271
#define INTEGER_CONSTANT 272
#define FLOAT_CONSTANT 273
#define PROGRAM 274
#define SEMICOLON 275
#define ELSE 276
#define FOR 277
#define DO 278
#define BEGIN_TAG 279
#define END 280
#define WRITE 281
#define READ 282
#define DOWNTO 283
#define TO 284
#define OF 285
#define COLON 286
#define VAR 287
#define ARRAY 288
#define THEN 289
#define COMMA 290
#define OPEN_BRACKET 291
#define OPEN_PARANTHESIS 292
#define CLOSE_BRACKET 293
#define CLOSE_PARANTHESIS 294
#define PERIOD 295
#define RANGE_DOTS 296

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

#line 271 "y.tab.c"

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
  YYSYMBOL_ARITHEMATIC_OP = 13,            /* ARITHEMATIC_OP  */
  YYSYMBOL_ARITHEMATIC_OP_MINUS = 14,      /* ARITHEMATIC_OP_MINUS  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_INTEGER_CONSTANT = 17,          /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 18,            /* FLOAT_CONSTANT  */
  YYSYMBOL_PROGRAM = 19,                   /* PROGRAM  */
  YYSYMBOL_SEMICOLON = 20,                 /* SEMICOLON  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_BEGIN_TAG = 24,                 /* BEGIN_TAG  */
  YYSYMBOL_END = 25,                       /* END  */
  YYSYMBOL_WRITE = 26,                     /* WRITE  */
  YYSYMBOL_READ = 27,                      /* READ  */
  YYSYMBOL_DOWNTO = 28,                    /* DOWNTO  */
  YYSYMBOL_TO = 29,                        /* TO  */
  YYSYMBOL_OF = 30,                        /* OF  */
  YYSYMBOL_COLON = 31,                     /* COLON  */
  YYSYMBOL_VAR = 32,                       /* VAR  */
  YYSYMBOL_ARRAY = 33,                     /* ARRAY  */
  YYSYMBOL_THEN = 34,                      /* THEN  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_OPEN_BRACKET = 36,              /* OPEN_BRACKET  */
  YYSYMBOL_OPEN_PARANTHESIS = 37,          /* OPEN_PARANTHESIS  */
  YYSYMBOL_CLOSE_BRACKET = 38,             /* CLOSE_BRACKET  */
  YYSYMBOL_CLOSE_PARANTHESIS = 39,         /* CLOSE_PARANTHESIS  */
  YYSYMBOL_PERIOD = 40,                    /* PERIOD  */
  YYSYMBOL_RANGE_DOTS = 41,                /* RANGE_DOTS  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_start = 43,                     /* start  */
  YYSYMBOL_variable_declaration = 44,      /* variable_declaration  */
  YYSYMBOL_variable_list = 45,             /* variable_list  */
  YYSYMBOL_variable_line = 46,             /* variable_line  */
  YYSYMBOL_left_side_vars = 47,            /* left_side_vars  */
  YYSYMBOL_rigth_side_type = 48,           /* rigth_side_type  */
  YYSYMBOL_datatype = 49,                  /* datatype  */
  YYSYMBOL_program_declaration = 50,       /* program_declaration  */
  YYSYMBOL_statements = 51,                /* statements  */
  YYSYMBOL_statementline = 52,             /* statementline  */
  YYSYMBOL_for_conditionals1 = 53,         /* for_conditionals1  */
  YYSYMBOL_for_conditionals2 = 54,         /* for_conditionals2  */
  YYSYMBOL_condition = 55,                 /* condition  */
  YYSYMBOL_conditional_head = 56,          /* conditional_head  */
  YYSYMBOL_conditionals = 57,              /* conditionals  */
  YYSYMBOL_condtional_unit = 58,           /* condtional_unit  */
  YYSYMBOL_relational_exp = 59,            /* relational_exp  */
  YYSYMBOL_left_side_vars_write = 60,      /* left_side_vars_write  */
  YYSYMBOL_possible_writes = 61,           /* possible_writes  */
  YYSYMBOL_possible_write_values = 62,     /* possible_write_values  */
  YYSYMBOL_possible_reads = 63,            /* possible_reads  */
  YYSYMBOL_arith_expression = 64,          /* arith_expression  */
  YYSYMBOL_unit = 65,                      /* unit  */
  YYSYMBOL_unit_2 = 66                     /* unit_2  */
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
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,   109,   110,   111,   112,   123,   125,   138,
     153,   154,   175,   196,   217,   240,   249,   258,   267,   278,
     281,   284,   285,   296,   300,   304,   321,   351,   366,   380,
     391,   402,   418,   438,   458,   460,   463,   465,   468,   470,
     480,   490,   500,   510,   520,   525,   536,   588,   592,   606,
     622,   623,   625,   626,   627,   629,   651,   663,   679,   680,
     681,   684,   712,   742,   766,   801,   814,   818
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
  "BOOLEAN_OP_NOT", "ASSIGNMENT_OP", "RELATIONAL_OP", "ARITHEMATIC_OP",
  "ARITHEMATIC_OP_MINUS", "IF", "WHILE", "INTEGER_CONSTANT",
  "FLOAT_CONSTANT", "PROGRAM", "SEMICOLON", "ELSE", "FOR", "DO",
  "BEGIN_TAG", "END", "WRITE", "READ", "DOWNTO", "TO", "OF", "COLON",
  "VAR", "ARRAY", "THEN", "COMMA", "OPEN_BRACKET", "OPEN_PARANTHESIS",
  "CLOSE_BRACKET", "CLOSE_PARANTHESIS", "PERIOD", "RANGE_DOTS", "$accept",
  "start", "variable_declaration", "variable_list", "variable_line",
  "left_side_vars", "rigth_side_type", "datatype", "program_declaration",
  "statements", "statementline", "for_conditionals1", "for_conditionals2",
  "condition", "conditional_head", "conditionals", "condtional_unit",
  "relational_exp", "left_side_vars_write", "possible_writes",
  "possible_write_values", "possible_reads", "arith_expression", "unit",
  "unit_2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,     9,    16,     2,   -73,    -8,    24,     7,    28,   -73,
      24,    13,    75,    25,    24,   -73,    53,    45,    18,    18,
      76,   -73,    50,    70,    46,    90,   -73,   -73,   -73,   -73,
     -73,   -73,    73,    62,   -73,    20,    20,    79,    18,    20,
     -73,   -73,    18,   102,   -73,   -73,   -73,   115,    61,    30,
     -73,   112,   126,   116,   117,    95,   135,   -73,   -73,   125,
     -73,    20,   100,   -73,    34,    20,   -73,   115,   114,   -73,
     104,    -6,     6,   132,     7,    18,    20,    20,    20,    18,
       7,    20,     7,     7,    68,   109,   -73,   106,   -73,   110,
     108,   107,     1,   -73,   138,    38,   -73,   -73,   -73,   101,
     -73,   114,   120,   136,   -73,   -73,   114,   131,    82,   133,
     134,   149,    20,    95,   137,    20,   139,   141,    20,   -73,
     -73,     7,   -73,    20,    20,   -73,   -73,   121,   -73,    54,
     -73,   -73,    56,   -73,   122,   105,   142,   120,   120,   -73,
     -73,   140,   -73,   -73,   124,   -73,   -73,   -73,   -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     8,     3,
       5,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    21,     2,     9,    15,    16,
      17,    18,     0,     0,    10,     0,     0,    63,     0,     0,
      66,    67,     0,     0,    34,    37,    38,    36,     0,    59,
      58,     0,     0,     0,     0,    51,     0,    19,    22,     0,
       7,     0,     0,    59,     0,     0,    43,     0,    45,    65,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    53,    52,     0,    50,    56,
       0,     0,     0,    25,     0,     0,    44,    47,    60,     0,
      39,    40,    46,    61,    62,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      28,     0,    31,     0,     0,    29,    30,    48,    49,     0,
      54,    23,     0,    24,     0,     0,     0,    33,    32,    55,
      57,     0,    26,    27,     0,    11,    12,    13,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   145,   -73,   147,   -73,   -73,   -72,   143,
     -73,   -73,   -73,   144,   -73,   -25,   -73,    66,    55,   -73,
      51,   -73,   -35,   -13,   -73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,     9,    10,    11,    33,    34,    13,    24,
      25,    53,    54,    43,    44,    45,    46,    67,    86,    87,
      88,    90,    48,    63,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    64,    99,    75,    69,    49,    49,    72,   107,     1,
     109,   110,     3,    66,    77,    78,     4,    70,    76,    77,
      78,    37,     5,    37,     6,    68,    92,     8,    38,    73,
      95,    12,    39,    97,    39,    40,    41,    40,    41,    79,
      98,   102,   103,   104,    16,    98,   108,    77,    78,   136,
     100,    77,    78,   -35,   105,    42,    35,    61,    28,    29,
      30,    31,   101,    14,   -35,    26,   106,    77,    78,    77,
      78,    57,    94,    76,    77,    78,   119,   129,    17,    52,
     132,    36,    60,   135,    47,    47,    32,    55,   137,   138,
      18,    19,   139,    17,   140,    77,    78,    20,    84,    85,
      21,    22,    23,   111,   112,    18,    19,    56,    71,    59,
     123,   124,    20,    77,    78,    65,    22,    23,    77,    78,
      93,   120,   121,    79,    75,   142,   -59,   -59,   -59,   145,
     146,   147,   148,    77,    78,    80,    74,    81,    89,    82,
      83,    79,    91,    96,   113,   114,   115,   116,   117,   118,
      78,   122,   127,   125,   126,    15,   111,   131,   134,   133,
     141,    27,   143,    51,   130,     0,   128,     0,    58,     0,
     144
};

static const yytype_int8 yycheck[] =
{
      35,    36,    74,     9,    39,    18,    19,    42,    80,    19,
      82,    83,     3,    38,    13,    14,     0,    42,    12,    13,
      14,     3,    20,     3,    32,    38,    61,     3,    10,    42,
      65,    24,    14,    39,    14,    17,    18,    17,    18,     9,
      39,    76,    77,    78,    31,    39,    81,    13,    14,   121,
      75,    13,    14,    23,    79,    37,    11,    37,     5,     6,
       7,     8,    75,    35,    34,    40,    79,    13,    14,    13,
      14,    25,    38,    12,    13,    14,    38,   112,     3,     3,
     115,    36,    20,   118,    18,    19,    33,    37,   123,   124,
      15,    16,    38,     3,    38,    13,    14,    22,     3,     4,
      25,    26,    27,    35,    36,    15,    16,    37,    42,    36,
      28,    29,    22,    13,    14,    36,    26,    27,    13,    14,
      20,    20,    21,     9,     9,    20,    12,    13,    14,     5,
       6,     7,     8,    13,    14,    23,    34,    11,     3,    23,
      23,     9,    17,    39,    35,    39,    36,    39,    41,    11,
      14,    20,     3,    20,    20,    10,    35,    20,    17,    20,
      38,    14,    20,    19,   113,    -1,   111,    -1,    25,    -1,
      30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    43,     3,     0,    20,    32,    44,     3,    45,
      46,    47,    24,    50,    35,    45,    31,     3,    15,    16,
      22,    25,    26,    27,    51,    52,    40,    47,     5,     6,
       7,     8,    33,    48,    49,    11,    36,     3,    10,    14,
      17,    18,    37,    55,    56,    57,    58,    59,    64,    65,
      66,    55,     3,    53,    54,    37,    37,    25,    51,    36,
      20,    37,    64,    65,    64,    36,    57,    59,    65,    64,
      57,    59,    64,    65,    34,     9,    12,    13,    14,     9,
      23,    11,    23,    23,     3,     4,    60,    61,    62,     3,
      63,    17,    64,    20,    38,    64,    39,    39,    39,    50,
      57,    65,    64,    64,    64,    57,    65,    50,    64,    50,
      50,    35,    36,    35,    39,    36,    39,    41,    11,    38,
      20,    21,    20,    28,    29,    20,    20,     3,    60,    64,
      62,    20,    64,    20,    17,    64,    50,    64,    64,    38,
      38,    38,    20,    20,    30,     5,     6,     7,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    47,    47,
      48,    48,    48,    48,    48,    49,    49,    49,    49,    50,
      50,    51,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    54,    55,    55,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    65,    65,    65,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     2,     0,     1,     2,     4,     1,     3,
       1,     8,     8,     8,     8,     1,     1,     1,     1,     3,
       2,     1,     2,     5,     5,     4,     7,     7,     5,     5,
       5,     5,     5,     5,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     2,     3,     2,     3,     3,     1,     3,
       1,     0,     1,     1,     3,     4,     1,     4,     1,     1,
       3,     3,     3,     1,     4,     2,     1,     1
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
#line 85 "task3.y"
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
                                                                                        printErrors();
                                                                                    }
                                                                                    else{
                                                                                        printf("Valid Input\n\n");
                                                                                        
                                                                                        printTable();
                                                                                        printf("\n");
                                                                                    }
                                                                                    writeToFile((yyval.node));
                                                                                      }
#line 1439 "y.tab.c"
    break;

  case 3: /* variable_declaration: VAR variable_list  */
#line 109 "task3.y"
                                        {(yyval.node)=make_unary_node("VAR",(yyvsp[0].node));}
#line 1445 "y.tab.c"
    break;

  case 4: /* variable_declaration: %empty  */
#line 110 "task3.y"
                      {(yyval.node)=NULL;}
#line 1451 "y.tab.c"
    break;

  case 5: /* variable_list: variable_line  */
#line 111 "task3.y"
                             { (yyval.node)=(yyvsp[0].node);}
#line 1457 "y.tab.c"
    break;

  case 6: /* variable_list: variable_line variable_list  */
#line 112 "task3.y"
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
#line 1472 "y.tab.c"
    break;

  case 7: /* variable_line: left_side_vars COLON rigth_side_type SEMICOLON  */
#line 123 "task3.y"
                                                              { struct node * temp1=make_leaf(";");
                                                                (yyval.node)=make_binary_node(":",(yyvsp[-3].node),(yyvsp[-1].node));}
#line 1479 "y.tab.c"
    break;

  case 8: /* left_side_vars: IDENTIFIER  */
#line 125 "task3.y"
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
#line 1497 "y.tab.c"
    break;

  case 9: /* left_side_vars: IDENTIFIER COMMA left_side_vars  */
#line 138 "task3.y"
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
#line 1516 "y.tab.c"
    break;

  case 10: /* rigth_side_type: datatype  */
#line 153 "task3.y"
                          { (yyval.node)=(yyvsp[0].node);}
#line 1522 "y.tab.c"
    break;

  case 11: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF INTEGER  */
#line 154 "task3.y"
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
#line 1548 "y.tab.c"
    break;

  case 12: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF REAL  */
#line 175 "task3.y"
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
#line 1574 "y.tab.c"
    break;

  case 13: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF BOOLEAN  */
#line 196 "task3.y"
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
#line 1600 "y.tab.c"
    break;

  case 14: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF CHAR  */
#line 217 "task3.y"
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
#line 1626 "y.tab.c"
    break;

  case 15: /* datatype: INTEGER  */
#line 240 "task3.y"
                  {struct node* temp= make_leaf(";");
                    (yyval.node)=make_unary_node("INTEGER",temp);
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0 ) {
                            strcpy(current->type, "INTEGER");
                        }
                        current = current->next;
                    }}
#line 1640 "y.tab.c"
    break;

  case 16: /* datatype: REAL  */
#line 249 "task3.y"
              {struct node* temp= make_leaf(";");
                (yyval.node)=make_unary_node("REAL",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0){
                        strcpy(current->type, "REAL");
                    }
                    current = current->next;
                }}
#line 1654 "y.tab.c"
    break;

  case 17: /* datatype: BOOLEAN  */
#line 258 "task3.y"
                 {struct node* temp= make_leaf(";");
                (yyval.node)=make_unary_node("BOOLEAN",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0) {
                        strcpy(current->type, "BOOLEAN");
                    }
                    current = current->next;
                }}
#line 1668 "y.tab.c"
    break;

  case 18: /* datatype: CHAR  */
#line 267 "task3.y"
              {struct node* temp= make_leaf(";");
                (yyval.node)=make_unary_node("CHAR",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0) {
                        strcpy(current->type, "CHAR");
                    }
                    current = current->next;
                }}
#line 1682 "y.tab.c"
    break;

  case 19: /* program_declaration: BEGIN_TAG statements END  */
#line 278 "task3.y"
                                              { struct node* temp=make_leaf("END");
                                                (yyval.node)=make_binary_node("BEGIN",(yyvsp[-1].node),temp);
                                                }
#line 1690 "y.tab.c"
    break;

  case 20: /* program_declaration: BEGIN_TAG END  */
#line 281 "task3.y"
                        { struct node* temp=make_leaf("END");
            (yyval.node)=make_unary_node("BEGIN",temp);}
#line 1697 "y.tab.c"
    break;

  case 21: /* statements: statementline  */
#line 284 "task3.y"
                          { (yyval.node)=(yyvsp[0].node);}
#line 1703 "y.tab.c"
    break;

  case 22: /* statements: statementline statements  */
#line 285 "task3.y"
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
#line 1718 "y.tab.c"
    break;

  case 23: /* statementline: WRITE OPEN_PARANTHESIS possible_writes CLOSE_PARANTHESIS SEMICOLON  */
#line 296 "task3.y"
                                                                                  { (yyvsp[-3].node)=make_leaf("(");
                                                                                    (yyvsp[0].node)=make_leaf(";");
                                                                                    (yyvsp[-1].node)=make_unary_node(")",(yyvsp[0].node));
                                                                                    (yyval.node)=make_ternary_node("WRITE",(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1727 "y.tab.c"
    break;

  case 24: /* statementline: READ OPEN_PARANTHESIS possible_reads CLOSE_PARANTHESIS SEMICOLON  */
#line 300 "task3.y"
                                                                                  { (yyvsp[-3].node)=make_leaf("(");
                                                                                    (yyvsp[0].node)=make_leaf(";");
                                                                                    (yyvsp[-1].node)=make_unary_node(")",(yyvsp[0].node));
                                                                                    (yyval.node)=make_ternary_node("READ",(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1736 "y.tab.c"
    break;

  case 25: /* statementline: IDENTIFIER ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 304 "task3.y"
                                                                     { char * x; x=(char*)malloc(100*sizeof(char));
                                                                        strcpy(x,(yyvsp[-3].sval).val);
                                                                        x=tolowercase(x);
                                                                        if(find_symbol(x)==NULL ){
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-3].sval).val,(yyvsp[-3].sval).line);
                                                                            addError(errormsg);
                                                                        }
                                                                        node* temp=make_leaf(";");
                                                                        node* temp1=make_leaf((yyvsp[-3].sval).val);
                                                                        (yyval.node)=make_ternary_node((yyvsp[-2].sval).val,temp1,(yyvsp[-1].node),temp);
                                                                        if(strcmp(find_symbol(x)->type,(yyvsp[-1].node)->type)!=0){
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Assignment of mismatched types at line number: %d",(yyvsp[-3].sval).line);
                                                                            addError(errormsg);
                                                                        }
                                                                        find_symbol(x)->value=1;}
#line 1758 "y.tab.c"
    break;

  case 26: /* statementline: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 321 "task3.y"
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
#line 1793 "y.tab.c"
    break;

  case 27: /* statementline: IF condition THEN program_declaration ELSE program_declaration SEMICOLON  */
#line 351 "task3.y"
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
#line 1813 "y.tab.c"
    break;

  case 28: /* statementline: IF condition THEN program_declaration SEMICOLON  */
#line 366 "task3.y"
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
#line 1832 "y.tab.c"
    break;

  case 29: /* statementline: FOR for_conditionals1 DO program_declaration SEMICOLON  */
#line 380 "task3.y"
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
#line 1848 "y.tab.c"
    break;

  case 30: /* statementline: FOR for_conditionals2 DO program_declaration SEMICOLON  */
#line 391 "task3.y"
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
#line 1864 "y.tab.c"
    break;

  case 31: /* statementline: WHILE condition DO program_declaration SEMICOLON  */
#line 402 "task3.y"
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
#line 1884 "y.tab.c"
    break;

  case 32: /* for_conditionals1: IDENTIFIER ASSIGNMENT_OP arith_expression TO arith_expression  */
#line 418 "task3.y"
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
        sprintf(errormsg,"For loop variables should be integer at line number: %d",(yyvsp[-4].sval).line);
        addError(errormsg);
    }
    find_symbol(x)->value=1;
    node * temp=make_leaf((yyvsp[-4].sval).val);
    node * temp1=make_binary_node("TO",(yyvsp[-2].node),(yyvsp[0].node));
    (yyval.node)=make_binary_node(":=",temp,temp1);
}
#line 1908 "y.tab.c"
    break;

  case 33: /* for_conditionals2: IDENTIFIER ASSIGNMENT_OP arith_expression DOWNTO arith_expression  */
#line 438 "task3.y"
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
        sprintf(errormsg,"For loop variables should be integer at line number: %d",(yyvsp[-4].sval).line);
        addError(errormsg);
    }
    find_symbol(x)->value=1;
    node * temp=make_leaf((yyvsp[-4].sval).val);
    node * temp1=make_binary_node("DOWNTO",(yyvsp[-2].node),(yyvsp[0].node));
    (yyval.node)=make_binary_node(":=",temp,temp1);
}
#line 1932 "y.tab.c"
    break;

  case 34: /* condition: conditional_head  */
#line 458 "task3.y"
                            {(yyval.node)=(yyvsp[0].node);
                            strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 1939 "y.tab.c"
    break;

  case 35: /* condition: unit  */
#line 460 "task3.y"
                  {(yyval.node)=(yyvsp[0].node);
                   strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 1946 "y.tab.c"
    break;

  case 36: /* conditional_head: relational_exp  */
#line 463 "task3.y"
                                 { (yyval.node)=(yyvsp[0].node);
                                    strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 1953 "y.tab.c"
    break;

  case 37: /* conditional_head: conditionals  */
#line 465 "task3.y"
                                  { (yyval.node)=(yyvsp[0].node);
                                    strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 1960 "y.tab.c"
    break;

  case 38: /* conditionals: condtional_unit  */
#line 468 "task3.y"
                                {(yyval.node)=(yyvsp[0].node);
                                strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 1967 "y.tab.c"
    break;

  case 39: /* conditionals: relational_exp BOOLEAN_OP conditionals  */
#line 470 "task3.y"
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
#line 1982 "y.tab.c"
    break;

  case 40: /* conditionals: relational_exp BOOLEAN_OP unit  */
#line 480 "task3.y"
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
#line 1997 "y.tab.c"
    break;

  case 41: /* conditionals: unit BOOLEAN_OP conditionals  */
#line 490 "task3.y"
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
#line 2012 "y.tab.c"
    break;

  case 42: /* conditionals: unit BOOLEAN_OP unit  */
#line 500 "task3.y"
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
#line 2027 "y.tab.c"
    break;

  case 43: /* conditionals: BOOLEAN_OP_NOT conditionals  */
#line 510 "task3.y"
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
#line 2042 "y.tab.c"
    break;

  case 44: /* conditionals: OPEN_PARANTHESIS conditionals CLOSE_PARANTHESIS  */
#line 520 "task3.y"
                                                                 {node * temp=make_leaf(")");
                                                                (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);
                                                                strcpy((yyval.node)->type,(yyvsp[-1].node)->type);}
#line 2050 "y.tab.c"
    break;

  case 45: /* condtional_unit: BOOLEAN_OP_NOT unit  */
#line 525 "task3.y"
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
#line 2065 "y.tab.c"
    break;

  case 46: /* relational_exp: arith_expression RELATIONAL_OP arith_expression  */
#line 536 "task3.y"
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
#line 2122 "y.tab.c"
    break;

  case 47: /* relational_exp: OPEN_PARANTHESIS relational_exp CLOSE_PARANTHESIS  */
#line 588 "task3.y"
                                                                   {node * temp=make_leaf(")");
                                                                    (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);
                                                                    strcpy((yyval.node)->type,(yyvsp[-1].node)->type);}
#line 2130 "y.tab.c"
    break;

  case 48: /* left_side_vars_write: IDENTIFIER  */
#line 592 "task3.y"
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
#line 2149 "y.tab.c"
    break;

  case 49: /* left_side_vars_write: IDENTIFIER COMMA left_side_vars_write  */
#line 606 "task3.y"
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
#line 2169 "y.tab.c"
    break;

  case 50: /* possible_writes: possible_write_values  */
#line 622 "task3.y"
                                       { (yyval.node)=(yyvsp[0].node);}
#line 2175 "y.tab.c"
    break;

  case 51: /* possible_writes: %empty  */
#line 623 "task3.y"
      {(yyval.node)=NULL;}
#line 2181 "y.tab.c"
    break;

  case 52: /* possible_write_values: left_side_vars_write  */
#line 625 "task3.y"
                                            {(yyval.node)=(yyvsp[0].node);}
#line 2187 "y.tab.c"
    break;

  case 53: /* possible_write_values: STRING_CONSTANT  */
#line 626 "task3.y"
                                         { (yyval.node)=make_leaf((yyvsp[0].sval).val);}
#line 2193 "y.tab.c"
    break;

  case 54: /* possible_write_values: STRING_CONSTANT COMMA possible_write_values  */
#line 627 "task3.y"
                                                                     {node* temp=make_leaf((yyvsp[-2].sval).val);
                                                                        (yyval.node)=make_binary_node(",",temp,(yyvsp[0].node));}
#line 2200 "y.tab.c"
    break;

  case 55: /* possible_write_values: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 629 "task3.y"
                                                                                 {char * x; x=(char*)malloc(100*sizeof(char));
                                                                                strcpy(x,(yyvsp[-3].sval).val);
                                                                                x=tolowercase(x);
                                                                                if(find_symbol(x)==NULL || strcmp(find_symbol(x)->type,"undefined")==0){
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
#line 2226 "y.tab.c"
    break;

  case 56: /* possible_reads: IDENTIFIER  */
#line 651 "task3.y"
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
#line 2243 "y.tab.c"
    break;

  case 57: /* possible_reads: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 663 "task3.y"
                                                                        {char * x; x=(char*)malloc(100*sizeof(char));
                                                                        strcpy(x,(yyvsp[-3].sval).val);
                                                                        x=tolowercase(x);
                                                                        if(find_symbol(x)==NULL || strcmp(find_symbol(x)->type,"undefined")==0){
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Undeclared variable: %s at line number: %d",(yyvsp[-3].sval).val,(yyvsp[-3].sval).line);
                                                                            addError(errormsg);
                                                                            add_symbol(x,"undefined");
                                                                            symbol_table->value=0;     
                                                                        }
                                                                        find_symbol(x)->value=1;
                                                                        node* temp=make_leaf((yyvsp[-3].sval).val);
                                                                        (yyvsp[0].node)=make_leaf("r_brace");
                                                                        (yyval.node)=make_ternary_node("l_brace",temp,(yyvsp[-2].node),(yyvsp[-1].node));}
#line 2262 "y.tab.c"
    break;

  case 58: /* arith_expression: unit_2  */
#line 679 "task3.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2268 "y.tab.c"
    break;

  case 59: /* arith_expression: unit  */
#line 680 "task3.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2274 "y.tab.c"
    break;

  case 60: /* arith_expression: OPEN_PARANTHESIS arith_expression CLOSE_PARANTHESIS  */
#line 681 "task3.y"
                                                                      {node * temp=make_leaf(")");
                                                                        (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);
                                                                        strcpy((yyval.node)->type,(yyvsp[-1].node)->type);}
#line 2282 "y.tab.c"
    break;

  case 61: /* arith_expression: arith_expression ARITHEMATIC_OP arith_expression  */
#line 684 "task3.y"
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
#line 2315 "y.tab.c"
    break;

  case 62: /* arith_expression: arith_expression ARITHEMATIC_OP_MINUS arith_expression  */
#line 712 "task3.y"
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
#line 2348 "y.tab.c"
    break;

  case 63: /* unit: IDENTIFIER  */
#line 742 "task3.y"
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
#line 2375 "y.tab.c"
    break;

  case 64: /* unit: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 766 "task3.y"
                                                             {char * x; x=(char*)malloc(100*sizeof(char));
                                                            strcpy(x,(yyvsp[-3].sval).val);
                                                            x=tolowercase(x);
                                                            node* temp=make_leaf((yyvsp[-3].sval).val);
                                                            (yyvsp[0].node)=make_leaf("r_brace");
                                                            (yyval.node)=make_ternary_node("l_brace",temp,(yyvsp[-2].node),(yyvsp[-1].node));
                                                            if(find_symbol(x)==NULL || strcmp(find_symbol(x)->type,"undefined")==0){
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
#line 2415 "y.tab.c"
    break;

  case 65: /* unit: ARITHEMATIC_OP_MINUS arith_expression  */
#line 801 "task3.y"
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
#line 2432 "y.tab.c"
    break;

  case 66: /* unit_2: INTEGER_CONSTANT  */
#line 814 "task3.y"
                         { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                            sprintf(temp,"%d",(yyvsp[0].ival).val);
                            (yyval.node)=make_leaf(temp);
                            sprintf((yyval.node)->type,"INTEGER");}
#line 2441 "y.tab.c"
    break;

  case 67: /* unit_2: FLOAT_CONSTANT  */
#line 818 "task3.y"
                     { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%f",(yyvsp[0].dval).val);
                        (yyval.node)=make_leaf(temp);
                        sprintf((yyval.node)->type,"REAL");}
#line 2450 "y.tab.c"
    break;


#line 2454 "y.tab.c"

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

#line 823 "task3.y"


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
