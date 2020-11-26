%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ast.h>
    #include <funcoes.h>
    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);

    TreeNode* AST = NULL;

%}

%union{
    TreeNode* ast;
    float real;
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
%type <ast> exp
%type <ast> exp1
%type <ast> exp2
%type <ast> exp3
%type <ast> exp4
%type <ast> term

%type <real> REAL


%%

calc: option SEMICOLON EOL {printf(">");}
    |exp EOL { AST = $1; 
        if(AST){
            RPN_Walk(AST);
            printf("resultado->%f\n",calcula(AST));
            Delete_Tree(AST);
        }
        printf(">");
    }
;

option:SHOW SETTINGS {imprimeSettings();}
    |RESET SETTINGS {resetSettings();}
    |SET HVIEW {setHView();}
    |SET VVIEW {setVView();}
    |SET AXIS ON {axisOn();}
    |SET AXIS OFF {axisOff();}
    |PLOT {printf("%s\n",yytext);}
    |PLOT L_PAREN exp1 R_PAREN {printf("%s\n",yytext);}
    |SET INTEGRAL_STEPS {printf("%s\n",yytext);}
    |SET INTEGRATE {printf("%s\n",yytext);}
    |MATRIX {printf("%s\n",yytext);}
    |SHOW MATRIX {printf("%s\n",yytext);}
    |SOLVE DETERMINANT {printf("%s\n",yytext);}
    |SOLVE LINEAR_SYSTEM {printf("%s\n",yytext);}
    |ABOUT {imprimeAbout();}
    |QUIT {return 0;}
;

exp:exp1
    |MINUS exp1 {$$ = mallocTree($2,NULL,0,MINUS);}
    |PLUS exp1 {$$ = mallocTree($2,NULL,0,PLUS);}
;

exp1:exp2 {$$=$1;}
    |exp1 PLUS exp2 {$$ = mallocTree($1,$3,0,PLUS);}
    |exp1 MINUS exp2 {$$ = mallocTree($1,$3,0,MINUS);}
    
;

exp2:exp3 {$$ = $1;}
    |exp2 ASTERIX exp3 {$$ = mallocTree($1,$3,0,ASTERIX);}
    |exp2 DIV exp3 {$$ = mallocTree($1,$3,0,DIV);}
    |exp2 PERCENT exp3 {$$ = mallocTree($1,$3,0,PERCENT);}
;

exp3:exp4 {$$ = $1;}
    |exp3 EXP exp4 {$$ = mallocTree($1,$3,0,EXP);}  
    |SEN L_PAREN exp1 R_PAREN {$$ = mallocTree($3,NULL,0,SEN); }
    |COS L_PAREN exp1 R_PAREN {$$ = mallocTree($3,NULL,0,COS);}
    |TAN L_PAREN exp1 R_PAREN {$$ = mallocTree($3,NULL,0,TAN);}
    |ABS L_PAREN exp1 R_PAREN {$$ = mallocTree($3,NULL,0,ABS);}
;

exp4:term {$$ = $1;}
    |L_PAREN exp1 R_PAREN {$$ = $2;}
;

term:VAR {$$ = mallocTree(NULL,NULL,0,VAR);}
    |REAL {$$ = mallocTree(NULL,NULL,$1,REAL);}
;

%%

void yyerror(char *s){
    printf("Erro de Sintaxe: 9|%s|9", yytext);
    exit(0);
}

int main(int argc, char **argv){
    printf(">");
    while(yyparse());
    return 0;
}