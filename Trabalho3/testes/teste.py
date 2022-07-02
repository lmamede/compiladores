import subprocess
import json

ANSI = '\x1b['
VERMELHO = ANSI + "1;31;1m"
VERDE = ANSI + "1;32;1m"
ANSI_CLOSE = ANSI + '0m'

FALHA_TESTES = f":{VERMELHO} FALHOU, \nesperava"
SUCESSO_TESTES = f":{VERDE} PASSOU para"
PROGRAMA = "./miniJS"

def mostrar_falha(nome_teste, expected, output, input):
    falha = f"{nome_teste}{FALHA_TESTES}"
    print(falha, f"\"{expected}\", \nencontrou \"{output}\", \ninput \"{input}\"{ANSI_CLOSE}\n")

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

def testar_single_input(testes, nome_teste):
    for input in testes.keys():
        command = f"echo \"{input}\" | {PROGRAMA}"
        output = subprocess.check_output(command, shell=True).decode("utf-8")
        
        if not testar_match(output, nome_teste, input):
            continue
        
        check_o = output

        expected = testes.get(input)
        testar_saida(check_o, expected, nome_teste, input)
    print("\n")

def testar_single_input(arquivo, expected_out, nome_teste):
    command = f"{PROGRAMA} < {arquivo}"
    output = subprocess.check_output(command, shell=True).decode("utf-8")
    
    if not testar_match(output, nome_teste, arquivo):
        return

    f = open(arquivo)
    input = f.readlines()

    f = open(expected_out)
    expected = f.readlines()

    testar_saida(output, expected[0], nome_teste, ' '.join(input))
    print("\n")

   
def main():
    f = open('testes/cenarios.json')
    cenarios = json.load(f)

    for teste in cenarios["testes"]:
        testar_single_input(teste["arquivo_input"], teste["arquivo_output"],teste["nome"])
        #testar_single_input(teste["casos"], teste["nome"])
    
main()