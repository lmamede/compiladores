
all: lex.yy.mdp.o var_object.cc mdp.cc
	 g++ -Wall -std=c++17 mdp.cc lex.yy.mdp.o -lfl -o interpretador 
		
lex.yy.mdp.o: lex.yy.mdp.c 
	g++ -Wall -std=c++14 -c lex.yy.mdp.c 
	
lex.yy.mdp.c: mdp.l 
	lex -o lex.yy.mdp.c mdp.l 
	