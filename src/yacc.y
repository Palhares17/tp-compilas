%{
    #include "./src/arvore.h"
    #include "./src/tabela.h"
    #include "./src/lib.h"
    #include "y.tab.h"
    void defineDataType();
    char dataType[18];
    void handleError(const char *str);
%}

%union {
  struct lexval {
    char name[100];
    char type[20];
    TipoApontador node;
    char gotoLabel[10];
    char nextGotoLabel[10];
  } lexval;
}

%token <lexval> VOID CHARACTER PRINT INT FLOAT CHAR FOR IF ELSE TRUE FALSE NUMBER FLOAT_NUM ID
%token <lexval> LE GE EQ NE GT LT AND OR STR ADD MULTIPLY DIVIDE SUBTRACT UNARY RETURN WHILE
%token <lexval> FUNCTION CONST CONTINUE BREAK

%type <lexval> begin main body return datatype expression statement init value arithmetic relop condition else

%%

begin: main '(' ')' '{' body return '}' {
  $1.node = Insere("main", $5.node, $6.node);
  $$.node = Insere("begin", $1.node, NULL);
  head = $$.node;
}
;

main: datatype ID {
  addToSymbolTable(&st, FUNCT, yylineno, dataType, yytext);
  $2.node = Insere($2.name, NULL, NULL);
  $$.node = Insere("fun-decl", $2.node, NULL);
}
;

datatype: INT { defineDataType(); }
        | FLOAT { defineDataType(); }
        | CHAR { defineDataType(); }
        | VOID { defineDataType(); }
;

body:
    FOR '(' statement ';' condition ';' statement ')' '{' body '}' {
        TipoApontador loopCond = Insere("for-cond", $5.node, $7.node);
        TipoApontador loopHead = Insere("for-init", $3.node, loopCond);
        $$.node = Insere("for", loopHead, $10.node);
        char labelStart[20], labelEnd[20];
        sprintf(labelStart, "L%d", regEnd++);
        sprintf(labelEnd, "L%d", regEnd++);
        addThreeAddressCode("LABEL", labelStart, "-", "-");
        addThreeAddressCode("IF_FALSE", $5.name, labelEnd, "-");

        // ... corpo do for ...
        addThreeAddressCode("GOTO", labelStart, "-", "-");
        addThreeAddressCode("LABEL", labelEnd, "-", "-");
    }
  | IF '(' condition ')' '{' body '}' else {
        TipoApontador nodeIf = Insere("if", $3.node, $6.node);
        $$.node = Insere("if-else", nodeIf, $8.node);
        char labelElse[20], labelEnd[20];
        sprintf(labelElse, "L%d", regEnd++);
        sprintf(labelEnd, "L%d", regEnd++);
        addThreeAddressCode("IF_FALSE", $3.name, labelElse, "-");

        // ... corpo do if ...
        addThreeAddressCode("GOTO", labelEnd, "-", "-");
        addThreeAddressCode("LABEL", labelElse, "-", "-");
        
        // ... corpo do else ...
        addThreeAddressCode("LABEL", labelEnd, "-", "-");
    }
  | statement ';' {
        $$.node = $1.node;
    }
  | body body {
        $$.node = Insere("block", $1.node, $2.node);
    }
  | PRINT '(' STR ')' ';' {
        TipoApontador strNode = Insere($3.name, NULL, NULL);
        $$.node = Insere("print", strNode, NULL);
        addThreeAddressCode("PRINT", $3.name, "-", "-");
    }
  | WHILE '(' condition ')' '{' body '}' {
        $$.node = Insere("while", $3.node, $6.node);
        char labelStart[20], labelEnd[20];
        sprintf(labelStart, "L%d", regEnd++);
        sprintf(labelEnd, "L%d", regEnd++);
        addThreeAddressCode("LABEL", labelStart, "-", "-");
        addThreeAddressCode("IF_FALSE", $3.name, labelEnd, "-");
        // ... corpo do while ...
        addThreeAddressCode("GOTO", labelStart, "-", "-");
        addThreeAddressCode("LABEL", labelEnd, "-", "-");
    }
;

else:
    ELSE '{' body '}' {
        $$.node = Insere("else", $3.node, NULL);
    }
  | {
        $$.node = NULL;
    }
;

condition:
    value relop value {
        $$.node = Insere($2.name, $1.node, $3.node);
        char tempVar[20];
        sprintf(tempVar, "t%d", tempReg++);
        strcpy($$.name, tempVar);
        addThreeAddressCode($2.name, $1.name, $3.name, tempVar);
    }
  | TRUE {
        $$.node = Insere("true", NULL, NULL);
        strcpy($$.name, "true");
    }
  | FALSE {
        $$.node = Insere("false", NULL, NULL);
        strcpy($$.name, "false");
    }
  | {
        $$.node = NULL;
    }
;

statement:
    datatype ID { addToSymbolTable(&st, IDTYPE, yylineno, dataType, yytext); } init {
        $2.node = Insere($2.name, NULL, NULL);
        $$.node = Insere("declaration", $2.node, $4.node);
        if (strcmp($4.name, "NULL") != 0) {
            addThreeAddressCode("ASSIGN", $4.name, "-", $2.name);
        }
    }
  | ID '=' expression {
        $1.node = Insere($1.name, NULL, NULL);
        $$.node = Insere("=", $1.node, $3.node);
        addThreeAddressCode("ASSIGN", $3.name, "-", $1.name);
    }
  | ID relop expression {
        $1.node = Insere($1.name, NULL, NULL);
        $$.node = Insere($2.name, $1.node, $3.node);
    }
;

init: '=' value {
  $$.node = $2.node;
  strcpy($$.type, $2.type);
  strcpy($$.name, $2.name);
}
| {
  strcpy($$.type, "null");
  strcpy($$.name, "NULL");
  $$.node = Insere("NULL", NULL, NULL);
}
;

expression: expression arithmetic expression {
  $$.node = Insere($2.name, $1.node, $3.node);
  char tempVar[20];
  sprintf(tempVar, "t%d", tempReg++);
  strcpy($$.name, tempVar);
  addThreeAddressCode($2.name, $1.name, $3.name, tempVar);
}
| value {
  $$.node = $1.node;
  strcpy($$.name, $1.name);
}
;

arithmetic: ADD | SUBTRACT | MULTIPLY | DIVIDE;
relop: LT | GT | LE | GE | EQ | NE;

value: NUMBER {
  $$.node = Insere($1.name, NULL, NULL);
  strcpy($$.name, $1.name);
  strcpy($$.type, "int");
}
| FLOAT_NUM {
  $$.node = Insere($1.name, NULL, NULL);
  strcpy($$.name, $1.name);
  strcpy($$.type, "float");
}
| ID {
  $$.node = Insere($1.name, NULL, NULL);
  strcpy($$.name, $1.name);
}
;

return: RETURN value ';' {
  $1.node = Insere("return", NULL, NULL);
  $$.node = Insere("RETURN", $1.node, $2.node);
  addThreeAddressCode("RETURN", $2.name, "-", "-");
}
| {
  $$.node = NULL;
}
;

%%

void defineDataType() {
  strcpy(dataType, yytext);
}

int main(int argc, char *argv[]) {
  return begin();
}

void yyerror(const char* msg) {
  handleError(msg);
}
