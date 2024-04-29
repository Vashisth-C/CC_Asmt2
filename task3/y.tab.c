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
extern FILE *yyin;
int yylex();
int yyerror();

typedef struct node{
    char lexeme[100];
    int NumChild;
    struct node **child;
    } node;

struct node* make_binary_node(char*, node*, node*);
struct node* make_leaf(char* );
struct node* make_ternary_node(char* , node* , node* ,node* );
struct node* make_unary_node(char* , node* );
void AST_print(struct node* );
void writeToFile(struct node* );
void preOrderTraversal(struct node* , char* );



#line 96 "y.tab.c"

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
    INTEGER_CONSTANT = 270,        /* INTEGER_CONSTANT  */
    FLOAT_CONSTANT = 271,          /* FLOAT_CONSTANT  */
    PROGRAM = 272,                 /* PROGRAM  */
    SEMICOLON = 273,               /* SEMICOLON  */
    IF = 274,                      /* IF  */
    WHILE = 275,                   /* WHILE  */
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
#define INTEGER_CONSTANT 270
#define FLOAT_CONSTANT 271
#define PROGRAM 272
#define SEMICOLON 273
#define IF 274
#define WHILE 275
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
#line 26 "task3.y"

    int ival;
    char *sval;
    double dval;
    struct node* node;

