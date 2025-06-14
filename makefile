file = lex.l
input = input/erro.txt

all:
	bison -d translate.y
	flex $(file)
	gcc translate.tab.c lex.yy.c -o output/a.out
	./output/a.out < $(input)

clean:
	rm -rf ./output/a.out
