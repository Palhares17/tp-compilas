%{
#include <stdio.h>
#include "translate.tab.h"
extern int yylineno;
extern YYSTYPE yylval;
%}

%option noyywrap

/* Definições regulares */
delim            [ \t\n]
ws               {delim}+

digito  Zero|Uno|Due|Tre|Quattro|Cinque|Sei|Sette|Otto|Nove
numero  ({digito})+
ident            [a-zA-Z_][a-zA-Z0-9_]*
string_literal   \"([^"\\]|\\.)*\"

%%

{ws}                            {/* Ignorar espaços em branco */}

"TralaleroTralala"                { printf("TOKEN_TIPO_INT: %s\n", yytext); return TOKEN_TIPO_INT; }
"BombardinoCrocodilo"             { printf("TOKEN_TIPO_STRING: %s\n", yytext); return TOKEN_TIPO_STRING; }
"BrbrbrParapim"                   { printf("TOKEN_TIPO_BOOLEAN: %s\n", yytext); return TOKEN_TIPO_BOOLEAN; }

"ChipampanziniBananini"           { printf("TOKEN_FOR: %s\n", yytext); return TOKEN_FOR; }
"BallerinaCappuccina"             { printf("TOKEN_WHILE: %s\n", yytext); return TOKEN_WHILE; }

"BallerinaGlaucinna"              { printf("TOKEN_ABRE_BLOCO: %s\n", yytext); return TOKEN_ABRE_BLOCO; }
"GlaucinnaBallerina"              { printf("TOKEN_FECHA_BLOCO: %s\n", yytext); return TOKEN_FECHA_BLOCO; }
"Aprire"                          { printf("TOKEN_ABRE_PARENTESES: %s\n", yytext); return TOKEN_ABRE_PARENTESES; }
"Chiudere"                        { printf("TOKEN_FECHA_PARENTESES: %s\n", yytext); return TOKEN_FECHA_PARENTESES; }

"TungTungTungAroldo"              { printf("TOKEN_ATRIBUICAO: %s\n", yytext); return TOKEN_ATRIBUICAO; }
"BanditoCarioquito"               { printf("TOKEN_ADICAO: %s\n", yytext); return TOKEN_ADICAO; }
"BombardinoFabaiano"              { printf("TOKEN_SUBTRACAO: %s\n", yytext); return TOKEN_SUBTRACAO; }
"BombouliniBoulinis"              { printf("TOKEN_MULTIPLICACAO: %s\n", yytext); return TOKEN_MULTIPLICACAO; }
"ChocofantoElefanto"              { printf("TOKEN_DIVISAO: %s\n", yytext); return TOKEN_DIVISAO; }

"NoooLa"                          {/* Comentário de abertura - ignorar */}
"PoliziaNooo"                     {/* Comentário de fechamento - ignorar */}

"RhinoToasterino"                 { printf("TOKEN_CONST: %s\n", yytext); return TOKEN_CONST; }
"Importare"                       { printf("TOKEN_IMPORT: %s\n", yytext); return TOKEN_IMPORT; }
"LaVacaSaturnoSaturnita"          { printf("TOKEN_FUNCTION: %s\n", yytext); return TOKEN_FUNCTION; }

"GelatoFiordilatte" { printf("PONTO_E_VIRGULA: %s\n", yytext); return ';'; }

"Maior" { printf("TOKEN_MAIOR: %s\n", yytext); return TOKEN_MAIOR; }
"Menor" { printf("TOKEN_MENOR: %s\n", yytext); return TOKEN_MENOR; }
"Igualdade" { printf("TOKEN_IGUALDADE: %s\n", yytext); return TOKEN_IGUALDADE; }
"Diferente" { printf("TOKEN_DIFERENTE: %s\n", yytext); return TOKEN_DIFERENTE; }
"MaiorIgual" { printf("TOKEN_MAIOR_IGUAL: %s\n", yytext); return TOKEN_MAIOR_IGUAL; }
"MenorIgual" { printf("TOKEN_MENOR_IGUAL: %s\n", yytext); return TOKEN_MENOR_IGUAL; }

{numero}    { yylval.str = strdup(yytext); return TOKEN_NUMERO; }
{string_literal} { printf("TOKEN_STRING_LITERAL: %s\n", yytext); yylval.str = strdup(yytext); return TOKEN_STRING_LITERAL; }
{ident}     { printf("TOKEN_IDENTIFICADOR: %s\n", yytext); yylval.str = strdup(yytext); return TOKEN_IDENTIFICADOR; }

   .|\n    { fprintf(stderr, "ERRO LÉXICO na linha %d: Símbolo inválido: %s\n", yylineno, yytext); return TOKEN_ERRO; }

%%
