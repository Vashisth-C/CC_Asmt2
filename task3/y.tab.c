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
    CHAR_CONSTANT = 272,           /* CHAR_CONSTANT  */
    INTEGER_CONSTANT = 273,        /* INTEGER_CONSTANT  */
    FLOAT_CONSTANT = 274,          /* FLOAT_CONSTANT  */
    PROGRAM = 275,                 /* PROGRAM  */
    SEMICOLON = 276,               /* SEMICOLON  */
    ELSE = 277,                    /* ELSE  */
    FOR = 278,                     /* FOR  */
    DO = 279,                      /* DO  */
    BEGIN_TAG = 280,               /* BEGIN_TAG  */
    END = 281,                     /* END  */
    WRITE = 282,                   /* WRITE  */
    READ = 283,                    /* READ  */
    DOWNTO = 284,                  /* DOWNTO  */
    TO = 285,                      /* TO  */
    OF = 286,                      /* OF  */
    COLON = 287,                   /* COLON  */
    VAR = 288,                     /* VAR  */
    ARRAY = 289,                   /* ARRAY  */
    THEN = 290,                    /* THEN  */
    COMMA = 291,                   /* COMMA  */
    OPEN_BRACKET = 292,            /* OPEN_BRACKET  */
    OPEN_PARANTHESIS = 293,        /* OPEN_PARANTHESIS  */
    CLOSE_BRACKET = 294,           /* CLOSE_BRACKET  */
    CLOSE_PARANTHESIS = 295,       /* CLOSE_PARANTHESIS  */
    PERIOD = 296,                  /* PERIOD  */
    RANGE_DOTS = 297               /* RANGE_DOTS  */
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
#define CHAR_CONSTANT 272
#define INTEGER_CONSTANT 273
#define FLOAT_CONSTANT 274
#define PROGRAM 275
#define SEMICOLON 276
#define ELSE 277
#define FOR 278
#define DO 279
#define BEGIN_TAG 280
#define END 281
#define WRITE 282
#define READ 283
#define DOWNTO 284
#define TO 285
#define OF 286
#define COLON 287
#define VAR 288
#define ARRAY 289
#define THEN 290
#define COMMA 291
#define OPEN_BRACKET 292
#define OPEN_PARANTHESIS 293
#define CLOSE_BRACKET 294
#define CLOSE_PARANTHESIS 295
#define PERIOD 296
#define RANGE_DOTS 297

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

