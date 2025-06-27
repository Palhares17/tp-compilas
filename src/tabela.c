#include "tabela.h"

void initializeSymbolTable(SymbolTable *st) {
    st->first = 0;
    st->last = st->first;
}

// verifica se o simbolo encontrado ja esta na tabela
int verifyAlreadyIsInTable(SymbolTable *table, char *id) {
    int i;
    for (i = table->last - 1; i >= 0; i--) {
        if (strcmp(table->table[i].token.lexem, id) == 0) {
            return -1;
            break;
        }
    }
    return 0;
}

void enterTableData(SymbolTable *table, int index, MetaType c, int lineNum, char *dataType, char *yytext) {
    table->table[index].token.lexem = strdup(yytext);
    table->table[index].line = lineNum;
    table->table[index].type = c;
    table->table[index].data_type = strdup(dataType);
}

void addToSymbolTable(SymbolTable *table, MetaType c, int lineNum, char *dataType, char *yytext) {
    if (!verifyAlreadyIsInTable(table, yytext)) {
        int index = table->last;
        switch (c) {
            case KEYWORD:
                enterTableData(table, index, c, lineNum, dataType, yytext);
                break;
            case IDTYPE:
                enterTableData(table, index, c, lineNum, dataType, yytext);
                break;
            case CONSTANT:
                enterTableData(table, index, c, lineNum, dataType, yytext);
                break;
            case FUNCT:
                enterTableData(table, index, c, lineNum, dataType, yytext);
                break;
            case OPERATOR:
                enterTableData(table, index, c, lineNum, dataType, yytext);
                break;
            default:
                printf("Not mapped\n");
                break;
        }

        index++;
        table->last = index;
    }
}

char *handleShowMetaType(MetaType t) {
    switch (t) {
        case KEYWORD:
            return "Palavra chave";
            break;
        case IDTYPE:
            return "Variavel";
            break;
        case CONSTANT:
            return "Constante";
            break;
        case FUNCT:
            return "Funcao";
            break;
        case OPERATOR:
            return "Operador";
            break;
        default:
            return "";
            break;
    }
}

void print_truncated(const char *str, int width) {
    int len = strlen(str);
    if (len > width - 1) {
        for (int i = 0; i < width - 3; i++) putchar(str[i]);
        printf("...");
    } else {
        printf("%-*s", width, str);
    }
}

void print_centered(const char *str, int width) {
    int len = strlen(str);
    int padding = (width - len) / 2;
    for (int i = 0; i < padding; i++) putchar(' ');
    printf("%s", str);
    for (int i = 0; i < width - padding - len; i++) putchar(' ');
}

void printSymbolTable(SymbolTable st) {
    printf("\n\033[1;36m╔════════════════════════╦════════════════════╦════════════════════════╦══════════════╗\033[0m\n");
    printf("\033[1;36m║\033[1;33m");
    print_centered("Símbolo", 24);
    printf("\033[1;36m║\033[1;33m");
    print_centered("Tipo", 20);
    printf("\033[1;36m║\033[1;33m");
    print_centered("Tipo de Dado", 24);
    printf("\033[1;36m║\033[1;33m");
    print_centered("Linha", 12);
    printf("\033[1;36m║\033[0m\n");

    printf("\033[1;36m╠════════════════════════╬════════════════════╬════════════════════════╬══════════════╣\033[0m\n");

    for (int i = 0; i < st.last; i++) {
        printf("\033[1;36m║\033[0m \033[1;32m");
        print_truncated(st.table[i].token.lexem, 24);
        printf("\033[0m \033[1;36m║\033[0m \033[1;35m");
        print_truncated(handleShowMetaType(st.table[i].type), 20);
        printf("\033[0m \033[1;36m║\033[0m \033[1;34m");
        print_truncated(st.table[i].data_type, 24);
        printf("\033[0m \033[1;36m║\033[0m \033[1;33m");
        printf("%-12d", st.table[i].line);
        printf("\033[1;36m║\033[0m\n");
    }

    printf("\033[1;36m╚════════════════════════╩════════════════════╩════════════════════════╩══════════════╝\033[0m\n");
}
