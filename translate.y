%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int yylineno;
void yyerror(const char *s);

// ---------------------- TABELA DE SÍMBOLOS ----------------------

#define MAX_SYMBOLS 1000

typedef struct {
    char nome[64];
    int valor;
} Simbolo;

Simbolo tabela_simbolos[MAX_SYMBOLS];
int qtd_simbolos = 0;

int get_valor(char *nome) {
    for (int i = 0; i < qtd_simbolos; i++) {
        if (strcmp(tabela_simbolos[i].nome, nome) == 0)
            return tabela_simbolos[i].valor;
    }
    return 0;
}

void set_valor(char *nome, int valor) {
    for (int i = 0; i < qtd_simbolos; i++) {
        if (strcmp(tabela_simbolos[i].nome, nome) == 0) {
            tabela_simbolos[i].valor = valor;
            return;
        }
    }
    strcpy(tabela_simbolos[qtd_simbolos].nome, nome);
    tabela_simbolos[qtd_simbolos].valor = valor;
    qtd_simbolos++;
}

char nome_identificador_atual[64];

%}

%union {
    int valor;
    char* str;
} 
%left TOKEN_ADICAO TOKEN_SUBTRACAO
%left TOKEN_MULTIPLICACAO TOKEN_DIVISAO
%token TOKEN_TIPO_INT TOKEN_TIPO_STRING TOKEN_TIPO_BOOLEAN
%token TOKEN_FOR TOKEN_WHILE TOKEN_IF TOKEN_ELSE TOKEN_RETURN
%token TOKEN_ABRE_BLOCO TOKEN_FECHA_BLOCO
%token TOKEN_ABRE_PARENTESES TOKEN_FECHA_PARENTESES
%token TOKEN_ATRIBUICAO TOKEN_ADICAO TOKEN_SUBTRACAO TOKEN_MULTIPLICACAO TOKEN_DIVISAO
%token TOKEN_CONST TOKEN_IMPORT TOKEN_FUNCTION
%token <str> TOKEN_STRING_LITERAL TOKEN_IDENTIFICADOR TOKEN_NUMERO
%token TOKEN_IGUALDADE TOKEN_DIFERENTE TOKEN_MAIOR TOKEN_MENOR TOKEN_MAIOR_IGUAL TOKEN_MENOR_IGUAL
%token TOKEN_TRUE TOKEN_FALSE TOKEN_PRINT TOKEN_READ TOKEN_MAIN
%token TOKEN_ERRO

%type <valor> expressao

%%

programa:
    lista_de_comandos { printf("Programa sintaticamente correto\n"); }
;

lista_de_comandos:
    comando
    | lista_de_comandos comando
;

comando:
    declaracao
    | atribuicao
    | repeticao_while
    | repeticao_for
    | comando_print
    | bloco
;

declaracao:
    tipo TOKEN_IDENTIFICADOR { strcpy(nome_identificador_atual, $2); }
    TOKEN_ATRIBUICAO expressao ';'
    {
        set_valor(nome_identificador_atual, $5);
    }
;

atribuicao:
    TOKEN_IDENTIFICADOR { strcpy(nome_identificador_atual, $1); }
    TOKEN_ATRIBUICAO expressao ';'
    {
        set_valor(nome_identificador_atual, $4);
    }
;

comando_print:
    TOKEN_PRINT TOKEN_IDENTIFICADOR ';'
    {
        printf("%d\n", get_valor($2));
    }
  | TOKEN_PRINT TOKEN_STRING_LITERAL ';'
    {
        printf("%s\n", $2);
    }
;

repeticao_while:
    TOKEN_WHILE TOKEN_ABRE_PARENTESES condicao TOKEN_FECHA_PARENTESES bloco
;

repeticao_for:
    TOKEN_FOR TOKEN_ABRE_PARENTESES atribuicao condicao ';' atribuicao TOKEN_FECHA_PARENTESES bloco
;

bloco:
    TOKEN_ABRE_BLOCO lista_de_comandos TOKEN_FECHA_BLOCO
;

tipo:
    TOKEN_TIPO_INT
    | TOKEN_TIPO_STRING
    | TOKEN_TIPO_BOOLEAN
;

expressao:
    TOKEN_IDENTIFICADOR        { $$ = get_valor($1); }
    | TOKEN_NUMERO             { $$ = atoi($1); }
    | expressao TOKEN_ADICAO expressao        { $$ = $1 + $3; }
    | expressao TOKEN_SUBTRACAO expressao     { $$ = $1 - $3; }
    | expressao TOKEN_MULTIPLICACAO expressao { $$ = $1 * $3; }
    | expressao TOKEN_DIVISAO expressao       { $$ = $1 / $3; }
;

condicao:
    expressao operador_relacional expressao
;

operador_relacional:
    TOKEN_IGUALDADE
    | TOKEN_DIFERENTE
    | TOKEN_MAIOR
    | TOKEN_MENOR
    | TOKEN_MAIOR_IGUAL
    | TOKEN_MENOR_IGUAL
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro próximo à linha %d: %s\n", yylineno, s);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Erro ao abrir arquivo");
            return 1;
        }
    }
    yyparse();
    return 0;
}
