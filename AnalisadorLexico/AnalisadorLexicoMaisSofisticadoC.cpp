#include <string>
#include <iostream>
#include <ctype.h> //define se um caracter um digito
#include <stdio.h>


//ID letra(digito|letra)
//NUM digito+(.digito+)? varios digitos pelo menos um(ponto varios digitos pelo menos, opcional)
//OPER ("+" | "-" | "*" | "/" | "(" | ")" )
//IF if 
//FOR for 

using namespace std;

string lexema; //guardamos quando a entrada bater com algum padrão da linguagem

//definicoes para mais de um caracter, quando somente um eh usado a tabela ascii que vai ateh 255
#define ID 257
#define NUM 258

void erro(string msg){
    cout << "Erro: " << msg << endl;
    exit(1);
}

void avanca_entrada(int& ch){ //delimita passagem por referencia
    lexema += ch;
    ch = getchar();
}

int ehIdentificador(int& ch){
    if(isalpha(ch ) || ch == '_'){ //'a' <= ch && ch <= 'z' || maiuscula
        avanca_entrada(ch);

        while(isalnum(ch) || ch == '_'){
            avanca_entrada(ch);
        }

        return 1;
    }

    return 0;
}

int ehNumero(int& ch){
    if(isdigit(ch)){ 
        avanca_entrada(ch);

        while(isdigit(ch)){
            avanca_entrada(ch);
        }

        if(ch == '.'){
            avanca_entrada(ch);

            if(!isdigit(ch)){
                erro("Um numero nao pode terminar em '.'!");
            }

            while(isdigit(ch)){
                avanca_entrada(ch);
            }
        }

        return 1;
    }

    return 0;
}

int ehOperador(int& ch){
    switch(ch){
        case '+': 
            avanca_entrada(ch);
            return '+';
        case '-':
            avanca_entrada(ch);
            return '-';
        case '*':
            avanca_entrada(ch);
            return '*';
        case '/':
            avanca_entrada(ch);
            return '/';
        case '(':
            avanca_entrada(ch);
            return '(';
        case ')':
            avanca_entrada(ch);
            return ')';
    }

    return 0;
}

int ehEspacoBranco(int& ch){
    return  (ch == ' ' || ch == '\t' || ch == '\n');
}

int next_token(){
    static int ch = ' ';
    lexema = "";

    while(ehEspacoBranco(ch)) ch = getchar();
    
    if(ehIdentificador(ch)) return ID;
    
    else if(ehNumero(ch)) return NUM;
    
    return ehOperador(ch);
}

int main(){
    while(next_token() != 0){
        cout << lexema << endl;
    }
}