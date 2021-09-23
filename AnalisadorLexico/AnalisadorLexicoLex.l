%{
 #include <string>
 #include <stdio.h>

 using namespace std;

//equivale aos defines usados na versão em C
 enum TOKEN {ID = 256, NUM, FOR, MAIOR_IGUAL}; /*nao eh necessario definir codigo para todos, apenas o de inicio, 256 no caso*/
%}

/*Declarações*/
 //Substitui tudo aquilo q foi feito manualmente em C por regex,
 //essa parte equivale aos ifs de verificação 


 //[0-9] colchetes implica em classe de caracteres, sinais de + e - sao reservados
 //[A-Za-z] cada expressao tem implicitamente um OU
 //* implica em repetição daquela classe 0 ou mais vezes
 //+ implica em repetição daquela classe 1 ou mais vezes
 //{ } é usado para referenciar outra declaracao
 //. eh um caracter reservado, definido como qlqr caracter exceto \n
 //^vc usa para fazer o complemento, ou seja, a negacao de uma classe

DIGITO  [0-9]

 //inclusao do sublinhado como parte do alfabeto para ser usado na identificacao de identificador
LETRA   [A-Za-z_]

WS      [ \t\n]*

NUM     {DIGITO}+("."{DIGITO}+)?

LINHA   [^\n]*

IDENTIFICADOR {LETRA}+({LETRA}|{DIGITO})*

%%
 //Essa parte equivale as chamadas das funcoes criadas na versao manual em C, exemplo ehIdentificador, ehNumero 

{WS}    {  }
{NUM}   {return NUM;}

 /*equivale ao switch case que usamos anteriormente*/
"for"   {return FOR;}
"+"     {return '+';}
">="    {return MAIOR_IGUAL;}

{IDENTIFICADOR}    {return ID;}

.       {return yytext[0];} /*equivale ao default, retorna um caracter por vez*/

 /* yytext equivale a variavel lexema*/

%%

//exatamente o mesmo papel q a main do codigo anterior
//a expressao do while equivale a chamada de next_token do codigo anterior, 
//yylex retorna EOF quando nao ha entradas ou o codigo definido no enum (token)
//yytext guarda toda a entrada que foi identificada como algum padrao
int main(){
    int token = 0;

    
    while((token = yylex()) != EOF){
        printf("Token: %d %s\n", token, yytext);
    }
    
    return 0;
}