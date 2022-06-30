%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Atributos {
  string teste;

};

#define YYSTYPE Atributos

extern "C" int yylex();  
int yyparse();
void yyerror(const char *);

%}

%token _ID _FOR _IF _INT _FLOAT _MAIG _MEIG _IG _DIF _STRING _STRING2 _COMENTARIO _PRINT

%start Entrada

%%

Operador_Menos_Prioritario  :   '-' {cout << "1- ";}
                            |   '+' {cout << "2+ ";} 
                            ;

Operador_Prioritario    :   '*' {cout << "* ";}
                        |   '/' {cout << "/ ";}
                        |   '^' {cout << "^ ";} 
                        |   '!' {cout << "! ";}  
                        ;


Membro  :   _STRING {cout << "string ";}
        |   _INT    {cout << "int ";}
        |   _FLOAT  {cout << "float ";}
        |   _ID     {cout << "id ";}
        |   _PRINT  {cout << "print ";}
        |   '+'     {cout << "+ ";}
        |   '-'     {cout << "- ";}
        |   '('     {cout << "( ";}
        ;

Termo   :   Membro {cout << "termo ";}
        |   Operador_Prioritario;
        ;

Expressao   :   Termo   {cout << "expressao ";}
            |   Operador_Menos_Prioritario 
            ;

Entrada  :  Expressao ';' {cout << "Entrada ";}
         ;
%%

#include "lex.yy.c"

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Proximo a: %s\n", yytext );
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}