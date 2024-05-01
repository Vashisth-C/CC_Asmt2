%{
# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern FILE *yyin;
int yylex();
int yyerror();

typedef struct node{
    char lexeme[100];
    int NumChild;
    char type[100];
    struct node **child;
} node;

typedef struct symbol {
    char name[100];
    char type[100];
    int value;
    struct symbol* next;
} symbol;

symbol* symbol_table = NULL;

struct node* make_binary_node(char*, node*, node*);
struct node* make_leaf(char* );
struct node* make_ternary_node(char* , node* , node* ,node* );
struct node* make_unary_node(char* , node* );
void AST_print(struct node* );
void writeToFile(struct node* );
void preOrderTraversal(struct node* , char* );
void add_symbol(const char*, const char*);
symbol* find_symbol(const char*);
char * tolowercase(char *);
void printTable();

typedef struct error{
    char error[100];
    struct error* next;
} error;

error* error_table = NULL;

void addError(const char*);
void printErrors();

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
    struct node* node;
}


%left ARITHEMATIC_OP_PLUS ARITHEMATIC_OP_MINUS
%left ARITHEMATIC_OP_MUL ARITHEMATIC_OP_DIV ARITHEMATIC_OP_MOD
%left BOOLEAN_OP
%right RELATIONAL_OP
%left BOOLEAN_OP_NOT

%token <sval> BOOLEAN_OP_NOT ASSIGNMENT_OP RELATIONAL_OP ARITHEMATIC_OP_PLUS ARITHEMATIC_OP_MINUS IF WHILE CHAR_CONSTANT
%token <sval> IDENTIFIER STRING_CONSTANT INTEGER REAL BOOLEAN CHAR BOOLEAN_OP ARITHEMATIC_OP_MUL ARITHEMATIC_OP_DIV ARITHEMATIC_OP_MOD
%token <ival> INTEGER_CONSTANT
%token <dval> FLOAT_CONSTANT
%token <node> PROGRAM SEMICOLON ELSE FOR DO BEGIN_TAG END WRITE READ DOWNTO TO OF COLON VAR ARRAY THEN
%token <node> COMMA OPEN_BRACKET OPEN_PARANTHESIS CLOSE_BRACKET CLOSE_PARANTHESIS PERIOD RANGE_DOTS 


%type <node> start variable_declaration program_declaration variable_list variable_line left_side_vars  statementline for_conditionals1 for_conditionals2
%type <node> relational_exp conditionals condtional_unit left_side_vars_write left_array_assignment for_conditionals3 for_conditionals4
%type <node> possible_writes possible_write_values possible_reads arith_expression unit condition rigth_side_type datatype unit_2 statements

%%

start: PROGRAM IDENTIFIER SEMICOLON variable_declaration program_declaration PERIOD {$1=make_leaf("PROGRAM");
                                                                                    $6=make_binary_node(";",$4,$5);
                                                                                    $$=make_binary_node($2.val,$1,$6);
                                                                                    node* t=$$;
                                                                                    add_symbol($2.val,"PROGRAM");
                                                                                    symbol_table->value=1;
                                                                                    while(t->child!=NULL){
                                                                                        t=t->child[t->NumChild-1];
                                                                                    }
                                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                                    t->child[0]=make_leaf(".");
                                                                                    t->NumChild++;
                                                                                    if(error_table!=NULL){
                                                                                        printf("\nRun the Python file to see AST\n\n");
                                                                                        printf("\n\n");
                                                                                        printErrors();
                                                                                    }
                                                                                    else{
                                                                                        printf("\n");
                                                                                        printf("No Errors\nRun the Python file to see AST");
                                                                                        printf("\n");
                                                                                    }
                                                                                    writeToFile($$);
                                                                                      };

variable_declaration: VAR variable_list {$$=make_unary_node("VAR",$2);}
                    | {$$=NULL;};
variable_list: variable_line { $$=$1;}
                |variable_line variable_list {
                    node* ptr=$1;
                    while(ptr->child!=NULL){
                        ptr=ptr->child[ptr->NumChild-1];
                    }
                    ptr->child=(struct node**)malloc(sizeof(struct node*));
                    ptr->child[0]=$2;
                    ptr->NumChild++;
                    $$=$1;
                    }

variable_line: left_side_vars COLON rigth_side_type SEMICOLON { struct node * temp1=make_leaf(";");
                                                                $$=make_binary_node(":",$1,$3);}
