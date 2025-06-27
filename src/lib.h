#include "arvore.h"
#include "tabela.h"
#include "codigo.h"

#define MAX_SEMANTIC_ERROS 256
#define MAX_ERROR_LENGTH 60

// Variáveis do YACC/LEX
extern int yylineno, yychar, yydebug;
extern char *yytext;
extern FILE *yyin;

// Estado do compilador
extern int hasError;
extern SymbolTable st;
extern TipoApontador head;

/**
 * Funcao principal que ira rodar os principais recursos
 *
 * @return  int
 */
int begin(void);

/**
 * Funcao para tratar mensagens de erro
 *
 * @param  str mensagem de erro
 */

// Funcoes do YACC/LEX
void yyerror(const char *str);
int yylex(void);
int yyparse(void);
