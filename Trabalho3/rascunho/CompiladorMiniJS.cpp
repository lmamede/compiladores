/*Esse programa recebe uma entrada em NPR e retorna seus valores transformados, ou seja, o estado final da pilha*/

#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum TOKEN {NUM=256, ID, LET, LET_A, STRING};

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

int ehString(int& look_ahead){
    lexema = (char) look_ahead;

    if(look_ahead == '\"'){
        look_ahead = getchar();
        while(look_ahead != '\"'){
            lexema += (char) look_ahead;
            look_ahead = getchar();
        }
        
        lexema += (char) look_ahead; 
        look_ahead = getchar();

        return 1;
    }


    if(look_ahead == '\''){
        look_ahead = getchar();
        int i = 0;
        while(look_ahead != '\''){
            lexema += (char) look_ahead;
            i++;
            look_ahead = getchar();
        }

        lexema += (char) look_ahead; 
        look_ahead = getchar();
        
        return 1;
    }

    return 0;
}

int ehNumero(int& look_ahead){
    if( isdigit( look_ahead ) ) {
        lexema = (char) look_ahead;
        look_ahead = getchar();

        return 1;
    }

    return 0;
}

int ehLet(int& look_ahead){
    if(look_ahead == 'l'){
        look_ahead = getchar();   
        if(look_ahead == 'e'){
            lexema += (char) look_ahead;    
            look_ahead = getchar();
            if(look_ahead == 't'){
                lexema += (char) look_ahead;
                look_ahead = getchar();
                if(look_ahead = ' '){
                    /*lexema = "";
                    look_ahead = getchar();
                    while(isalpha( look_ahead ) ) {
                        lexema += (char) look_ahead;    
                        look_ahead = getchar();   
                    }*/
                    lexema += (char) look_ahead;
                    return 1;
                }
            }
        }

    }

    return 0;

}
int ehEspacoBranco(int& look_ahead){
    return (look_ahead == ' ' || look_ahead == '\n' || look_ahead == '\r' || look_ahead == '\t') ;
}

int next_token(){
    static int look_ahead = ' ';


    while(ehEspacoBranco(look_ahead)){
        look_ahead = getchar();
    }

    if( ehNumero( look_ahead ) ) {
        return NUM;
    }

    if(ehString(look_ahead)){
        return STRING;
    }

    if( isalpha( look_ahead ) ) {
        lexema = (char) look_ahead;
        
        if(ehLet(look_ahead)){
            /*if(look_ahead == ';'){
                return LET;            
            }
            return LET_A;*/
            return LET;
        }

        look_ahead = getchar(); 
        while( isalpha( look_ahead ) ) {
            lexema += (char) look_ahead;    
            look_ahead = getchar();   
        }

        return ID;
    }

    int temp = look_ahead;
    switch( look_ahead ) {
        case '+':
            look_ahead = getchar();
            return temp;
        //case '-':
        //case '*':
        //case '/':
        case '[':
            look_ahead = getchar();
            return temp;
        case ']':
            look_ahead = getchar();
            return temp;
        case '{':
            look_ahead = getchar();
            return temp;
        case '}':
            look_ahead = getchar();
            return temp;
        case '.':
            look_ahead = getchar();
            return temp;
        case ',':
            look_ahead = getchar();
            return temp;
        case ';':
            look_ahead = getchar();
            return temp;
        case '=':
            {
                /*lexema = "";
                look_ahead = getchar();

                while(look_ahead == ' ' || look_ahead == '\t'){
                    look_ahead = getchar();
                }

                while(look_ahead != ';'){
                    lexema += (char) look_ahead;
                    look_ahead = getchar();
                }*/
                look_ahead = getchar();
                return temp;
            }
            
    }
  
    return EOF;    
}

int main() {
    int token = next_token();
    
    while( token != EOF ) {
        double op1, op2;
        

        //identifiquei sobre o que se trata a entrada e decido o que fazer com ela
        switch( token ) {
            case STRING:
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top == "^"){
                            string eq = pop_string();
                            push(lexema);
                            push(eq);
                            push(top);
                        }else{
                            push(top);
                            push(lexema);        
                        } 
                    }
                    break;
                }
            
            case LET:
                //push(lexema + "&");
                push("&");    
                break;
            
            case LET_A:
                push(lexema + "&");
                cout << "eh top" <<endl;
                push(lexema);    
                break;

            case NUM:
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top == "^"){
                            string eq = pop_string();
                            push(lexema);
                            push(eq);
                            push(top);
                        }else{
                            push(top);
                            push(lexema);        
                        } 
                    }
                    break;
                }

            case ID:
            {
                string top;
                if(!pilha.empty()){
                    top = pop_string();
                    if(top == "&"){
                        push( lexema + "&" );
                        push(lexema);
                        push("&");
                        break;
                    }else if(top == "^"){
                        pop_string();
                        push(lexema);
                        push("=");
                        push("^");
                        break;

                    }
                    push(top);
                }     
                push(lexema);
                break;
            }
                
            case '=':
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top != "&")
                            push(top);
                    }
                    //push(lexema);
                    push("=");
                    push("^");
                    break;
                }
            
            case '+':
                push("+"); 
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

            case ',': 
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top != "&")
                            push(top);
                        else{
                            pop_string();
                            push(top);
                        } 
                    }
                    break;
                }
            
            case '.': 
                {
                    string id = pop_string();
                    push(id + "@");
                    break;
                }
            
            

            case ';':
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top != "&")
                            push(top);
                        else{
                            pop_string();         
                        } 
                    }
                    push("\n");
                    break;
                }

                case '[':
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top == "^"){
                            string eq = pop_string();
                            push("[");
                            push(eq);
                            push(top);
                        }else{
                            push(top);        
                        } 
                    }
                    break;
                }

                case ']':
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top == "^"){
                            string eq = pop_string();
                            push("]");
                            push(eq);
                            push(top);
                        }else{
                            push(top);
                            push("]");        
                        } 
                    }
                    break;
                }

                case '{':
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top == "^"){
                            string eq = pop_string();
                            push("{");
                            push(eq);
                            push(top);
                        }else{
                            push(top);        
                        } 
                    }
                    break;
                }

                case '}':
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top == "^"){
                            string eq = pop_string();
                            push("}");
                            push(eq);
                            push(top);
                        }else{
                            push(top);
                            push("]");        
                        } 
                    }
                    break;
                }
            
        }
        
        token = next_token();
    }
    
    for( string x : pilha ){
        if(x == "\n") cout << x;
        else cout << x << " ";
    }
    
    cout << endl;
}