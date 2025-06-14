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

void print_centered(const char *text, int width) {
    int len = strlen(text);
    int pad = (width - len) / 2;
    for (int i = 0; i < pad; i++) printf(" ");
    printf("%s", text);
    for (int i = 0; i < width - len - pad; i++) printf(" ");
}

void print_truncated(const char *text, int width) {
    int len = strlen(text);
    if (len > width - 1) {
        for (int i = 0; i < width - 4; i++) putchar(text[i]);
        printf("...");
    } else {
        printf("%-*s", width, text);
    }
}

void imprimir_tabela_simbolos() {
    printf("\n\033[1;36m╔════════════════════════╦════════════════════════╗\033[0m\n");
    printf("\033[1;36m║\033[1;33m");
    print_centered("Nome", 24);
    printf("\033[1;36m║\033[1;33m");
    print_centered("Valor", 24);
    printf("\033[1;36m║\033[0m\n");
    printf("\033[1;36m╠════════════════════════╬════════════════════════╣\033[0m\n");

    for (int i = 0; i < qtd_simbolos; i++) {
        printf("\033[1;36m║\033[0m \033[1;32m");
        print_truncated(tabela_simbolos[i].nome, 24);
        printf("\033[0m \033[1;36m║\033[0m \033[1;35m");
        char valor_str[25];
        snprintf(valor_str, sizeof(valor_str), "%d", tabela_simbolos[i].valor);
        print_truncated(valor_str, 24);
        printf("\033[0m \033[1;36m║\033[0m\n");
    }

    printf("\033[1;36m╚════════════════════════╩════════════════════════╝\033[0m\n");
}

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
    | declaracao_const
    | importacao
    | repeticao_while
    | repeticao_for
    | comando_print
    | bloco
;

declaracao:
    tipo TOKEN_IDENTIFICADOR ';'
    | tipo TOKEN_IDENTIFICADOR TOKEN_ATRIBUICAO expressao ';'
;

declaracao_const:
    TOKEN_CONST TOKEN_IDENTIFICADOR TOKEN_ATRIBUICAO expressao ';'
;

importacao:
    TOKEN_IMPORT TOKEN_STRING_LITERAL ';'
;

atribuicao:
    TOKEN_IDENTIFICADOR TOKEN_ATRIBUICAO expressao ';'
    {
        set_valor($1, $3);
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
    | TOKEN_STRING_LITERAL     { /* Para simplificação, retorna 0 para strings em contexto aritmético */ $$ = 0; }
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
    printf("\n");
    fprintf(stderr, "Erro próximo à linha %d: %s\n", yylineno, s);
}

int main() {
    yyin = stdin;
    int linha = 1;
    char c;
    FILE *temp = tmpfile();

    while ((c = getchar()) != EOF) {
        if (c == '\n') linha++;
        fputc(c, temp);
    }

    rewind(temp);
    yyin = temp;

    printf("====== Código fonte: ======\n");
    linha = 0;
    rewind(temp);

    while ((c = fgetc(temp)) != EOF) {
        putchar(c);
        if (c == '\n') {
            printf("%3d: ", linha);
            linha++;
        }
    }
    
    rewind(temp);
    yyin = temp;
    yyparse();
    imprimir_tabela_simbolos();
    fclose(temp);
    return 0;
}