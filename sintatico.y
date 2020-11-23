%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ast.h>
    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);

    TreeNode* AST = NULL;

%}

%union{
    TreeNode* ast;
    int integer;
}

%token PLUS
%token MINUS
%token ASTERIX
%token DIV
%token EXP
%token PERCENT
%token L_PAREN
%token R_PAREN
%token SEMICOLON
%token SEN
%token COS
%token TAN
%token ABS
%token INT
%token REAL
%token VAR
%token EOL
%token ENDOFFILE
%token TAB
%token SHOW
%token SETTINGS
%token RESET
%token QUIT
%token SET
%token HVIEW
%token VVIEW
%token AXIS
%token ON
%token OFF
%token PLOT
%token INTEGRAL_STEPS
%token INTEGRATE
%token MATRIX
%token SOLVE
%token DETERMINANT
%token LINEAR_SYSTEM
%token ABOUT

%type <ast> calc
%type <ast> option
%type <ast> exp1
%type <ast> exp2
%type <ast> exp3
%type <ast> exp4
%type <ast> term
%type <integer> REAL

%%

calc: option SEMICOLON EOL {printf("cadeia aceita\n");return 1;}
    |exp1 EOL { printf("cadeia aceita\n"); return 1;} 
    //AST = $1; 
    //                 if(AST){
    //                     RPN_Walk(AST);
    //                     Delete_Tree(AST);
    //                 }else{
    //                     printf("AST is ''NULL\n");
    //                 }
    //                 return 0;
    //             }
;

option:SHOW SETTINGS {printf("%s\n",yytext);}
    |RESET SETTINGS {printf("%s\n",yytext);}
    |SET HVIEW {printf("%s\n",yytext);}
    |SET VVIEW {printf("%s\n",yytext);}
    |SET AXIS ON {printf("%s\n",yytext);}
    |SET AXIS OFF {printf("%s\n",yytext);}
    |PLOT {printf("%s\n",yytext);}
    |PLOT L_PAREN exp1 R_PAREN {printf("%s\n",yytext);}
    |SET INTEGRAL_STEPS {printf("%s\n",yytext);}
    |SET INTEGRATE {printf("%s\n",yytext);}
    |MATRIX {printf("%s\n",yytext);}
    |SHOW MATRIX {printf("%s\n",yytext);}
    |SOLVE DETERMINANT {printf("%s\n",yytext);}
    |SOLVE LINEAR_SYSTEM {printf("%s\n",yytext);}
    |ABOUT {printf("%s\n",yytext);}
    |QUIT {return 1;}
;

exp1:exp2 {printf("%s\n",yytext);}
    |exp1 PLUS exp2 {printf("%s\n",yytext);}
    |exp1 MINUS exp2 {printf("%s\n",yytext);}
;

exp2:exp3 {printf("exp3 %s\n",yytext);}
    |exp2 ASTERIX exp3 {printf("exp3 %s\n",yytext);}
    |exp2 DIV exp3 {printf("exp3 %s\n",yytext);}
    |exp2 PERCENT exp3 {printf("exp3 %s\n",yytext);}
;

exp3:exp4 {printf("%s\n",yytext);}
    |exp3 EXP exp4 {printf("%s\n",yytext);}  
    |func L_PAREN exp1 R_PAREN {printf("%s\n",yytext);}
;

exp4:term {printf("%s\n",yytext);}
    |L_PAREN exp1 R_PAREN {printf("%s\n",yytext);}
;

term:VAR {printf("%s\n",yytext);}
    |REAL {printf("%s\n",yytext);}
;

func:SEN{printf("%s\n",yytext);}
    |COS{printf("%s\n",yytext);}
    |TAN{printf("%s\n",yytext);}
    |ABS{printf("%s\n",yytext);}
;

// exp: factor          { $$ = $1;}
//     | exp PLUS factor {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
//                        aux->node_type = PLUS;
//                        aux->v''alue = 0;
//                        aux->l''eft = $1;
//                        aux->right = $3;
//                        $$ = aux;
//                       }
//     | exp MINUS factor {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
//                        aux->node_type = MINUS;
//                        aux->value = 0;
//                        aux->left = $1;
//                        aux->right = $3;
//                        $$ = aux;
//                       }
// ;

// factor: term          { $$ = $1;}
//     | factor ASTERIX term {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
//                        aux->node_type = ASTERIX;
//                        aux->value = 0;
//                        aux->left = $1;
//                        aux->right = $3;
//                        $$ = aux;
//                       }
//     | factor DIV term {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
//                        aux->node_type = DIV;
//                        aux->value = 0;
//                        aux->left = $1;
//                        aux->right = $3;
//                        $$ = aux;
//                       }
// ;

// term: REAL   { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node)); 
//                  aux->node_type = REAL;
//                  aux->value = $1;
//                  aux->left = NULL;
//                  aux->right = NULL;
//                  $$ = (TreeNode*) aux;
//                }
// ;


%%

void yyerror(char *s)
{
    printf("Erro de Sintaxe: %s", yytext);
    exit(0);
}

int main(int argc, char **argv)
{
    return yyparse();
}