all: miniJS 
	python3 testes/testes3/test.py

lex.yy.c: miniJS.l
	lex miniJS.l

y.tab.c: miniJS.y
	yacc miniJS.y

miniJS: lex.yy.c y.tab.c
	g++ -o miniJS y.tab.c -lfl