%{
# include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
%}

%left ARITHEMATIC_OP
%left BOOLEAN_OP

%token IDENTIFIER CONSTANT ARITHEMATIC_OP RELATIONAL_OP ASSIGNMENT_OP SEMICOLON COMMA BOOLEAN_OP OPEN_BRACKET OPEN_PARANTHESIS CLOSE_BRACKET CLOSE_PARANTHESIS PERIOD RANGE_DOTS 
%token IF WHILE ELSE FOR DO BEGIN_TAG END WRITE READ PROGRAM STRING_CONSTANT DOWNTO TO OF COLON VAR DATATYPE ARRAY THEN BOOLEAN_OP_NOT

%%

start: PROGRAM IDENTIFIER SEMICOLON variable_declaration program_declaration PERIOD  {printf("Program is correct\n");};

variable_declaration: VAR variable_list| ;
variable_list: variable_line|variable_line variable_list
variable_line: left_side_vars COLON rigth_side_type SEMICOLON
left_side_vars: IDENTIFIER|IDENTIFIER COMMA left_side_vars
rigth_side_type: DATATYPE|ARRAY OPEN_BRACKET CONSTANT RANGE_DOTS CONSTANT CLOSE_BRACKET OF DATATYPE

program_declaration: BEGIN_TAG statements END

statements: statementline|statementline statements ;

statementline: WRITE OPEN_PARANTHESIS possible_writes CLOSE_PARANTHESIS SEMICOLON |
                READ OPEN_PARANTHESIS possible_reads CLOSE_PARANTHESIS SEMICOLON | 
                IDENTIFIER ASSIGNMENT_OP expression SEMICOLON |
                IF OPEN_PARANTHESIS conditionals CLOSE_PARANTHESIS THEN program_declaration ELSE program_declaration SEMICOLON |
                IF OPEN_PARANTHESIS conditionals CLOSE_PARANTHESIS THEN program_declaration SEMICOLON |
                IF conditionals THEN program_declaration ELSE program_declaration SEMICOLON |
                IF conditionals THEN program_declaration SEMICOLON |
                WHILE OPEN_PARANTHESIS conditionals CLOSE_PARANTHESIS DO program_declaration SEMICOLON |
                FOR IDENTIFIER ASSIGNMENT_OP expression TO expression DO program_declaration SEMICOLON |
                FOR IDENTIFIER ASSIGNMENT_OP expression DOWNTO expression DO program_declaration SEMICOLON |
                WHILE conditionals DO program_declaration SEMICOLON  
                
conditionals: expression RELATIONAL_OP expression

possible_writes: possible_write_values| ;
possible_write_values: left_side_vars|STRING_CONSTANT|STRING_CONSTANT COMMA possible_write_values 
possible_reads: IDENTIFIER|IDENTIFIER OPEN_BRACKET expression CLOSE_BRACKET

expression: unit| OPEN_PARANTHESIS expression CLOSE_PARANTHESIS | expression ARITHEMATIC_OP expression | expression BOOLEAN_OP expression
unit: IDENTIFIER|CONSTANT| IDENTIFIER OPEN_BRACKET expression CLOSE_BRACKET| BOOLEAN_OP_NOT unit 

%%

int main(){
    printf("Enter the filename: ");
    char filename[100];
    scanf("%s", filename);
    printf("\n\n");
    yyin=fopen(filename, "r");
    yyparse();
    return 0;
}

int yyerror(){
    printf("Syntax Error\n");
    return 0;
}