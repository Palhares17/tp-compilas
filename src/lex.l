%{
    #include "./src/arvore.h"
    #include "./src/tabela.h"
    #include "./src/lib.h"
    #include "y.tab.h"
    int countn=0;
    int line_number = 1; 
%}
 
%option yylineno
alpha [a-zA-Z]
digit [0-9]

%%

"TralaleroTralala"                { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return INT; }
"BombardinoCrocodilo"             { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return CHAR; }
"TraleroLero"                     { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return FLOAT; }

"ChipampanziniBananini"           { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return FOR; }
"BallerinaCappuccina"             { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return WHILE; }
"PizzicatoBravissimo"             { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return IF; }
"GlissandoContrario"              { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return ELSE; }

"LaVacaSaturnoSaturnita"          { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return FUNCTION; }
"RhinoToasterino"                 { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return CONST; }
"RitornoSubito"                   { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return RETURN; }
"Continuare"                      { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return CONTINUE; }
"Romperino"                       { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return BREAK; }
"printare"                        { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return PRINT; }

"Verissimo"                       { return TRUE; }
"Falsissimo"                      { return FALSE; }

[-]?{digit}+                      { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return NUMBER; }
[-]?{digit}+\.{digit}{1,6}        { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return FLOAT_NUM; }
{alpha}({alpha}|{digit})*         { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return ID; }
"<="                              { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return LE; }
">="                              { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return GE; }
"=="                              { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return EQ; }
"!="                              { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return NE; }
">"	                              { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return GT; }
"<"	                              { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return LT; }
"&&"	                          { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return AND; }
"||"	                          { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return OR; }
"+"                               { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return ADD; }
"-"                               { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return SUBTRACT; }
"/"                               { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return DIVIDE; }
"*"                               { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return MULTIPLY; }
\/\/.*                            { printf("%s", yytext); }
\/\*(.*\n)*.*\*\/                 { printf("%s", yytext); } 
[ \t]*                            { printf("%s", yytext); }
[\n]                              { printf("\n%10d\t", yylineno);countn++; }
.	                              { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return *yytext; }
["].*["]                          { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return STR; }
['].[']                           { printf("%s", yytext); strcpy(yylval.lexval.name,(yytext)); return CHARACTER; }
%% 

int yywrap() {
    return 1;
}