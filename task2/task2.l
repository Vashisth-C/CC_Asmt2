%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"

int line = 1;
%}

%x COMMENT

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

DIGIT [0-9]

REALNUMBER {DIGIT}+"."{DIGIT}+

%%

<INITIAL>{
    {SPACE} {}
    \n {line++;}
    "//" {line++,BEGIN(COMMENT);}
    ";" {return SEMICOLON;}
    {P}{R}{O}{G}{R}{A}{M} {return PROGRAM;}
    {I}{F} {return IF;}
    {T}{H}{E}{N} {return THEN;}
    {E}{L}{S}{E} {return ELSE;}
    {W}{H}{I}{L}{E} {return WHILE;}
    {D}{O} {return DO;}
    {F}{O}{R} {return FOR;}
    {O}{F} {return OF;}
    {B}{E}{G}{I}{N} {return BEGIN_TAG;}
    {E}{N}{D} {return END;}
    {R}{E}{A}{D} {return READ;}
    {W}{R}{I}{T}{E} {return WRITE;}
    {A}{N}{D} {return BOOLEAN_OP;}
    {O}{R} {return BOOLEAN_OP;}
    {N}{O}{T} {return BOOLEAN_OP_NOT;}
    {I}{N}{T}{E}{G}{E}{R} {return DATATYPE;}
    {R}{E}{A}{L} {return DATATYPE;}
    {B}{O}{O}{L}{E}{A}{N} {return DATATYPE;}
    {C}{H}{A}{R} {return DATATYPE;}
    {V}{A}{R} {return VAR;}
    {A}{R}{R}{A}{Y} {return ARRAY;}
    {D}{O}{W}{N}{T}{O} {return DOWNTO;}
    {T}{O} {return TO;}
    [A-Za-z][A-Za-z0-9|_]* {return IDENTIFIER;}
    [1-9][0-9]*|"0" {return CONSTANT;}
    {REALNUMBER} {return CONSTANT;}
    "\"".*"\"" {return STRING_CONSTANT;}
    "[" {return OPEN_BRACKET;}
    "]" {return CLOSE_BRACKET;}
    "(" {return OPEN_PARANTHESIS;}
    ")" {return CLOSE_PARANTHESIS;}
    ":" {return COLON;}
    "," {return COMMA;}
    "+" {return ARITHEMATIC_OP;}
    "-" {return ARITHEMATIC_OP_MINUS;}
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

<COMMENT>{
    \n {BEGIN(INITIAL);}
    [[A-Za-z]*[0-9]*]* {}
    . {}
}

%%

int yywrap(){
	return -1;
}
