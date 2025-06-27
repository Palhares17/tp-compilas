#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct TipoRegistro {
    char *Chave;
} TipoRegistro;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {
    TipoRegistro Reg;
    TipoApontador Esq, Dir;
} TipoNo;

void inicializaArvore(TipoApontador arvore);
TipoApontador Insere(char *token, TipoApontador left, TipoApontador right);
void printArvore(TipoApontador arvore, int nivel);
void printArvoreSimples(TipoApontador arvore, int nivel);

// Funções auxiliares para formatação
void printPrefix(int nivel, int* path, int isLast);
int isOperator(const char* token);
int isKeyword(const char* token);
int isLiteral(const char* token);

#endif