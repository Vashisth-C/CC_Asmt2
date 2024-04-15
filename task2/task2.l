%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylval;

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
    ";" {return SEMICOLON;}
    {P}{R}{O}{G}{R}{A}{M} {return KEYWORD;}
    {I}{F} {return KEYWORD;}
    {T}{H}{E}{N} {return KEYWORD;}
    {E}{L}{S}{E} {return KEYWORD;}
    {W}{H}{I}{L}{E} {return KEYWORD;}
    {D}{O} {return KEYWORD;}
    {F}{O}{R} {return KEYWORD;}
    {O}{F} {return KEYWORD;}
    {B}{E}{G}{I}{N} {return KEYWORD;}
    {E}{N}{D} {return KEYWORD;}
    {R}{E}{A}{D} {return KEYWORD;}
    {W}{R}{I}{T}{E} {return KEYWORD;}
    {A}{N}{D} {return BOOLEAN_OP;}
    {O}{R} {return BOOLEAN_OP;}
    {N}{O}{T} {return BOOLEAN_OP;}
    {I}{N}{T}{E}{G}{E}{R} {return KEYWORD;}
    {R}{E}{A}{L} {return KEYWORD;}
    {B}{O}{O}{L}{E}{A}{N} {return KEYWORD;}
    {C}{H}{A}{R} {return KEYWORD;}
    {V}{A}{R} {return KEYWORD;}
    {A}{R}{R}{A}{Y} {return KEYWORD;}
    {D}{O}{W}{N}{T}{O} {return KEYWORD;}
    {T}{O} {return KEYWORD;}
    [A-Za-z][A-Za-z0-9|_]* {return IDENTIFIER;}
    [1-9][0-9]*|"0" {return CONSTANT;}
    "\"" {yymore(),BEGIN(STRING);}
    "[" {return OPEN_BRACKET;},
    "]" {return CLOSE_BRACKET;}
    "(" {return OPEN_PARANTHESIS;}
    ")" {return CLOSE_PARANTHESIS;}
    ":" {return COLON;}
    "," {return COMMA;}
    "+" {return ARITHEMATIC_OP;}
    "-" {return ARITHEMATIC_OP;}
    "*" {return ARITHEMATIC_OP;}
    "/" {return ARITHEMATIC_OP;}
    "%" {return ARITHEMATIC_OP;}
    ":=" {return ASSIGNMENT_OP;}
    "=" {return RELATIONAL_OP;}
    "<" {return RELATIONAL_OP;}
    ">" {return RELATIONAL_OP;}
    "<=" {return RELATIONAL_OP;}
    ">=" {return RELATIONAL_OP;}
    "<>" {return RELATIONAL_OP;}
    "."  {return PERIOD;}
    ".." {return RANGE_DOTS;}
}

<STRING>{
    "\"" {return CONSTANT;BEGIN(INITIAL);}
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
    // printf("LINE_NO      LEXEME      TOKEN\n\n");
    yylex();
    return 0;
}

int yywrap(){
	return -1;
}
