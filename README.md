# 🎵 Compilador de Linguagem Personalizada

Um compilador completo para uma linguagem de programação criativa e divertida, implementado como projeto acadêmico para a disciplina de Compiladores.

## 📋 Descrição

Este projeto implementa um **compilador completo** que processa uma linguagem de programação personalizada com palavras-chave únicas e criativas. O compilador realiza análise léxica, sintática, geração de código intermediário e construção de árvore sintática.

### 🎯 Funcionalidades

- ✅ **Análise Léxica**: Reconhecimento de tokens personalizados
- ✅ **Análise Sintática**: Parsing de estruturas de controle
- ✅ **Geração de Código Intermediário**: Código de três endereços
- ✅ **Tabela de Símbolos**: Gerenciamento de identificadores
- ✅ **Árvore Sintática**: Representação hierárquica do código
- ✅ **Tratamento de Erros**: Detecção e reporte de erros sintáticos

## 🎨 A Linguagem Personalizada

A linguagem utiliza palavras-chave criativas em italiano/português:

### Tipos de Dados
| Palavra-chave | Significado |
|---------------|-------------|
| `TralaleroTralala` | `int` |
| `TraleroLero` | `float` |
| `BombardinoCrocodilo` | `char` |
| `VOID` | `void` |

### Estruturas de Controle
| Palavra-chave | Significado |
|---------------|-------------|
| `ChipampanziniBananini` | `for` |
| `BallerinaCappuccina` | `while` |
| `PizzicatoBravissimo` | `if` |
| `GlissandoContrario` | `else` |

### Outros Elementos
| Palavra-chave | Significado |
|---------------|-------------|
| `printare` | `print` |
| `RitornoSubito` | `return` |
| `Verissimo` | `true` |
| `Falsissimo` | `false` |
| `LaVacaSaturnoSaturnita` | `function` |
| `RhinoToasterino` | `const` |
| `Continuare` | `continue` |
| `Romperino` | `break` |

## 🏗️ Arquitetura do Projeto

```
tp-compilas/
├── src/
│   ├── lex.l              # Analisador léxico (Flex)
│   ├── yacc.y             # Analisador sintático (Bison)
│   ├── arvore.c/h         # Implementação da árvore sintática
│   ├── tabela.c/h         # Tabela de símbolos
│   ├── codigo.c/h         # Geração de código intermediário
│   ├── lib.c/h            # Funções auxiliares
│   └── test/              # Arquivos de teste
│       ├── entrada1.txt   # Teste básico
│       ├── entrada2.txt   # Teste com estruturas condicionais
│       └── entrada3.txt   # Teste adicional
├── makefile               # Script de compilação
├── y.tab.c               # Código gerado pelo Bison
├── y.tab.h               # Headers gerados pelo Bison
├── lex.yy.c              # Código gerado pelo Flex
├── y.output              # Análise de conflitos do Bison
└── a.out                 # Executável do compilador
```

## 🚀 Como Executar

### Pré-requisitos

Certifique-se de ter instalado:
- **Flex** (Analisador léxico)
- **Bison** (Analisador sintático)
- **GCC** (Compilador C)

### Instalação no Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install flex bison gcc make
```

### Instalação no macOS
```bash
brew install flex bison gcc make
```

### Compilação e Execução

1. **Clone o repositório:**
   ```bash
   git clone <url-do-repositorio>
   cd tp-compilas
   ```

2. **Compile o compilador:**
   ```bash
   make
   ```

3. **Execute com um arquivo de teste:**
   ```bash
   ./a.out < src/test/entrada1.txt
   ```

4. **Para limpar arquivos gerados:**
   ```bash
   make clean
   ```

## 📝 Exemplos de Código

### Exemplo Básico (entrada1.txt)
```c
TralaleroTralala main() {
    TralaleroTralala x=1;
    TraleroLero f;
    TralaleroTralala a=3;
    TralaleroTralala x;
    a = x * 3 + 5;
}
```

### Exemplo com Estruturas Condicionais (entrada2.txt)
```c
TralaleroTralala main() {
    TralaleroTralala x=1;
    TraleroLero f;
    TralaleroTralala a=3;
    TralaleroTralala x;
    a = x * 3 + 5;
    PizzicatoBravissimo(x > a) {
        printare("Ola TralaleroTralala");
        a = x * 3 + 100;
        PizzicatoBravissimo(x > a) {
            printare("Ola condicoes!");
            a = x * 3 + 100;
        }
        GlissandoContrario {
            x = a * 3 + 100;
        }
    }
    GlissandoContrario {
        x = a * 3 + 100;
    }
}
```

## 🎯 Saída do Compilador

O compilador gera várias saídas:

### 1. Análise Léxica
- Lista todos os tokens reconhecidos
- Mostra números de linha
- Identifica tipos de tokens

### 2. Tabela de Símbolos
- Identificadores declarados
- Tipos de dados
- Escopo das variáveis

### 3. Árvore Sintática
- Representação hierárquica do código
- Estrutura de nós da árvore

### 4. Código de Três Endereços
- Quádruplas geradas
- Operações intermediárias
- Labels para estruturas de controle

## 🔧 Estrutura do Código

### Analisador Léxico (`src/lex.l`)
- Define padrões para reconhecimento de tokens
- Implementa palavras-chave personalizadas
- Suporta comentários e números

### Analisador Sintático (`src/yacc.y`)
- Define gramática da linguagem
- Implementa regras de produção
- Gera árvore sintática

### Geração de Código (`src/codigo.c/h`)
- Implementa código de três endereços
- Gerencia variáveis temporárias
- Cria quádruplas para operações

### Tabela de Símbolos (`src/tabela.c/h`)
- Gerencia identificadores
- Armazena tipos e escopo
- Suporta diferentes tipos de símbolos

### Árvore Sintática (`src/arvore.c/h`)
- Implementa estrutura de árvore binária
- Funções para inserção e impressão
- Representação visual da árvore

## 🐛 Tratamento de Erros

O compilador inclui:
- Detecção de erros sintáticos
- Mensagens de erro informativas
- Recuperação de erros básica

## 📚 Conceitos Implementados

Este projeto demonstra os conceitos fundamentais de compiladores:

- **Análise Léxica**: Reconhecimento de tokens
- **Análise Sintática**: Parsing e validação de estrutura
- **Análise Semântica**: Verificação de tipos e escopo
- **Geração de Código**: Código intermediário
- **Gerenciamento de Símbolos**: Tabela de símbolos
- **Estruturas de Dados**: Árvores sintáticas

## 🎓 Propósito Educacional

Este projeto foi desenvolvido como trabalho prático para a disciplina de **Compiladores (CCF 451)** da UFV, demonstrando:

- Implementação prática de conceitos teóricos
- Uso de ferramentas como Flex e Bison
- Desenvolvimento de um compilador completo
- Gerenciamento de projeto de software

## 🤝 Contribuição

Para contribuir com o projeto:

1. Faça um fork do repositório
2. Crie uma branch para sua feature
3. Implemente suas mudanças
4. Teste com os arquivos de exemplo
5. Envie um pull request

## 📄 Licença

Este projeto é desenvolvido para fins educacionais como parte do curso de Compiladores da UFV.

---

**Desenvolvido por:** [Seu Nome]  
**Disciplina:** CCF 451 - Compiladores  
**Universidade:** UFV - Universidade Federal de Viçosa
