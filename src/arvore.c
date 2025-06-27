#include "arvore.h"

void inicializaArvore(TipoApontador arvore) {
    arvore = NULL;
}

TipoApontador Insere(char *token, TipoApontador left, TipoApontador right) {
    TipoApontador newnode = (TipoApontador)malloc(sizeof(TipoNo));
    newnode->Esq = left;
    newnode->Dir = right;
    newnode->Reg.Chave = strdup(token);

    return newnode;
}

// Função auxiliar para imprimir prefixos da árvore
void printPrefix(int nivel, int* path, int isLast) {
    for (int i = 0; i < nivel; i++) {
        if (path[i]) {
            printf("│   ");
        } else {
            printf("    ");
        }
    }
    
    if (nivel > 0) {
        if (isLast) {
            printf("└── ");
        } else {
            printf("├── ");
        }
    }
}

// Função para determinar se um nó é um operador
int isOperator(const char* token) {
    return (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0 ||
            strcmp(token, "=") == 0 || strcmp(token, "<") == 0 ||
            strcmp(token, ">") == 0 || strcmp(token, "<=") == 0 ||
            strcmp(token, ">=") == 0 || strcmp(token, "==") == 0 ||
            strcmp(token, "!=") == 0 || strcmp(token, "&&") == 0 ||
            strcmp(token, "||") == 0);
}

// Função para determinar se um nó é uma palavra-chave
int isKeyword(const char* token) {
    return (strcmp(token, "if") == 0 || strcmp(token, "else") == 0 ||
            strcmp(token, "for") == 0 || strcmp(token, "while") == 0 ||
            strcmp(token, "return") == 0 || strcmp(token, "print") == 0 ||
            strcmp(token, "main") == 0 || strcmp(token, "begin") == 0 ||
            strcmp(token, "fun-decl") == 0 || strcmp(token, "declaration") == 0 ||
            strcmp(token, "if-else") == 0 || strcmp(token, "block") == 0 ||
            strcmp(token, "for-init") == 0 || strcmp(token, "for-cond") == 0);
}

// Função para determinar se um nó é um valor literal
int isLiteral(const char* token) {
    return (strcmp(token, "true") == 0 || strcmp(token, "false") == 0 ||
            strcmp(token, "NULL") == 0 || 
            (token[0] >= '0' && token[0] <= '9') ||
            (token[0] == '-' && token[1] >= '0' && token[1] <= '9'));
}

void printArvore(TipoApontador arvore, int nivel) {
    if (arvore == NULL) return;

    static int path[100]; // Array para rastrear o caminho na árvore
    
    // Imprimir o nó atual
    printPrefix(nivel, path, 0);
    
    // Aplicar cores baseadas no tipo do nó
    if (isOperator(arvore->Reg.Chave)) {
        printf("\033[1;33m%s\033[0m", arvore->Reg.Chave); // Amarelo para operadores
    } else if (isKeyword(arvore->Reg.Chave)) {
        printf("\033[1;34m%s\033[0m", arvore->Reg.Chave); // Azul para palavras-chave
    } else if (isLiteral(arvore->Reg.Chave)) {
        printf("\033[1;32m%s\033[0m", arvore->Reg.Chave); // Verde para literais
    } else if (strcmp(arvore->Reg.Chave, "ID") == 0 || 
               (arvore->Reg.Chave[0] >= 'a' && arvore->Reg.Chave[0] <= 'z') ||
               (arvore->Reg.Chave[0] >= 'A' && arvore->Reg.Chave[0] <= 'Z')) {
        printf("\033[1;35m%s\033[0m", arvore->Reg.Chave); // Magenta para identificadores
    } else {
        printf("\033[1;37m%s\033[0m", arvore->Reg.Chave); // Branco para outros
    }
    printf("\n");

    // Processar filhos
    if (arvore->Esq != NULL || arvore->Dir != NULL) {
        if (arvore->Esq) {
            path[nivel] = (arvore->Dir != NULL) ? 1 : 0;
            printArvore(arvore->Esq, nivel + 1);
        }
        
        if (arvore->Dir) {
            path[nivel] = 0;
            printArvore(arvore->Dir, nivel + 1);
        }
    }
}

// Função alternativa sem cores (para compatibilidade)
void printArvoreSimples(TipoApontador arvore, int nivel) {
    if (arvore == NULL) return;

    static int path[100];
    
    printPrefix(nivel, path, 0);
    printf("%s\n", arvore->Reg.Chave);

    if (arvore->Esq != NULL || arvore->Dir != NULL) {
        if (arvore->Esq) {
            path[nivel] = (arvore->Dir != NULL) ? 1 : 0;
            printArvoreSimples(arvore->Esq, nivel + 1);
        }
        
        if (arvore->Dir) {
            path[nivel] = 0;
            printArvoreSimples(arvore->Dir, nivel + 1);
        }
    }
}