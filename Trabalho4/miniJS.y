%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

int count_label = 0;
int linha = 1;
int coluna = 1;

int recuperarValor(int tk);
void mostrar(string valor);
void erro(string valor);
extern "C" int yylex();  
int yyparse();
void yyerror(const char *);
void setVar(string var, int linha);
void checkVar(string var);
string enderecoPraFrente(string nome);
string enderecoResolvido(string nome);

map<string,int> var_declaradas;

string retorno_default = "undefined @ '&retorno' @ ~";

string funcoes = "";
map<string, string> retornos;

struct Atributos {
  string valor;
  string retorno = "";
  string getRetorno(){
        if(" " + valor == retorno){
                return "";
        } 
        else return retorno;
  }
};

#define YYSTYPE Atributos

#define LABEL_IF ":then_"
#define LABEL_ENDIF ":end_if"
#define LABEL_WHILE ":while_"
#define LABEL_CORPO_WHILE ":whilec_"
#define LABEL_ENDWHILE ":end_while"
#define LABEL_FOR ":for_"
#define LABEL_CORPO_FOR ":forc_"
#define LABEL_ENDFOR ":end_for"

#define LABEL_RIF ";then_"
#define LABEL_RENDIF ";end_if"
#define LABEL_RWHILE ";while_"
#define LABEL_RCORPO_WHILE ";whilec_"
#define LABEL_RENDWHILE ";end_while"
#define LABEL_RFOR ";for_"
#define LABEL_RCORPO_FOR ";forc_"
#define LABEL_RENDFOR ";end_for"

%}

%token _ID _FOR _IF _ELSE _INT _FLOAT _MAIG _MEIG _IG _DIF _STRING _STRING2 _COMENTARIO _PRINT _LET _CONST _VAR _CONC _MAISMAIS _NEWOBJECT _WHILE _FUNCTION _TRUE _FALSE _RETURN

%start Entrada

%%

Argumentos  : Conta               {$$.valor = $1.valor;}
            | Conta ',' Conta     {$$.valor = $1.valor + " " + $3.valor;}
            |                     {$$.valor = "";}
            ;

Atribuicao_Objeto2      : Objeto '=' Atribuicao_Objeto2  {$$.valor = " " +$1.valor + $3.valor + " " + $1.valor + "[@]" + " [=] ^";}
                        | Conta                          {$$.valor = " " + $1.valor + " [=] ^";}
                        ;

Atribuicao_Objeto       : '=' Atribuicao_Objeto2    {$$.valor = $2.valor;}   
                        |                           {$$.valor = "[@]";}
                        ;

Atribuicao_MIGUAL       : '=' Conta      {$$.valor = $2.valor + " + = ^";}
                        ;

AtribuicaoObj_MIGUAL    : '=' Conta      {$$.valor = $2.valor + " + [=] ^";}
                        ;

Atribuicao_ID2 : _ID '=' Atribuicao_ID2  {$$.valor = " " +$1.valor + $3.valor + " " + $1.valor + "@" + " = ^";}
               | Conta                   {$$.valor = " " + $1.valor + " = ^";}
               ;

Atribuicao_ID   : '=' Atribuicao_ID2      {$$.valor = $2.valor;}
                |                         {$$.valor = "@";}
                ;

Conta_Simples :   '-' Termo Conta_Simples               {$$.valor = " " + $2.valor + " -" + $3.valor;} 
              |   '+' Termo Conta_Simples               {$$.valor = " " + $2.valor + " +" + $3.valor;} 
              |   '>' Termo Conta_Simples               {$$.valor = " " + $2.valor + $3.valor + " >";}
              |   '<' Termo Conta_Simples               {$$.valor = " " + $2.valor + $3.valor + " <";}
              |   _IG Termo Conta_Simples               {$$.valor = " " + $2.valor + $3.valor + " ==";}
              |                                         {$$.valor = "";}
              ;

