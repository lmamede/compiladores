%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Atributos {
  string e;
  string d;
};

#define YYSTYPE Atributos

int yylex();
int yyparse();
void yyerror(const char *);

%}

%token NUM CTE X

// Start indica o símbolo inicial da gramática
%start S

%%

S : E { cout << "f(x)     = " << $1.e << endl
             << "df(x)/dx = " << $1.d << endl; }
  ;

T : let
  
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