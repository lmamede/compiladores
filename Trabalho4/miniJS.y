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
int linha = 0;
int coluna = 1;
int locais = 0;
string declaracao = "";

int recuperarValor(int tk);
void mostrar(string valor);
void erro(string valor);
extern "C" int yylex();  
int yyparse();
void yyerror(const char *);
void setVar(string var);
void checkVar(string var);
string enderecoPraFrente(string nome);
string enderecoResolvido(string nome);
string declarar(string var);
string declarar_arg(vector<string> args);
string acessar_campo(string nome_objeto, string campo);
string acessar_objeto(string nome_var);
string jumpComandos(string label_endereco_final, string label_endereco_corpo);
void ReplaceStringInPlace(std::string& subject, const std::string& search,const std::string& replace);
string asm_trim(string asm_command);
string declara_funcao(string nome, string parametros, string corpo);
string acessar_variavel(string nome_var);

#define YYSTYPE Atributos

#define LABEL_IF "then_"
#define LABEL_ENDIF "end_if"
#define LABEL_WHILE "while_"
#define LABEL_CORPO_WHILE "whilec_"
#define LABEL_ENDWHILE "end_while"
#define LABEL_FOR "for_"
#define LABEL_CORPO_FOR "forc_"
#define LABEL_ENDFOR "end_for"

#define GET_VALUE " @"
#define DECLARACAO " & "



map<string,int> var_declaradas;
map<string,map<string,int>> var_locais_declaradas;

string undefined = "undefined";
string retorno_default = undefined + GET_VALUE + " '&retorno'" + GET_VALUE + " ~";

string funcoes = "";
map<string, string> retornos;

bool escopo_local = false;

string funcao = "";
string id = "";

int args=0;
struct Atributos {
  string valor;
  string retorno = "";
  int parametros=0;
  vector<string> args_value;
  string getRetorno(){
        if(" " + valor == retorno){
                return "";
        } 
        else return retorno;
  }
};


%}

%token _ID _FOR _IF _ELSE _INT _FLOAT _MAIG _MEIG _IG _DIF _STRING _STRING2 _COMENTARIO _PRINT _LET _CONST _VAR _CONC _MAISMAIS _NEWOBJECT _WHILE _FUNCTION _BOOLEAN _RETURN _ASM _ARRAY

%start Entrada

%%

Atribuicao_Objeto2      : Objeto '=' Atribuicao_Objeto2  {$$.valor = $1.valor + $3.valor + " " + $1.valor + "[@] [=] ^ ";}
                        | Conta                          {$$.valor = $1.valor + "[=] ^ ";}
                        ;

Atribuicao_Objeto       : '=' Atribuicao_Objeto2    {$$.valor = $2.valor;}   
                        |                           {$$.valor = "[@] ";}
                        ;

Atribuicao_MIGUAL       : '=' Conta      {$$.valor = $2.valor + " + = ^ ";}
                        ;

AtribuicaoObj_MIGUAL    : '=' Conta      {$$.valor = $2.valor + " + [=] ^ ";}
                        ;

Atribuicao_ID2 : _ID '=' Atribuicao_ID2  {$$.valor = $1.valor + $3.valor + acessar_variavel($1.valor) + "= ^ ";}
               | Conta                   {$$.valor = $1.valor + "= ^ ";}
               ;

Atribuicao_ID   : '=' Atribuicao_ID2      {$$.valor = " " + $2.valor;}
                |                         {string space = " ";$$.valor = GET_VALUE + space;}
                ;

Conta_Simples :   '-' Termo Conta_Simples               {$$.valor = $2.valor + "- " + $3.valor;} 
              |   '+' Termo Conta_Simples               {$$.valor = $2.valor + "+ " + $3.valor;} 
              |   '>' Termo Conta_Simples               {$$.valor = $2.valor + $3.valor + ">";}
              |   '<' Termo Conta_Simples               {$$.valor = $2.valor + $3.valor + "<";}
              |   _IG Termo Conta_Simples               {$$.valor = $2.valor + $3.valor + "==";}
              |                                         {$$.valor = "";}
              ;

Conta_Complexa2   :   '^' Termo {$$.valor = " " + $2.valor + " ^";} 
                  |   '!' Termo {$$.valor = " fat #" + $2.valor;}
                  |             {$$.valor = "";}  
                  ;

Conta_Complexa    :   '*' Membro Conta_Complexa2 Conta_Complexa {$$.valor = $2.valor + $3.valor + "* " + $4.valor;}
                  |   '/' Termo                                 {$$.valor = $2.valor + "/ ";}
                  |   '%' Membro Conta_Complexa2 Conta_Complexa {$$.valor = $2.valor + $3.valor + "% " + $4.valor;}
                  |   Conta_Complexa2                           {$$.valor = $1.valor;}
                  |                                             {$$.valor = "";}
                  ;

