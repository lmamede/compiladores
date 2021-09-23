    /*Esse programa recebe a entrada via arquivo e retorna
    se a sintaxe está correta*/

    /*
    Produções:
    V -> T L ;
    T -> int | char | double
    L -> P id A R
    R -> , P id A R | ε
    A -> [cte_num] A | ε
    P -> * P | ε
    */

%{
#include <stdio.h>
#include <stdlib.h>    
#include <iostream>
#include <map>

using namespace std;

int token;

/*prototipo das funcoes para permitir declaração em qualquer ordem*/

void P();
void A();
void R();
void L();
void V();
void VS();
void T();
void avanca_entrada(int);


enum { tk_int = 256, tk_char, tk_double, tk_id, tk_cte_int };

/*Convertendo os tokens em palavras mais descritivas*/
map<int,string> nome_tokens = {
  { tk_int, "int" },
  { tk_char, "char" },
  { tk_double, "double" },
  { tk_id, "nome de identificador" },
  { tk_cte_int, "constante inteira" }
};

%}

WS	[ \n\t]
DIGITO	[0-9]
LETRA	[A-Za-z_]

NUM	{DIGITO}+
ID	{LETRA}({LETRA}|{DIGITO})*

%%

{WS}  		{ }
{NUM} 		{ return tk_cte_int; }
"char"		{ return tk_char; }
"int"		{ return tk_int; }
"double"	{ return tk_double; }

{ID}		{ return tk_id; }

.		{ return yytext[0]; }

%%

string nome_token( int token ) {
  if( nome_tokens.find( token ) != nome_tokens.end() )
    return nome_tokens[token];
  else {
    string r;
    
    r = token;
    return r;
  }
}


//P -> * P | ε
void P() {
  if( token == '*' ) {
    avanca_entrada( '*' );
    P();
  }
}

//A -> [cte_num] A | ε
void A() {
  if( token == '[' ) {
    avanca_entrada( '[' );
    avanca_entrada( tk_cte_int );
    avanca_entrada( ']' );
    A();
  }
}

//R -> , P id A R | ε
void R() {
  if( token == ',' ) {
    avanca_entrada( ',' );
    P();
    avanca_entrada( tk_id );
    A();
    R();
  }
}

//L -> P id A R
void L() {
  P();
  avanca_entrada( tk_id );
  A();
  R();
}

//T -> int | char | double
void T() {
  switch( token ) {
    case tk_int : avanca_entrada( tk_int ); break;
    case tk_char : avanca_entrada( tk_char ); break;
    case tk_double : avanca_entrada( tk_double ); break;
    
    default:
       cout << "Tipo esperado "  
	   << " , encontrado: " << nome_token( token ) << endl;
    exit( 1 );
  }
}

//V -> T L ;
void V() {
  T();  
  L(); 
  avanca_entrada( ';' );
}

void avanca_entrada( int esperado ) {
  if( token == esperado )
    token = yylex();
  else {
    cout << "Esperado " << nome_token( esperado ) 
	   << " , encontrado: " << nome_token( token ) << endl;
    exit( 1 );
  }
}

/*verificando se o próximo símbolo da entrada é o início de uma declaração de variável*/
void VS() {
  V();
  switch( token ) { 
    case tk_int:
    case tk_char:
    case tk_double:
      VS();
      break;
  }
}


int main() {
  token = yylex();
  VS();
  
  if( token == 0 )
    cout << "Sintaxe ok!" << endl;
  else
    cout << "Caracteres encontrados após o final do programa" << endl;
  return 0;
}

