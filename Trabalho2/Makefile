all: analisador testes/teste.py
	python3 testes/teste.py

lex.yy.c: scan.l
	lex scan.l

analisador: main.cc lex.yy.c 
	g++ -std=c++17 main.cc -o analisador -lfl
	
clean: analisador lex.yy.c
	rm analisador lex.yy.c