#line 273 "y.tab.c"

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
  YYSYMBOL_CHAR_CONSTANT = 17,             /* CHAR_CONSTANT  */
  YYSYMBOL_INTEGER_CONSTANT = 18,          /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 19,            /* FLOAT_CONSTANT  */
  YYSYMBOL_PROGRAM = 20,                   /* PROGRAM  */
  YYSYMBOL_SEMICOLON = 21,                 /* SEMICOLON  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_BEGIN_TAG = 25,                 /* BEGIN_TAG  */
  YYSYMBOL_END = 26,                       /* END  */
  YYSYMBOL_WRITE = 27,                     /* WRITE  */
  YYSYMBOL_READ = 28,                      /* READ  */
  YYSYMBOL_DOWNTO = 29,                    /* DOWNTO  */
  YYSYMBOL_TO = 30,                        /* TO  */
  YYSYMBOL_OF = 31,                        /* OF  */
  YYSYMBOL_COLON = 32,                     /* COLON  */
  YYSYMBOL_VAR = 33,                       /* VAR  */
  YYSYMBOL_ARRAY = 34,                     /* ARRAY  */
  YYSYMBOL_THEN = 35,                      /* THEN  */
  YYSYMBOL_COMMA = 36,                     /* COMMA  */
  YYSYMBOL_OPEN_BRACKET = 37,              /* OPEN_BRACKET  */
  YYSYMBOL_OPEN_PARANTHESIS = 38,          /* OPEN_PARANTHESIS  */
  YYSYMBOL_CLOSE_BRACKET = 39,             /* CLOSE_BRACKET  */
  YYSYMBOL_CLOSE_PARANTHESIS = 40,         /* CLOSE_PARANTHESIS  */
  YYSYMBOL_PERIOD = 41,                    /* PERIOD  */
  YYSYMBOL_RANGE_DOTS = 42,                /* RANGE_DOTS  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_start = 44,                     /* start  */
  YYSYMBOL_variable_declaration = 45,      /* variable_declaration  */
  YYSYMBOL_variable_list = 46,             /* variable_list  */
  YYSYMBOL_variable_line = 47,             /* variable_line  */
  YYSYMBOL_left_side_vars = 48,            /* left_side_vars  */
  YYSYMBOL_rigth_side_type = 49,           /* rigth_side_type  */
  YYSYMBOL_datatype = 50,                  /* datatype  */
  YYSYMBOL_program_declaration = 51,       /* program_declaration  */
  YYSYMBOL_statements = 52,                /* statements  */
  YYSYMBOL_statementline = 53,             /* statementline  */
  YYSYMBOL_for_conditionals1 = 54,         /* for_conditionals1  */
  YYSYMBOL_for_conditionals2 = 55,         /* for_conditionals2  */
  YYSYMBOL_for_conditionals3 = 56,         /* for_conditionals3  */
  YYSYMBOL_for_conditionals4 = 57,         /* for_conditionals4  */
  YYSYMBOL_left_array_assignment = 58,     /* left_array_assignment  */
  YYSYMBOL_condition = 59,                 /* condition  */
  YYSYMBOL_conditional_head = 60,          /* conditional_head  */
  YYSYMBOL_conditionals = 61,              /* conditionals  */
  YYSYMBOL_condtional_unit = 62,           /* condtional_unit  */
  YYSYMBOL_relational_exp = 63,            /* relational_exp  */
  YYSYMBOL_left_side_vars_write = 64,      /* left_side_vars_write  */
  YYSYMBOL_possible_writes = 65,           /* possible_writes  */
  YYSYMBOL_possible_write_values = 66,     /* possible_write_values  */
  YYSYMBOL_possible_reads = 67,            /* possible_reads  */
  YYSYMBOL_arith_expression = 68,          /* arith_expression  */
  YYSYMBOL_unit = 69,                      /* unit  */
  YYSYMBOL_unit_2 = 70                     /* unit_2  */
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
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,   110,   111,   112,   113,   124,   126,   139,
     154,   155,   176,   197,   218,   241,   250,   259,   268,   279,
     282,   285,   286,   297,   301,   305,   326,   356,   371,   385,
     396,   407,   418,   429,   445,   465,   485,   490,   495,   523,
     525,   528,   530,   533,   535,   545,   555,   565,   575,   585,
     590,   601,   653,   657,   671,   687,   688,   690,   691,   692,
     694,   716,   728,   747,   748,   749,   752,   780,   810,   834,
     869,   882,   886,   890
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
  "ARITHEMATIC_OP_MINUS", "IF", "WHILE", "CHAR_CONSTANT",
  "INTEGER_CONSTANT", "FLOAT_CONSTANT", "PROGRAM", "SEMICOLON", "ELSE",
  "FOR", "DO", "BEGIN_TAG", "END", "WRITE", "READ", "DOWNTO", "TO", "OF",
  "COLON", "VAR", "ARRAY", "THEN", "COMMA", "OPEN_BRACKET",
  "OPEN_PARANTHESIS", "CLOSE_BRACKET", "CLOSE_PARANTHESIS", "PERIOD",
  "RANGE_DOTS", "$accept", "start", "variable_declaration",
  "variable_list", "variable_line", "left_side_vars", "rigth_side_type",
  "datatype", "program_declaration", "statements", "statementline",
  "for_conditionals1", "for_conditionals2", "for_conditionals3",
  "for_conditionals4", "left_array_assignment", "condition",
  "conditional_head", "conditionals", "condtional_unit", "relational_exp",
  "left_side_vars_write", "possible_writes", "possible_write_values",
  "possible_reads", "arith_expression", "unit", "unit_2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-65)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,    38,    32,    43,   -74,    20,    69,    57,    60,   -74,
      69,    56,    94,    95,    69,   -74,    68,    12,    21,    21,
      81,   -74,   108,   109,    72,    96,   -74,   -74,   -74,   -74,
     -74,   -74,   111,   128,   -74,    52,    52,   113,    21,    52,
     -74,   -74,   -74,    21,   116,   -74,   -74,   -74,   143,     7,
       9,   -74,   129,    54,   130,   132,   133,   134,   144,    22,
     156,   -74,   -74,   142,   -74,    52,   112,   -74,    15,    52,
     -74,   143,   125,   -74,   121,    -3,    65,   153,    57,    21,
      52,    52,    52,    21,    57,    52,    52,    57,    57,    57,
      57,    52,    49,   127,   -74,   124,   -74,   136,   126,   123,
      -4,   -74,   157,    29,   -74,   -74,   -74,    82,   -74,   125,
     131,   155,   -74,   -74,   125,   146,   100,    44,   149,   150,
     151,   154,   102,   171,    52,    22,   158,    52,   159,   160,
      52,   -74,   -74,    57,   -74,    52,    52,   -74,   -74,   -74,
     -74,   -74,    52,    52,   140,   -74,    48,   -74,   -74,    67,
     -74,   138,   114,   161,   131,   131,   131,   131,   -74,   -74,
     152,   -74,   -74,   135,   -74,   -74,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     8,     3,
       5,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    21,     2,     9,    15,    16,
      17,    18,     0,     0,    10,     0,     0,    68,     0,     0,
      73,    71,    72,     0,     0,    39,    42,    43,    41,     0,
      64,    63,     0,     0,     0,     0,     0,     0,     0,    56,
       0,    19,    22,     0,     7,     0,     0,    64,     0,     0,
      48,     0,    50,    70,     0,     0,     0,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    58,    57,     0,    55,    61,     0,     0,
       0,    25,     0,     0,    49,    52,    65,     0,    44,    45,
      51,    66,    67,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    28,     0,    33,     0,     0,    38,    29,    30,
      31,    32,     0,     0,    53,    54,     0,    59,    23,     0,
      24,     0,     0,     0,    35,    34,    37,    36,    60,    62,
       0,    26,    27,     0,    11,    12,    13,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   174,   -74,   167,   -74,   -74,   -73,   162,
     -74,   -74,   -74,   -74,   -74,   -74,   166,   -74,   -31,   -74,
      75,    63,   -74,    64,   -74,   -35,   -16,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,     9,    10,    11,    33,    34,    13,    24,
      25,    54,    55,    56,    57,    58,    44,    45,    46,    47,
      71,    94,    95,    96,    98,    49,    67,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    68,    50,    50,    73,   107,    79,    70,    76,    81,
      82,   115,    74,     1,   118,   119,   120,   121,    83,    80,
      81,    82,    72,    35,    37,    92,    93,    77,    81,    82,
     100,    38,     4,   -40,   103,    39,   106,   105,    40,    41,
      42,     3,    81,    82,   -40,   110,   111,   112,   108,    36,
     116,   117,   113,     6,   102,    37,   122,    81,    82,    43,
     153,    81,    82,   109,     5,    85,    39,   114,   131,    40,
      41,    42,     8,    28,    29,    30,    31,    80,    81,    82,
      81,    82,    12,   137,    53,   123,   124,   158,    16,   146,
      65,    86,   149,    48,    48,   152,    14,    17,    61,    17,
     154,   155,    32,   132,   133,   106,   159,   156,   157,    18,
      19,    18,    19,    81,    82,    81,    82,    20,    75,    20,
      21,    22,    23,    22,    23,    81,    82,    81,    82,   135,
     136,   142,   143,   101,    83,   161,    26,   -64,   -64,   -64,
     164,   165,   166,   167,    81,    82,    59,    60,    63,    64,
      69,    78,    79,    84,    87,    91,    88,    89,    90,    97,
      99,   104,    83,   125,   126,   129,   128,   134,   130,    82,
     138,   139,   140,   127,   144,   141,   123,   160,   151,   148,
     150,    27,   162,   163,    15,    52,   145,    62,     0,   147
};

