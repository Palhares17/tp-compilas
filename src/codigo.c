#include "codigo.h"
#include <stdio.h>
#include <string.h>

// Variáveis globais
int tempReg = 0;
int regEnd = 0;
int actualConditional = ifElse;
ThreeAdd intermediateCode;

void initializeThreeAddressCode() {
    intermediateCode.last = 0;
    tempReg = 0;
    regEnd = 0;
    actualConditional = ifElse;
}

void addThreeAddressCode(const char* op, const char* arg1, const char* arg2, const char* result) {
    if (intermediateCode.last < MAX_CODE_TAM) {
        strncpy(intermediateCode.table[intermediateCode.last].op, op ? op : "-", MAX_CODE_STR_LENGTH-1);
        strncpy(intermediateCode.table[intermediateCode.last].arg1, arg1 ? arg1 : "-", MAX_CODE_STR_LENGTH-1);
        strncpy(intermediateCode.table[intermediateCode.last].arg2, arg2 ? arg2 : "-", MAX_CODE_STR_LENGTH-1);
        strncpy(intermediateCode.table[intermediateCode.last].result, result ? result : "-", MAX_CODE_STR_LENGTH-1);
        intermediateCode.table[intermediateCode.last].op[MAX_CODE_STR_LENGTH-1] = '\0';
        intermediateCode.table[intermediateCode.last].arg1[MAX_CODE_STR_LENGTH-1] = '\0';
        intermediateCode.table[intermediateCode.last].arg2[MAX_CODE_STR_LENGTH-1] = '\0';
        intermediateCode.table[intermediateCode.last].result[MAX_CODE_STR_LENGTH-1] = '\0';
        intermediateCode.last++;
    }
}

void printThreeAddressTable(int mode) {
    printf("\n\033[1;36m╔══════════════╦══════════════════════════╦══════════════");
    if (mode == 0) printf("╦══════════════╗\n");
    else printf("╗\n");
    printf("║\033[1;33m%-12s║%-24s║%-12s", "Operation", "Arg 1", "Arg 2");
    if (mode == 0) printf("║%-12s", "Result");
    printf("\033[0m\n");
    printf("\033[1;36m╠══════════════╬══════════════════════════╬══════════════");
    if (mode == 0) printf("╬══════════════╣\n");
    else printf("╣\n");

    for (int i = 0; i < intermediateCode.last; i++) {
        printf("\033[1;36m║\033[0m \033[1;32m%-12s\033[0m \033[1;36m║\033[0m \033[1;35m%-24s\033[0m \033[1;36m║\033[0m \033[1;35m%-12s\033[0m",
            intermediateCode.table[i].op,
            intermediateCode.table[i].arg1,
            intermediateCode.table[i].arg2);
        if (mode == 0)
            printf(" \033[1;36m║\033[0m \033[1;35m%-12s\033[0m", intermediateCode.table[i].result);
        printf(" \033[1;36m║\033[0m\n");
    }
    printf("\033[1;36m╚══════════════╩══════════════════════════╩══════════════");
    if (mode == 0) printf("╩══════════════╝\033[0m\n");
    else printf("╝\033[0m\n");
}
