file = lex.l
input = input/entrada.txt

all:
	bison -d translate.y
	flex $(file)
	gcc translate.tab.c lex.yy.c -o output/a.out
	./output/a.out < $(input)
