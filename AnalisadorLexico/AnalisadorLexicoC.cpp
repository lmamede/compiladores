#include <stdlib.h>
#include <stdio.h>

//Tokens a serem reconhecidos: <, >, <=, >=, ==, !=

#define GT 2
#define GE 3
#define LT 4
#define LE 5
#define EQ 6
#define NE 7

void erro(const char* msg){
    printf("Erro: %s \n", msg);
    exit(0);
}

int next_token(){
    int ch = getchar();

    if(ch == '<'){
        ch = getchar();
        if(ch == '='){
            return LE;
        }else{
            return LT;
        }
    }
    else if(ch == '>'){
        ch = getchar();
        if(ch == '='){
            return GE;
        }else{
            return GT;
        }
    }

    if(ch == '='){
        ch = getchar();
        if(ch == '='){
            return EQ;
        }else{
            erro("Operador inválido!");
        }
    }

    if(ch == '!'){
        ch = getchar();
        if(ch == '='){
            return NE;
        }else{
            erro("Operador inválido!");
        }
    }
    else{
        erro("Operador inválido!");
    }    

    return 0;
}

int main(){
    int token = next_token();

    printf("%d\n", token);
}