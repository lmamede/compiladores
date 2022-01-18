/*Esse programa recebe uma entrada em NPR e retorna seus valores transformados, ou seja, o estado final da pilha*/
%{
    
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


struct Atributos {
  string v;
};

#define YYSTYPE Atributos

int yylex();
int yyparse();
void yyerror(const char *);


void F();
void Declaracao();
void Operacao();
void TipoAcesso();
void TipoAcessoExpressao();

%}

%token tk_cte_int tk_id tk_let tk_string
%start F

%%

TipoAcessoExpressao : '.' tk_id OperacaoSobreEstruturas {$0.v += $2.v + "[@] " + $3.v; }
                    | '[' tk_cte_int ']' OperacaoSobreEstruturas {$0.v = "@ " + $2.v + " " + $3.v;}
                    |
                    ;

D : tk_id {cout << "Erro\: a variável " + $1.v + " não foi declarada." << endl; exit(1);}
  |
  ;

Expressao : tk_id TipoAcessoExpressao Operacao {$0.v = $1.v + "@" + $2.v + $3.v;} 
          | tk_cte_int Operacao {$0 = $2;}
          | '{' '}' Expressao {$0.v = $1.v + $2.v + " " + $3.v;}
          | '[' ']' Expressao {$0.v = $1.v + $2.v + " " + $3.v;}
          | tk_string
          | ',' D Expressao {$0.v =  $3.v + " ";}
          |
          ;

PosDeclaracao : tk_id '=' Expressao {$0.v = $1.v + "& " + $1.v + " " + $2.v + "= ^ ";} 
              | tk_id ',' tk_id {$0.v = $1.v + "& " + $3.v + "& ";} 
              ;

OperacaoBasica : '+' Expressao {$0.v = $2.v + " + ";}
               | '-' Expressao {$0.v = $2.v + "- ";}
               |
               ;

Operacao : OperacaoBasica
         | '=' Expressao {$0.v = $2.v + " = ^";}
         | 
         ;

OperacaoSobreEstruturas : OperacaoBasica
                        | '=' Expressao { $0.v = $2.v + " [=] ^ "; }
                        ;

TipoAcesso : '.' tk_id TipoAcesso OperacaoSobreEstruturas {$0.v = "@ " + $2.v + " " + $3.v + $4.v;}
           | '[' tk_cte_int ']' OperacaoSobreEstruturas {$0.v = "@ " + $2.v + " " + $3.v;}
           | 
           ;

F : tk_id TipoAcesso Operacao ';' {cout << $1.v + $2.v << endl;} F
  | tk_let PosDeclaracao ';' {cout << $1.v << endl;} F 
  | {cout << ".";}
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
  cout << endl;
  return 0;
}

