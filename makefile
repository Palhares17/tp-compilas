all:
	flex ./src/lex.l
	yacc -v -d ./src/yacc.y
	gcc lex.yy.c y.tab.c ./src/tabela.c ./src/lib.c ./src/arvore.c ./src/codigo.c
	./a.out < ./src/test/entrada2.txt

clean:
	rm -f lex.yy.c y.tab.c y.tab.h a.out
