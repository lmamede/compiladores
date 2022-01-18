%{
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum { tk_int = 256, tk_char, tk_double, tk_id, tk_cte_int };

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

string lexema;
vector<string> pilha;
map<string, double> var;

void push( double valor ) {
  pilha.push_back( to_string( valor ) );
}
void push( string valor ) {
  pilha.push_back( valor );
}

string pop_string() {
  string temp = pilha.back();
  pilha.pop_back();
  return temp;
}

double pop_double() {
  double temp = stod( pilha.back() );
  pilha.pop_back();
  return temp;
}

int next_token() {
  static int look_ahead = ' ';
  
  while( look_ahead == ' ' || look_ahead == '\n' || look_ahead == '\r' || look_ahead == '\t' )
     look_ahead = getchar();
  
  if( isdigit( look_ahead ) ) {
    lexema = (char) look_ahead;
    
    look_ahead = getchar();
    return NUM;
  }
  
  if( isalpha( look_ahead ) ) {
    lexema = (char) look_ahead;
    
    look_ahead = getchar();
    return ID;
  }

  switch( look_ahead ) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '=':
    case '@':
      int temp = look_ahead;
      look_ahead = getchar();
      return temp;
  }
  
  return EOF;
}

int main() {
  int token = next_token();
  
  while( token != EOF ) {
    double op1, op2;
    
    switch( token ) {
      case NUM:
	push( lexema ); 
	break;

      case ID:
	push( lexema );
	break;
	
      case '@':
	push( var[pop_string()] );
	break;
	
      case '=':
	op2 = pop_double();
	var[pop_string()] = op2;
	break;
	
      case '+':
	op2 = pop_double();
	op1 = pop_double();
	
	push( op1 + op2 ); 
	break;

      case '-':
	op2 = pop_double();
	op1 = pop_double();
	
	push( op1 - op2 ); 
	break;

      case '/':
	op2 = pop_double();
	op1 = pop_double();
	
	push( op1 / op2 ); 
	break;

      case '*':
	op2 = pop_double();
	op1 = pop_double();
	
	push( op1 * op2 ); 
	break;
    }
    
    token = next_token();
  }
  
  for( string x : pilha )
    cout << x << " ";
  
  cout << endl;
}




void A() {
// Guardamos o lexema pois a função 'casa' altera o seu valor.
  string temp = lexema; 
  casa( ID );
  print( temp );
  casa( '=' );
  E();
  print( "=" );
}

void E() {
  T();
  E_linha();
}

void E_linha() {
  switch( token ) {
    case '+' : casa( '+' ); T(); print( "+"); E_linha(); break;
    case '-' : casa( '-' ); T(); print( "-"); E_linha(); break;
  }
}

void T() {
  F();
  T_linha();
}

void T_linha() {
  switch( token ) {
    case '*' : casa( '*' ); F(); print( "*"); T_linha(); break;
    case '/' : casa( '/' ); F(); print( "/"); T_linha(); break;
  }
}

void F() {
  switch( token ) {
    case ID : {
      string temp = lexema;
      casa( ID ); print( temp + "@" ); } 
      break;
    case NUM : {
      string temp = lexema;
      casa( NUM ); print( temp ); }
      break;
    case '(': 
      casa( '(' ); E(); casa ')'; break;
    default:
      erro( "Operando esperado, encontrado " + lexema );
  }
}


void casa( int esperado ) {
  if( token == esperado )
    token = next_token();
  else {
      cout << "Esperado " << nome_token( esperado ) 
	   << " , encontrado: " << nome_token( token ) << endl;
    exit( 1 );
  }
}