/*Esse programa recebe uma entrada em NPR e retorna seus valores transformados, ou seja, o estado final da pilha*/
%{
    
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum TOKEN {tk_cte_int=256, tk_id, tk_let, tk_string};

//string yytext;
vector<string> pilha;
map<string, double> variaveis;

void push(double valor);
void push(string valor);
string pop_string();
double pop_double();

%}


WS	               [ \n\t]
DIGITO             [0-9]
LETRA              [A-Za-z_]
DOUBLE             {DIGITO}+("."{DIGITO}+)?
ID                 {LETRA}({LETRA}|{DIGITO})*

NUM	               {DIGITO}+
STRING             ([\".\"]|[\'.\'])

%%


{WS}  		{ }
{STRING}    { return tk_string; }
{NUM} 		{ return tk_cte_int; }
"let"		{ return tk_let; }

{ID}		{ return tk_id; }

.   		{ return yytext[0]; }

%%

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


int main() {
    int token = yylex();
    
    while( token != 0 ) {
        double op1, op2;
        
        switch( token ) {
            case tk_string:
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top == "^"){
                            string eq = pop_string();
                            push(yytext);
                            push(eq);
                            push(top);
                        }else{
                            push(top);
                            push(yytext);        
                        } 
                    }
                    break;
                }
            
            case tk_let:
                push("&");    
                break;
            
            case tk_cte_int:
                {
                    string top;
                    if(!pilha.empty()){
                        top = pop_string();
                        if(top == "^"){
                            string eq = pop_string();
                            push(yytext);
                            push(eq);
                            push(top);
                        }else{
                            push(top);
                            push(yytext);        
                        } 
                    }
                    break;
                }

            case tk_id:
            {
                string top;
                string lexema = yytext;
                if(!pilha.empty()){
                    top = pop_string();
                    if(top == "&"){
                        push( lexema + "&" );
                        push(yytext);
                        push("&");
                        break;
                    }else if(top == "^"){
                        pop_string();
                        push(yytext);
                        push("=");
                        push("^");
                        break;

                    }
                    push(top);
                }     
                push(yytext);
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
        
        token = yylex();
    }
    
    for( string x : pilha ){
        if(x == "\n") cout << x;
        else cout << x << " ";
    }
    
    cout << endl;
}