static const yytype_int16 yycheck[] =
{
      35,    36,    18,    19,    39,    78,     9,    38,    43,    13,
      14,    84,    43,    20,    87,    88,    89,    90,     9,    12,
      13,    14,    38,    11,     3,     3,     4,    43,    13,    14,
      65,    10,     0,    24,    69,    14,    40,    40,    17,    18,
      19,     3,    13,    14,    35,    80,    81,    82,    79,    37,
      85,    86,    83,    33,    39,     3,    91,    13,    14,    38,
     133,    13,    14,    79,    21,    11,    14,    83,    39,    17,
      18,    19,     3,     5,     6,     7,     8,    12,    13,    14,
      13,    14,    25,    39,     3,    36,    37,    39,    32,   124,
      38,    37,   127,    18,    19,   130,    36,     3,    26,     3,
     135,   136,    34,    21,    22,    40,    39,   142,   143,    15,
      16,    15,    16,    13,    14,    13,    14,    23,    43,    23,
      26,    27,    28,    27,    28,    13,    14,    13,    14,    29,
      30,    29,    30,    21,     9,    21,    41,    12,    13,    14,
       5,     6,     7,     8,    13,    14,    38,    38,    37,    21,
      37,    35,     9,    24,    24,    11,    24,    24,    24,     3,
      18,    40,     9,    36,    40,    42,    40,    21,    11,    14,
      21,    21,    21,    37,     3,    21,    36,    39,    18,    21,
      21,    14,    21,    31,    10,    19,   123,    25,    -1,   125
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    44,     3,     0,    21,    33,    45,     3,    46,
      47,    48,    25,    51,    36,    46,    32,     3,    15,    16,
      23,    26,    27,    28,    52,    53,    41,    48,     5,     6,
       7,     8,    34,    49,    50,    11,    37,     3,    10,    14,
      17,    18,    19,    38,    59,    60,    61,    62,    63,    68,
      69,    70,    59,     3,    54,    55,    56,    57,    58,    38,
      38,    26,    52,    37,    21,    38,    68,    69,    68,    37,
      61,    63,    69,    68,    61,    63,    68,    69,    35,     9,
      12,    13,    14,     9,    24,    11,    37,    24,    24,    24,
      24,    11,     3,     4,    64,    65,    66,     3,    67,    18,
      68,    21,    39,    68,    40,    40,    40,    51,    61,    69,
      68,    68,    68,    61,    69,    51,    68,    68,    51,    51,
      51,    51,    68,    36,    37,    36,    40,    37,    40,    42,
      11,    39,    21,    22,    21,    29,    30,    39,    21,    21,
      21,    21,    29,    30,     3,    64,    68,    66,    21,    68,
      21,    18,    68,    51,    68,    68,    68,    68,    39,    39,
      39,    21,    21,    31,     5,     6,     7,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    48,    48,
      49,    49,    49,    49,    49,    50,    50,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    55,    56,    57,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    69,    69,
      69,    70,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     2,     0,     1,     2,     4,     1,     3,
       1,     8,     8,     8,     8,     1,     1,     1,     1,     3,
       2,     1,     2,     5,     5,     4,     7,     7,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     4,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     2,     3,
       2,     3,     3,     1,     3,     1,     0,     1,     1,     3,
       4,     1,     4,     1,     1,     3,     3,     3,     1,     4,
       2,     1,     1,     1
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
#line 86 "task3.y"
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
#line 1457 "y.tab.c"
    break;

  case 3: /* variable_declaration: VAR variable_list  */
#line 110 "task3.y"
                                        {(yyval.node)=make_unary_node("VAR",(yyvsp[0].node));}
#line 1463 "y.tab.c"
    break;

  case 4: /* variable_declaration: %empty  */
#line 111 "task3.y"
                      {(yyval.node)=NULL;}
#line 1469 "y.tab.c"
    break;

  case 5: /* variable_list: variable_line  */
#line 112 "task3.y"
                             { (yyval.node)=(yyvsp[0].node);}
#line 1475 "y.tab.c"
    break;

  case 6: /* variable_list: variable_line variable_list  */
#line 113 "task3.y"
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
#line 1490 "y.tab.c"
    break;

  case 7: /* variable_line: left_side_vars COLON rigth_side_type SEMICOLON  */
#line 124 "task3.y"
                                                              { struct node * temp1=make_leaf(";");
                                                                (yyval.node)=make_binary_node(":",(yyvsp[-3].node),(yyvsp[-1].node));}
#line 1497 "y.tab.c"
    break;

  case 8: /* left_side_vars: IDENTIFIER  */
#line 126 "task3.y"
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
#line 1515 "y.tab.c"
    break;

  case 9: /* left_side_vars: IDENTIFIER COMMA left_side_vars  */
#line 139 "task3.y"
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
#line 1534 "y.tab.c"
    break;

  case 10: /* rigth_side_type: datatype  */
#line 154 "task3.y"
                          { (yyval.node)=(yyvsp[0].node);}
#line 1540 "y.tab.c"
    break;

  case 11: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF INTEGER  */
#line 155 "task3.y"
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
#line 1566 "y.tab.c"
    break;

  case 12: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF REAL  */
#line 176 "task3.y"
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
#line 1592 "y.tab.c"
    break;

  case 13: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF BOOLEAN  */
#line 197 "task3.y"
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
#line 1618 "y.tab.c"
    break;

  case 14: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF CHAR  */
#line 218 "task3.y"
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
#line 1644 "y.tab.c"
    break;

  case 15: /* datatype: INTEGER  */
#line 241 "task3.y"
                  {struct node* temp= make_leaf(";");
                    (yyval.node)=make_unary_node("INTEGER",temp);
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0 ) {
                            strcpy(current->type, "INTEGER");
                        }
                        current = current->next;
                    }}
