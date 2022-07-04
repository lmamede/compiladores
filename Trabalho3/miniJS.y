%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Atributos {
  string valor;

};

#define YYSTYPE Atributos

int recuperarValor(int tk);
void mostrar(string valor);
extern "C" int yylex();  
int yyparse();
void yyerror(const char *);

%}

%token _ID _FOR _IF _INT _FLOAT _MAIG _MEIG _IG _DIF _STRING _STRING2 _COMENTARIO _PRINT _LET _CONST _VAR _CONC

%start Entrada

%%

Argumentos  : Conta               {$$.valor = $1.valor;}
            | Conta ',' Conta     {$$.valor = $1.valor + " " + $3.valor;}
            |                     {$$.valor = "";}
            ;

Indice  : _INT {$$.valor = $1.valor;}
        ;

Atribuicao_Objeto       : '=' Conta    {$$.valor = " " + $2.valor + " [=] ^";}   
                        |              {$$.valor = "[@]";}
                        ;

Atribuicao_MIGUAL       : '=' Conta      {$$.valor = $2.valor + "+ = ^";}
                        ;

Atribuicao_ID2 : _ID '=' Atribuicao_ID2  {$$.valor = " " +$1.valor + $3.valor + " " + $1.valor + "@" + " = ^ ";}
               | Conta                   {$$.valor = " " + $1.valor + " = ^";}
               ;

Atribuicao_ID   : '=' Atribuicao_ID2      {$$.valor = $2.valor;}
                |                         {$$.valor = "@";}
                ;

Conta_Simples :   '-' Termo Conta_Simples               {$$.valor = " " + $2.valor + " -" + $3.valor;} 
              |   '+' Termo Conta_Simples               {$$.valor = " " + $2.valor + " +" + $3.valor;} 
              |   '+' '=' Termo Conta_Simples           {$$.valor = " " + $3.valor + " + = ^";}
              |   '+''+' Conta_Simples                  {$$.valor = " 1 + " + $3.valor;}
              |   '>' Termo Conta_Simples               {$$.valor = " " + $2.valor + " >" + $3.valor;}
              |   '<' Termo Conta_Simples               {$$.valor = " " + $2.valor + " <" + $3.valor;}
              |                                         {$$.valor = "";}
              ;

Conta_Complexa2   :   '^' Termo {$$.valor = " " + $2.valor + " ^";} 
                  |   '!' Termo {$$.valor = " fat #" + $2.valor;}
                  |             {$$.valor = "";}  
                  ;

Conta_Complexa    :   '*' Membro Conta_Complexa2 Conta_Complexa {$$.valor = " " + $2.valor + $3.valor + " *" + $4.valor;}
                  |   '/' Termo                                 {$$.valor = " " + $2.valor + " /";}
                  |   Conta_Complexa2                           {$$.valor = $1.valor;}
                  |                                             {$$.valor = "";}
                  ;

Funcao  : _ID '(' Argumentos ')'  {$$.valor = $3.valor + " " + $1.valor + " #";}
        | _PRINT  Argumentos      {$$.valor = $2.valor + " print #";}
        ;
        
Declaracao_Complexa     :  Declaracao_Simples                   {$$.valor = $1.valor;}
                        | ',' _ID '=' Conta Declaracao_Complexa {$$.valor = " " + $2.valor + "& " + $2.valor + " " + $4.valor + " = ^"+ $5.valor;}
                        |                                       {$$.valor = "";}
                        ;

Declaracao_Simples  : ',' _ID Declaracao_Simples  {$$.valor = " " + $2.valor + "&" + $3.valor;}
                    |                             {$$.valor = "";}
                    ;

Expressao_Declaracao  : _ID  '=' Conta Declaracao_Complexa    {$$.valor = $1.valor + "& " + $1.valor + " " + $3.valor + " = ^" + $4.valor;}
                      | _ID  Declaracao_Complexa              {$$.valor = $1.valor + "&" + $2.valor;}
                      ;

Declaracao  : _LET    Expressao_Declaracao    {$$.valor = $2.valor;}
            | _CONST  Expressao_Declaracao    {$$.valor = $2.valor;}
            | _VAR    Expressao_Declaracao    {$$.valor = $2.valor;}
            |                                 {$$.valor = "";}
            ;

Membro_Simples  :   _STRING    {$$.valor = $1.valor;}
                |   _INT       {$$.valor = $1.valor;}
                |   _FLOAT     {$$.valor = $1.valor;}
                |  '{' '}'     {$$.valor = "{}";}
                |  '[' ']'     {$$.valor = "[]";}
                ;

Objeto  :   _ID '.' _ID          {$$.valor = $1.valor + "@ " + $3.valor;}
        |   _ID '[' Indice ']'   {$$.valor = $1.valor + "@ " + $3.valor;}
        ;

Casos_ID        : _ID        Atribuicao_ID       {$$.valor = $1.valor + $2.valor;}
                | _ID _CONC  Atribuicao_MIGUAL   {$$.valor = $1.valor + " " + $1.valor + "@ " + $3.valor;}
                ;

Membro  :   Membro_Simples                        {$$.valor = $1.valor;}      
        |   Funcao                                {$$.valor = $1.valor;}
        |   Objeto Atribuicao_Objeto              {$$.valor = $1.valor + $2.valor;}
        |   Casos_ID                              {$$.valor = $1.valor;}
        |   '+'    Conta                          {$$.valor = $2.valor;}
        |   '-'    Termo                          {$$.valor = "0 " + $2.valor + " -";}  
        |   '('    Conta ')'                      {$$.valor = $2.valor;}
        |                                         {$$.valor = "";}
        ;

Termo :   Membro  Conta_Complexa  {$$.valor = $1.valor + $2.valor;}
      ;

Conta   :   Termo   Conta_Simples {$$.valor = $1.valor + $2.valor;}          
        ;

Comando :  _IF  Expressao {$$.valor = $1.valor;}
        |  _FOR
        ;

Expressao       :   Declaracao              {$$.valor = $1.valor;}
                |   Conta   Expressao       {$$.valor = $1.valor + $2.valor;}
                |   Comando                 {$$.valor = $1.valor;}
                ;

Continuacao : Expressao ';' Continuacao {$$.valor = " " + $1.valor + $3.valor;}
            |                           {$$.valor = "";}
            ;

Entrada  :  Expressao ';' Continuacao {mostrar($1.valor + $3.valor + " .");}
         ;  
%%

#include "lex.yy.c"

void mostrar(string valor){
    cout << valor;
}

int recuperarValor( int tk ) {  
  yylval.valor = yytext; 

  return tk;
}

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Proximo a: %s\n", yytext );
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}