left_side_vars: IDENTIFIER { char * temp; temp=(char*)malloc(100*sizeof(char));
                            strcpy(temp,$1.val);
                            temp=tolowercase(temp);
                            if(find_symbol(temp)==NULL){
                                add_symbol(temp,"undefined");
                                symbol_table->value=0;
                                }
                            else{
                                char *errormsg=(char*)malloc(100*sizeof(char));
                                sprintf(errormsg,"Multiple Declarations of the variable: %s at line number: %d",$1.val,$1.line);
                                addError(errormsg);
                                }
                            $$=make_leaf($1.val);}
                |IDENTIFIER COMMA left_side_vars { char * temp; temp=(char*)malloc(100*sizeof(char));
                                                strcpy(temp,$1.val);
                                                temp=tolowercase(temp);
                                                if(find_symbol(temp)==NULL){
                                                    add_symbol(temp,"undefined");
                                                    symbol_table->value=0;
                                                    }
                                                    else{
                                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                                        sprintf(errormsg,"Multiple Declarations of the variable: %s at line number: %d",$1.val,$1.line);
                                                        addError(errormsg);
                                                    };
                                                    struct node * temp1=make_leaf($1.val);
                                                    $$=make_binary_node(",",temp1,$3);}

rigth_side_type: datatype { $$=$1;}
                |ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF INTEGER {
                        symbol* current = symbol_table;
                        while (current != NULL) {
                            if (strcmp(current->type, "undefined") == 0) {
                                strcpy(current->type, "ARRAY_INTEGER");
                            }
                            current = current->next;
                        }
                        $1= make_leaf("ARRAY");
                        $2=make_unary_node("l_brace",$1);
                        char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%d",$3.val);
                        node* temp1=make_unary_node(temp,$2);
                        node * sc=make_leaf(";");
                        node* dt=make_unary_node("INTEGER",sc);
                        $7=make_unary_node("OF",dt);
                        $6=make_unary_node("r_brace",$7);
                        char* temp3; temp3=(char*)malloc(100*sizeof(char));
                        sprintf(temp3,"%d",$5.val);
                        node* temp2=make_unary_node(temp3,$6);
                        $$=make_binary_node("..",temp1,temp2);}
                |ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF REAL {
                        symbol* current = symbol_table;
                        while (current != NULL) {
                            if (strcmp(current->type, "undefined") == 0) {
                                strcpy(current->type, "ARRAY_REAL");
                            }
                            current = current->next;
                        }
                        $1= make_leaf("ARRAY");
                        $2=make_unary_node("l_brace",$1);
                        char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%d",$3.val);
                        node* temp1=make_unary_node(temp,$2);
                        node * sc=make_leaf(";");
                        node* dt=make_unary_node("REAL",sc);
                        $7=make_unary_node("OF",dt);
                        $6=make_unary_node("r_brace",$7);
                        char* temp3; temp3=(char*)malloc(100*sizeof(char));
                        sprintf(temp3,"%d",$5.val);
                        node* temp2=make_unary_node(temp3,$6);
                        $$=make_binary_node("..",temp1,temp2);}
                |ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF BOOLEAN {
                        symbol* current = symbol_table;
                        while (current != NULL) {
                            if (strcmp(current->type, "undefined") == 0) {
                                strcpy(current->type, "ARRAY_BOOLEAN");
                            }
                            current = current->next;
                        }
                        $1= make_leaf("ARRAY");
                        $2=make_unary_node("l_brace",$1);
                        char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%d",$3.val);
                        node* temp1=make_unary_node(temp,$2);
                        node * sc=make_leaf(";");
                        node* dt=make_unary_node("BOOLEAN",sc);
                        $7=make_unary_node("OF",dt);
                        $6=make_unary_node("r_brace",$7);
                        char* temp3; temp3=(char*)malloc(100*sizeof(char));
                        sprintf(temp3,"%d",$5.val);
                        node* temp2=make_unary_node(temp3,$6);
                        $$=make_binary_node("..",temp1,temp2);}
                |ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF CHAR {
                        symbol* current = symbol_table;
                        while (current != NULL) {
                            if (strcmp(current->type, "undefined") == 0) {
                                strcpy(current->type, "ARRAY_CHAR");
                            }
                            current = current->next;
                        }
                        $1= make_leaf("ARRAY");
                        $2=make_unary_node("l_brace",$1);
                        char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%d",$3.val);
                        node* temp1=make_unary_node(temp,$2);
                        node * sc=make_leaf(";");
                        node* dt=make_unary_node("CHAR",sc);
                        $7=make_unary_node("OF",dt);
                        $6=make_unary_node("r_brace",$7);
                        char* temp3; temp3=(char*)malloc(100*sizeof(char));
                        sprintf(temp3,"%d",$5.val);
                        node* temp2=make_unary_node(temp3,$6);
                        $$=make_binary_node("..",temp1,temp2);}


datatype: INTEGER {struct node* temp= make_leaf(";");
                    $$=make_unary_node("INTEGER",temp);
                    symbol* current = symbol_table;
                    while (current != NULL) {
                        if (strcmp(current->type, "undefined") == 0 ) {
                            strcpy(current->type, "INTEGER");
                        }
                        current = current->next;
                    }}
        |REAL {struct node* temp= make_leaf(";");
                $$=make_unary_node("REAL",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0){
                        strcpy(current->type, "REAL");
                    }
                    current = current->next;
                }}
        |BOOLEAN {struct node* temp= make_leaf(";");
                $$=make_unary_node("BOOLEAN",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0) {
                        strcpy(current->type, "BOOLEAN");
                    }
                    current = current->next;
                }}
        |CHAR {struct node* temp= make_leaf(";");
                $$=make_unary_node("CHAR",temp);
                symbol* current = symbol_table;
                while (current != NULL) {
                    if (strcmp(current->type, "undefined") == 0) {
                        strcpy(current->type, "CHAR");
                    }
                    current = current->next;
                }}