#line 1658 "y.tab.c"
    break;

  case 16: /* datatype: REAL  */
#line 250 "task3.y"
              {struct node* temp= make_leaf(";");
                (yyval.node)=make_unary_node("REAL",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0){
                        strcpy(current->type, "REAL");
                    }
                    current = current->next;
                }}
#line 1672 "y.tab.c"
    break;

  case 17: /* datatype: BOOLEAN  */
#line 259 "task3.y"
                 {struct node* temp= make_leaf(";");
                (yyval.node)=make_unary_node("BOOLEAN",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0) {
                        strcpy(current->type, "BOOLEAN");
                    }
                    current = current->next;
                }}
#line 1686 "y.tab.c"
    break;

  case 18: /* datatype: CHAR  */
#line 268 "task3.y"
              {struct node* temp= make_leaf(";");
                (yyval.node)=make_unary_node("CHAR",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0) {
                        strcpy(current->type, "CHAR");
                    }
                    current = current->next;
                }}
#line 1700 "y.tab.c"
    break;

  case 19: /* program_declaration: BEGIN_TAG statements END  */
#line 279 "task3.y"
                                              { struct node* temp=make_leaf("END");
                                                (yyval.node)=make_binary_node("BEGIN",(yyvsp[-1].node),temp);
                                                }
