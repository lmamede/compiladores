#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, _PRINT};

extern "C" int yylex();  

void yyerror(const char* s);

void termo();
void operadores_prioritarios();
void expressao();
void operadores_menos_prioritarios();
void membro();
void casa( int );
int token;

#include "lex.yy.c"

int next_token() {
  return yylex();
}

void next_termo(int token_esperado, string operador){
  casa(token_esperado);
  cout << " ";
  termo();
  cout << " " << operador;
}

void operadores_menos_prioritarios(){
    switch(token){
      case '-':
        next_termo('-',"-");
        operadores_menos_prioritarios();
        break;
      case '+':
        next_termo('+',"+");
        operadores_menos_prioritarios();        
        break;
    }
}

void operadores_prioritarios2(){
    switch(token){
      case '^':
        next_termo('^',"^");
        break;
      case '!':
        casa('!');
        cout << " fat #";
        termo();
        break;
    }
}

void operadores_prioritarios(){
    switch(token){
      case '*':
        casa('*');
        cout << " ";
        membro();
        operadores_prioritarios2();
        cout << " " << "*";
        operadores_prioritarios();
        break;
      case '/':
        next_termo('/',"/");
        break;
      case '^':
        next_termo('^',"^");
        break;
      case '!':
        casa('!');
        cout << " fat #";
        termo();
        break;
    }
}

void primeiro_membro(int token_esperado){
  cout << yytext;
  casa(token_esperado);
}

void avaliar_depois_id(string id){
  if(token == '='){
    cout << id << " ";
    casa('=');
    expressao();
    cout << " =";
  }else if(token == '('){
    casa('(');
    expressao();
    if(token == ','){
      casa(',');
      cout << " ";
      expressao();
    } 
    casa(')');
    cout << " " << id << " #";
  }else if(token != '='){
    cout << id <<" @";
  }else{
    cout << id;
  }
}

void membro(){
  string tmp;
  switch(token){
    case _STRING:
      primeiro_membro(_STRING);
      break;

    case _INT:
      primeiro_membro(_INT); 
      break;

    case _FLOAT:
      primeiro_membro(_FLOAT);
      break;

    case _ID:
      tmp = yytext;
      casa(_ID);
      avaliar_depois_id(tmp);
      break;
    
    case _PRINT:
      casa(_PRINT);
      expressao();
      cout << " print #";
      break;

    case '+': 
      casa('+');
      expressao();
      break;
    case '-':
      cout << "0";
      operadores_menos_prioritarios();
      break;
  
    case '(':
      casa('(');
      expressao();
      casa(')');
      break;
  }
} 

void termo(){
  membro();
  operadores_prioritarios();
}

void expressao(){
  termo();      
  operadores_menos_prioritarios();
}

void VS() {
  expressao();
  casa(';');
  if(token != 0) cout << " ";
}

void casa( int esperado ) {
  if( token == esperado ){
    token = next_token();
  }
}

int main() {
  token = next_token();
  while(token != 0){
    VS();
  }

  return 0;
}