program_declaration: BEGIN_TAG statements END { struct node* temp=make_leaf("END");
                                                $$=make_binary_node("BEGIN",$2,temp);
                                                }
        | BEGIN_TAG END { struct node* temp=make_leaf("END");
            $$=make_unary_node("BEGIN",temp);}

statements: statementline { $$=$1;}
            |statementline statements {
                node* ptr=$1;
                while(ptr->child!=NULL){
                    ptr=ptr->child[ptr->NumChild-1];
                }
                ptr->child=(struct node**)malloc(sizeof(struct node*));
                ptr->child[0]=$2;
                ptr->NumChild++;
                $$=$1;
            }

statementline: WRITE OPEN_PARANTHESIS possible_writes CLOSE_PARANTHESIS SEMICOLON { $2=make_leaf("(");
                                                                                    $5=make_leaf(";");
                                                                                    $4=make_unary_node(")",$5);
                                                                                    $$=make_ternary_node("WRITE",$2,$3,$4);}
                |READ OPEN_PARANTHESIS possible_reads CLOSE_PARANTHESIS SEMICOLON { $2=make_leaf("(");
                                                                                    $5=make_leaf(";");
                                                                                    $4=make_unary_node(")",$5);
                                                                                    $$=make_ternary_node("READ",$2,$3,$4);}
                |IDENTIFIER ASSIGNMENT_OP arith_expression SEMICOLON { char * x; x=(char*)malloc(100*sizeof(char));
                                                                        strcpy(x,$1.val);
                                                                        x=tolowercase(x);
                                                                        node* temp=make_leaf(";");
                                                                        node* temp1=make_leaf($1.val);
                                                                        $$=make_ternary_node($2.val,temp1,$3,temp);
                                                                        if(find_symbol(x)==NULL ){
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
                                                                            addError(errormsg);
                                                                            
                                                                        }else{
                                                                            if(strcmp($3->type,"undefined")==0){
                                                                                
                                                                            }
                                                                            else if(strcmp(find_symbol(x)->type,$3->type)!=0){
                                                                                char *errormsg=(char*)malloc(100*sizeof(char));
                                                                                sprintf(errormsg,"Assignment of mismatched types at line number: %d",$1.line);
                                                                                addError(errormsg);}
                                                                            find_symbol(x)->value=1;}}
                                                                        
                |IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET ASSIGNMENT_OP arith_expression SEMICOLON {
                    char * x; x=(char*)malloc(100*sizeof(char));
                    strcpy(x,$1.val);
                    x=tolowercase(x);
                    if(find_symbol(x)==NULL){
                        char *errormsg=(char*)malloc(100*sizeof(char) );
                        sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
                        addError(errormsg);
                    }
                    if(strcmp($3->type,"INTEGER")!=0){
                        char *errormsg=(char*)malloc(100*sizeof(char));
                        sprintf(errormsg,"Array Indices should be Integer at line number: %d",$1.line);
                        addError(errormsg);
                    }
                    char *typ=(char*)malloc(100*sizeof(char));
                    strcpy(typ,find_symbol(x)->type);
                    char *subStr = NULL;
                    char *underscorePos = strchr(typ, '_');
                    subStr = underscorePos + 1;
                    if(strcmp(subStr,$6->type)!=0){
                        char *errormsg=(char*)malloc(100*sizeof(char));
                        sprintf(errormsg,"Assignment of mismatched types at line number: %d",$1.line);
                        addError(errormsg);
                    }
                    node* temp=make_leaf(";");
                    node* temp1=make_leaf($1.val);
                    node* temp2=make_leaf("r_brace");
                    $2=make_ternary_node("l_brace",temp1,$3,temp2);
                    $$=make_ternary_node($5.val,$2,$6,temp);
                    find_symbol(x)->value=1;}
                |IF condition THEN program_declaration ELSE program_declaration SEMICOLON { node* then= make_unary_node("THEN",$4);
                                                                                        node* elset= make_unary_node("ELSE",$6);
                                                                                        $$=make_ternary_node("IF",$2,then,elset);
                                                                                        node* t=$$;
                                                                                        while(t->child!=NULL){
                                                                                        t=t->child[t->NumChild-1];
                                                                                        }
                                                                                        t->child=(struct node**)malloc(sizeof(struct node*));
                                                                                        t->child[0]=make_leaf(";");
                                                                                        t->NumChild++;
                                                                                        if(strcmp($2->type,"BOOLEAN")!=0){
                                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                                            sprintf(errormsg,"If-condition should be boolean at line number: %d",$1.line);
                                                                                            addError(errormsg);
                                                                                        }}
                |IF condition THEN program_declaration SEMICOLON { node* then= make_unary_node("THEN",$4);
                                                                    $$=make_binary_node("IF",$2,then);
                                                                    node* t=$$;
                                                                    while(t->child!=NULL){
                                                                        t=t->child[t->NumChild-1];
                                                                    }
                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                    t->child[0]=make_leaf(";");
                                                                    t->NumChild++;
                                                                    if(strcmp($2->type,"BOOLEAN")!=0){
                                                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                                                        sprintf(errormsg,"If-condition should be boolean at line number: %d",$1.line);
                                                                        addError(errormsg);
                                                                    }}
                |FOR for_conditionals1 DO program_declaration SEMICOLON {
                    node* dotemp=make_unary_node("DO",$4);
                    $$=make_binary_node("FOR",$2,dotemp);
                    node* t=$$;
                    while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
                |FOR for_conditionals2 DO program_declaration SEMICOLON {
                    node* dotemp=make_unary_node("DO",$4);
                    $$=make_binary_node("FOR",$2,dotemp);
                    node* t=$$;
                    while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
                |FOR for_conditionals3 DO program_declaration SEMICOLON {
                    node* dotemp=make_unary_node("DO",$4);
                    $$=make_binary_node("FOR",$2,dotemp);
                    node* t=$$;
                    while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
                | FOR for_conditionals4 DO program_declaration SEMICOLON {
                    node* dotemp=make_unary_node("DO",$4);
                    $$=make_binary_node("FOR",$2,dotemp);
                    node* t=$$;
                    while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
                |WHILE condition DO program_declaration SEMICOLON { node* temp=make_unary_node("DO",$4);
                                                                    $$=make_binary_node("WHILE",$2,temp);
                                                                    node* t=$$;
                                                                     while(t->child!=NULL){
                                                                        t=t->child[t->NumChild-1];
                                                                    }
                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                    t->child[0]=make_leaf(";");
                                                                    t->NumChild++;
                                                                    if(strcmp($2->type,"BOOLEAN")!=0){
                                                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                                                        sprintf(errormsg,"While-condition should be boolean at line number: %d",$1.line);
                                                                        addError(errormsg);
                                                                    }
                                                                    }

for_conditionals1: IDENTIFIER ASSIGNMENT_OP arith_expression TO arith_expression{
    char * x; x=(char*)malloc(100*sizeof(char));
    strcpy(x,$1.val);
    x=tolowercase(x);
    if(find_symbol(x)==NULL){
        char *errormsg=(char*)malloc(100*sizeof(char));
        sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
        addError(errormsg);
    }
    else if(!(strcmp(find_symbol(x)->type,"INTEGER")==0 && strcmp($3->type,"INTEGER")==0 && strcmp($5->type,"INTEGER")==0)){
        char *errormsg=(char*)malloc(100*sizeof(char));
        sprintf(errormsg,"For loop variables and constraints should be integer at line number: %d",$1.line);
        addError(errormsg);
    }
    find_symbol(x)->value=1;
    node * temp=make_leaf($1.val);
    node * temp1=make_binary_node("TO",$3,$5);
    $$=make_binary_node(":=",temp,temp1);
}

for_conditionals2: IDENTIFIER ASSIGNMENT_OP arith_expression DOWNTO arith_expression{
    char * x; x=(char*)malloc(100*sizeof(char));
    strcpy(x,$1.val);
    x=tolowercase(x);
    if(find_symbol(x)==NULL){
        char *errormsg=(char*)malloc(100*sizeof(char));
        sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
        addError(errormsg);
    }
    if(!(strcmp(find_symbol(x)->type,"INTEGER")==0 && strcmp($3->type,"INTEGER")==0 && strcmp($5->type,"INTEGER")==0)){
        char *errormsg=(char*)malloc(100*sizeof(char));
        sprintf(errormsg,"For loop variables and constraints should be integer at line number: %d",$1.line);
        addError(errormsg);
    }
    find_symbol(x)->value=1;
    node * temp=make_leaf($1.val);
    node * temp1=make_binary_node("DOWNTO",$3,$5);
    $$=make_binary_node(":=",temp,temp1);
}

for_conditionals3: left_array_assignment ASSIGNMENT_OP arith_expression TO arith_expression{
    node * temp1=make_binary_node("TO",$3,$5);
   $$=make_binary_node($2.val,$1,temp1);
}

for_conditionals4: left_array_assignment ASSIGNMENT_OP arith_expression DOWNTO arith_expression{
    node * temp1=make_binary_node("DOWNTO",$3,$5);
   $$=make_binary_node($2.val,$1,temp1);
}

left_array_assignment: IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {
    char * x; x=(char*)malloc(100*sizeof(char));
    strcpy(x,$1.val);
    x=tolowercase(x);
    node* temp=make_leaf($1.val);
    $4=make_leaf("r_brace");
    $$=make_ternary_node("l_brace",temp,$3,$4);
    if(find_symbol(x)==NULL || strcmp(find_symbol(x)->type,"undefined")==0){
        char *errormsg=(char*)malloc(100*sizeof(char) );
        sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
        addError(errormsg);
    }
    else{
        char *typ=(char*)malloc(100*sizeof(char));
        strcpy(typ,find_symbol(x)->type);
        char *subStr = NULL;
        char *underscorePos = strchr(typ, '_');
        subStr = underscorePos + 1;
        strcpy($$->type,subStr);
        find_symbol(x)->value=1;
    }
    if(strcmp($3->type,"INTEGER")!=0){
        char *errormsg=(char*)malloc(100*sizeof(char));
        sprintf(errormsg,"Array Indices should be Integer at line number: %d",$1.line);
        addError(errormsg);
    }
    }

condition: conditionals{$$=$1;
                            strcpy($$->type,$1->type);}
            |unit {$$=$1;
                   strcpy($$->type,$1->type);}


conditionals:   condtional_unit {$$=$1;
                                strcpy($$->type,$1->type);}
                |relational_exp {$$=$1; 
                                strcpy($$->type,$1->type);}
                |relational_exp BOOLEAN_OP conditionals { $$=make_binary_node($2.val,$1,$3);
                                                            if(strcmp($1->type,"BOOLEAN")==0 && strcmp($3->type,"BOOLEAN")==0){
                                                                strcpy($$->type,"BOOLEAN");
                                                            }
                                                            else{
                                                                char *errormsg=(char*)malloc(100*sizeof(char));
                                                                sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                                                addError(errormsg);
                                                                strcpy($$->type,"BOOLEAN");
                                                            }}
                | relational_exp BOOLEAN_OP unit { $$=make_binary_node($2.val,$1,$3);
                                                    if(strcmp($1->type,"BOOLEAN")==0 && strcmp($3->type,"BOOLEAN")==0){
                                                        strcpy($$->type,"BOOLEAN");
                                                    }
                                                    else{
                                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                                        sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                                        addError(errormsg);
                                                        strcpy($$->type,"BOOLEAN");
                                                    }}
                |unit BOOLEAN_OP conditionals  { $$=make_binary_node($2.val,$1,$3);
                                                if(strcmp($1->type,"BOOLEAN")==0 && strcmp($3->type,"BOOLEAN")==0){
                                                    strcpy($$->type,"BOOLEAN");
                                                }
                                                else{
                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                    sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                                    addError(errormsg);
                                                    strcpy($$->type,"BOOLEAN");
                                                }}
                | unit BOOLEAN_OP unit  { $$=make_binary_node($2.val,$1,$3);
                                        if(strcmp($1->type,"BOOLEAN")==0 && strcmp($3->type,"BOOLEAN")==0){
                                            strcpy($$->type,"BOOLEAN");
                                        }
                                        else{
                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                            sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                            addError(errormsg);
                                            strcpy($$->type,"BOOLEAN");
                                        }}
                | BOOLEAN_OP_NOT conditionals { $$=make_unary_node($1.val,$2);
                                                if(strcmp($2->type,"BOOLEAN")==0){
                                                    strcpy($$->type,"BOOLEAN");
                                                }
                                                else{
                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                    sprintf(errormsg,"Type Mismatch at line number: %d",$1.line);
                                                    addError(errormsg);
                                                    strcpy($$->type,"BOOLEAN");
                                                }}
                
                

condtional_unit:BOOLEAN_OP_NOT unit {$$=make_unary_node($1.val,$2);
                                    if(strcmp($2->type,"BOOLEAN")==0){
                                        strcpy($$->type,"BOOLEAN");
                                    }
                                    else{
                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                        sprintf(errormsg,"Type Mismatch at line number: %d",$1.line);
                                        addError(errormsg);
                                        strcpy($$->type,"BOOLEAN");
                                    }}

relational_exp: arith_expression RELATIONAL_OP arith_expression { $$=make_binary_node($2.val,$1,$3);

                                                                    if(strcmp($2.val,"<>")==0 || strcmp($2.val,"=")==0){
                                                                        if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }else if(strcmp($1->type,"CHAR")==0 && strcmp($3->type,"CHAR")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }else if(strcmp($1->type,"BOOLEAN")==0 && strcmp($3->type,"BOOLEAN")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }else if(strcmp($1->type,"ARRAY_INTEGER")==0 && strcmp($3->type,"ARRAY_INTEGER")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }else if(strcmp($1->type,"ARRAY_REAL")==0 && strcmp($3->type,"ARRAY_REAL")==0){
                                                                            strcpy($$->type,"BOOLEAN");}
                                                                        else if(strcmp($1->type,"ARRAY_BOOLEAN")==0 && strcmp($3->type,"ARRAY_BOOLEAN")==0){
                                                                            strcpy($$->type,"BOOLEAN");}
                                                                        else if(strcmp($1->type,"ARRAY_CHAR")==0 && strcmp($3->type,"ARRAY_CHAR")==0){
                                                                            strcpy($$->type,"BOOLEAN");}
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                                                            addError(errormsg);
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }
                                                                    }else{
                                                                        if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }
                                                                        else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                                                            addError(errormsg);
                                                                            strcpy($$->type,"BOOLEAN");
                                                                        }
                                                                    }}
                |OPEN_PARANTHESIS relational_exp CLOSE_PARANTHESIS {node * temp=make_leaf(")");
                                                                    $$=make_binary_node("(",$2,temp);
                                                                    strcpy($$->type,$2->type);}

