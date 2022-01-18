%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

%}

DELIM              [\t\n ]
DIGITO             [0-9]
LETRA              [A-Za-z_]
DOUBLE             {DIGITO}+("."{DIGITO}+)?
IDENTIFICADOR      {LETRA}({LETRA}|{DIGITO})*

%%

{DELIM}    { }

             
{DOUBLE}    {return NUM; }

{IDENTIFICADOR}       { return CTE; }

.      { return yytext[0]; }

%%

int main() {
  token = yylex();
  VS();
  
  if( token == 0 )
    cout << "Sintaxe ok!" << endl;
  else
    cout << "Caracteres encontrados após o final do programa" << endl;
  return 0;
}

