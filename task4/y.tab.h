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
    ARITHEMATIC_OP_PLUS = 268,     /* ARITHEMATIC_OP_PLUS  */
    ARITHEMATIC_OP_DIV = 269,      /* ARITHEMATIC_OP_DIV  */
    ARITHEMATIC_OP_MUL = 270,      /* ARITHEMATIC_OP_MUL  */
    ARITHEMATIC_OP_MINUS = 271,    /* ARITHEMATIC_OP_MINUS  */
    IF = 272,                      /* IF  */
    WHILE = 273,                   /* WHILE  */
    ARITHEMATIC_OP_MOD = 274,      /* ARITHEMATIC_OP_MOD  */
    INTEGER_CONSTANT = 275,        /* INTEGER_CONSTANT  */
    FLOAT_CONSTANT = 276,          /* FLOAT_CONSTANT  */
    PROGRAM = 277,                 /* PROGRAM  */
    SEMICOLON = 278,               /* SEMICOLON  */
    ELSE = 279,                    /* ELSE  */
    FOR = 280,                     /* FOR  */
    DO = 281,                      /* DO  */
    BEGIN_TAG = 282,               /* BEGIN_TAG  */
    END = 283,                     /* END  */
    WRITE = 284,                   /* WRITE  */
    READ = 285,                    /* READ  */
    DOWNTO = 286,                  /* DOWNTO  */
    TO = 287,                      /* TO  */
    OF = 288,                      /* OF  */
    COLON = 289,                   /* COLON  */
    VAR = 290,                     /* VAR  */
    ARRAY = 291,                   /* ARRAY  */
    THEN = 292,                    /* THEN  */
    COMMA = 293,                   /* COMMA  */
    OPEN_BRACKET = 294,            /* OPEN_BRACKET  */
    OPEN_PARANTHESIS = 295,        /* OPEN_PARANTHESIS  */
    CLOSE_BRACKET = 296,           /* CLOSE_BRACKET  */
    CLOSE_PARANTHESIS = 297,       /* CLOSE_PARANTHESIS  */
    PERIOD = 298,                  /* PERIOD  */
    RANGE_DOTS = 299               /* RANGE_DOTS  */
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
#define ARITHEMATIC_OP_PLUS 268
#define ARITHEMATIC_OP_DIV 269
#define ARITHEMATIC_OP_MUL 270
#define ARITHEMATIC_OP_MINUS 271
#define IF 272
#define WHILE 273
#define ARITHEMATIC_OP_MOD 274
#define INTEGER_CONSTANT 275
#define FLOAT_CONSTANT 276
#define PROGRAM 277
#define SEMICOLON 278
#define ELSE 279
#define FOR 280
#define DO 281
#define BEGIN_TAG 282
#define END 283
#define WRITE 284
#define READ 285
#define DOWNTO 286
#define TO 287
#define OF 288
#define COLON 289
#define VAR 290
#define ARRAY 291
#define THEN 292
#define COMMA 293
#define OPEN_BRACKET 294
#define OPEN_PARANTHESIS 295
#define CLOSE_BRACKET 296
#define CLOSE_PARANTHESIS 297
#define PERIOD 298
#define RANGE_DOTS 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "task4.y"

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

#line 170 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
