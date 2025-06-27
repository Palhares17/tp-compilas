#ifndef CODIGO_H
#define CODIGO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CODE_TAM 900
#define MAX_CODE_STR_LENGTH 100

// Estrutura para quádruplas
typedef struct Quadruple {
    char op[MAX_CODE_STR_LENGTH];
    char arg1[MAX_CODE_STR_LENGTH];
    char arg2[MAX_CODE_STR_LENGTH];
    char result[MAX_CODE_STR_LENGTH];
} Quadruple;

// Enum para tipos de condicionais
enum Conditionals {
    ifElse,
    forStatement,
    whileStatement
};

extern int tempReg; // Contador para variáveis temporárias
extern int regEnd;  // Contador para labels
extern int actualConditional; // Tipo de condicional atual

typedef struct ThreeAdd {
    Quadruple table[MAX_CODE_TAM];
    int last;
} ThreeAdd;

extern ThreeAdd intermediateCode;

// Funções para manipulação do código de três endereços
void addThreeAddressCode(const char* op, const char* arg1, const char* arg2, const char* result);
void printThreeAddressTable(int mode); // 0 = quadrupla, 1 = tripla
void initializeThreeAddressCode();
void createFileOutput();

#endif