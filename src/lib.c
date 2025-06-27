#include "lib.h"

int hasError = 0;           // definição real
SymbolTable st;             // definição real
TipoApontador head = NULL;  // definição real da variável head

int begin(void) {
    hasError = 0;
    initializeSymbolTable(&st);
    initializeThreeAddressCode();  // Inicializar código de três endereços

    printf("\n\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    COMPILADOR - ANÁLISE SINTÁTICA            ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf("\n");

    printf("ARQUIVO DE ENTRADA:\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    yyparse();

    printf("\n\n");
    printf("TABELA DE SÍMBOLOS:\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printSymbolTable(st);

    printf("\n\n");
    printf("ÁRVORE SINTÁTICA ABSTRATA:\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    if (head != NULL) {
        printArvore(head, 0);
    } else {
        printf("   (árvore vazia)\n");
    }

    // Imprimir tabelas de três endereços
    printThreeAddressTable(0);  // Quádrupla
    printThreeAddressTable(1);  // Tripla

    printf("\n\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    if (hasError) {
        printf("❌ PROGRAMA INCORRETO! Encerrando compilador!\n");
    } else {
        printf(" PROGRAMA CORRETO! Encerrando compilador!\n");
    }
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("\n");

    return 0;
}

void handleError(const char *str) {
    printf("\n");
    printf("ERRO: %s na linha %d\n", str, yylineno);
    printf("\n");

    hasError = 1;
}