Declaracao_Complexa     :  Declaracao_Simples                   {$$.valor = $1.valor; $$.args_value = $1.args_value;}
                        | ',' _ID '=' Conta Declaracao_Complexa {$$.valor = declarar($2.valor) + $2.valor + " " + $4.valor + "= ^ "+ $5.valor;}
                        |                                       {$$.valor = "";}
                        ;

Declaracao_Simples  : ',' _ID Declaracao_Simples  {$$.valor = declarar($2.valor) + $3.valor; $3.args_value.push_back($2.valor); $$.args_value = $3.args_value;}
                    |                             {$$.valor = ""; }
                    ;

Expressao_Declaracao  : _ID  '=' Conta Declaracao_Complexa    {$$.valor = declarar($1.valor) + $1.valor + " " + $3.valor + "= ^ " + $4.valor;}
                      | _ID  Declaracao_Complexa              {$$.valor = declarar($1.valor) + $2.valor; $2.args_value.push_back($1.valor); $$.args_value = $2.args_value;}
                      ;

Declaracao  : _LET   {declaracao = $1.valor;} Expressao_Declaracao    {$$.valor = $3.valor;}
            | _CONST {declaracao = $1.valor;} Expressao_Declaracao    {$$.valor = $3.valor;}
            | _VAR   {declaracao = $1.valor;} Expressao_Declaracao    {$$.valor = $3.valor;}
            |                                 {$$.valor = "";}
            ;

Membro_Simples  :   _STRING        {$$.valor = $1.valor + " ";}
                |   _INT           {$$.valor = $1.valor + " ";}
                |   _FLOAT         {$$.valor = $1.valor + " ";}
                |  _NEWOBJECT      {$$.valor = "{} ";}
                |  _ARRAY          {$$.valor = "[] ";}
                ;

Dimensoes       :   '[' Conta ']' Dimensoes {$$.valor ="[@] " + $2.valor + $2.getRetorno() + $4.valor;}
                |                           {$$.valor = "";}
                ;


Array   :       _ID  '[' Conta ']'                 {$$.valor = acessar_objeto($1.valor) + $3.valor;}  
        |       _ID  '[' Conta ']'  Dimensoes      {$$.valor = acessar_campo($1.valor, $3.valor) + $3.getRetorno() + $5.valor;}
        ;

Campo_Objeto    :  Array                             {$$.valor = $1.valor;}
                |  _ID                               {$$.valor = $1.valor;}
                ;

Continuacao_Objeto      :   Campo_Objeto  Continuacao_Objeto          {$$.valor = $1.valor + $2.valor;}
                        |   Array                                     {$$.valor = $1.valor;}
                        |   '.'  Campo_Objeto Continuacao_Objeto      {string space = " ";$$.valor = " [@]" + space + $2.valor + $3.valor;}
                        |                                             {$$.valor = "";}
                        ;

Objeto  :   _ID  '.' Continuacao_Objeto                        {$$.valor = acessar_campo($1.valor, $3.valor);}
        |   '(' _ID  ')' '.' Continuacao_Objeto                {$$.valor = acessar_campo($2.valor, $5.valor);}
        |   Array                                              {$$.valor = $1.valor + " ";}
        |   '(' Objeto ')' Dimensoes                           {$$.valor = $2.valor + $4.valor;}
        ;

Casos_ID        : _ID _CONC          Atribuicao_MIGUAL   {$$.valor = $1.valor + acessar_variavel($1.valor) + $3.valor;}
                | _ID _MAISMAIS      Conta_Simples       {$$.valor = $1.valor + GET_VALUE + $3.valor + " " + $1.valor + " " + acessar_variavel($1.valor) + "1 + = ^ ";}
                | _ID Funcao                             {$$.valor = $2.valor + acessar_variavel($1.valor) + "$ ";}
                | '(' _ID ')' Funcao                     {$$.valor = $4.valor + acessar_variavel($2.valor) + "$ ";}
                | _ID Atribuicao_ID                      {checkVar($1.valor);$$.valor = $1.valor + $2.valor; $$.retorno = $2.valor == " @ "? "" : acessar_variavel($1.valor);}
                ;

Casos_Objeto    : Objeto    Atribuicao_Objeto                       {$$.valor = $1.valor + $2.valor;}
                | Objeto   _CONC               AtribuicaoObj_MIGUAL {$$.valor = $1.valor + " " + acessar_objeto($1.valor) + $3.valor;}
                | Objeto   _MAISMAIS                                {$$.valor = $1.valor + acessar_variavel($1.valor) + "1 + [=] ^ " + acessar_variavel($1.valor);}
                | Objeto   Funcao                                   {$$.valor = $2.valor + $1.valor + "[@] $ ";}
                ;

