file = lex.l
input = input/entrada.txt

all:
	flex $(file)
	gcc lex.yy.c -o output/a.out
	./output/a.out < $(input)