left_side_vars_write: IDENTIFIER {char * temp; temp=(char*)malloc(100*sizeof(char));
                                    strcpy(temp,$1.val);
                                    temp=tolowercase(temp);
                                    if(find_symbol(temp)==NULL || strcmp(find_symbol(temp)->type,"undefined")==0){
                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                        sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
                                        addError(errormsg);
                                    }
                                    else if(find_symbol(temp)->value==0){
                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                        sprintf(errormsg,"Variable not initialized: %s at line number: %d",$1.val,$1.line);
                                        addError(errormsg);
                                    }
                                $$=make_leaf($1.val);}
                |IDENTIFIER COMMA left_side_vars_write { char * temp; temp=(char*)malloc(100*sizeof(char));
                                                strcpy(temp,$1.val);
                                                temp=tolowercase(temp);
                                                if(find_symbol(temp)==NULL){
                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                    sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
                                                    addError(errormsg);
                                                }
                                                else if(find_symbol(temp)->value==0){
                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                    sprintf(errormsg,"Variable not initialized: %s at line number: %d",$1.val,$1.line);
                                                    addError(errormsg);
                                                }
                                                struct node * temp1=make_leaf($1.val);
                                                $$=make_binary_node(",",temp1,$3);}
                |STRING_CONSTANT { $$=make_leaf($1.val);}

