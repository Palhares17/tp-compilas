%{
#include <stdio.h>
%}

%option noyywrap

/* Definições regulares */
delim            [ \t\n]
ws               {delim}+

digito  Zero|Uno|Due|Tre|Quattro|Cinque|Sei|Sette|Otto|Nove
numero  ({digito})+
ident            [a-zA-Z_][a-zA-Z0-9_]*
string_literal   \"([^\"\\]|\\.)*\"

%%

{ws}                            {/* Ignorar espaços em branco */}

"TralaleroTralala"                { printf("TOKEN_TIPO_INT: %s\n", yytext); }
"BombardinoCrocodilo"             { printf("TOKEN_TIPO_STRING: %s\n", yytext); }
"BrbrbrParapim"                   { printf("TOKEN_TIPO_BOOLEAN: %s\n", yytext); }

"ChipampanziniBananini"           { printf("TOKEN_FOR: %s\n", yytext); }
"BallerinaCappuccina"             { printf("TOKEN_WHILE: %s\n", yytext); }

"BallerinaGlaucinna"          { printf("TOKEN_ABRE_BLOCO: %s\n", yytext); }
"GlaucinnaBallerina"           { printf("TOKEN_FECHA_BLOCO: %s\n", yytext); }
"Aprire"           { printf("TOKEN_ABRE_PARENTESES: %s\n", yytext); }
"Chiudere"                       { printf("TOKEN_FECHA_PARENTESES: %s\n", yytext); }
"Chiudere"                     { printf("TOKEN_FECHA_PARENTESES: %s\n", yytext); }

"TungTungTungAroldo"                            { printf("TOKEN_ATRIBUICAO: %s\n", yytext); }
"BanditoCarioquito"           { printf("TOKEN_ADICAO: %s\n", yytext); }
"BombardinoFabaiano"            { printf("TOKEN_SUBTRACAO: %s\n", yytext); }
"BombouliniBoulinis"           { printf("TOKEN_MULTIPLICACAO: %s\n", yytext); }
"ChocofantoElefanto"           { printf("TOKEN_DIVISAO: %s\n", yytext); }

"NoooLa"           { printf("TOKEN_COMENTARIO_ABERTURA: %s\n", yytext); }
"PoliziaNooo"                       { printf("TOKEN_COMENTARIO_FECHAMENTO: %s\n", yytext); }

"RhinoToasterino"                  { printf("TOKEN_CONST: %s\n", yytext); }
"Importare"              { printf("TOKEN_IMPORT: %s\n", yytext); }
"LaVacaSaturnoSaturnita"      { printf("TOKEN_FUNCTION: %s\n", yytext); }

{numero}    { printf("Número reconhecido: %s\n", yytext); }
{string_literal}               { printf("TOKEN_STRING_LITERAL: %s\n", yytext); }
{ident}                        { printf("TOKEN_IDENTIFICADOR: %s\n", yytext); }

.|\n                            { printf("ERRO LÉXICO: Símbolo inválido: %s\n", yytext); }

%%

int main(void) {
    yylex();
    return 0;
}
