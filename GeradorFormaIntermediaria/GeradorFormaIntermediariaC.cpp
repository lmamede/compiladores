/*Esse programa recebe uma entrada em NPR e retorna seus valores transformados, ou seja, o estado final da pilha*/

#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum TOKEN {NUM=256, ID};

string lexema;
vector<string> pilha;
map<string, double> variaveis;

void print();
void Max2();


typedef void (*Funcao)();

map<string,Funcao> funcao = {
  { "print", &print },
  { "max", &Max2 }
};

void push(double valor){
    pilha.push_back(to_string(valor));
}

void push(string valor){
    pilha.push_back(valor);
}

string pop_string(){
    string temp = pilha.back(); //resgata o valor q esta no topo da pilha antes de dar o pop
    pilha.pop_back();//apaga o valor que esta no topo da pilha
    return temp;
}


double pop_double(){
    double temp = stod(pilha.back()); //converte em double
    pilha.pop_back();//apaga o valor que esta no topo da pilha
    return temp;
}

void print() {
  cout << pop_double() << " ";
}

void Max2() {
  double b = pop_double();
  double a = pop_double();
  
  push( a > b ? a : b );
}



int next_token(){
    static int look_ahead = ' ';


    while( look_ahead == ' ' || look_ahead == '\n' || look_ahead == '\r' || look_ahead == '\t' ){
        look_ahead = getchar();
    }

    if( isdigit( look_ahead ) ) {
        lexema = (char) look_ahead;
        
        look_ahead = getchar();
        return NUM;
    }

    if( isalpha( look_ahead ) ) {
        lexema = (char) look_ahead;

        look_ahead = getchar();

         while( isalpha( look_ahead ) ) {
            lexema += (char) look_ahead;    
            look_ahead = getchar();   
        }

        return ID;
    }

    switch( look_ahead ) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '=':
        case '@':
        case '#':
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
        

        //identifiquei sobre o que se trata a entrada e decido o que fazer com ela
        switch( token ) {
            case NUM:
                push( lexema ); 
                break;

            case ID:
                push( lexema );
                break;
            
            //se for arroba, se trata de uma variavel, entao empilho o valor da variavel que vou resgatar da tabela
            case '@':
                push( variaveis[pop_string()] );
                break;
            
            //atribuicao, logo pego o valor e salvo na tabela, lembrando q a pilha esta como = valor variavel
            case '=':
                op2 = pop_double();
                variaveis[pop_string()] = op2;//aqui o pop tira o nome da variavel da pilha
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

            case '#': {
                string temp = pop_string();
                Funcao f = funcao[temp];
            
                if( f == nullptr ) {
                    cout << "Funcao não definida: " << temp << endl;
                    exit( 1 );
                }
            
                f();
            }
        }
        
        token = next_token();
    }
    
    for( string x : pilha )
        cout << x << " ";
    
    cout << endl;
}