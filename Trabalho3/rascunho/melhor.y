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
  string e;
};

#define YYSTYPE Atributos

int yylex();
int yyparse();
void yyerror(const char *);

string erro;
void checkErro();

void F();
void Declaracao();
void Operacao();
void TipoAcesso();
void TipoAcessoExpressao();

%}

%token tk_cte_int tk_id tk_let tk_string
%start F

%%

TipoAcessoExpressao : '.' tk_id {cout << $2.v+"[@]" << " "; } OperacaoSobreEstruturas
                    | '[' tk_cte_int ']' {cout << "@ " + $2.v << " ";} OperacaoSobreEstruturas
                    |
                    ;

D : tk_id {erro = "Erro\: a variável " + $1.v + " não foi declarada.";}
  |
  ;

Expressao : tk_id {cout << $1.v + "@" << " ";} TipoAcessoExpressao Operacao
          | tk_cte_int {cout <<$1.v << " ";} Expressao Operacao
          | '{' '}' {cout << "{}" << " ";} Expressao 
          | '[' ']' {cout << "[]" << " ";} Expressao
          | tk_string {cout << $1.v << " ";} Operacao
          | ',' PosDeclaracao
          |
          ;

PosDeclaracao : tk_id '=' {cout << $1.v + "& " + $1.v << " ";} Expressao {cout << "= ^" << " ";}
              | tk_id ',' tk_id {cout << $1.v + "& " + $3.v + "&" << " ";} 
              ;

Multiplicacao : tk_id {cout << $1.v + "@" << " ";} TipoAcessoExpressao 
              | tk_cte_int {cout <<$1.v << " ";} 
              ;


OperacaoBasica : '*' Multiplicacao {cout << "*" << " ";}  Operacao 
               | '+' Expressao {cout << "+" << " ";}
               | '-' Expressao {cout << "-"  << " ";}
               | 
               ;

Operacao : OperacaoBasica
         | '=' Expressao {cout << "= ^"  << " ";}
         ;

OperacaoSobreEstruturas : OperacaoBasica
                        | '=' Expressao { cout << "[=] ^" << " "; }
                        ;

TipoAcesso : '.' tk_id {cout << "@ " + $2.v;} TipoAcesso OperacaoSobreEstruturas
           | '[' tk_cte_int ']' {cout << "@ " + $2.v << " ";} OperacaoSobreEstruturas
           | {cout << " ";}
           ;

F : tk_id {cout << $1.v;} TipoAcesso Operacao ';' {cout << endl;} F
  | tk_let PosDeclaracao ';' {cout << endl;} F 
  | {cout << "."; checkErro();}
  ;

%%

#include "lex.yy.c"

void checkErro(){
    if(!erro.empty()) {
        cout << erro << endl; 
        exit(1);
    }
}

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

