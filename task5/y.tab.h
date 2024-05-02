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

#line 172 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
