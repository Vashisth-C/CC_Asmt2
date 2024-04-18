%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int line = 1;
%}

%x COMMENT
%x STRING

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]

SPACE [ ]

%%

<INITIAL>{
    {SPACE} {}
    \n {line++;}
    "//" {line++,BEGIN(COMMENT);}
    ";" {printf("%d         %s         SEMICOLON\n",line,yytext);}
    {P}{R}{O}{G}{R}{A}{M} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {I}{F} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {T}{H}{E}{N} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {E}{L}{S}{E} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {W}{H}{I}{L}{E} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {D}{O} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {F}{O}{R} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {O}{F} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {B}{E}{G}{I}{N} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {E}{N}{D} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {R}{E}{A}{D} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {W}{R}{I}{T}{E} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {A}{N}{D} {printf("%d         %s         BOOLEAN_OP\n",line,yytext);}
    {O}{R} {printf("%d         %s         BOOLEAN_OP\n",line,yytext);}
    {N}{O}{T} {printf("%d         %s         BOOLEAN_OP\n",line,yytext);}
    {I}{N}{T}{E}{G}{E}{R} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {R}{E}{A}{L} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {B}{O}{O}{L}{E}{A}{N} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {C}{H}{A}{R} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {V}{A}{R} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {A}{R}{R}{A}{Y} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {D}{O}{W}{N}{T}{O} {printf("%d         %s         KEYWORD\n",line,yytext);}
    {T}{O} {printf("%d         %s         KEYWORD\n",line,yytext);}
    [A-Za-z][A-Za-z0-9|_]* {printf("%d         %s         IDENTIFIER\n",line,yytext);}
    [1-9][0-9]*|"0" {printf("%d         %s         CONSTANT\n",line,yytext);}
    "\"" {printf("%d         %s         DQUOTE\n",line,yytext);BEGIN(STRING);}
    "[" {printf("%d         %s         OPEN_BRACKET\n",line,yytext);}
    "]" {printf("%d         %s         CLOSE_BRACKET\n",line,yytext);}
    "(" {printf("%d         %s         OPEN_PARANTHESES\n",line,yytext);}
    ")" {printf("%d         %s         CLOSE_PARANTHESES\n",line,yytext);}
    ":" {printf("%d         %s         COLON\n",line,yytext);}
    "," {printf("%d         %s         COMMA\n",line,yytext);}
    "+" {printf("%d         %s         ARITHEMATIC_OP\n",line,yytext);}
    "-" {printf("%d         %s         ARITHEMATIC_OP\n",line,yytext);}
    "*" {printf("%d         %s         ARITHEMATIC_OP\n",line,yytext);}
    "/" {printf("%d         %s         ARITHEMATIC_OP\n",line,yytext);}
    "%" {printf("%d         %s         ARITHEMATIC_OP\n",line,yytext);}
    ":=" {printf("%d         %s         ASSIGNMENT_OP\n",line,yytext);}
    "=" {printf("%d         %s         RELATIONAL_OP\n",line,yytext);}
    "<" {printf("%d         %s         RELATIONAL_OP\n",line,yytext);}
    ">" {printf("%d         %s         RELATIONAL_OP\n",line,yytext);}
    "<=" {printf("%d         %s         RELATIONAL_OP\n",line,yytext);}
    ">=" {printf("%d         %s         RELATIONAL_OP\n",line,yytext);}
    "<>" {printf("%d         %s         RELATIONAL_OP\n",line,yytext);}
    "."  {printf("%d         %s         PERIOD\n",line,yytext);}
    ".." {printf("%d         %s         RANGE_DOTS\n",line,yytext);}
    . {printf("%d         %s         INVALID\n",line,yytext);}
}

<STRING>{
    "\"" {char* x=yytext ;
            char c= x[strlen(x)-1];
            x[strlen(x)-1]='\0'; 
            printf("%d         %s         STRING_CONSTANT\n",line,x);
            printf("%d         %c         DQUOTE\n",line,c);
            BEGIN(INITIAL);}
    "\n" {char* x=yytext ;
        x[strlen(x)-1]='\0';
        printf("%d         %s         INVALID\n",line,x);
        line++;
        BEGIN(INITIAL);}
    . {yymore();}
}

<COMMENT>{
    \n {BEGIN(INITIAL);}
    [[A-Za-z]*[0-9]*]* {}
    . {}
}

%%

int main(){
    printf("Enter the filename: ");
    char filename[100];
    scanf("%s", filename);
    printf("\n\n");
    yyin=fopen(filename, "r");
    printf("LINE_NO      LEXEME      TOKEN\n\n");
    yylex();
    return 0;
}

int yywrap(){
	return -1;
}