#line 1708 "y.tab.c"
    break;

  case 20: /* program_declaration: BEGIN_TAG END  */
#line 282 "task3.y"
                        { struct node* temp=make_leaf("END");
            (yyval.node)=make_unary_node("BEGIN",temp);}
#line 1715 "y.tab.c"
    break;

  case 21: /* statements: statementline  */
#line 285 "task3.y"
                          { (yyval.node)=(yyvsp[0].node);}
#line 1721 "y.tab.c"
    break;

  case 22: /* statements: statementline statements  */
#line 286 "task3.y"
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
#line 1736 "y.tab.c"
    break;

  case 23: /* statementline: WRITE OPEN_PARANTHESIS possible_writes CLOSE_PARANTHESIS SEMICOLON  */
#line 297 "task3.y"
                                                                                  { (yyvsp[-3].node)=make_leaf("(");
                                                                                    (yyvsp[0].node)=make_leaf(";");
                                                                                    (yyvsp[-1].node)=make_unary_node(")",(yyvsp[0].node));
                                                                                    (yyval.node)=make_ternary_node("WRITE",(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1745 "y.tab.c"
    break;

  case 24: /* statementline: READ OPEN_PARANTHESIS possible_reads CLOSE_PARANTHESIS SEMICOLON  */
#line 301 "task3.y"
                                                                                  { (yyvsp[-3].node)=make_leaf("(");
                                                                                    (yyvsp[0].node)=make_leaf(";");
                                                                                    (yyvsp[-1].node)=make_unary_node(")",(yyvsp[0].node));
                                                                                    (yyval.node)=make_ternary_node("READ",(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1754 "y.tab.c"
    break;

  case 25: /* statementline: IDENTIFIER ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 305 "task3.y"
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
#line 1779 "y.tab.c"
    break;

  case 26: /* statementline: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 326 "task3.y"
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
#line 1814 "y.tab.c"
    break;

  case 27: /* statementline: IF condition THEN program_declaration ELSE program_declaration SEMICOLON  */
#line 356 "task3.y"
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
#line 1834 "y.tab.c"
    break;

  case 28: /* statementline: IF condition THEN program_declaration SEMICOLON  */
#line 371 "task3.y"
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
#line 1853 "y.tab.c"
    break;

  case 29: /* statementline: FOR for_conditionals1 DO program_declaration SEMICOLON  */
#line 385 "task3.y"
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
#line 1869 "y.tab.c"
    break;

  case 30: /* statementline: FOR for_conditionals2 DO program_declaration SEMICOLON  */
#line 396 "task3.y"
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
#line 1885 "y.tab.c"
    break;

  case 31: /* statementline: FOR for_conditionals3 DO program_declaration SEMICOLON  */
#line 407 "task3.y"
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
#line 1901 "y.tab.c"
    break;

  case 32: /* statementline: FOR for_conditionals4 DO program_declaration SEMICOLON  */
#line 418 "task3.y"
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
#line 1917 "y.tab.c"
    break;

  case 33: /* statementline: WHILE condition DO program_declaration SEMICOLON  */
#line 429 "task3.y"
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
#line 1937 "y.tab.c"
    break;

  case 34: /* for_conditionals1: IDENTIFIER ASSIGNMENT_OP arith_expression TO arith_expression  */
#line 445 "task3.y"
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
#line 1961 "y.tab.c"
    break;

  case 35: /* for_conditionals2: IDENTIFIER ASSIGNMENT_OP arith_expression DOWNTO arith_expression  */
#line 465 "task3.y"
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
#line 1985 "y.tab.c"
    break;

  case 36: /* for_conditionals3: left_array_assignment ASSIGNMENT_OP arith_expression TO arith_expression  */
#line 485 "task3.y"
                                                                                           {
    node * temp1=make_binary_node("TO",(yyvsp[-2].node),(yyvsp[0].node));
   (yyval.node)=make_binary_node((yyvsp[-3].sval).val,(yyvsp[-4].node),temp1);
}
#line 1994 "y.tab.c"
    break;

  case 37: /* for_conditionals4: left_array_assignment ASSIGNMENT_OP arith_expression DOWNTO arith_expression  */
#line 490 "task3.y"
                                                                                               {
    node * temp1=make_binary_node("DOWNTO",(yyvsp[-2].node),(yyvsp[0].node));
   (yyval.node)=make_binary_node((yyvsp[-3].sval).val,(yyvsp[-4].node),temp1);
}
#line 2003 "y.tab.c"
    break;

  case 38: /* left_array_assignment: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 495 "task3.y"
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
#line 2035 "y.tab.c"
    break;

  case 39: /* condition: conditional_head  */
#line 523 "task3.y"
                            {(yyval.node)=(yyvsp[0].node);
                            strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 2042 "y.tab.c"
    break;

  case 40: /* condition: unit  */
#line 525 "task3.y"
                  {(yyval.node)=(yyvsp[0].node);
                   strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 2049 "y.tab.c"
    break;

  case 41: /* conditional_head: relational_exp  */
#line 528 "task3.y"
                                 { (yyval.node)=(yyvsp[0].node);
                                    strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 2056 "y.tab.c"
    break;

  case 42: /* conditional_head: conditionals  */
#line 530 "task3.y"
                                  { (yyval.node)=(yyvsp[0].node);
                                    strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 2063 "y.tab.c"
    break;

  case 43: /* conditionals: condtional_unit  */
#line 533 "task3.y"
                                {(yyval.node)=(yyvsp[0].node);
                                strcpy((yyval.node)->type,(yyvsp[0].node)->type);}
#line 2070 "y.tab.c"
    break;

  case 44: /* conditionals: relational_exp BOOLEAN_OP conditionals  */
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
#line 2085 "y.tab.c"
    break;

  case 45: /* conditionals: relational_exp BOOLEAN_OP unit  */
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
#line 2100 "y.tab.c"
    break;

  case 46: /* conditionals: unit BOOLEAN_OP conditionals  */
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
#line 2115 "y.tab.c"
    break;

  case 47: /* conditionals: unit BOOLEAN_OP unit  */
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
#line 2130 "y.tab.c"
    break;

  case 48: /* conditionals: BOOLEAN_OP_NOT conditionals  */
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
#line 2145 "y.tab.c"
    break;

  case 49: /* conditionals: OPEN_PARANTHESIS conditionals CLOSE_PARANTHESIS  */
#line 585 "task3.y"
                                                                 {node * temp=make_leaf(")");
                                                                (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);
                                                                strcpy((yyval.node)->type,(yyvsp[-1].node)->type);}
#line 2153 "y.tab.c"
    break;

  case 50: /* condtional_unit: BOOLEAN_OP_NOT unit  */
#line 590 "task3.y"
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
#line 2168 "y.tab.c"
    break;

  case 51: /* relational_exp: arith_expression RELATIONAL_OP arith_expression  */
#line 601 "task3.y"
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
#line 2225 "y.tab.c"
    break;

  case 52: /* relational_exp: OPEN_PARANTHESIS relational_exp CLOSE_PARANTHESIS  */
#line 653 "task3.y"
                                                                   {node * temp=make_leaf(")");
                                                                    (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);
                                                                    strcpy((yyval.node)->type,(yyvsp[-1].node)->type);}
#line 2233 "y.tab.c"
    break;

  case 53: /* left_side_vars_write: IDENTIFIER  */
#line 657 "task3.y"
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
#line 2252 "y.tab.c"
    break;

  case 54: /* left_side_vars_write: IDENTIFIER COMMA left_side_vars_write  */
#line 671 "task3.y"
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
#line 2272 "y.tab.c"
    break;

  case 55: /* possible_writes: possible_write_values  */
#line 687 "task3.y"
                                       { (yyval.node)=(yyvsp[0].node);}
#line 2278 "y.tab.c"
    break;

  case 56: /* possible_writes: %empty  */
#line 688 "task3.y"
      {(yyval.node)=NULL;}
#line 2284 "y.tab.c"
    break;

  case 57: /* possible_write_values: left_side_vars_write  */
#line 690 "task3.y"
                                            {(yyval.node)=(yyvsp[0].node);}
#line 2290 "y.tab.c"
    break;

  case 58: /* possible_write_values: STRING_CONSTANT  */
#line 691 "task3.y"
                                         { (yyval.node)=make_leaf((yyvsp[0].sval).val);}
#line 2296 "y.tab.c"
    break;

  case 59: /* possible_write_values: STRING_CONSTANT COMMA possible_write_values  */
#line 692 "task3.y"
                                                                     {node* temp=make_leaf((yyvsp[-2].sval).val);
                                                                        (yyval.node)=make_binary_node(",",temp,(yyvsp[0].node));}
#line 2303 "y.tab.c"
    break;

  case 60: /* possible_write_values: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 694 "task3.y"
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
#line 2329 "y.tab.c"
    break;

  case 61: /* possible_reads: IDENTIFIER  */
#line 716 "task3.y"
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
#line 2346 "y.tab.c"
    break;

  case 62: /* possible_reads: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 728 "task3.y"
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
#line 2368 "y.tab.c"
    break;

  case 63: /* arith_expression: unit_2  */
#line 747 "task3.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2374 "y.tab.c"
    break;

  case 64: /* arith_expression: unit  */
#line 748 "task3.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2380 "y.tab.c"
    break;

  case 65: /* arith_expression: OPEN_PARANTHESIS arith_expression CLOSE_PARANTHESIS  */
#line 749 "task3.y"
                                                                      {node * temp=make_leaf(")");
                                                                        (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);
                                                                        strcpy((yyval.node)->type,(yyvsp[-1].node)->type);}
#line 2388 "y.tab.c"
    break;

  case 66: /* arith_expression: arith_expression ARITHEMATIC_OP arith_expression  */
#line 752 "task3.y"
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
#line 2421 "y.tab.c"
    break;

  case 67: /* arith_expression: arith_expression ARITHEMATIC_OP_MINUS arith_expression  */
#line 780 "task3.y"
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
#line 2454 "y.tab.c"
    break;

  case 68: /* unit: IDENTIFIER  */
#line 810 "task3.y"
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
#line 2481 "y.tab.c"
    break;

  case 69: /* unit: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 834 "task3.y"
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
#line 2521 "y.tab.c"
    break;

  case 70: /* unit: ARITHEMATIC_OP_MINUS arith_expression  */
#line 869 "task3.y"
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
#line 2538 "y.tab.c"
    break;

  case 71: /* unit_2: INTEGER_CONSTANT  */
#line 882 "task3.y"
                         { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                            sprintf(temp,"%d",(yyvsp[0].ival).val);
                            (yyval.node)=make_leaf(temp);
                            sprintf((yyval.node)->type,"INTEGER");}
#line 2547 "y.tab.c"
    break;

  case 72: /* unit_2: FLOAT_CONSTANT  */
#line 886 "task3.y"
                     { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%f",(yyvsp[0].dval).val);
                        (yyval.node)=make_leaf(temp);
                        sprintf((yyval.node)->type,"REAL");}
#line 2556 "y.tab.c"
    break;

  case 73: /* unit_2: CHAR_CONSTANT  */
#line 890 "task3.y"
                    { char * temp; temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%s",(yyvsp[0].sval).val);
                        (yyval.node)=make_leaf(temp);
                        sprintf((yyval.node)->type,"CHAR");}
#line 2565 "y.tab.c"
    break;


#line 2569 "y.tab.c"

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

#line 895 "task3.y"


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