Conta_Complexa2   :   '^' Termo {$$.valor = " " + $2.valor + " ^";} 
                  |   '!' Termo {$$.valor = " fat #" + $2.valor;}
                  |             {$$.valor = "";}  
                  ;

Conta_Complexa    :   '*' Membro Conta_Complexa2 Conta_Complexa {$$.valor = " " + $2.valor + $3.valor + " *" + $4.valor;}
                  |   '/' Termo                                 {$$.valor = " " + $2.valor + " /";}
                  |   '%' Membro Conta_Complexa2 Conta_Complexa {$$.valor = " " + $2.valor + $3.valor + " *" + $4.valor;}
                  |   Conta_Complexa2                           {$$.valor = $1.valor;}
                  |                                             {$$.valor = "";}
                  ;

Parametros : Expressao_Declaracao {$$.valor = $1.valor;}
           |                      {$$.valor = "";}
           ;

Retorno : _RETURN Conta {$$.valor = $2.valor + "'&retorno'" + "@ ~";}
        |               {$$.valor = retorno_default;}
        ;

Funcao  : _FUNCTION _ID '(' Parametros ')' '{' Continuacao '}'  { string label = enderecoPraFrente($2.valor);
                                                                   funcoes = funcoes + enderecoResolvido($2.valor) + $4.valor + " " + $7.valor + " ";
                                                                   $$.valor = $2.valor + "& " + $2.valor + " {} = '&funcao' " + label + " [=] ^ ";}
        | _PRINT  Argumentos                                  {$$.valor = $2.valor + " print #";}
        | _ID '(' Argumentos ')'                              {$$.valor = $3.valor + " " + $1.valor + "@ $";}
        ;

Declaracao_Complexa     :  Declaracao_Simples                   {$$.valor = $1.valor;}
                        | ',' _ID '=' Conta Declaracao_Complexa {setVar($2.valor, linha);$$.valor = " " + $2.valor + "& " + $2.valor + " " + $4.valor + " = ^"+ $5.valor;}
                        |                                       {$$.valor = "";}
                        ;

Declaracao_Simples  : ',' _ID Declaracao_Simples  {setVar($2.valor, linha);$$.valor = " " + $2.valor + "&" + $3.valor;}
                    |                             {$$.valor = "";}
                    ;

Expressao_Declaracao  : _ID  '=' Conta Declaracao_Complexa    {setVar($1.valor, linha); $$.valor = $1.valor + "& " + $1.valor + " " + $3.valor + " = ^" + $4.valor;}
                      | _ID  Declaracao_Complexa              {setVar($1.valor, linha); $$.valor = $1.valor + "&" + $2.valor;}
                      ;

Declaracao  : _LET    Expressao_Declaracao    {$$.valor = $2.valor;}
            | _CONST  Expressao_Declaracao    {$$.valor = $2.valor;}
            | _VAR    Expressao_Declaracao    {$$.valor = $2.valor;}
            |                                 {$$.valor = "";}
            ;

Membro_Simples  :   _STRING        {$$.valor = $1.valor;}
                |   _INT           {$$.valor = $1.valor;}
                |   _FLOAT         {$$.valor = $1.valor;}
                |  _NEWOBJECT '}'  {$$.valor = "{}";}
                |  '[' ']'         {$$.valor = "[]";}
                ;

Dimensoes       :   '[' Conta ']' Dimensoes {$$.valor ="[@] " + $2.valor + $2.getRetorno() + $4.valor;}
                |                           {$$.valor = "";}
                ;

Objeto  :   _ID '.' _ID                  {$$.valor = $1.valor + "@ " + $3.valor;}
        |   _ID '.' _ID '[' Conta ']'    {$$.valor = $1.valor + "@ " + $3.valor + "[@] " + $5.valor;}
        |   _ID '[' Conta ']'  Dimensoes {$$.valor = $1.valor + "@ " + $3.valor + $3.getRetorno() + $5.valor;}
        ;