possible_writes: possible_write_values { $$=$1;}
    | {$$=NULL;};

possible_write_values: left_side_vars_write {$$=$1;}
                        |STRING_CONSTANT COMMA possible_write_values {node* temp=make_leaf($1.val);
                                                                        $$=make_binary_node(",",temp,$3);}
                        | IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {char * x; x=(char*)malloc(100*sizeof(char));
                                                                                strcpy(x,$1.val);
                                                                                x=tolowercase(x);
                                                                                if(find_symbol(x)==NULL){
                                                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                                                    sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
                                                                                    addError(errormsg);
                                                                                }
                                                                                else if(find_symbol(x)->value==0){
                                                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                                                    sprintf(errormsg,"Variable not initialized: %s at line number: %d",$1.val,$1.line);
                                                                                    addError(errormsg);
                                                                                }
                                                                                if(strcmp($3->type,"INTEGER")!=0){
                                                                                    char *errormsg=(char*)malloc(100*sizeof(char));
                                                                                    sprintf(errormsg,"Array Indices should be Integer at line number: %d",$1.line);
                                                                                    addError(errormsg);
                                                                                }
                                                                                node* temp=make_leaf($1.val);
                                                                                $4=make_leaf("r_brace");
                                                                                $$=make_ternary_node("l_brace",temp,$2,$3);}

