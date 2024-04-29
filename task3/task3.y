%{
# include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern FILE *yyin;
int yylex();
int yyerror();

typedef struct node{
    char lexeme[100];
    int NumChild;
    struct node **child;
    } node;

struct node* make_binary_node(char*, node*, node*);
struct node* make_leaf(char* );
struct node* make_ternary_node(char* , node* , node* ,node* );
struct node* make_unary_node(char* , node* );
void AST_print(struct node* );
void writeToFile(struct node* );
void preOrderTraversal(struct node* , char* );


%}

%union{
    int ival;
    char *sval;
    double dval;
    struct node* node;
}


%left ARITHEMATIC_OP
%left BOOLEAN_OP
%left ARITHEMATIC_OP_MINUS
%right RELATIONAL_OP
%left BOOLEAN_OP_NOT

%token <sval> IDENTIFIER STRING_CONSTANT INTEGER REAL BOOLEAN CHAR BOOLEAN_OP BOOLEAN_OP_NOT ASSIGNMENT_OP RELATIONAL_OP ARITHEMATIC_OP ARITHEMATIC_OP_MINUS
%token <ival> INTEGER_CONSTANT
%token <dval> FLOAT_CONSTANT
%token <node> PROGRAM SEMICOLON IF WHILE ELSE FOR DO BEGIN_TAG END WRITE READ DOWNTO TO OF COLON VAR ARRAY THEN
%token <node> COMMA OPEN_BRACKET OPEN_PARANTHESIS CLOSE_BRACKET CLOSE_PARANTHESIS PERIOD RANGE_DOTS 


%type <node> start variable_declaration program_declaration variable_list variable_line left_side_vars rigth_side_type datatype unit_2 statements statementline
%type <node> possible_writes possible_write_values possible_reads arith_expression unit condition conditional_head relational_exp conditionals condtional_unit

%%

start: PROGRAM IDENTIFIER SEMICOLON variable_declaration program_declaration PERIOD {$1=make_leaf("PROGRAM");
                                                                                    $6=make_binary_node(";",$4,$5);
                                                                                    $$=make_binary_node($2,$1,$6);
                                                                                    node* t=$$;
                                                                                    while(t->child!=NULL){
                                                                                        t=t->child[t->NumChild-1];
                                                                                    }
                                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                                    t->child[0]=make_leaf(".");
                                                                                    t->NumChild++;
                                                                                    printf("Valid Input\n\n");
                                                                                    writeToFile($$);
                                                                                    AST_print($$);
                                                                                    printf("\n");  };

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
left_side_vars: IDENTIFIER { $$=make_leaf($1);}
                |IDENTIFIER COMMA left_side_vars { struct node * temp1=make_leaf($1);
                                                    $$=make_binary_node(",",temp1,$3);}

rigth_side_type: datatype { $$=$1;}
                |ARRAY OPEN_BRACKET INTEGER_CONSTANT RANGE_DOTS INTEGER_CONSTANT CLOSE_BRACKET OF datatype {$1= make_leaf("ARRAY");
                                                                                                            $2=make_unary_node("l_brace",$1);
                                                                                                            char * temp; temp=(char*)malloc(100*sizeof(char)); 
                                                                                                            sprintf(temp,"%d",$3);
                                                                                                            node* temp1=make_unary_node(temp,$2);
                                                                                                            $7=make_unary_node("OF",$8);
                                                                                                            $6=make_unary_node("r_brace",$7);
                                                                                                            char* temp3; temp3=(char*)malloc(100*sizeof(char));
                                                                                                            sprintf(temp3,"%d",$5);
                                                                                                            node* temp2=make_unary_node(temp3,$6);
                                                                                                            $$=make_binary_node("..",temp1,temp2);}