Casos_ID        : _ID           Atribuicao_ID       {checkVar($1.valor);$$.valor = $1.valor + $2.valor; $$.retorno = " " + $1.valor + "@";}
                | _ID _CONC     Atribuicao_MIGUAL   {$$.valor = $1.valor + " " + $1.valor + "@ " + $3.valor;}
                | _ID _MAISMAIS '+' Conta_Simples   {$$.valor = $1.valor + "@" + $4.valor + " " + $1.valor + " " + $1.valor + "@ 1 + = ^";}
                ;

Casos_Objeto    : Objeto           Atribuicao_Objeto    {$$.valor = $1.valor + $2.valor;}
                | Objeto _CONC     AtribuicaoObj_MIGUAL {$$.valor = $1.valor + " " + $1.valor + "[@] " + $3.valor;}
                | Objeto _MAISMAIS '+'                  {$$.valor = $1.valor + " " + $1.valor + "@ 1 + [=] ^ " + $1.valor + "@";}
                ;

Boolean : _TRUE  {$$.valor = $1.valor;}
        | _FALSE {$$.valor = $1.valor;}
        ;

Membro  :   Membro_Simples                        {$$.valor = $1.valor;}      
        |   Funcao                                {$$.valor = $1.valor;}
        |   Casos_Objeto                          {$$.valor = $1.valor;}
        |   Casos_ID                              {$$.valor = $1.valor;$$.retorno=$1.retorno;}
        |   '+'    Conta                          {$$.valor = $2.valor;}
        |   '-'    Termo                          {$$.valor = "0 " + $2.valor + " -";}  
        |   '('    Conta ')'                      {$$.valor = $2.valor;}
        |   Boolean                               {$$.valor = $1.valor;}
        |                                         {$$.valor = "";}
        ;

Termo :   Membro  Conta_Complexa  {$$.valor = $1.valor + $2.valor;$$.retorno=$1.retorno;}
      ;

Conta   :   Termo   Conta_Simples {$$.valor = $1.valor + $2.valor;$$.retorno=$1.retorno;}          
        ;

Jump_IF    : Expressao ';' SENAO            {count_label++; $$.valor = $3.valor + " " + LABEL_ENDIF + to_string(count_label) + " # " + LABEL_RIF + to_string(count_label) + " " + $1.valor + " " + LABEL_RENDIF + to_string(count_label);}
           | Bloco SENAO                     {count_label++; $$.valor = $2.valor + " " + LABEL_ENDIF + to_string(count_label) + " # " + LABEL_RIF + to_string(count_label) + $1.valor + " "+ LABEL_RENDIF + to_string(count_label);}
           ;

Jump_While      : Expressao ';'            {count_label++; $$.valor = LABEL_ENDWHILE + to_string(count_label) + " # " + LABEL_RCORPO_WHILE + to_string(count_label) + " " + $1.valor + " " + LABEL_WHILE + to_string(count_label) + " # " + LABEL_RENDWHILE + to_string(count_label);}
                | Bloco                    {count_label++; $$.valor = LABEL_ENDWHILE + to_string(count_label) + " # " + LABEL_RCORPO_WHILE + to_string(count_label) + $1.valor + " " + LABEL_WHILE + to_string(count_label) + " # " + LABEL_RENDWHILE + to_string(count_label);}
                ;

Jump_For        : Expressao ';'            {count_label++; $$.valor = LABEL_ENDFOR + to_string(count_label) + " # " + LABEL_RCORPO_FOR + to_string(count_label) + $1.valor;}
                | Bloco                    {count_label++; $$.valor = LABEL_ENDFOR + to_string(count_label) + " # " + LABEL_RCORPO_FOR + to_string(count_label) + $1.valor;}
                | 
                ;

SENAO   :  _ELSE Continuacao  {$$.valor = $2.valor;}
        |                     {$$.valor = "";}
        ;

