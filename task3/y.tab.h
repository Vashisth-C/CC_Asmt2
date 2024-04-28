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
    DATATYPE = 260,                /* DATATYPE  */
    BOOLEAN_OP = 261,              /* BOOLEAN_OP  */
    BOOLEAN_OP_NOT = 262,          /* BOOLEAN_OP_NOT  */
    ASSIGNMENT_OP = 263,           /* ASSIGNMENT_OP  */
    RELATIONAL_OP = 264,           /* RELATIONAL_OP  */
    ARITHEMATIC_OP = 265,          /* ARITHEMATIC_OP  */
    ARITHEMATIC_OP_MINUS = 266,    /* ARITHEMATIC_OP_MINUS  */
    INTEGER_CONSTANT = 267,        /* INTEGER_CONSTANT  */
    FLOAT_CONSTANT = 268,          /* FLOAT_CONSTANT  */
    SEMICOLON = 269,               /* SEMICOLON  */
    COMMA = 270,                   /* COMMA  */
    OPEN_BRACKET = 271,            /* OPEN_BRACKET  */
    OPEN_PARANTHESIS = 272,        /* OPEN_PARANTHESIS  */
    CLOSE_BRACKET = 273,           /* CLOSE_BRACKET  */
    CLOSE_PARANTHESIS = 274,       /* CLOSE_PARANTHESIS  */
    PERIOD = 275,                  /* PERIOD  */
    RANGE_DOTS = 276,              /* RANGE_DOTS  */
    IF = 277,                      /* IF  */
    WHILE = 278,                   /* WHILE  */
    ELSE = 279,                    /* ELSE  */
    FOR = 280,                     /* FOR  */
    DO = 281,                      /* DO  */
    BEGIN_TAG = 282,               /* BEGIN_TAG  */
    END = 283,                     /* END  */
    WRITE = 284,                   /* WRITE  */
    READ = 285,                    /* READ  */
    PROGRAM = 286,                 /* PROGRAM  */
    DOWNTO = 287,                  /* DOWNTO  */
    TO = 288,                      /* TO  */
    OF = 289,                      /* OF  */
    COLON = 290,                   /* COLON  */
    VAR = 291,                     /* VAR  */
    ARRAY = 292,                   /* ARRAY  */
    THEN = 293                     /* THEN  */
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
#define DATATYPE 260
#define BOOLEAN_OP 261
#define BOOLEAN_OP_NOT 262
#define ASSIGNMENT_OP 263
#define RELATIONAL_OP 264
#define ARITHEMATIC_OP 265
#define ARITHEMATIC_OP_MINUS 266
#define INTEGER_CONSTANT 267
#define FLOAT_CONSTANT 268
#define SEMICOLON 269
#define COMMA 270
#define OPEN_BRACKET 271
#define OPEN_PARANTHESIS 272
#define CLOSE_BRACKET 273
#define CLOSE_PARANTHESIS 274
#define PERIOD 275
#define RANGE_DOTS 276
#define IF 277
#define WHILE 278
#define ELSE 279
#define FOR 280
#define DO 281
#define BEGIN_TAG 282
#define END 283
#define WRITE 284
#define READ 285
#define PROGRAM 286
#define DOWNTO 287
#define TO 288
#define OF 289
#define COLON 290
#define VAR 291
#define ARRAY 292
#define THEN 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "task3.y"

    int ival;
    char *sval;
    double dval;
    char cval;

#line 150 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
