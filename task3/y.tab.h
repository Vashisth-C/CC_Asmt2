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
    CONSTANT = 259,                /* CONSTANT  */
    ARITHEMATIC_OP = 260,          /* ARITHEMATIC_OP  */
    RELATIONAL_OP = 261,           /* RELATIONAL_OP  */
    ASSIGNMENT_OP = 262,           /* ASSIGNMENT_OP  */
    SEMICOLON = 263,               /* SEMICOLON  */
    COMMA = 264,                   /* COMMA  */
    BOOLEAN_OP = 265,              /* BOOLEAN_OP  */
    OPEN_BRACKET = 266,            /* OPEN_BRACKET  */
    OPEN_PARANTHESIS = 267,        /* OPEN_PARANTHESIS  */
    CLOSE_BRACKET = 268,           /* CLOSE_BRACKET  */
    CLOSE_PARANTHESIS = 269,       /* CLOSE_PARANTHESIS  */
    PERIOD = 270,                  /* PERIOD  */
    RANGE_DOTS = 271,              /* RANGE_DOTS  */
    IF = 272,                      /* IF  */
    WHILE = 273,                   /* WHILE  */
    ELSE = 274,                    /* ELSE  */
    FOR = 275,                     /* FOR  */
    DO = 276,                      /* DO  */
    BEGIN_TAG = 277,               /* BEGIN_TAG  */
    END = 278,                     /* END  */
    WRITE = 279,                   /* WRITE  */
    READ = 280,                    /* READ  */
    PROGRAM = 281,                 /* PROGRAM  */
    STRING_CONSTANT = 282,         /* STRING_CONSTANT  */
    DOWNTO = 283,                  /* DOWNTO  */
    TO = 284,                      /* TO  */
    OF = 285,                      /* OF  */
    COLON = 286,                   /* COLON  */
    VAR = 287,                     /* VAR  */
    DATATYPE = 288,                /* DATATYPE  */
    ARRAY = 289,                   /* ARRAY  */
    THEN = 290,                    /* THEN  */
    BOOLEAN_OP_NOT = 291           /* BOOLEAN_OP_NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define CONSTANT 259
#define ARITHEMATIC_OP 260
#define RELATIONAL_OP 261
#define ASSIGNMENT_OP 262
#define SEMICOLON 263
#define COMMA 264
#define BOOLEAN_OP 265
#define OPEN_BRACKET 266
#define OPEN_PARANTHESIS 267
#define CLOSE_BRACKET 268
#define CLOSE_PARANTHESIS 269
#define PERIOD 270
#define RANGE_DOTS 271
#define IF 272
#define WHILE 273
#define ELSE 274
#define FOR 275
#define DO 276
#define BEGIN_TAG 277
#define END 278
#define WRITE 279
#define READ 280
#define PROGRAM 281
#define STRING_CONSTANT 282
#define DOWNTO 283
#define TO 284
#define OF 285
#define COLON 286
#define VAR 287
#define DATATYPE 288
#define ARRAY 289
#define THEN 290
#define BOOLEAN_OP_NOT 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
