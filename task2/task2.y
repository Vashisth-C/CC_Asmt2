%{
# include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
int yylex();
int yyerror();
%}


%left ARITHEMATIC_OP
%left BOOLEAN_OP
%left ARITHEMATIC_OP_MINUS
%right RELATIONAL_OP
%left BOOLEAN_OP_NOT

%token IDENTIFIER CONSTANT ARITHEMATIC_OP RELATIONAL_OP ASSIGNMENT_OP SEMICOLON COMMA BOOLEAN_OP OPEN_BRACKET OPEN_PARANTHESIS CLOSE_BRACKET CLOSE_PARANTHESIS PERIOD RANGE_DOTS 
%token IF WHILE ELSE FOR DO BEGIN_TAG END WRITE READ PROGRAM STRING_CONSTANT DOWNTO TO OF COLON VAR DATATYPE ARRAY THEN BOOLEAN_OP_NOT ARITHEMATIC_OP_MINUS

%%

start: PROGRAM IDENTIFIER SEMICOLON variable_declaration program_declaration PERIOD  {printf("Valid Input\n\n");};

variable_declaration: VAR variable_list| ;
variable_list: variable_line|variable_line variable_list
variable_line: left_side_vars COLON rigth_side_type SEMICOLON
left_side_vars: IDENTIFIER|IDENTIFIER COMMA left_side_vars
rigth_side_type: DATATYPE|ARRAY OPEN_BRACKET CONSTANT RANGE_DOTS CONSTANT CLOSE_BRACKET OF DATATYPE

program_declaration: BEGIN_TAG statements END| BEGIN_TAG END

statements: statementline|statementline statements;

statementline: WRITE OPEN_PARANTHESIS possible_writes CLOSE_PARANTHESIS SEMICOLON |
                READ OPEN_PARANTHESIS possible_reads CLOSE_PARANTHESIS SEMICOLON | 
                IDENTIFIER ASSIGNMENT_OP arith_expression SEMICOLON |    
                IF condition THEN program_declaration ELSE program_declaration SEMICOLON |
                IF condition THEN program_declaration SEMICOLON |
                FOR IDENTIFIER ASSIGNMENT_OP arith_expression TO arith_expression DO program_declaration SEMICOLON |
                FOR IDENTIFIER ASSIGNMENT_OP arith_expression DOWNTO arith_expression DO program_declaration SEMICOLON |
                WHILE condition DO program_declaration SEMICOLON 

condition: conditional_head|unit_x

conditional_head: relational_exp|conditionals
conditionals:   condtional_unit|
                relational_exp BOOLEAN_OP conditionals| relational_exp BOOLEAN_OP unit_x| 
                unit_x BOOLEAN_OP conditionals | unit_x BOOLEAN_OP unit_x | BOOLEAN_OP_NOT conditionals|
                OPEN_PARANTHESIS conditionals CLOSE_PARANTHESIS
                

condtional_unit:BOOLEAN_OP_NOT unit_x

relational_exp: arith_expression RELATIONAL_OP arith_expression|
                OPEN_PARANTHESIS relational_exp CLOSE_PARANTHESIS

possible_writes: possible_write_values| ;
possible_write_values: left_side_vars|STRING_CONSTANT|STRING_CONSTANT COMMA possible_write_values| IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET
possible_reads: IDENTIFIER|IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET


arith_expression: unit_2|unit| OPEN_PARANTHESIS arith_expression CLOSE_PARANTHESIS | arith_expression ARITHEMATIC_OP arith_expression| 
                    arith_expression ARITHEMATIC_OP_MINUS arith_expression


unit_x: unit | OPEN_PARANTHESIS unit CLOSE_PARANTHESIS
unit: IDENTIFIER| IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET|ARITHEMATIC_OP_MINUS arith_expression
unit_2: CONSTANT

%%

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