#line 238 "y.tab.c"

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
  YYSYMBOL_INTEGER_CONSTANT = 15,          /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 16,            /* FLOAT_CONSTANT  */
  YYSYMBOL_PROGRAM = 17,                   /* PROGRAM  */
  YYSYMBOL_SEMICOLON = 18,                 /* SEMICOLON  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
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
  YYSYMBOL_condition = 53,                 /* condition  */
  YYSYMBOL_conditional_head = 54,          /* conditional_head  */
  YYSYMBOL_conditionals = 55,              /* conditionals  */
  YYSYMBOL_condtional_unit = 56,           /* condtional_unit  */
  YYSYMBOL_relational_exp = 57,            /* relational_exp  */
  YYSYMBOL_possible_writes = 58,           /* possible_writes  */
  YYSYMBOL_possible_write_values = 59,     /* possible_write_values  */
  YYSYMBOL_possible_reads = 60,            /* possible_reads  */
  YYSYMBOL_arith_expression = 61,          /* arith_expression  */
  YYSYMBOL_unit = 62,                      /* unit  */
  YYSYMBOL_unit_2 = 63                     /* unit_2  */
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
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

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
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    67,    68,    69,    70,    81,    83,    84,
      87,    88,   100,   102,   103,   104,   106,   109,   112,   113,
     124,   128,   132,   135,   145,   155,   169,   183,   193,   194,
     196,   197,   199,   200,   201,   202,   203,   204,   205,   209,
     211,   212,   215,   216,   218,   219,   223,   225,   229,   230,
     235,   236,   237,   239,   240,   243,   244,   247,   249,   252
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
  "ARITHEMATIC_OP_MINUS", "INTEGER_CONSTANT", "FLOAT_CONSTANT", "PROGRAM",
  "SEMICOLON", "IF", "WHILE", "ELSE", "FOR", "DO", "BEGIN_TAG", "END",
  "WRITE", "READ", "DOWNTO", "TO", "OF", "COLON", "VAR", "ARRAY", "THEN",
  "COMMA", "OPEN_BRACKET", "OPEN_PARANTHESIS", "CLOSE_BRACKET",
  "CLOSE_PARANTHESIS", "PERIOD", "RANGE_DOTS", "$accept", "start",
  "variable_declaration", "variable_list", "variable_line",
  "left_side_vars", "rigth_side_type", "datatype", "program_declaration",
  "statements", "statementline", "condition", "conditional_head",
  "conditionals", "condtional_unit", "relational_exp", "possible_writes",
  "possible_write_values", "possible_reads", "arith_expression", "unit",
  "unit_2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,    10,    27,    40,   -68,    24,    59,    54,    51,   -68,
      59,    57,    78,    62,    59,   -68,    68,    88,    16,    16,
     103,   -68,    91,    93,   104,    65,   -68,   -68,   -68,   -68,
     -68,   -68,    95,   114,   -68,    20,    97,    16,    20,   -68,
     -68,    16,   100,   -68,   -68,   -68,   126,   109,    36,   -68,
     115,   125,    92,   134,   -68,   -68,   124,   -68,    20,    98,
     -68,    20,   -68,   126,   101,   -68,   102,    -2,     8,   131,
      54,    16,    20,    20,    20,    16,    54,    20,    89,   107,
     -68,   105,   -68,   110,   106,   108,    38,   -68,     4,   -68,
     -68,   -68,   -17,   -68,   101,   113,   129,   -68,   -68,   101,
     130,    80,    20,    92,   132,    20,   133,   137,   -68,   -68,
      54,   -68,    20,    20,    52,   -68,   -68,    69,   -68,   116,
     135,     1,    41,   -68,   -68,   117,   -68,    54,    54,   112,
     138,   139,   -68,   -68,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     8,     3,
       5,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,    17,     0,     0,     0,    18,     2,     9,    12,    13,
      14,    15,     0,     0,    10,     0,    55,     0,     0,    58,
      59,     0,     0,    28,    31,    32,    30,     0,    51,    50,
       0,     0,    43,     0,    16,    19,     0,     7,     0,     0,
      51,     0,    37,     0,    39,    57,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     8,    45,
      44,     0,    42,    48,     0,     0,     0,    22,     0,    38,
      41,    52,     0,    33,    34,    40,    53,    54,    35,    36,
       0,     0,     0,     0,     0,     0,     0,     0,    56,    24,
       0,    27,     0,     0,     0,    46,    20,     0,    21,     0,
       0,     0,     0,    47,    49,     0,    23,     0,     0,     0,
       0,     0,    11,    26,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   145,   -68,   -14,   -68,    29,   -67,   136,
     -68,   140,   -68,   -25,   -68,    30,   -68,    60,   -68,   -33,
      -8,   -68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,     9,    10,    11,    33,    34,    13,    24,
      25,    42,    43,    44,    45,    63,    81,    82,    84,    47,
      60,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,   109,    59,    92,   110,    65,     1,    71,    68,   100,
      48,    48,    62,     3,    73,    74,    66,    73,    74,    36,
      72,    73,    74,    36,   127,    86,    37,     4,    88,    64,
      38,    39,    40,    69,    38,    39,    40,    90,    80,    95,
      96,    97,   108,   120,   101,    75,    93,    91,    46,    46,
      98,    73,    74,    41,    73,    74,     6,    58,     5,   -29,
     130,   131,     8,    94,   128,    73,    74,    99,    17,   114,
     -29,    67,   117,    28,    29,    30,    31,    91,    12,   121,
     122,    17,    73,    74,    18,    19,    14,    20,    16,    80,
     123,    22,    23,    73,    74,    78,    79,    18,    19,    35,
      20,    32,    26,    21,    22,    23,    51,   124,   112,   113,
      75,    73,    74,   -51,   -51,   -51,    87,    28,    29,    30,
      31,    72,    73,    74,    14,   102,    73,    74,    52,    54,
      53,    56,    57,    61,    70,    71,    77,    83,    76,    85,
      75,    89,   103,    74,   104,   106,   105,   129,   111,   107,
     116,   118,   119,   126,   125,    15,   133,   134,   132,    50,
       0,    55,     0,   115
};

