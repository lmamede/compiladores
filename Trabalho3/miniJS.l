/* Lorena Mamede Botelho - DRE 117039095 */

DIGITO  [0-9]

LETRA   [A-Za-z]

WS      [ \s\t\n]*

INT     {DIGITO}+

FLOAT   {INT}("."{INT})?([Ee]("-"|"+")?{INT})?

LINHA   [^\n]*

FOR     [Ff][Oo][Rr]

IF      [Ii][Ff]

ELSE    [Ee][Ll][Ss][Ee]

IDENTIFICADOR ("$"|{LETRA}|_)+({LETRA}|{DIGITO})*

COMENTARIO1   "//"(.)*[\n]
COMENTARIO2   "/*"([^\*]|"*"[^/])*"*/"


STRING        ["]([^\"]|"\\"[\"]|[\"][\"])*["]
STRING1       [']([^\']|"\\'"|[\'][\'])*[']
STRING2       [`]({WS}|.)*[`]

%%

"\n"	  { linha++;}
{WS}      { }

{INT}     {return recuperarValor(_INT);}
{FLOAT}   {return recuperarValor(_FLOAT);}

{FOR}   {return recuperarValor(_FOR);}
{IF}    {return recuperarValor(_IF);}
{ELSE}  {return recuperarValor(_ELSE);}
"print" {return recuperarValor(_PRINT);}

"let"    {return recuperarValor(_LET);}
"const"  {return recuperarValor(_CONST);}
"var"    {return recuperarValor(_VAR);}

"{"/"}"     {return recuperarValor(_NEWOBJECT);}
"+"         {return recuperarValor('+');}
"+"/"+"     {return recuperarValor(_MAISMAIS);}
"+"/"="     {return recuperarValor(_CONC);}
">="        {return recuperarValor(_MAIG);}
"<="        {return recuperarValor(_MEIG);}
"=="        {return recuperarValor(_IG);}
"!="        {return recuperarValor(_DIF);}

{IDENTIFICADOR}     {return recuperarValor(_ID);}
{COMENTARIO2}       {return recuperarValor(_COMENTARIO);}
{COMENTARIO1}       {return recuperarValor(_COMENTARIO);}
{STRING}            {return recuperarValor(_STRING);}
{STRING1}           {return recuperarValor(_STRING);}
{STRING2}           {return recuperarValor(_STRING2);}

.       {return recuperarValor(yytext[0]);}

%%