%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;

struct Atributos {
  string valor;

};

#define YYSTYPE Atributos

#define LABEL_IF ":then_"
#define LABEL_ENDIF ":end_if"

#define LABEL_RIF ";then_"
#define LABEL_RENDIF ";end_if"


int count_label = 0;
int recuperarValor(int tk);
void mostrar(string valor);
extern "C" int yylex();  
int yyparse();
void yyerror(const char *);

%}

%token _ID _FOR _IF _INT _FLOAT _MAIG _MEIG _IG _DIF _STRING _STRING2 _COMENTARIO _PRINT _LET _CONST _VAR _CONC _MAISMAIS

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
              |   '>' Termo Conta_Simples               {$$.valor = " " + $2.valor + $3.valor + " > ";}
              |   '<' Termo Conta_Simples               {$$.valor = " " + $2.valor + $3.valor + " < ";}
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

Casos_ID        : _ID           Atribuicao_ID       {$$.valor = $1.valor + $2.valor;}
                | _ID _CONC     Atribuicao_MIGUAL   {$$.valor = $1.valor + " " + $1.valor + "@ " + $3.valor;}
                | _ID _MAISMAIS '+'                 {$$.valor = $1.valor + " " + $1.valor + "@ 1 + = ^ " + $1.valor + "@";}
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

Jump    : Expressao Expressao  {count_label++; $$.valor = LABEL_ENDIF + to_string(count_label) + " # " + LABEL_RIF + to_string(count_label) + " " + $1.valor + " " +LABEL_RENDIF + to_string(count_label) + " " + $2.valor;}
        ;

Comando :  _IF  '(' Expressao ')' Jump {$$.valor = $3.valor + LABEL_IF + to_string(count_label) + " ? " + $5.valor;}
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

void ReplaceStringInPlace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

string printToken(int numToken, string tk){
        //cout << numToken << " " << tk << endl;
        return "";
}

void mostrar(string valor){
   int pc_nolabel = 0;
   bool palavra = false;
   bool palavra2 = false;
   bool label = false;
   map<string,int> instPC;
   string label_in_process = "";
   string tk = "";

   for(int pc = 0; valor[pc] != '.' ; pc++) {
     
        if(valor[pc] == ';'){
                label = true;
                tk += valor[pc];
                continue;
        }

        if(label){
                if(valor[pc] == ' '){
                        label = false;
                        instPC[label_in_process] = pc_nolabel;
                        
                        //tk = printToken(pc_nolabel, tk);
                        label_in_process = "";
                }else{
                        label_in_process += valor[pc];
                        tk += valor[pc];
                }

                continue;       
        }

        if(valor[pc] == '"'){
                if(!palavra){
                        palavra = true;
                }else{
                        palavra = false;
                        tk = printToken(pc_nolabel,tk);
                        pc_nolabel++;
                }
                continue;
        }

        if(palavra){
                tk += valor[pc];
                continue;
        }

        if(valor[pc] == ':'){
                if(!palavra2){
                        palavra2 = true;
                }

                continue;
        }
        
        
        if(palavra2){
                if(valor[pc] == ' '){
                        palavra2 = false;
                        tk = printToken(pc_nolabel,tk);
                        pc_nolabel++;
                } else{
                        tk += valor[pc];
                }
                continue;
        }
        
        if(valor[pc] == ' ') {
                tk = "";
                continue;
        }

        tk = valor[pc];
        tk = printToken(pc_nolabel, tk);
        pc_nolabel++;
   }

   map<string,int>::iterator it;
   for(it=instPC.begin(); it!=instPC.end(); ++it){
      //cout << it->first << "=>" << it->second << endl;
      ReplaceStringInPlace(valor, ":" + it->first, to_string(it->second)); 
      ReplaceStringInPlace(valor, ";" + it->first + " ", ""); 
   }
        
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