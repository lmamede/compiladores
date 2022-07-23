all: analisador
	../Testes_Trabalhos/test.py -d testes -p ./analisador

lex.yy.c: scan.l
	lex scan.l

analisador: main.cc lex.yy.c 
	g++ -std=c++17 main.cc -o analisador -lfl
	
clean: analisador lex.yy.c
	rm analisador lex.yy.c