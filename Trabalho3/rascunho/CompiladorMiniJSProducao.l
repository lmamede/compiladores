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

int token;

void F();
void Declaracao();
void Operacao();
void TipoAcesso();
void TipoAcessoExpressao();

%}


WS	               [ \n\t]
DIGITO             [0-9]
LETRA              [A-Za-z_]
DOUBLE             {DIGITO}+("."{DIGITO}+)?
ID                 {LETRA}({LETRA}|{DIGITO})*

NUM	               {DIGITO}+


STRING             \'([^\'\n]|(\\\')|\'\')+\'

%%


{WS}  		{ }
{NUM} 		{ return tk_cte_int; }
"let"		{ return tk_let; }

{STRING}    { return tk_string; }
{ID}		{ return tk_id; }

.   		{ return yytext[0]; }

%%

void casa( int esperado ) {
  if( token == esperado ){
      token = yylex();
  }
}


void print( string st ) {
  cout << st << " ";
}

void Mapa(){

}

void Array(){

}

void Expressao(){
    string op1 = yytext;
    
    switch(token){
        case tk_id:
            TipoAcessoExpressao();
            //casa(tk_id); print(op1+"@");
            Operacao(); 
            break;
        case tk_cte_int:
            casa(tk_cte_int); print(op1);
            Operacao();
            break;
        case '{': 
            casa('{'); print("{"); Mapa(); casa('}'); print("}"); 
            break;
        case '[': 
            casa('['); print("["); Array(); casa(']');print("]");
            break;
        case tk_string:
            print(yytext);
            casa(tk_string); 
            break;  
        default:
            cout << "Erro: Atribuicao invalida! token: " << token << endl;
    }
}

void PosDeclaracao(){
    string id = yytext;
    casa(tk_id);
    print(id + "&");
    switch(token){        
        case '=': print(id); casa('='); Expressao(); print("= ^"); break;
        case ',': casa(','); string id2 = yytext; casa(tk_id); print(id2+"&"); break;
    }
}

void AcessaVetor(){   
    casa('['); 
    string index = yytext; 
    casa(tk_cte_int);
    print(index);
    casa(']');
}

void Operacao(){
    switch(token){
        case '+': casa('+'); Expressao(); print("+"); break;
        case '-': casa('-'); Expressao(); print("-"); break;
        case '=': casa('='); Expressao(); print("= ^"); break;
    }
}


void OperacaoSobreEstruturas(){
    switch(token){
        case '+': casa('+'); Expressao(); print("+"); break;
        case '-': casa('-'); Expressao(); print("-"); break;
        case '=': casa('='); Expressao(); print("[=] ^"); break;
    }
}

void TipoAcessoExpressao(){
    string id = yytext;
    casa(tk_id);

    switch(token){
        case '.': {
            print(id+"@"); 
            casa('.'); 
            string campo = yytext; 
            casa(tk_id);
            print(campo+"[@]") ;
            OperacaoSobreEstruturas();
            break;
        }
        case '[': print(id+"@"); AcessaVetor(); OperacaoSobreEstruturas();break;
        default: print(id+"@");
    } 

}

void TipoAcesso(){
    string id = yytext;
    casa(tk_id);

    switch(token){
        case '.': print(id+"@"); casa('.'); TipoAcesso(); OperacaoSobreEstruturas();break;
        case '[': print(id+"@"); AcessaVetor(); OperacaoSobreEstruturas();break;
        default: print(id);
    } 

}

void Declaracao(){
    switch(token)
    {
        case tk_id:{
            TipoAcesso();
            Operacao();
            break;
        }
            
        case tk_let:{
            casa(tk_let);
            PosDeclaracao();
            break;
        }
    }
}

void PontoVirgula(){
    if(token == ';') cout << endl;
}

void E(){
    Declaracao();
    PontoVirgula();
    //cout << "Depois Declaracao: " << yytext << endl;
}

int main() {
    token = yylex();
    
    while(token != 0) {
        
        //aqui
        E();
        
        token = yylex();
        //cout << "Depois E: " << yytext << endl;
    }
    
    for( string x : pilha ){
        if(x == "\n") cout << x;
        else cout << x << " ";
    }
    
    cout << endl;
}