possible_reads: IDENTIFIER {char * temp; temp=(char*)malloc(100*sizeof(char));
                            strcpy(temp,$1.val);
                            temp=tolowercase(temp);
                            if(find_symbol(temp)==NULL){
                                char *errormsg=(char*)malloc(100*sizeof(char));
                                sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
                                addError(errormsg);
                            }else{
                                find_symbol(temp)->value=1;
                            }
                            printf("Value of %s: \n",temp);
                            $$=make_leaf($1.val);}
                |IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {char * x; x=(char*)malloc(100*sizeof(char));
                                                                        strcpy(x,$1.val);
                                                                        x=tolowercase(x);
                                                                        if(find_symbol(x)==NULL){
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
                                                                            addError(errormsg);   
                                                                        }
                                                                        find_symbol(x)->value=1;
                                                                        node* temp=make_leaf($1.val);
                                                                        $4=make_leaf("r_brace");
                                                                        $$=make_ternary_node("l_brace",temp,$3,$4);
                                                                        if(strcmp($3->type,"INTEGER")!=0){
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Array Indices should be Integer at line number: %d",$1.line);
                                                                            addError(errormsg);
                                                                        }}


arith_expression: unit_2 {$$=$1;}
                |unit {$$=$1;}
                | OPEN_PARANTHESIS arith_expression CLOSE_PARANTHESIS {node * temp=make_leaf(")");
                                                                        $$=make_binary_node("(",$2,temp);
                                                                        strcpy($$->type,$2->type);}
                | arith_expression ARITHEMATIC_OP_PLUS arith_expression { $$=make_binary_node($2.val,$1,$3);
                                                                    if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"INTEGER")==0){
                                                                        strcpy($$->type,"INTEGER");
                                                                    }
                                                                    else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"REAL")==0){
                                                                        strcpy($$->type,"REAL");
                                                                    }
                                                                    else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"REAL")==0){
                                                                        strcpy($$->type,"REAL");
                                                                    }
                                                                    else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"INTEGER")==0){
                                                                        strcpy($$->type,"REAL");
                                                                    }else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"undefined")==0){
                                                                        strcpy($$->type,"INTEGER");
                                                                    }else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"undefined")==0){
                                                                        strcpy($$->type,"REAL");
                                                                    }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"INTEGER")==0){
                                                                        strcpy($$->type,"INTEGER");
                                                                    }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"REAL")==0){
                                                                        strcpy($$->type,"REAL");
                                                                    }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"undefined")==0){
                                                                        strcpy($$->type,"undefined");
                                                                    }
                                                                    else{
                                                                        char *errormsg=(char*)malloc(100*sizeof(char));
                                                                        sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                                                        addError(errormsg);
                                                                    }}
                | arith_expression ARITHEMATIC_OP_MINUS arith_expression { $$=make_binary_node("-",$1,$3);
                                                                            if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"INTEGER");
                                                                        }
                                                                        else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }
                                                                        else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }
                                                                        else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"INTEGER");
                                                                        }else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"INTEGER");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"undefined");
                                                                        }
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                                                            addError(errormsg);
                                                                        }}
                | arith_expression ARITHEMATIC_OP_MUL arith_expression { $$=make_binary_node("*",$1,$3);
                                                                        if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"INTEGER");
                                                                        }
                                                                        else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }
                                                                        else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }
                                                                        else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"INTEGER");
                                                                        }else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"INTEGER");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"undefined");
                                                                        }
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                                                            addError(errormsg);
                                                                        }}
                | arith_expression ARITHEMATIC_OP_DIV arith_expression { $$=make_binary_node("/",$1,$3);
                                                                        if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }
                                                                        else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }
                                                                        else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }
                                                                        else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"REAL")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"REAL")==0){
                                                                            strcpy($$->type,"REAL");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"undefined");
                                                                        }
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                                                            addError(errormsg);
                                                                        }}
                | arith_expression ARITHEMATIC_OP_MOD arith_expression { $$=make_binary_node("%",$1,$3);
                                                                        if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"INTEGER");
                                                                        }
                                                                        else if(strcmp($1->type,"INTEGER")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"INTEGER");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"INTEGER")==0){
                                                                            strcpy($$->type,"INTEGER");
                                                                        }else if(strcmp($1->type,"undefined")==0 && strcmp($3->type,"undefined")==0){
                                                                            strcpy($$->type,"undefined");
                                                                        }
                                                                        else{
                                                                            char *errormsg=(char*)malloc(100*sizeof(char));
                                                                            sprintf(errormsg,"Type Mismatch at line number: %d",$2.line);
                                                                            addError(errormsg);
                                                                        }}


