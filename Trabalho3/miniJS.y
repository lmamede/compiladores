%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Atributos {
  string valor;

};

#define YYSTYPE Atributos

int recuperarValor(int tk);
void mostrar(string valor);
extern "C" int yylex();  
int yyparse();
void yyerror(const char *);

%}

%token _ID _FOR _IF _INT _FLOAT _MAIG _MEIG _IG _DIF _STRING _STRING2 _COMENTARIO _PRINT

%start Entrada

%%

Argumentos  : Expressao               {$$.valor = $1.valor;}
            | Expressao ',' Expressao {$$.valor = $1.valor + " " + $3.valor;}
            |                         {$$.valor = "";}
            ;

Avaliar_ID  :   '=' Expressao       {$$.valor = $2.valor + " =";}
            |                       {$$.valor = "@";}
            ;

Conta_Simples :   '-' Termo Conta_Simples {$$.valor = " " + $2.valor + " -" + $3.valor;} 
              |   '+' Termo Conta_Simples {$$.valor = " " + $2.valor + " +" + $3.valor;} 
              |                           {$$.valor = "";}
              ;

Conta_Complexa2   :   '^' Termo {$$.valor = " " + $2.valor + " ^";} 
                  |   '!' Termo {$$.valor = " fat #" + $2.valor;}
                  |             {$$.valor = "";}  
                  ;

Conta_Complexa    :   '*' Membro Conta_Complexa2 Conta_Complexa {$$.valor = " " + $2.valor + $3.valor + " *" + $4.valor;}
                  |   '/' Termo {$$.valor = " " + $2.valor + " /";}
                  |   '^' Termo {$$.valor = " " + $2.valor + " ^";} 
                  |   '!' Termo {$$.valor = " fat #" + $2.valor;}
                  |             {$$.valor = "";}
                  ;

Funcao  : _ID '(' Argumentos ')' {$$.valor = $3.valor + " " + $1.valor + " #";}
        ;

Membro  :   _STRING               {$$.valor = $1.valor;}
        |   _INT                  {$$.valor = $1.valor;}
        |   _FLOAT                {$$.valor = $1.valor;}
        |   Funcao                {$$.valor = $1.valor;}
        |   _ID     Avaliar_ID    {$$.valor = $1.valor + " " + $2.valor;}
        |   _PRINT  Expressao     {$$.valor = $2.valor + " print #";}
        |   '+'     Expressao     {$$.valor = $2.valor;}
        |   '-'     Termo         {$$.valor = "0 " + $2.valor + " -";}  
        |   '('     Expressao ')' {$$.valor = $2.valor;}
        |                         {$$.valor = "";}
        ;

Termo :   Membro Conta_Complexa {$$.valor = $1.valor + $2.valor;}
      ;

Expressao :   Termo Conta_Simples {$$.valor = $1.valor + $2.valor;}   
          ;

Continuacao : Expressao ';' Continuacao {$$.valor = " " + $1.valor + $3.valor;}
            |                           {$$.valor = "";}
            ;

Entrada  :  Expressao ';' Continuacao {mostrar($1.valor + $3.valor);}
         ;  
%%

#include "lex.yy.c"

void mostrar(string valor){
    cout << valor;
}

int recuperarValor( int tk ) {  
  yylval.valor = yytext; 

  return tk;
}

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Proximo a: %s\n", yytext );
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}