static const yytype_int16 yycheck[] =
{
      14,    18,    35,    70,    21,    38,    17,     9,    41,    76,
      18,    19,    37,     3,    13,    14,    41,    13,    14,     3,
      12,    13,    14,     3,    23,    58,    10,     0,    61,    37,
      14,    15,    16,    41,    14,    15,    16,    39,    52,    72,
      73,    74,    38,   110,    77,     9,    71,    39,    18,    19,
      75,    13,    14,    37,    13,    14,    32,    37,    18,    23,
     127,   128,     3,    71,    23,    13,    14,    75,     3,   102,
      34,    41,   105,     5,     6,     7,     8,    39,    24,   112,
     113,     3,    13,    14,    19,    20,    35,    22,    31,   103,
      38,    26,    27,    13,    14,     3,     4,    19,    20,    11,
      22,    33,    40,    25,    26,    27,     3,    38,    28,    29,
       9,    13,    14,    12,    13,    14,    18,     5,     6,     7,
       8,    12,    13,    14,    35,    36,    13,    14,    37,    25,
      37,    36,    18,    36,    34,     9,    11,     3,    23,    15,
       9,    39,    35,    14,    39,    39,    36,    30,    18,    41,
      18,    18,    15,    18,    38,    10,    18,    18,   129,    19,
      -1,    25,    -1,   103
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    43,     3,     0,    18,    32,    44,     3,    45,
      46,    47,    24,    50,    35,    45,    31,     3,    19,    20,
      22,    25,    26,    27,    51,    52,    40,    47,     5,     6,
       7,     8,    33,    48,    49,    11,     3,    10,    14,    15,
      16,    37,    53,    54,    55,    56,    57,    61,    62,    63,
      53,     3,    37,    37,    25,    51,    36,    18,    37,    61,
      62,    36,    55,    57,    62,    61,    55,    57,    61,    62,
      34,     9,    12,    13,    14,     9,    23,    11,     3,     4,
      47,    58,    59,     3,    60,    15,    61,    18,    61,    39,
      39,    39,    50,    55,    62,    61,    61,    61,    55,    62,
      50,    61,    36,    35,    39,    36,    39,    41,    38,    18,
      21,    18,    28,    29,    61,    59,    18,    61,    18,    15,
      50,    61,    61,    38,    38,    38,    18,    23,    23,    30,
      50,    50,    49,    18,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    47,    47,
      48,    48,    49,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    56,
      57,    57,    58,    58,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     2,     0,     1,     2,     4,     1,     3,
       1,     8,     1,     1,     1,     1,     3,     2,     1,     2,
       5,     5,     4,     7,     5,     9,     9,     5,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     3,     2,
       3,     3,     1,     0,     1,     1,     3,     4,     1,     4,
       1,     1,     3,     3,     3,     1,     4,     2,     1,     1
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
#line 52 "task3.y"
                                                                                    {(yyvsp[-5].node)=make_leaf("PROGRAM");
                                                                                    (yyvsp[0].node)=make_binary_node(";",(yyvsp[-2].node),(yyvsp[-1].node));
                                                                                    (yyval.node)=make_binary_node((yyvsp[-4].sval),(yyvsp[-5].node),(yyvsp[0].node));
                                                                                    node* t=(yyval.node);
                                                                                    while(t->child!=NULL){
                                                                                        t=t->child[t->NumChild-1];
                                                                                    }
                                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                                    t->child[0]=make_leaf(".");
                                                                                    t->NumChild++;
                                                                                    printf("Valid Input\n\n");
                                                                                    writeToFile((yyval.node));
                                                                                    AST_print((yyval.node));
                                                                                    printf("\n");  }
#line 1385 "y.tab.c"
    break;

  case 3: /* variable_declaration: VAR variable_list  */
#line 67 "task3.y"
                                        {(yyval.node)=make_unary_node("VAR",(yyvsp[0].node));}
#line 1391 "y.tab.c"
    break;

  case 4: /* variable_declaration: %empty  */
#line 68 "task3.y"
                      {(yyval.node)=NULL;}
#line 1397 "y.tab.c"
    break;

  case 5: /* variable_list: variable_line  */
#line 69 "task3.y"
                             { (yyval.node)=(yyvsp[0].node);}
#line 1403 "y.tab.c"
    break;

  case 6: /* variable_list: variable_line variable_list  */
#line 70 "task3.y"
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
#line 1418 "y.tab.c"
    break;

  case 7: /* variable_line: left_side_vars COLON rigth_side_type SEMICOLON  */
#line 81 "task3.y"
                                                              { struct node * temp1=make_leaf(";");
                                                                (yyval.node)=make_binary_node(":",(yyvsp[-3].node),(yyvsp[-1].node));}
#line 1425 "y.tab.c"
    break;

  case 8: /* left_side_vars: IDENTIFIER  */
#line 83 "task3.y"
                           { (yyval.node)=make_leaf((yyvsp[0].sval));}
#line 1431 "y.tab.c"
    break;

  case 9: /* left_side_vars: IDENTIFIER COMMA left_side_vars  */
#line 84 "task3.y"
                                                 { struct node * temp1=make_leaf((yyvsp[-2].sval));
                                                    (yyval.node)=make_binary_node(",",temp1,(yyvsp[0].node));}
#line 1438 "y.tab.c"
    break;

  case 10: /* rigth_side_type: datatype  */
#line 87 "task3.y"
                          { (yyval.node)=(yyvsp[0].node);}
#line 1444 "y.tab.c"
    break;

  case 11: /* rigth_side_type: ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF datatype  */
#line 88 "task3.y"
                                                                                                           {(yyvsp[-7].node)= make_leaf("ARRAY");
                                                                                                            (yyvsp[-6].node)=make_unary_node("l_brace",(yyvsp[-7].node));
                                                                                                            char * temp; temp=(char*)malloc(100*sizeof(char)); 
                                                                                                            sprintf(temp,"%d",(yyvsp[-5].ival));
                                                                                                            node* temp1=make_unary_node(temp,(yyvsp[-6].node));
                                                                                                            (yyvsp[-1].node)=make_unary_node("OF",(yyvsp[0].node));
                                                                                                            (yyvsp[-2].node)=make_unary_node("r_brace",(yyvsp[-1].node));
                                                                                                            char* temp3; temp3=(char*)malloc(100*sizeof(char));
                                                                                                            sprintf(temp3,"%d",(yyvsp[-3].ival));
                                                                                                            node* temp2=make_unary_node(temp3,(yyvsp[-2].node));
                                                                                                            (yyval.node)=make_binary_node("..",temp1,temp2);}
#line 1460 "y.tab.c"
    break;

  case 12: /* datatype: INTEGER  */
#line 100 "task3.y"
                  {struct node* temp= make_leaf(";");
                    (yyval.node)=make_unary_node("INTEGER",temp);}
#line 1467 "y.tab.c"
    break;

  case 13: /* datatype: REAL  */
#line 102 "task3.y"
              {struct node* temp= make_leaf(";");(yyval.node)=make_unary_node("REAL",temp);}
#line 1473 "y.tab.c"
    break;

  case 14: /* datatype: BOOLEAN  */
#line 103 "task3.y"
                 {struct node* temp= make_leaf(";");(yyval.node)=make_unary_node("BOOLEAN",temp);}
#line 1479 "y.tab.c"
    break;

  case 15: /* datatype: CHAR  */
#line 104 "task3.y"
              {struct node* temp= make_leaf(";");(yyval.node)=make_unary_node("CHAR",temp);}
#line 1485 "y.tab.c"
    break;

  case 16: /* program_declaration: BEGIN_TAG statements END  */
#line 106 "task3.y"
                                              { struct node* temp=make_leaf("END");
                                                (yyval.node)=make_binary_node("BEGIN",(yyvsp[-1].node),temp);
                                                }
#line 1493 "y.tab.c"
    break;

  case 17: /* program_declaration: BEGIN_TAG END  */
#line 109 "task3.y"
                        { struct node* temp=make_leaf("END");
            (yyval.node)=make_unary_node("BEGIN",temp);}
#line 1500 "y.tab.c"
    break;

  case 18: /* statements: statementline  */
#line 112 "task3.y"
                          { (yyval.node)=(yyvsp[0].node);}
#line 1506 "y.tab.c"
    break;

  case 19: /* statements: statementline statements  */
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
#line 1521 "y.tab.c"
    break;

  case 20: /* statementline: WRITE OPEN_PARANTHESIS possible_writes CLOSE_PARANTHESIS SEMICOLON  */
#line 124 "task3.y"
                                                                                  { (yyvsp[-3].node)=make_leaf("(");
                                                                                    (yyvsp[0].node)=make_leaf(";");
                                                                                    (yyvsp[-1].node)=make_unary_node(")",(yyvsp[0].node));
                                                                                    (yyval.node)=make_ternary_node("WRITE",(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1530 "y.tab.c"
    break;

  case 21: /* statementline: READ OPEN_PARANTHESIS possible_reads CLOSE_PARANTHESIS SEMICOLON  */
#line 128 "task3.y"
                                                                                  { (yyvsp[-3].node)=make_leaf("(");
                                                                                    (yyvsp[0].node)=make_leaf(";");
                                                                                    (yyvsp[-1].node)=make_unary_node(")",(yyvsp[0].node));
                                                                                    (yyval.node)=make_ternary_node("READ",(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1539 "y.tab.c"
    break;

  case 22: /* statementline: IDENTIFIER ASSIGNMENT_OP arith_expression SEMICOLON  */
#line 132 "task3.y"
                                                                     { node* temp=make_leaf(";");
                                                                        node* temp1=make_leaf((yyvsp[-3].sval));
                                                                        (yyval.node)=make_ternary_node((yyvsp[-2].sval),temp1,(yyvsp[-1].node),temp);}
#line 1547 "y.tab.c"
    break;

  case 23: /* statementline: IF condition THEN program_declaration ELSE program_declaration SEMICOLON  */
#line 135 "task3.y"
                                                                                          { node* then= make_unary_node("THEN",(yyvsp[-3].node));
                                                                                        node* elset= make_unary_node("ELSE",(yyvsp[-1].node));
                                                                                        (yyval.node)=make_ternary_node("IF",(yyvsp[-5].node),then,elset);
                                                                                        node* t=(yyval.node);
                                                                                        while(t->child!=NULL){
                                                                                        t=t->child[t->NumChild-1];
                                                                                        }
                                                                                        t->child=(struct node**)malloc(sizeof(struct node*));
                                                                                        t->child[0]=make_leaf(";");
                                                                                        t->NumChild++;}
#line 1562 "y.tab.c"
    break;

  case 24: /* statementline: IF condition THEN program_declaration SEMICOLON  */
#line 145 "task3.y"
                                                                 { node* then= make_unary_node("THEN",(yyvsp[-1].node));
                                                                    (yyval.node)=make_binary_node("IF",(yyvsp[-3].node),then);
                                                                    node* t=(yyval.node);
                                                                    while(t->child!=NULL){
                                                                        t=t->child[t->NumChild-1];
                                                                    }
                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                    t->child[0]=make_leaf(";");
                                                                    t->NumChild++;
                                                                    }
#line 1577 "y.tab.c"
    break;

  case 25: /* statementline: FOR IDENTIFIER ASSIGNMENT_OP arith_expression TO arith_expression DO program_declaration SEMICOLON  */
#line 155 "task3.y"
                                                                                                                    {
                    node* dotemp=make_unary_node("DO",(yyvsp[-1].node));
                    node* id=make_leaf((yyvsp[-7].sval));
                    node* temp=make_binary_node("TO",(yyvsp[-5].node),(yyvsp[-3].node));
                    node* temp1=make_binary_node((yyvsp[-6].sval),id,temp);
                    (yyval.node)=make_binary_node("FOR",temp1,dotemp);
                    node* t=(yyval.node);
                    while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
#line 1596 "y.tab.c"
    break;

  case 26: /* statementline: FOR IDENTIFIER ASSIGNMENT_OP arith_expression DOWNTO arith_expression DO program_declaration SEMICOLON  */
#line 169 "task3.y"
                                                                                                                        {
                    node* dotemp=make_unary_node("DO",(yyvsp[-1].node));
                    node* id=make_leaf((yyvsp[-7].sval));
                    node* temp=make_binary_node("DOWNTO",(yyvsp[-5].node),(yyvsp[-3].node));
                    node* temp1=make_binary_node((yyvsp[-6].sval),id,temp);
                    (yyval.node)=make_binary_node("FOR",temp1,dotemp);
                    node* t=(yyval.node);
                     while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
#line 1615 "y.tab.c"
    break;

  case 27: /* statementline: WHILE condition DO program_declaration SEMICOLON  */
#line 183 "task3.y"
                                                                  { node* temp=make_unary_node("DO",(yyvsp[-1].node));
                                                                    (yyval.node)=make_binary_node("WHILE",(yyvsp[-3].node),temp);
                                                                    node* t=(yyval.node);
                                                                     while(t->child!=NULL){
                                                                        t=t->child[t->NumChild-1];
                                                                    }
                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                    t->child[0]=make_leaf(";");
                                                                    t->NumChild++;}
#line 1629 "y.tab.c"
    break;

  case 28: /* condition: conditional_head  */
#line 193 "task3.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 1635 "y.tab.c"
    break;

  case 29: /* condition: unit  */
#line 194 "task3.y"
                  {(yyval.node)=(yyvsp[0].node);}
#line 1641 "y.tab.c"
    break;

  case 30: /* conditional_head: relational_exp  */
#line 196 "task3.y"
                                 { (yyval.node)=(yyvsp[0].node);}
#line 1647 "y.tab.c"
    break;

  case 31: /* conditional_head: conditionals  */
#line 197 "task3.y"
                                  { (yyval.node)=(yyvsp[0].node);}
#line 1653 "y.tab.c"
    break;

  case 32: /* conditionals: condtional_unit  */
#line 199 "task3.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 1659 "y.tab.c"
    break;

  case 33: /* conditionals: relational_exp BOOLEAN_OP conditionals  */
#line 200 "task3.y"
                                                        { (yyval.node)=make_binary_node((yyvsp[-1].sval),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1665 "y.tab.c"
    break;

  case 34: /* conditionals: relational_exp BOOLEAN_OP unit  */
#line 201 "task3.y"
                                                 { (yyval.node)=make_binary_node((yyvsp[-1].sval),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1671 "y.tab.c"
    break;

  case 35: /* conditionals: unit BOOLEAN_OP conditionals  */
#line 202 "task3.y"
                                               { (yyval.node)=make_binary_node((yyvsp[-1].sval),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1677 "y.tab.c"
    break;

  case 36: /* conditionals: unit BOOLEAN_OP unit  */
#line 203 "task3.y"
                                        { (yyval.node)=make_binary_node((yyvsp[-1].sval),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1683 "y.tab.c"
    break;

  case 37: /* conditionals: BOOLEAN_OP_NOT conditionals  */
#line 204 "task3.y"
                                              { (yyval.node)=make_unary_node((yyvsp[-1].sval),(yyvsp[0].node));}
#line 1689 "y.tab.c"
    break;

  case 38: /* conditionals: OPEN_PARANTHESIS conditionals CLOSE_PARANTHESIS  */
#line 205 "task3.y"
                                                                 {node * temp=make_leaf(")");
                                                                (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);}
#line 1696 "y.tab.c"
    break;

  case 39: /* condtional_unit: BOOLEAN_OP_NOT unit  */
#line 209 "task3.y"
                                    {(yyval.node)=make_unary_node((yyvsp[-1].sval),(yyvsp[0].node));}
#line 1702 "y.tab.c"
    break;

  case 40: /* relational_exp: arith_expression RELATIONAL_OP arith_expression  */
#line 211 "task3.y"
                                                                { (yyval.node)=make_binary_node((yyvsp[-1].sval),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1708 "y.tab.c"
    break;

  case 41: /* relational_exp: OPEN_PARANTHESIS relational_exp CLOSE_PARANTHESIS  */
#line 212 "task3.y"
                                                                   {node * temp=make_leaf(")");
                                                                    (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);}
#line 1715 "y.tab.c"
    break;

  case 42: /* possible_writes: possible_write_values  */
#line 215 "task3.y"
                                       { (yyval.node)=(yyvsp[0].node);}
#line 1721 "y.tab.c"
    break;

  case 43: /* possible_writes: %empty  */
#line 216 "task3.y"
      {(yyval.node)=NULL;}
#line 1727 "y.tab.c"
    break;

  case 44: /* possible_write_values: left_side_vars  */
#line 218 "task3.y"
                                      {(yyval.node)=(yyvsp[0].node);}
#line 1733 "y.tab.c"
    break;

  case 45: /* possible_write_values: STRING_CONSTANT  */
#line 219 "task3.y"
                                         {char text[100];
                                        strcat(text,"r");
                                        strcat(text,(yyvsp[0].sval));
                                        (yyval.node)=make_leaf(text);}
#line 1742 "y.tab.c"
    break;

  case 46: /* possible_write_values: STRING_CONSTANT COMMA possible_write_values  */
#line 223 "task3.y"
                                                                     {node* temp=make_leaf((yyvsp[-2].sval));
                                                                        (yyval.node)=make_binary_node(",",temp,(yyvsp[0].node));}
#line 1749 "y.tab.c"
    break;

  case 47: /* possible_write_values: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 225 "task3.y"
                                                                                 {node* temp=make_leaf((yyvsp[-3].sval));
                                                                                (yyvsp[0].node)=make_leaf("r_brace");
                                                                                (yyval.node)=make_ternary_node("l_brace",temp,(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1757 "y.tab.c"
    break;

  case 48: /* possible_reads: IDENTIFIER  */
#line 229 "task3.y"
                           {(yyval.node)=make_leaf((yyvsp[0].sval));}
#line 1763 "y.tab.c"
    break;

  case 49: /* possible_reads: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 230 "task3.y"
                                                                        {node* temp=make_leaf((yyvsp[-3].sval));
                                                                        (yyvsp[0].node)=make_leaf("r_brace");
                                                                        (yyval.node)=make_ternary_node("l_brace",temp,(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1771 "y.tab.c"
    break;

  case 50: /* arith_expression: unit_2  */
#line 235 "task3.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 1777 "y.tab.c"
    break;

  case 51: /* arith_expression: unit  */
#line 236 "task3.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 1783 "y.tab.c"
    break;

  case 52: /* arith_expression: OPEN_PARANTHESIS arith_expression CLOSE_PARANTHESIS  */
#line 237 "task3.y"
                                                                      {node * temp=make_leaf(")");
                                                                        (yyval.node)=make_binary_node("(",(yyvsp[-1].node),temp);}
#line 1790 "y.tab.c"
    break;

  case 53: /* arith_expression: arith_expression ARITHEMATIC_OP arith_expression  */
#line 239 "task3.y"
                                                                   { (yyval.node)=make_binary_node((yyvsp[-1].sval),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1796 "y.tab.c"
    break;

  case 54: /* arith_expression: arith_expression ARITHEMATIC_OP_MINUS arith_expression  */
#line 240 "task3.y"
                                                                         { (yyval.node)=make_binary_node("-",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1802 "y.tab.c"
    break;

  case 55: /* unit: IDENTIFIER  */
#line 243 "task3.y"
                 {(yyval.node)=make_leaf((yyvsp[0].sval));}
#line 1808 "y.tab.c"
    break;

  case 56: /* unit: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET  */
#line 244 "task3.y"
                                                             {node* temp=make_leaf((yyvsp[-3].sval));
                                                            (yyvsp[0].node)=make_leaf("r_brace");
                                                            (yyval.node)=make_ternary_node("l_brace",temp,(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1816 "y.tab.c"
    break;

  case 57: /* unit: ARITHEMATIC_OP_MINUS arith_expression  */
#line 247 "task3.y"
                                           {(yyval.node)=make_unary_node("-",(yyvsp[0].node));}
#line 1822 "y.tab.c"
    break;

  case 58: /* unit_2: INTEGER_CONSTANT  */
#line 249 "task3.y"
                         { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                            sprintf(temp,"%d",(yyvsp[0].ival));
                            (yyval.node)=make_leaf(temp);}
#line 1830 "y.tab.c"
    break;

  case 59: /* unit_2: FLOAT_CONSTANT  */
#line 252 "task3.y"
                     { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%f",(yyvsp[0].dval));
                        (yyval.node)=make_leaf(temp);}
#line 1838 "y.tab.c"
    break;


#line 1842 "y.tab.c"

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

#line 256 "task3.y"


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


int main(int argc, char *argv[]){
    char* filename;
    filename=argv[1];
    printf("\n");
    yyin=fopen(filename, "r");
    yyparse();
    return 0;
}

int yyerror(){
    printf("Syntax Error\n\n");
    return 0;
}