unit: IDENTIFIER {char * temp; temp=(char*)malloc(100*sizeof(char));
                strcpy(temp,$1.val);
                temp=tolowercase(temp);
                $$=make_leaf($1.val);
                if(find_symbol(temp)==NULL){
                    char *errormsg=(char*)malloc(100*sizeof(char));
                    sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
                    addError(errormsg);
                    strcpy($$->type,"undefined");
                }
                else if(find_symbol(temp)->value==0){
                    char *errormsg=(char*)malloc(100*sizeof(char));
                    sprintf(errormsg,"Variable not initialized: %s at line number: %d",$1.val,$1.line);
                    addError(errormsg);
                    char *typ=(char*)malloc(100*sizeof(char));
                    strcpy(typ,find_symbol(temp)->type);
                    strcpy($$->type,typ);
                }else{
                    char *typ=(char*)malloc(100*sizeof(char));
                    strcpy(typ,find_symbol(temp)->type);
                    strcpy($$->type,typ);}
                }
                
                
    | IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {char * x; x=(char*)malloc(100*sizeof(char));
                                                            strcpy(x,$1.val);
                                                            x=tolowercase(x);
                                                            node* temp=make_leaf($1.val);
                                                            $4=make_leaf("r_brace");
                                                            $$=make_ternary_node("l_brace",temp,$3,$4);
                                                            if(find_symbol(x)==NULL){
                                                                char *errormsg=(char*)malloc(100*sizeof(char) );
                                                                sprintf(errormsg,"Undeclared variable: %s at line number: %d",$1.val,$1.line);
                                                                addError(errormsg);
                                                            }
                                                            else if(find_symbol(x)->value==0){
                                                                char *errormsg=(char*)malloc(100*sizeof(char));
                                                                sprintf(errormsg,"Variable not initialized: %s at line number: %d",$1.val,$1.line);
                                                                addError(errormsg);
                                                                char *typ=(char*)malloc(100*sizeof(char));
                                                                strcpy(typ,find_symbol(x)->type);
                                                                char *subStr = NULL;
                                                                char *underscorePos = strchr(typ, '_');
                                                                subStr = underscorePos + 1;
                                                                strcpy($$->type,subStr);
                                                            }
                                                            else{
                                                                char *typ=(char*)malloc(100*sizeof(char));
                                                                strcpy(typ,find_symbol(x)->type);
                                                                char *subStr = NULL;
                                                                char *underscorePos = strchr(typ, '_');
                                                                subStr = underscorePos + 1;
                                                                strcpy($$->type,subStr);
                                                            }
                                                            if(strcmp($3->type,"INTEGER")!=0){
                                                                char *errormsg=(char*)malloc(100*sizeof(char));
                                                                sprintf(errormsg,"Array Indices should be Integer at line number: %d",$1.line);
                                                                addError(errormsg);
                                                            }}
    |ARITHEMATIC_OP_MINUS arith_expression {$$=make_unary_node("-",$2);
                                            if(strcmp($2->type,"INTEGER")==0){
                                                strcpy($$->type,"INTEGER");
                                            }
                                            else if(strcmp($2->type,"REAL")==0){
                                                strcpy($$->type,"REAL");
                                            }
                                            else{
                                                char *errormsg=(char*)malloc(100*sizeof(char));
                                                sprintf(errormsg,"Type Mismatch at line number: %d",$1.line);
                                                addError(errormsg);
                                            }}

