%{
# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern FILE *yyin;
int yylex();
int yyerror();


typedef struct symbol {
    char name[100];
    char type[100];
    int value;
    struct symbol* next;
} symbol;

symbol* symbol_table = NULL;


void add_symbol(const char*, const char*);
symbol* find_symbol(const char*);
char * tolowercase(char *);
void printTable();
void reverseTAC();
void printFormatted();
void reverseWrite();
void printTempTable();

typedef struct TAC{
    char op[100];
    char arg1[100];
    char arg2[100];
    char result[100];
    struct TAC* next;
} TAC;

TAC* TAC_table = NULL;

typedef struct Stack{
    char* data;
    struct Stack* next;
}stack;

stack* top = NULL;

int qindex=0;
int lindex=0;
int wcount=1;

typedef struct stringConstants{
    char* sc;
    struct stringConstants* next;
} sc;

typedef struct variables{
    char* var;
    struct variables* next;
} var;

typedef struct writeTable{
    sc* sc;
    var* var;
    char* order;
    struct writeTable* next;
} wt;

wt* write_table=NULL;

typedef struct temporaryVariables{
    char* temp;
    char* type;
    char* value;
    struct temporaryVariables* next;
} temp;

temp* temp_table=NULL;

void addTAC(const char*, const char*, const char*, const char*);
void printTAC();
void push(char*);
char* pop();
void printFormatted();
void initialiseWriteTableElement();
void addSC(const char*);
void addVar(const char*);
void printWriteTable();
void parseTAC();


%}

%union{
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
}


%left ARITHEMATIC_OP_PLUS ARITHEMATIC_OP_MINUS
%left ARITHEMATIC_OP_MUL ARITHEMATIC_OP_DIV ARITHEMATIC_OP_MOD
%left BOOLEAN_OP
%left BOOLEAN_OP_NOT
%left RELATIONAL_OP
%left ASSIGNMENT_OP

%token <sval> IDENTIFIER STRING_CONSTANT INTEGER REAL BOOLEAN CHAR BOOLEAN_OP BOOLEAN_OP_NOT ASSIGNMENT_OP RELATIONAL_OP CHAR_CONSTANT
%token <sval> ARITHEMATIC_OP_PLUS ARITHEMATIC_OP_DIV ARITHEMATIC_OP_MUL ARITHEMATIC_OP_MINUS IF WHILE ARITHEMATIC_OP_MOD
%token <ival> INTEGER_CONSTANT
%token <dval> FLOAT_CONSTANT
%token PROGRAM SEMICOLON ELSE FOR DO BEGIN_TAG END WRITE READ DOWNTO TO OF COLON VAR ARRAY THEN
%token COMMA OPEN_BRACKET OPEN_PARANTHESIS CLOSE_BRACKET CLOSE_PARANTHESIS PERIOD RANGE_DOTS 



%%

start: PROGRAM IDENTIFIER SEMICOLON variable_declaration program_declaration PERIOD {printf("Valid Input\n");
                                                                                    parseTAC();
                                                                                    printTAC();
                                                                                    // reverseWrite();
                                                                                    // printWriteTable();
                                                                                    printTempTable();
                                                                                    }

variable_declaration: VAR variable_list 
                    | ;
variable_list: variable_line 
                |variable_line variable_list

variable_line: left_side_vars COLON rigth_side_type SEMICOLON 
left_side_vars: IDENTIFIER {
                    char * temp; temp=(char*)malloc(100*sizeof(char));
                    strcpy(temp,$1.val);
                    temp=tolowercase(temp);
                    add_symbol(temp, "undefined");
                }
                |IDENTIFIER COMMA left_side_vars {
                    char * temp; temp=(char*)malloc(100*sizeof(char));
                    strcpy(temp,$1.val);
                    temp=tolowercase(temp);
                    add_symbol(temp, "undefined");
                }

