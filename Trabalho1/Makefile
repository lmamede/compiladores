all: saida entrada.txt
	./saida < entrada.txt

lex.yy.c: scan.lex
	lex scan.lex

saida: main.cc lex.yy.c 
	g++ main.cc -o saida -lfl
	
clean: saida lex.yy.c
	rm saida lex.yy.c