datatype: INTEGER {struct node* temp= make_leaf(";");
                    $$=make_unary_node("INTEGER",temp);}
        |REAL {struct node* temp= make_leaf(";");$$=make_unary_node("REAL",temp);}
        |BOOLEAN {struct node* temp= make_leaf(";");$$=make_unary_node("BOOLEAN",temp);}
        |CHAR {struct node* temp= make_leaf(";");$$=make_unary_node("CHAR",temp);}

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
                |IDENTIFIER ASSIGNMENT_OP arith_expression SEMICOLON { node* temp=make_leaf(";");
                                                                        node* temp1=make_leaf($1);
                                                                        $$=make_ternary_node($2,temp1,$3,temp);}
                |IF condition THEN program_declaration ELSE program_declaration SEMICOLON { node* then= make_unary_node("THEN",$4);
                                                                                        node* elset= make_unary_node("ELSE",$6);
                                                                                        $$=make_ternary_node("IF",$2,then,elset);
                                                                                        node* t=$$;
                                                                                        while(t->child!=NULL){
                                                                                        t=t->child[t->NumChild-1];
                                                                                        }
                                                                                        t->child=(struct node**)malloc(sizeof(struct node*));
                                                                                        t->child[0]=make_leaf(";");
                                                                                        t->NumChild++;}
                |IF condition THEN program_declaration SEMICOLON { node* then= make_unary_node("THEN",$4);
                                                                    $$=make_binary_node("IF",$2,then);
                                                                    node* t=$$;
                                                                    while(t->child!=NULL){
                                                                        t=t->child[t->NumChild-1];
                                                                    }
                                                                    t->child=(struct node**)malloc(sizeof(struct node*));
                                                                    t->child[0]=make_leaf(";");
                                                                    t->NumChild++;
                                                                    }
                |FOR IDENTIFIER ASSIGNMENT_OP arith_expression TO arith_expression DO program_declaration SEMICOLON {
                    node* dotemp=make_unary_node("DO",$8);
                    node* id=make_leaf($2);
                    node* temp=make_binary_node("TO",$4,$6);
                    node* temp1=make_binary_node($3,id,temp);
                    $$=make_binary_node("FOR",temp1,dotemp);
                    node* t=$$;
                    while(t->child!=NULL){
                        t=t->child[t->NumChild-1];
                    }
                    t->child=(struct node**)malloc(sizeof(struct node*));
                    t->child[0]=make_leaf(";");
                    t->NumChild++;
                }
                |FOR IDENTIFIER ASSIGNMENT_OP arith_expression DOWNTO arith_expression DO program_declaration SEMICOLON {
                    node* dotemp=make_unary_node("DO",$8);
                    node* id=make_leaf($2);
                    node* temp=make_binary_node("DOWNTO",$4,$6);
                    node* temp1=make_binary_node($3,id,temp);
                    $$=make_binary_node("FOR",temp1,dotemp);
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
                                                                    t->NumChild++;}

condition: conditional_head {$$=$1;}
            |unit {$$=$1;}

conditional_head: relational_exp { $$=$1;}
                    |conditionals { $$=$1;}

conditionals:   condtional_unit {$$=$1;}
                |relational_exp BOOLEAN_OP conditionals { $$=make_binary_node($2,$1,$3);}
                | relational_exp BOOLEAN_OP unit { $$=make_binary_node($2,$1,$3);}
                |unit BOOLEAN_OP conditionals  { $$=make_binary_node($2,$1,$3);}
                | unit BOOLEAN_OP unit  { $$=make_binary_node($2,$1,$3);}
                | BOOLEAN_OP_NOT conditionals { $$=make_unary_node($1,$2);}
                |OPEN_PARANTHESIS conditionals CLOSE_PARANTHESIS {node * temp=make_leaf(")");
                                                                $$=make_binary_node("(",$2,temp);}
                

condtional_unit:BOOLEAN_OP_NOT unit {$$=make_unary_node($1,$2);}

relational_exp: arith_expression RELATIONAL_OP arith_expression { $$=make_binary_node($2,$1,$3);}
                |OPEN_PARANTHESIS relational_exp CLOSE_PARANTHESIS {node * temp=make_leaf(")");
                                                                    $$=make_binary_node("(",$2,temp);}

possible_writes: possible_write_values { $$=$1;}
    | {$$=NULL;};

possible_write_values: left_side_vars {$$=$1;}
                        |STRING_CONSTANT { $$=make_leaf($1);}
                        |STRING_CONSTANT COMMA possible_write_values {node* temp=make_leaf($1);
                                                                        $$=make_binary_node(",",temp,$3);}
                        | IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {node* temp=make_leaf($1);
                                                                                $4=make_leaf("r_brace");
                                                                                $$=make_ternary_node("l_brace",temp,$2,$3);}

possible_reads: IDENTIFIER {$$=make_leaf($1);}
                |IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {node* temp=make_leaf($1);
                                                                        $4=make_leaf("r_brace");
                                                                        $$=make_ternary_node("l_brace",temp,$2,$3);}


arith_expression: unit_2 {$$=$1;}
                |unit {$$=$1;}
                | OPEN_PARANTHESIS arith_expression CLOSE_PARANTHESIS {node * temp=make_leaf(")");
                                                                        $$=make_binary_node("(",$2,temp);}
                | arith_expression ARITHEMATIC_OP arith_expression { $$=make_binary_node($2,$1,$3);}
                | arith_expression ARITHEMATIC_OP_MINUS arith_expression { $$=make_binary_node("-",$1,$3);}


unit: IDENTIFIER {$$=make_leaf($1);}
    | IDENTIFIER OPEN_BRACKET arith_expression CLOSE_BRACKET {node* temp=make_leaf($1);
                                                            $4=make_leaf("r_brace");
                                                            $$=make_ternary_node("l_brace",temp,$2,$3);}
    |ARITHEMATIC_OP_MINUS arith_expression {$$=make_unary_node("-",$2);}

unit_2: INTEGER_CONSTANT { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                            sprintf(temp,"%d",$1);
                            $$=make_leaf(temp);}
    | FLOAT_CONSTANT { char * temp; temp=(char*)malloc(100*sizeof(char)); 
                        sprintf(temp,"%f",$1);
                        $$=make_leaf(temp);}

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