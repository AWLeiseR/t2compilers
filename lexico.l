%option noyywrap

%{
    #include <ast.h>
    #include <sintatico.tab.h>
    
    extern YYSTYPE yylval; /* YYSTYPE eh int por padrao */
%}

%%

"+"                 { return PLUS; }

"-"                 { return MINUS; }

"*"                 { return ASTERIX; }

"/"                 { return DIV; }

"^"                 { return EXP; }

"%"                 { return PERCENT; }

"("                 { return L_PAREN; }

")"                 { return R_PAREN; }

"["                 { return L_BRACKET; }

"]"                 { return R_BRACKET; }

";"                 { return SEMICOLON; }

":"                 {return COLON;}

","                 {return COMMA;}

"="                 {return EQUAL;}

"sen"               { return SEN; }

"cos"               { return COS; }

"tan"               { return TAN; }

"abs"               { return ABS; }

[0-9]+              {yylval.real=atof(yytext); return REAL; }

[0-9]+"."[0-9]+     {yylval.real=atof(yytext); return REAL; }

"x"                 {  return VAR; }

\n                  { return EOL; }

\t                  { return TAB; }

" "                 { }

"show"              { return SHOW; }

"settings"          { return SETTINGS; }

"reset"             { return RESET; }

"quit"              { return QUIT; }

"set"               { return SET; }

"h_view"            { return HVIEW; }

"v_view"            { return VVIEW; }

"axis"             { return AXIS; }

"on"                { return ON; }

"off"               { return OFF; }

"plot"              { return PLOT; }

"integral_steps"    { return INTEGRAL_STEPS; }

"integrate"         { return INTEGRATE; }

"matrix"            { return MATRIX; }

"solve"             { return SOLVE; }

"determinant"       { return DETERMINANT; }

"linear_system"     { return LINEAR_SYSTEM; }

"about"             { return ABOUT; }

. {printf("Simbolo Invalido -> %s\n\n",yytext);}

%%