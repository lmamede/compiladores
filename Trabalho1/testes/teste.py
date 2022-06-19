import subprocess
import json

ANSI = '\x1b['
VERMELHO = ANSI + "1;31;1m"
VERDE = ANSI + "1;32;1m"
ANSI_CLOSE = ANSI + '0m'

FALHA_TESTES = f":{VERMELHO} FALHOU, esperava"
SUCESSO_TESTES = f":{VERDE} PASSOU para"
PROGRAMA = "./saida"

def mostrar_falha(nome_teste, expected, output, input):
    falha = f"{nome_teste}{FALHA_TESTES}"
    print(falha, f"\"{expected}\", encontrou \"{output}\", input \"{input}\"{ANSI_CLOSE}")

def testar_token(output, expected_token, nome_teste, input):
    if output != expected_token:
        mostrar_falha(nome_teste, "token " + expected_token, output, input)

def testar_saida(output, expected, nome_teste, input):
    sucesso = f"{nome_teste}{SUCESSO_TESTES}"

    if output != expected:
        mostrar_falha(nome_teste, expected, output, input)
    else: 
        print(sucesso, f"input {input}{ANSI_CLOSE}")    

def testar_match(output, nome_teste, input):
    if len(output) == 0 or len(output) == 1:
        mostrar_falha(nome_teste, "algum match", output, input)
        return False
    return True

def testar_single_input(testes, nome_teste, token):
    for input in testes.keys():
        command = f"echo \"{input}\" | {PROGRAMA}"
        output = subprocess.check_output(command, shell=True).decode("utf-8"). rstrip("\n").split(" ",1)
        
        if not testar_match(output, nome_teste, input):
            continue
        
        check_t = output[0]
        check_o = output[1]

        expected = testes.get(input)
        testar_token(check_t, token, nome_teste, input)
        testar_saida(check_o, expected, nome_teste, input)
    print("\n")

   
def main():
    f = open('testes/cenarios.json')
    cenarios = json.load(f)

    for teste in cenarios["cenarios"]:
        testar_single_input(teste["casos"], teste["nome"], teste["token"])
    
main()