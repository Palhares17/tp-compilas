# Trabalho Prático de Compiladores
Este repositório contém a implementação do frontend de um compilador desenvolvido como parte do Trabalho Prático da disciplina CCF 441 – Compiladores, da Universidade Federal de Viçosa – Campus Florestal. A aplicação tem como objetivo principal a criação e análise de uma linguagem de programação original, chamada Piccola Lingua Brasiliana, concebida a partir do universo cômico do meme Italian Brainrot. A linguagem foi projetada com uma estética caricata, usando palavras e estruturas inspiradas na sonoridade do "italiano inventado", criando um ambiente lúdico e criativo para a aprendizagem dos conceitos formais de compiladores. Este compilador foi construído em C, utilizando as ferramentas Flex e Bison para as fases de análise léxica e sintática, além de incluir etapas de análise semântica e geração de código intermediário. O trabalho está dividido em três partes, refletindo o progresso incremental no desenvolvimento do compilador, desde a definição da linguagem até sua análise completa.

## 📚 Descrição da Linguagem
A Piccola Lingua Brasiliana é uma linguagem procedural fictícia, criada com base no humor e estética do meme Italian Brainrot. Suas palavras-chave seguem um estilo caricatural italiano e seus comandos e estruturas utilizam personagens fictícios como "Fabianito Innamorato" e "Danieluzzo Supremo". A linguagem foi pensada para ensinar os fundamentos de compiladores de maneira divertida e envolvente.

## Integrantes
- Aroldo Augusto Barbosa Simões - 4250
- Fabiano Lara Leroy - 4227
- Igor Nascimento Silva - 4257
- Juan Pablo Andrade Avelar - 4229
- Matheus Silva Palhares - 4249

## Pré-requisitos
- Flex
```bash
sudo apt install flex
```
- GCC (GNU Compiler Collection)
```bash
sudo apt install build-essential
```

- O Makefile espera:
    - Um arquivo chamado: lex.l (o arquivo com definições léxicas)
    - Um diretório: input/ contendo o arquivo entrada.txt
    - Um diretório de saída: output/ para colocar o executável a.out
    - 🔧 Certifique-se de que os diretórios input/ e output/ existem.

## Como executar?
- Certifique-se de que o arquivo lex.l está no diretório raiz do projeto.
- Verifique a existência dos diretórios e arquivos existentes no makefile.
- Execute o comando:
```bash
make
```
- Após a execução do comando, o arquivo executável será gerado no diretório output/ e o sistema será executado.

## Exemplos de execução

### Código sintaticamente correto
Arquivo: `input/entrada.txt`
```txt
Importare "magia.brb"

TralaleroTralala contador
BombardinoCrocodilo mensagem
BrbrbrParapim ligado

RhinoToasterino limite TungTungTungAroldo UnoZero

BallerinaGlaucinna
  BallerinaCappuccina Aprire contador Chiudere BallerinaGlaucinna
    ChipampanziniBananini Aprire contador Chiudere BallerinaGlaucinna
      contador TungTungTungAroldo contador BanditoCarioquito Due GelatoFiordilatte
      mensagem TungTungTungAroldo "Contando..." GelatoFiordilatte
    GlaucinnaBallerina
  GlaucinnaBallerina
GlaucinnaBallerina
```
Saída esperada:
```
Programa sintaticamente correto
```

### Código sintaticamente incorreto
Arquivo: `input/erro.txt`
```txt
TralaleroTralala contador
BombardinoCrocodilo mensagem
BallerinaGlaucinna
  BallerinaCappuccina Aprire contador Chiudere
    contador TungTungTungAroldo contador BanditoCarioquito Due GelatoFiordilatte
  GlaucinnaBallerina
# Faltou fechar bloco principal
```
Saída esperada:
```
Erro próximo à linha 7: syntax error
```

## Como rodar outros testes?
- Coloque arquivos de teste no diretório `input/`.
- Altere o Makefile para apontar para o arquivo desejado ou rode manualmente:
```bash
./output/a.out < input/erro.txt
```

## Interpretação das mensagens de erro
- Mensagens como `Erro próximo à linha X: syntax error` indicam erro sintático.
- Mensagens como `ERRO LÉXICO na linha X: Símbolo inválido: ...` indicam erro léxico.