Membro  :   Membro_Simples                        {$$.valor = $1.valor;}      
        |   Casos_Objeto                          {$$.valor = $1.valor;}
        |   Casos_ID                              {$$.valor = $1.valor; $$.retorno=$1.retorno;}
        |   Funcao                                {$$.valor = $1.valor;}
        |   '+'    Conta                          {$$.valor = $2.valor;}
        |   '-'    Termo                          {$$.valor = "0 " + $2.valor + " -";}  
        |   '('    Conta ')' Membro               {$$.valor = $2.valor;}
        |   _BOOLEAN                              {$$.valor = $1.valor;}
        ;

Termo :   Membro  Conta_Complexa  {$$.valor = $1.valor + $2.valor;$$.retorno=$1.retorno;}
      ;

Conta   :   Termo   Conta_Simples {$$.valor = $1.valor + $2.valor;$$.retorno=$1.retorno;}          
        ;

Argumentos  : Conta Argumentos    {$$.valor = $1.valor + $1.getRetorno() + $2.valor; $$.parametros = 1 + $2.parametros;}
            | ','  Argumentos     {$$.valor = $2.valor; $$.parametros = $2.parametros;}
            |                     {$$.valor = ""; $$.parametros = 0;}
            ;

Parametros : Expressao_Declaracao {$$.valor = declarar_arg($1.args_value);}
           |                      {$$.valor = "";}
           ;

Bloco_Funcao : '{' Continuacao Retorno '}' {$$.valor = $2.valor + $3.valor;}
             ;

Retorno : _RETURN Conta {$$.valor = $2.valor + acessar_variavel("'&retorno'") + "~ " + retorno_default;}
        |               {$$.valor = retorno_default;}
        ;

Funcao  : _FUNCTION _ID {funcao = $2.valor; escopo_local = true;} '(' Parametros ')' Bloco_Funcao {$$.valor = declara_funcao($2.valor, $5.valor, $7.valor);}
        | _PRINT  Argumentos                      {$$.valor = $2.valor + " print # ";}
        | '(' Argumentos ')'                      {$$.valor = $2.valor + to_string($2.parametros) + " ";}
        ;

Jump_IF    : Expressao ';' SENAO           {count_label++;$$.valor = $3.valor + jumpComandos(LABEL_ENDIF, LABEL_IF) + $1.valor + enderecoResolvido(LABEL_ENDIF) + " ";}
           | Bloco SENAO                   {count_label++;$$.valor = $2.valor + " " + jumpComandos(LABEL_ENDIF, LABEL_IF) + $1.valor + enderecoResolvido(LABEL_ENDIF) + " ";}
           ;

Jump_While      : Expressao ';'            {count_label++;$$.valor = jumpComandos(LABEL_ENDWHILE, LABEL_CORPO_WHILE) + $1.valor + " " + jumpComandos(LABEL_WHILE, LABEL_ENDWHILE);}
                | Bloco                    {count_label++;$$.valor = jumpComandos(LABEL_ENDWHILE, LABEL_CORPO_WHILE) + $1.valor + " " + jumpComandos(LABEL_WHILE, LABEL_ENDWHILE);}
                ;

Jump_For        : Expressao ';'            {count_label++;$$.valor = jumpComandos(LABEL_ENDFOR, LABEL_CORPO_FOR) + $1.valor;}
                | Bloco                    {count_label++;$$.valor = jumpComandos(LABEL_ENDFOR, LABEL_CORPO_FOR) + $1.valor;}
                | 
                ;       

SENAO   :  _ELSE Continuacao  {$$.valor = $2.valor;}
        |                     {$$.valor = "";}
        ;

Comando :  _IF   '(' Expressao ')'  Jump_IF                              {$$.valor = $3.valor + " " + enderecoPraFrente(LABEL_IF) + " ? " + $5.valor;}
        |  _FOR  '(' Expressao ';'  Expressao ';' Expressao ')' Jump_For {$$.valor = $3.valor + " " + enderecoResolvido(LABEL_FOR) + " " + $5.valor + " " + enderecoPraFrente(LABEL_CORPO_FOR) + " ? " + $9.valor + " " + $7.valor + " " + enderecoPraFrente(LABEL_FOR) + " # " + enderecoResolvido(LABEL_ENDFOR);}
        | _WHILE '(' Expressao ')'  Jump_While                           {$$.valor = enderecoResolvido(LABEL_WHILE) + " " + $3.valor + " " + enderecoPraFrente(LABEL_CORPO_WHILE) + " ? " + $5.valor;}
        ;

Retorno_Comandos : _RETURN Conta {$$.valor = $2.valor + acessar_variavel("'&retorno'") + "~ ";}
                 |               {$$.valor = "";}
                 ;

