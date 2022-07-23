all: saida.out
	./saida.out < testes/entrada.txt

lex.yy.c: scan.lex
	lex scan.lex

saida.out: main.cc lex.yy.c 
	g++ main.cc -o saida.out -lfl
	
clean: saida.out lex.yy.c
	rm saida.out lex.yy.c