/* Lorena Mamede Botelho - DRE 117039095 */

DIGITO  [0-9]

LETRA   [A-Za-z]

WS      [ \s\t\n]*

INT     {DIGITO}+

FLOAT   {INT}("."{INT})?([Ee]("-"|"+")?{INT})?

LINHA   [^\n]*

FOR     [Ff][Oo][Rr]

IF      [Ii][Ff]

IDENTIFICADOR ("$"|{LETRA}|_)+({LETRA}|{DIGITO})*

COMENTARIO1   "//"(.)*[\n]
COMENTARIO2   "/*"([^\*]|"*"[^/])*"*/"


STRING        ["]([^\"]|"\\"[\"]|[\"][\"])*["]
STRING1       [']([^\']|"\\'"|[\'][\'])*[']
STRING2       [`]({WS}|.)*[`]

%%

{WS}      {  }
{INT}     {return _INT;}
{FLOAT}   {return _FLOAT;}

{FOR}   {return _FOR;}
{IF}    {return _IF;}
"print" {return _PRINT;}

"+"     {return '+';}
">="    {return _MAIG;}
"<="    {return _MEIG;}
"=="    {return _IG;}
"!="    {return _DIF;}

{IDENTIFICADOR}     {return _ID;}
{COMENTARIO2}       {return _COMENTARIO;}
{COMENTARIO1}       {return _COMENTARIO;}
{STRING}            {return _STRING;}
{STRING1}           {return _STRING;}
{STRING2}           {return _STRING2;}

.       {return yytext[0];}

%%