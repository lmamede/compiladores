#!/usr/bin/python3

import subprocess
import json
import sys, getopt

ANSI = '\x1b['
VERMELHO = ANSI + "1;31;1m"
VERDE = ANSI + "1;32;1m"
ANSI_CLOSE = ANSI + '0m'

FALHA_TESTES = f":{VERMELHO} FALHOU, \nesperava"
SUCESSO_TESTES = f":{VERDE} PASSOU para"
failed_count = 0
tests_count = 0

def mostrar_falha(nome_teste, expected, output, input):
    global failed_count
    falha = f"{nome_teste}{FALHA_TESTES}"
    failed_count += 1
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

def testar_single_input(testes, nome_teste, programa):
    for input in testes.keys():
        command = f"echo \"{input}\" | {programa}"
        output = subprocess.check_output(command, shell=True).decode("utf-8")
        
        if not testar_match(output, nome_teste, input):
            continue
        
        check_o = output

        expected = testes.get(input)
        testar_saida(check_o, expected, nome_teste, input)
    print("\n")

def testar_single_input(arquivo, expected_out, nome_teste, programa):
    command = f"{programa} < {arquivo}"
    output = subprocess.check_output(command, shell=True).decode("utf-8")
    
    if not testar_match(output, nome_teste, arquivo):
        return

    f = open(arquivo)
    input = f.readlines()

    f = open(expected_out)
    expected = f.readlines()

    testar_saida(output, expected[0], nome_teste, ' '.join(input))
    print("\n")

def show_failed_testes():
    print("==========================================================")
    print("#####     RESULTADO: ", failed_count, "/", tests_count, " testes falharam      ######\n") 

def main(argv):
    global tests_count
    test_dataset_json = ''
    dir = ''
    programa = ''
    test_index=0
    solo_test = False;

    try:
        opts, args = getopt.getopt(argv,"d:p:t:")
    except getopt.GetoptError:
        print('test.py -d <test_datasets_directory> -p <program_path> -t <test_index>')
        sys.exit(2)
    for opt, arg in opts:
        if opt in ("-d"):
            test_dataset_json = arg + "/cenarios.json"
            dir = arg + "/"
        elif opt in ("-p"):
            programa = arg
        elif opt in ("-t"):
            test_index = arg
            solo_test = True;

    f = open(test_dataset_json)
    cenarios = json.load(f)

    for teste in cenarios["testes"]:
        tests_count+=1
        if(solo_test):
            if(str(test_index) not in teste["arquivo_input"]): continue
        testar_single_input(dir + teste["arquivo_input"], dir + teste["arquivo_output"],teste["nome"], programa)
    
    show_failed_testes()
    
if __name__ == "__main__":
   main(sys.argv[1:])