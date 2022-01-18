WS	               [ \n\t]
DIGITO             [0-9]
LETRA              [A-Za-z_]
NUM                {DIGITO}+("."{DIGITO}+)?
ID                 {LETRA}({LETRA}|{DIGITO})*

STRING_S           \'([^\'\n]|(\\\')|\'\')+\'
STRING_D           \"([^\"\n]|(\\\")|\"\")+\"

STRING             ({STRING_S}|{STRING_D})

%%


{WS}  		{ }
{NUM} 		{yylval.v = yytext;
             return tk_cte_int; }

"let"		{yylval.v = yytext; 
             return tk_let; }

{STRING}    {yylval.v = yytext; 
             return tk_string; }

{ID}		{yylval.v = yytext;
             return tk_id; }

.   		{yylval.v = yytext; 
             return yytext[0]; }

%%