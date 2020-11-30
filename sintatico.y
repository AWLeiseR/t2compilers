%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ast.h>
    #include <funcoes.h>
    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);

    TreeNode* AST = NULL;
    TreeNode* plotTree=NULL;

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
%token L_BRACKET
%token R_BRACKET
%token SEMICOLON
%token COLON
%token COMMA
%token SEN
%token COS
%token TAN
%token ABS
%token EQUAL
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
%type <ast> mat
%type <ast> vector
%type <ast> element
%type <real> REAL

%%

calc: option SEMICOLON EOL {printf(">");return 1;}
    |exp EOL { AST = $1; imprimeRpnFormat(AST); return 1; }
    |EOL {printf(">");return 1;}
    |QUIT {return 0;}
;

option:SHOW SETTINGS {imprimeSettings();}
    |RESET SETTINGS {resetSettings();}
    |SET HVIEW REAL COLON REAL{setHView($3,$5);}
    |SET VVIEW REAL COLON REAL{setVView($3,$5);}
    |SET AXIS ON {axisOn();}
    |SET AXIS OFF {axisOff();}
    |PLOT {plotFunction();}
    |PLOT L_PAREN exp1 R_PAREN {plotTree=$3;plotFunction(plotTree);}
    |SET INTEGRAL_STEPS REAL {setIntegralSteps($3);}
    |INTEGRATE  L_PAREN REAL COLON REAL COMMA exp1 R_PAREN{AST=$7;integrate(AST,$3,$5);}
    |MATRIX EQUAL L_BRACKET mat R_BRACKET{printf("%s\n",yytext);}
    |SHOW MATRIX {printf("%s\n",yytext);}
    |SOLVE DETERMINANT {printf("%s\n",yytext);}
    |SOLVE LINEAR_SYSTEM {printf("%s\n",yytext);}
    |ABOUT {imprimeAbout();return 1;}
    
;

mat:L_BRACKET vector R_BRACKET {}
    |mat COMMA L_BRACKET vector R_BRACKET {}
;

vector:element {}
    |vector COMMA element {}
;

element:REAL {}
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

realSigned: PLUS REAL
    | MINUS REAL
;

%%

void yyerror(char *s){
    printf("Erro de Sintaxe: [%s]\n", yytext);
    
}

int main(int argc, char **argv){
    printf(">");
    while(yyparse());
    return 0;
}