Comando :  _IF   '(' Expressao ')'  Jump_IF                              {$$.valor = $3.valor + " " + LABEL_IF + to_string(count_label) + " ?" + $5.valor;}
        |  _FOR  '(' Expressao ';'  Expressao ';' Expressao ')' Jump_For {$$.valor = $3.valor + " " + LABEL_RFOR + to_string(count_label) + " " + $5.valor + " " + LABEL_CORPO_FOR + to_string(count_label) + " ? " + $9.valor + " " + $7.valor + " " + LABEL_FOR + to_string(count_label) + " # " + LABEL_RENDFOR + to_string(count_label);}
        | _WHILE '(' Expressao ')'  Jump_While                           {$$.valor = LABEL_RWHILE + to_string(count_label) + " " + $3.valor + " " + LABEL_CORPO_WHILE + to_string(count_label) + " ? " + $5.valor;}
        ;

Bloco : '{' Continuacao '}' {$$.valor = $2.valor;}
      ;

Expressao       :   Declaracao              {$$.valor = $1.valor;}
                |   Conta   Expressao       {$$.valor = $1.valor + $2.valor;}
                |   Bloco Expressao         {$$.valor = $1.valor + $2.valor;}
                ;

Continuacao  : Expressao ';' Continuacao         {$$.valor = " " + $1.valor + $3.valor;}
             | Comando       Continuacao         {$$.valor = " " + $1.valor + $2.valor;}
             | ';'   Continuacao                 {$$.valor = $2.valor;}         
             |                                   {$$.valor = "";}
             ;

Entrada :   Expressao ';' Continuacao         {mostrar($1.valor + $3.valor + " ." + funcoes);}
        |   Comando       Continuacao         {mostrar($1.valor + $2.valor + " ." + funcoes);}
        ;  
%%

#include "lex.yy.c"

void setVar(string var, int linha){
        map<string,int>::iterator it;
        for (it = var_declaradas.begin(); it != var_declaradas.end(); ++it){
                if(var == it->first) erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) +".");
        }
        var_declaradas[var] = linha;
}

void checkVar(string var){
        map<string,int>::iterator it;
        for (it = var_declaradas.begin(); it != var_declaradas.end(); ++it){
                if(var == it->first) return;
        }
        erro("a variável '" + var + "' não foi declarada.");
}

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

string enderecoPraFrente(string nome){
        return ":" + nome + to_string(count_label);
}

string enderecoResolvido(string nome){
        return ";" + nome + to_string(count_label);
}

void mostrar(string valor){
   int pc_nolabel = 0;
   bool palavra = false;
   bool palavra2 = false;
   bool palavra3 = false;
   bool label = false;
   map<string,int> instPC;
   string label_in_process = "";
   string tk = "";

   for(int pc = 0; pc != valor.size() ; pc++) {
     
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
                }
                continue;
        }

        if(palavra){
                tk += valor[pc];
                continue;
        }

        if(valor[pc] == '\''){
                if(!palavra3 && !palavra){
                        palavra3 = true;
                }else{
                        if(!palavra){
                                palavra3 = false;
                        }
                }
                continue;
        }

        

        if(valor[pc] == ':'){
                if(!palavra2){
                        palavra2 = true;
                        tk += valor[pc];
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
                tk = printToken(pc_nolabel, tk);
                pc_nolabel++;
                continue;
        }else{
                if(valor[pc] == '&' || valor[pc] == '@') {
                        tk = printToken(pc_nolabel, tk);
                        pc_nolabel++;
                        tk = valor[pc];
                        continue;
                }
        }

        tk += valor[pc];
   }

   map<string,int>::iterator it;
   for(it=instPC.begin(); it!=instPC.end(); ++it){
      //cout << it->first << "=>" << it->second << endl;
      ReplaceStringInPlace(valor, ":" + it->first, to_string(it->second)); 
      ReplaceStringInPlace(valor, ";" + it->first + " ", ""); 
   }
        
   cout << valor;

}

void erro( string msg ) {
  cout << "Erro: " << msg << endl;
  exit(0); //apenas para execucao local
  //exit(1); 
}


int recuperarValor( int tk ) {  
  yylval.valor = yytext; 

  return tk;
}

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Proximo a: %s\nCoord: %d-%d\n", yytext, linha, coluna);
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}