unit_2: INTEGER_CONSTANT { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                            sprintf(temp,"%d",$1.val);
                            $$=make_leaf(temp);
                            sprintf($$->type,"INTEGER");}
    | FLOAT_CONSTANT { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%f",$1.val);
                        $$=make_leaf(temp);
                        sprintf($$->type,"REAL");}
    | CHAR_CONSTANT { char * temp; temp=(char*)malloc(100*sizeof(char));
                        sprintf(temp,"%s",$1.val);
                        $$=make_leaf(temp);
                        sprintf($$->type,"CHAR");}

%%

struct node* make_binary_node(char* root, node* left, node* right){
    struct node* ASTnode = (struct node*)malloc(sizeof(struct node));
    ASTnode->child = (struct node**)malloc(2*sizeof(struct node *));
    ASTnode->NumChild = 2;
    strcpy(ASTnode->lexeme,root);
    ASTnode->child[0] = left;
    ASTnode->child[1] = right;
    return ASTnode;
}

struct node* make_ternary_node(char* root, node* left, node* middle, node* right){
    struct node* ASTnode = (struct node*)malloc(sizeof(struct node));
    ASTnode->child = (struct node**)malloc(3*sizeof(struct node *));
    ASTnode->NumChild = 3;
    strcpy(ASTnode->lexeme,root);
    ASTnode->child[0] = left;
    ASTnode->child[1] = middle;
    ASTnode->child[2] = right;
    return ASTnode;
}

struct node* make_unary_node(char* root, node* child){
    struct node* ASTnode = (struct node*)malloc(sizeof(struct node));
    ASTnode->child = (struct node**)malloc(sizeof(struct node *));
    ASTnode->NumChild = 1;
    strcpy(ASTnode->lexeme,root);
    ASTnode->child[0] = child;
    return ASTnode;
}

struct node* make_leaf(char* root){
	struct node* ASTnode = (struct node*)malloc(sizeof(struct node));
	strcpy(ASTnode->lexeme,root);
	ASTnode->NumChild = 0;
	ASTnode->child = NULL;
	return ASTnode;
}

void AST_print(struct node* t){
	static int ctr=0;
	int i;
	if(t->NumChild==0) 
		return;
	struct node* t2=t;
	printf("\n%s  -->",t2->lexeme);
	for(i=0;i<t2->NumChild;++i) {
        if(t2->child[i]!=NULL)
		    printf("%s ",t2->child[i]->lexeme);
	}
	for(i=0;i<t2->NumChild;++i){
        if(t->child[i]!=NULL)
		    AST_print(t->child[i]);
	}
}

void preOrderTraversal(struct node* n, char* text){
    if (n == NULL) {
        return;
    }
    strcat(text,"[");
    strcat(text, n->lexeme);
    // Recursively visit each child
    for (int i = 0; i < n->NumChild; i++) {
        preOrderTraversal(n->child[i],text);
    }
    strcat(text,"]");
}

void writeToFile(struct node* n){
    FILE *file = fopen("syntaxtree.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    char text[100000];
    preOrderTraversal(n,text);
    // Write the string to the file
    fprintf(file, "%s", text);
}

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

void addError(const char* e) {
    error* new_error = (error*)malloc(sizeof(error));
    strcpy(new_error->error, e);
    new_error->next = error_table;
    error_table = new_error;
}

void printErrors() {
    error* current = error_table;
    printf("Errors\n\n");
    while (current != NULL) {
        printf("%s\n", current->error);
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