rigth_side_type: datatype 
                |ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF INTEGER{
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_INTEGER");
                        }
                        current = current->next;
                    }
                } 
                |ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF REAL {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_REAL");
                        }
                        current = current->next;
                    }
                }
                |ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF BOOLEAN {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_BOOLEAN");
                        }
                        current = current->next;
                    }
                }
                |ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF CHAR {
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0) {
                            strcpy(current->type, "ARRAY_CHAR");
                        }
                        current = current->next;
                    }
                } 


datatype: INTEGER {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "INTEGER");
                }
                current = current->next;
            }}
        |REAL {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "REAL");
                }
                current = current->next;
            }}
        |BOOLEAN {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "BOOLEAN");
                }
                current = current->next;
            }} 
        |CHAR {
            symbol* current = symbol_table;
            while (current != NULL) {
                if (strcmp(current->type, "undefined") == 0) {
                    strcpy(current->type, "CHAR");
                }
                current = current->next;
            }}


program_declaration: BEGIN_TAG statements END 
        | BEGIN_TAG END 

statements: statementline 
            |statementline statements 

statementline: WRITE {initialiseWriteTableElement();} OPEN_PARANTHESIS possible_writes CLOSE_PARANTHESIS SEMICOLON {
    char * str=(char *)malloc(100*sizeof(char));
    sprintf(str,"%d",wcount);
    addTAC("WRITE",str,"","");
    wcount++;}
                |READ OPEN_PARANTHESIS possible_reads CLOSE_PARANTHESIS SEMICOLON 
                |IDENTIFIER ASSIGNMENT_OP arith_expression SEMICOLON{
                    addTAC($2.val,pop(), "", $1.val);
                }                                                     
                |left_array_assignment ASSIGNMENT_OP arith_expression SEMICOLON {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    char *id2=(char*)malloc(100*sizeof(char));
                    strcpy(id2,pop());
                    pop();
                    addTAC($2.val,id,"",id2);
                }
                |left_if middle_if right_if SEMICOLON 
                |left_if middle_if SEMICOLON 
                |FOR for_conditionals1 DO program_declaration SEMICOLON {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("+",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
                |FOR for_conditionals2 DO program_declaration SEMICOLON {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("-",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
                |FOR for_conditionals3 DO program_declaration SEMICOLON {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("+",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
                |FOR for_conditionals4 DO program_declaration SEMICOLON {
                    char *id=(char*)malloc(100*sizeof(char));
                    strcpy(id,pop());
                    addTAC("-",id,"1",id);
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }
                |while_left DO program_declaration SEMICOLON {
                    addTAC("GOTO",pop(),"","");
                    addTAC("LABEL",pop(),"","");
                }

while_left :WHILE condition {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp1[10];
    sprintf(temp1, "%d", lindex);
    strcat(str,temp1);
    lindex++;
    addTAC("LABEL",str,"","");
    char * str1= (char *)malloc(100*sizeof(char));
    strcpy(str1,"L");
    char temp2[10];
    sprintf(temp2,"%d",lindex);
    strcat(str1,temp2);
    lindex++;
    char * str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,"L");
    char temp3[10];
    sprintf(temp3, "%d", lindex);
    strcat(str2,temp3);
    lindex++;
    addTAC("IF",pop(),"GOTO",str1);
    push(str2);
    push(str);
    addTAC("GOTO",str2,"","");
    addTAC("LABEL",str1,"","");
    
}

left_if: IF condition{
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp[10];
    sprintf(temp, "%d", lindex);
    strcat(str,temp);
    lindex++;
    addTAC("IF",pop(),"GOTO",str);
    char* str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,"L");
    char temp2[10];
    sprintf(temp2, "%d", lindex);
    strcat(str2,temp2);
    addTAC("GOTO",str2,"","");
    addTAC("LABEL",str,"","");
    push(str2);
    lindex++;
    
}

middle_if: THEN program_declaration{
    addTAC("LABEL",pop(),"","");
}

right_if: ELSE program_declaration

left_array_assignment: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp1[10];
    sprintf(temp1, "%d", lindex);
    strcat(str,temp1);
    lindex++;
    addTAC("LABEL",str,"","");
    char *id=(char*)malloc(100*sizeof(char));
    strcpy(id,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(id,temp);
    addTAC("&",$1.val,"",id);
    qindex++;
    char *dt=(char*)malloc(100*sizeof(char));
    strcpy(dt,"t");
    char temp2[10];
    sprintf(temp2, "%d", qindex);
    strcat(dt,temp2);
    char*typ=(char *)malloc(100*sizeof(char));
    $1.val=tolowercase($1.val);
    strcpy(typ,find_symbol($1.val)->type);
    char *subStr = NULL;
    char *underscorePos = strchr(typ, '_');
    subStr = underscorePos + 1;
    addTAC("sizeof",subStr,"",dt);
    qindex++;
    char *id2=(char*)malloc(100*sizeof(char));
    strcpy(id2,"t");
    char temp3[10];
    sprintf(temp3, "%d", qindex);
    strcat(id2,temp3);
    addTAC("*",dt,pop(),id2);
    qindex++;
    char *id3=(char*)malloc(100*sizeof(char));
    strcpy(id3,"t");
    char temp4[10];
    sprintf(temp4, "%d", qindex);
    strcat(id3,temp4);
    addTAC("+",id,id2,id3);
    qindex++;
    char * start=(char*)malloc(100*sizeof(char));
    strcpy(start,"*");
    strcat(start,id3);
    push(str);
    push(start);
}

for_conditionals1: IDENTIFIER ASSIGNMENT_OP arith_expression TO arith_expression{
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp1[10];
    sprintf(temp1, "%d", lindex);
    strcat(str,temp1);
    lindex++;
    char * str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,pop());
    char * str1=(char *)malloc(100*sizeof(char));
    strcpy(str1,pop());
    addTAC("LABEL",str,"","");
    addTAC($2.val,str1,"",$1.val);
    char* cond=(char *)malloc(100*sizeof(char));
    strcpy(cond,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(cond,temp);
    addTAC(">",$1.val,str2,cond);
    qindex++;
    char* str3=(char *)malloc(100*sizeof(char));
    strcpy(str3,"L");
    char temp2[10];
    sprintf(temp2, "%d", lindex);
    strcat(str3,temp2);
    addTAC("IF",cond,"GOTO",str3);
    push(str3);
    push(str);
    push($1.val);
    lindex++;
}

for_conditionals2: IDENTIFIER ASSIGNMENT_OP arith_expression DOWNTO arith_expression{
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp1[10];
    sprintf(temp1, "%d", lindex);
    strcat(str,temp1);
    lindex++;
    char * str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,pop());
    char * str1=(char *)malloc(100*sizeof(char));
    strcpy(str1,pop());
    addTAC("LABEL",str,"","");
    addTAC($2.val,str1,"",$1.val);
    char* cond=(char *)malloc(100*sizeof(char));
    strcpy(cond,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(cond,temp);
    addTAC("<",$1.val,str2,cond);
    qindex++;
    char* str3=(char *)malloc(100*sizeof(char));
    strcpy(str3,"L");
    char temp2[10];
    sprintf(temp2, "%d", lindex);
    strcat(str3,temp2);
    addTAC("IF",cond,"GOTO",str3);
    push(str3);
    push(str);
    push($1.val);
    lindex++;
}

for_conditionals3: left_array_assignment ASSIGNMENT_OP arith_expression TO arith_expression{
    char * str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,pop());
    char * str1=(char *)malloc(100*sizeof(char));
    strcpy(str1,pop());
    char* str4=(char *)malloc(100*sizeof(char));
    strcpy(str4,pop());
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,pop());
    addTAC($2.val,str1,"",str4);
    char* cond=(char *)malloc(100*sizeof(char));
    strcpy(cond,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(cond,temp);
    addTAC(">=",str4,str2,cond);
    qindex++;
    char* str3=(char *)malloc(100*sizeof(char));
    strcpy(str3,"L");
    char temp2[10];
    sprintf(temp2, "%d", lindex);
    strcat(str3,temp2);
    addTAC("IF",cond,"GOTO",str3);
    push(str3);
    push(str);
    push(str4);
    lindex++;
}

for_conditionals4: left_array_assignment ASSIGNMENT_OP arith_expression DOWNTO arith_expression{
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"L");
    char temp1[10];
    sprintf(temp1, "%d", lindex);
    strcat(str,temp1);
    lindex++;
    addTAC("LABEL",str,"","");
    char * str2=(char *)malloc(100*sizeof(char));
    strcpy(str2,pop());
    char * str1=(char *)malloc(100*sizeof(char));
    strcpy(str1,pop());
    char* str4=(char *)malloc(100*sizeof(char));
    strcpy(str4,pop());
    addTAC($2.val,str1,"",str4);
    char* cond=(char *)malloc(100*sizeof(char));
    strcpy(cond,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(cond,temp);
    addTAC("<=",str4,str2,cond);
    qindex++;
    char* str3=(char *)malloc(100*sizeof(char));
    strcpy(str3,"L");
    char temp2[10];
    sprintf(temp2, "%d", lindex);
    strcat(str3,temp2);
    addTAC("IF",cond,"GOTO",str3);
    push(str3);
    push(str);
    push(str1);
    lindex++;
}

condition: conditionals
            |unit


conditionals:   condtional_unit 
                | relational_exp 
                |relational_exp BOOLEAN_OP conditionals {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC($2.val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
                | relational_exp BOOLEAN_OP unit {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC($2.val,pop(), pop(), str);
                    qindex++;
                    push(str);
                } 
                |unit BOOLEAN_OP conditionals {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC($2.val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
                | unit BOOLEAN_OP unit {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC($2.val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
                | BOOLEAN_OP_NOT conditionals {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC($1.val,pop(), "", str);
                    qindex++;
                    push(str);
                }
                

condtional_unit:BOOLEAN_OP_NOT unit {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(str,temp);
    addTAC($1.val,pop(), "", str);
    qindex++;
    push(str);
}

relational_exp: arith_expression RELATIONAL_OP arith_expression {
    char * str=(char *)malloc(100*sizeof(char));
    strcpy(str,"t");
    char temp[10];
    sprintf(temp, "%d", qindex);
    strcat(str,temp);
    addTAC($2.val,pop(), pop(), str);
    qindex++;
    push(str);
    }

left_side_vars_write: IDENTIFIER {addVar($1.val);}
                |IDENTIFIER COMMA left_side_vars_write {addVar($1.val);}
                |STRING_CONSTANT {
                            addSC($1.val);
                        }

possible_writes: possible_write_values
    | ;

possible_write_values: left_side_vars_write 
                        |STRING_CONSTANT COMMA possible_write_values {
                            addSC($1.val);
                        }
                        | IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {pop();}

possible_reads: IDENTIFIER 
                |IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {pop();}


arith_expression: unit_2 
                |unit 
                | OPEN_PARANTHESIS arith_expression CLOSE_PARANTHESIS 
                | arith_expression ARITHEMATIC_OP_PLUS arith_expression { 
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC($2.val,pop(), pop(), str);
                    qindex++;
                    push(str);}
                | arith_expression ARITHEMATIC_OP_MINUS arith_expression{
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC($2.val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
                | arith_expression ARITHEMATIC_OP_MUL arith_expression{
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC($2.val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
                | arith_expression ARITHEMATIC_OP_DIV arith_expression{
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC($2.val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }
                | arith_expression ARITHEMATIC_OP_MOD arith_expression {
                    char * str=(char *)malloc(100*sizeof(char));
                    strcpy(str,"t");
                    char temp[10];
                    sprintf(temp, "%d", qindex);
                    strcat(str,temp);
                    addTAC($2.val,pop(), pop(), str);
                    qindex++;
                    push(str);
                }


unit: IDENTIFIER {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%s",$1.val);
            push(str);
    }
    | IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {
            char *id=(char*)malloc(100*sizeof(char));
            strcpy(id,"t");
            char temp[10];
            sprintf(temp, "%d", qindex);
            strcat(id,temp);
            addTAC("&",$1.val,"",id);
            qindex++;
            char *dt=(char*)malloc(100*sizeof(char));
            strcpy(dt,"t");
            char temp2[10];
            sprintf(temp2, "%d", qindex);
            strcat(dt,temp2);
            char*typ=(char *)malloc(100*sizeof(char));
            $1.val=tolowercase($1.val);
            strcpy(typ,find_symbol($1.val)->type);
            char *subStr = NULL;
            char *underscorePos = strchr(typ, '_');
            subStr = underscorePos + 1;
            addTAC("sizeof",subStr,"",dt);
            qindex++;
            char *id2=(char*)malloc(100*sizeof(char));
            strcpy(id2,"t");
            char temp3[10];
            sprintf(temp3, "%d", qindex);
            strcat(id2,temp3);
            addTAC("*",dt,pop(),id2);
            qindex++;
            char *id3=(char*)malloc(100*sizeof(char));
            strcpy(id3,"t");
            char temp4[10];
            sprintf(temp4, "%d", qindex);
            strcat(id3,temp4);
            addTAC("+",id,id2,id3);
            qindex++;
            char * start=(char*)malloc(100*sizeof(char));
            strcpy(start,"*");
            strcat(start,id3);
            push(start);
        }

    |ARITHEMATIC_OP_MINUS arith_expression {
            char * str=(char *)malloc(100*sizeof(char));
            strcpy(str,"t");
            char temp[10];
            sprintf(temp, "%d", qindex);
            strcat(str,temp);
            addTAC($1.val,pop(), "", str);
            qindex++;
            push(str);
    }

unit_2: INTEGER_CONSTANT {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%d",$1.val);
            push(str);
    }
    | FLOAT_CONSTANT {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%f",$1.val);
            push(str);
    }
    | CHAR_CONSTANT {
            char * str=malloc(100*sizeof(char));
            sprintf(str,"%s",$1.val);
            push(str);
    }

%%

void add_symbol(const char* name, const char* type) {
    symbol* new_symbol = (symbol*)malloc(sizeof(symbol));
    strcpy(new_symbol->name, name);
    strcpy(new_symbol->type, type);
    new_symbol->next = symbol_table;
    symbol_table = new_symbol;
}

symbol* find_symbol(const char* name) {
    symbol* current = symbol_table;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printTable() {
    symbol* current = symbol_table;
    printf("\n\nSymbol Table\n");
    printf("Name\tType\n");
    while (current != NULL) {
        printf("%s\t%s\n", current->name, current->type);
        current = current->next;
    }
}

char * tolowercase(char *s){
    for(int i=0;i<strlen(s);i++){
        s[i]=tolower(s[i]);
    }
    return s;
}


void addTAC(const char* op, const char* arg1, const char* arg2, const char* result) {
    TAC* new_tac = (TAC*)malloc(sizeof(TAC));
    strcpy(new_tac->op, op);
    strcpy(new_tac->arg1, arg1);
    strcpy(new_tac->arg2, arg2);
    strcpy(new_tac->result, result);
    new_tac->next = TAC_table;
    TAC_table = new_tac;
}

void printTAC() {
    TAC* current = TAC_table;
    printf("\n\nThree Address Code\n");
    printf("Op\tArg1\tArg2\tResult\n");
    while (current != NULL) {
        printf("%s\t%s\t%s\t%s\n", current->op, current->arg1, current->arg2, current->result);
        current = current->next;
    }
}

void reverseTAC() {
    TAC* current = TAC_table;
    TAC* prev = NULL;
    TAC* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    TAC_table = prev;
}

void printFormatted(){
    TAC* current=TAC_table;
    printf("\n\nIntermediate Code:\n\n");
    while(current!=NULL){
        if(strcmp(current->op,"LABEL")==0){
            printf("%s:\n",current->arg1);
        }else if(strcmp(current->op,"GOTO")==0){
            printf("GOTO %s\n",current->arg1);
        }else if(strcmp(current->op,"IF")==0){
            printf("%s %s %s %s\n",current->op,current->arg1,current->arg2,current->result);
        }else if(strcmp(current->op,":=")==0){
            printf("%s = %s\n",current->result,current->arg1);
        }else if(strcmp(current->op,"sizeof")==0){
            printf("%s = sizeof(%s)\n",current->result,current->arg1);
        }else if(strcmp(current->op,"&")==0){
            printf("%s = &%s\n",current->result,current->arg1);
        }else{
            printf("%s = %s %s %s\n",current->result,current->arg1,current->op,current->arg2);
        }
        current=current->next;
    }
}

void push(char* data){
    stack* new_stack = (stack*)malloc(sizeof(stack));
    new_stack->data = data;
    new_stack->next = top;
    top = new_stack;
}

char* pop(){
    if(top == NULL){
        return NULL;
    }
    stack* temp = top;
    top = top->next;
    return temp->data;
}

void initialiseWriteTableElement(){
    wt* new_wt = (wt*)malloc(sizeof(wt));
    new_wt->sc = NULL;
    new_wt->var = NULL;
    new_wt->order= (char*)malloc(100*sizeof(char));
    new_wt->next = write_table;
    write_table = new_wt;
}

void addSC(const char* str){
    sc* new_sc = (sc*)malloc(sizeof(sc));
    new_sc->sc=(char*)malloc(100*sizeof(char));
    strcpy(new_sc->sc,str);
    new_sc->next = write_table->sc;
    strcat(write_table->order,"s");
    write_table->sc = new_sc;
}

void addVar(const char* v){
    var* new_var = (var*)malloc(sizeof(var));
    new_var->var=(char*)malloc(100*sizeof(char));
    strcpy(new_var->var ,v);
    new_var->next = write_table->var;
    strcat(write_table->order,"v");
    write_table->var = new_var;
}

void printWriteTable(){
    wt* current = write_table;
    printf("\n\nWrite Table\n");
    printf("Order\tString Constants\tVariables\n");
    while (current != NULL) {
        printf("%s\t", current->order);
        sc* sc_current = current->sc;
        while (sc_current != NULL) {
            printf("%s ", sc_current->sc);
            sc_current = sc_current->next;
        }
        printf("\t");
        var* var_current = current->var;
        while (var_current != NULL) {
            printf("%s ", var_current->var);
            var_current = var_current->next;
        }
        printf("\n");
        current = current->next;
    }
}

void addTemp(const char* name, const char* typ, const char* val){
    temp* new_temp = (temp*)malloc(sizeof(temp));
    new_temp->temp=(char*)malloc(100*sizeof(char));
    strcpy(new_temp->temp,name);
    new_temp->type=(char*)malloc(100*sizeof(char));
    strcpy(new_temp->type,typ);
    new_temp->value=(char*)malloc(100*sizeof(char));
    strcpy(new_temp->value,val);
    new_temp->next = temp_table;
    temp_table = new_temp;
}

void findLabelLocation(char* label){
    TAC* current = TAC_table;
    while (current != NULL) {
        if (strcmp(current->op, "LABEL") == 0 && strcmp(current->arg1, label) == 0) {
            break;
        }
        current = current->next;
    }
    TAC_table = current;
}

void reverseWrite(){
    wt* current = write_table;
    wt* prev = NULL;
    wt* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    write_table = prev;
}

temp* findTemp(const char* name){
    temp* current = temp_table;
    while (current != NULL) {
        if (strcmp(current->temp, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int ifFloat(char* str){
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='.'){
            return 1;
        }
    }
    return 0;
}

void parseTAC(){
    reverseTAC();
    TAC *current = TAC_table;
    while(current!=NULL){
        if(strcmp(current->op,"GOTO")==0){
            findLabelLocation(current->arg1);
        }else if(strcmp(current->op,"IF")==0){
            if(strcmp(current->arg1,"0")==1){
                findLabelLocation(current->result);
            }
        }else if(strcmp(current->op,":=")==0){
            if(current->arg1[0]!='t'){
                if (strlen(current->arg1)==3 && (current->arg1[0]=='\'' && current->arg1[2]=='\'')){
                    addTemp(current->result,"CHAR",current->arg1);
                }else if(ifFloat(current->arg1)){
                    addTemp(current->result,"REAL",current->arg1);
                }else{
                    addTemp(current->result,"INTEGER",current->arg1);
                }   
            }else{
                addTemp(current->result,findTemp(current->arg1)->type,findTemp(current->arg1)->value);
            }                                                                                                                                                                                                  
        }else if(strcmp(current->op,"+")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(ifFloat(current->arg1) || ifFloat(current->arg2)){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(current->arg1)+atof(current->arg2));
                    addTemp(current->result,"REAL",temp);    
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(current->arg1)+atoi(current->arg2));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(current->arg1)+atof(findTemp(current->arg2)->value));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(current->arg1)+atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(findTemp(current->arg1)->value)+atof(current->arg2));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)+atoi(current->arg2));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else{
                if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(findTemp(current->arg1)->value)+atof(findTemp(current->arg2)->value));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)+atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }
        }else if(strcmp(current->op,"-")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(ifFloat(current->arg1) || ifFloat(current->arg2)){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(current->arg1)-atof(current->arg2));
                    addTemp(current->result,"REAL",temp);    
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(current->arg1)-atoi(current->arg2));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(current->arg1)-atof(findTemp(current->arg2)->value));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(current->arg1)-atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(findTemp(current->arg1)->value)-atof(current->arg2));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)-atoi(current->arg2));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else{
                if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(findTemp(current->arg1)->value)-atof(findTemp(current->arg2)->value));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)-atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }
        }else if(strcmp(current->op,"*")==0){
            if(current->arg1[0]!='t' && current->arg2[0]!='t'){
                if(ifFloat(current->arg1) || ifFloat(current->arg2)){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(current->arg1)*atof(current->arg2));
                    addTemp(current->result,"REAL",temp);    
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(current->arg1)*atoi(current->arg2));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else if(current->arg1[0]!='t' && current->arg2[0]=='t'){
                if(ifFloat(current->arg1) || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(current->arg1)*atof(findTemp(current->arg2)->value));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(current->arg1)*atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else if(current->arg1[0]=='t' && current->arg2[0]!='t'){
                if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || ifFloat(current->arg2)){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(findTemp(current->arg1)->value)*atof(current->arg2));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)*atoi(current->arg2));
                    addTemp(current->result,"INTEGER",temp);
                }
            }else{
                if(strcmp(findTemp(current->arg1)->type,"REAL")==0 || strcmp(findTemp(current->arg2)->type,"REAL")==0){
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%f",atof(findTemp(current->arg1)->value)*atof(findTemp(current->arg2)->value));
                    addTemp(current->result,"REAL",temp);
                }else{
                    char* temp=(char*)malloc(100*sizeof(char));
                    sprintf(temp,"%d",atoi(findTemp(current->arg1)->value)*atoi(findTemp(current->arg2)->value));
                    addTemp(current->result,"INTEGER",temp);
                }
            }
        }
        
        current=current->next;
    }
}

void printTempTable(){
    temp* current = temp_table;
    printf("\n\nTemporary Variables Table\n");
    printf("Temp\tType\tValue\n");
    while (current != NULL) {
        printf("%s\t%s\t%s\n", current->temp, current->type, current->value);
        current = current->next;
    }
}

int main(int argc, char *argv[]){
    char* filename;
    filename=argv[1];
    yyin=fopen(filename, "r");
    yyparse();
    return 0;
}

int yyerror(){
    printf("Syntax Error\n\n");
    return 0;
}