Bloco : '{' {escopo_local = true; funcao = "local" + to_string(locais++);} Continuacao Retorno_Comandos'}' {escopo_local=false;$$.valor = "<{ " +  $3.valor + $4.valor + "}> ";}
      | Retorno_Comandos                    {$$.valor = $1.valor;}
      ;

Expressao       :   Declaracao              {$$.valor = $1.valor;}
                |   Conta   Expressao       {$$.valor = $1.valor + $2.valor;}
                |   Bloco   Expressao       {$$.valor = $1.valor + $2.valor;}
                |   _ASM                    {$$.valor = asm_trim($1.valor);}
                ;

Continuacao  : Expressao ';' Continuacao         {$$.valor = $1.valor + $3.valor;}
             | Comando    Continuacao            {$$.valor = $1.valor + $2.valor;}
             | ';'   Continuacao                 {$$.valor = $2.valor;}         
             |                                   {$$.valor = "";}
             ;

Entrada :   Expressao ';' Continuacao         {mostrar($1.valor + $3.valor + "." + funcoes);}
        |   Comando       Continuacao         {mostrar($1.valor + $2.valor + "." + funcoes);}
        ;  
%%

#include "lex.yy.c"

string declara_funcao(string nome, string parametros, string corpo){
        count_label++; 
        escopo_local = false; 
        funcao = "";
        string label = enderecoPraFrente(nome);
        funcoes = funcoes + " " + enderecoResolvido(nome) + " " + parametros + corpo;
        setVar(nome);
        return nome + DECLARACAO + nome + " {} = '&funcao' " + label + " [=] ^ ";

}

string asm_trim(string asm_command){
        ReplaceStringInPlace(asm_command, "asm{", "");
        ReplaceStringInPlace(asm_command, "}", "");
        return asm_command + " ";
}

string acessar_objeto(string nome_var){
        return nome_var + "[@]" + " ";
}

string acessar_variavel(string nome_var){
        return nome_var + GET_VALUE + " ";
}

string acessar_campo(string nome_objeto, string campo){
        campo = " " + campo;
        return nome_objeto + GET_VALUE + campo + " ";
}


string declarar(string var){
        setVar(var);
        return var + DECLARACAO;
}

string declarar_arg(vector<string> args){
        int count = args.size() - 1;
        string result = "";
        string space = "";

        for(string var : args){
                result = var + DECLARACAO + var + " " + acessar_variavel("arguments") +  to_string(count) + " [@] = ^" + space + result; 
                space = " ";
                count--;
        }

        return result + " ";
}


string enderecoPraFrente(string nome){
        return ":" + nome + to_string(count_label);
}

string enderecoResolvido(string nome){
        return ";" + nome + to_string(count_label);
}

string jumpComandos(string label_endereco_final, string label_endereco_corpo){
        return enderecoPraFrente(label_endereco_final) + " # " + enderecoResolvido(label_endereco_corpo) + " ";
}

void setVar(string var){
        map<string,int>::iterator it;

        int linhaAtual = linha + 1;
        if(escopo_local){
                map<string, int> vars = var_locais_declaradas[funcao];
                
                for (it = vars.begin(); it != vars.end(); ++it){
                        if(var == it->first && declaracao != "var") erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) +".");
                }
                var_locais_declaradas[funcao][var] = linhaAtual;
        }else{
                for (it = var_declaradas.begin(); it != var_declaradas.end(); ++it){
                        if(var == it->first & !escopo_local && declaracao != "var") erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) + ".");
                }
                var_declaradas[var] = linhaAtual;
        }        

}

void checkVar(string var){
        map<string,int>::iterator it;
        if(escopo_local){
                map<string, int> vars = var_locais_declaradas[funcao];
                for (it = vars.begin(); it != vars.end(); ++it){
                        if(var == it->first) return;
                }
                //erro("a variável '" + var + "' não foi declarada no escopo local para " + funcao);     
        }else{
                for (it = var_declaradas.begin(); it != var_declaradas.end(); ++it){
                        if(var == it->first) return;
                }
                erro("a variável '" + var + "' não foi declarada.");
        }  
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

        if(valor[pc] == '"' || valor[pc] == '\''){
                palavra = !palavra;
        }

        if(label){
                if(valor[pc] == ' '){
                        label = false;
                        instPC[label_in_process] = pc_nolabel;
                        
                        label_in_process = "";
                        tk = printToken(pc_nolabel, tk);
                        pc_nolabel++;
                }else{
                        label_in_process += valor[pc];
                        tk += valor[pc];
                }

                continue;       
        }
        
        if(valor[pc] == ' ' && !palavra) {
                tk = printToken(pc_nolabel, tk);
                pc_nolabel++;
                continue;
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