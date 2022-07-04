import json

DIRETORIO = "./testes/testes3"

def parsear_input(arquivo):
    f = open(arquivo)
    lines = f.readlines()

    test_file_input = ""
    test_file_out = ""

    isInput = False
    isOutput = False

    cenarios = dict()

    testes = []

    for line in lines:
        if line.startswith("Test "):
            test_file_input = DIRETORIO+"/Teste"+line.split()[1].replace(":", "")+'.txt'
            test_file_out = DIRETORIO+"/Teste"+line.split()[1].replace(":", "")+'-out.txt'

            print(f"Criando arquivo ${test_file_input}\n")

            teste = {
                "nome": line.replace("\n", ""),
                "arquivo_input": test_file_input,
                "arquivo_output": test_file_out
            }

            testes.append(teste)
            
            isOutput = False
        
        elif line.startswith("--- Program output"):
            print("Finalizando input\n")
            isInput = False

        elif line.startswith("--- Input"):
            print("Iniciando input\n")
            isInput = True

        elif line.startswith("--- Expected output"):
            print("Iniciando output\n")
            isOutput = True
        
        elif isInput:
            print(f"Abrindo ${test_file_input} para Input de ${line}")
            with open(test_file_input, 'a+') as f:
                f.write(line)
        
        elif isOutput:
            with open(test_file_out, 'a+') as f:
                f.write(line)
    
    cenarios["testes"] = testes
    return json.dumps(cenarios, indent=4, ensure_ascii=False).encode('utf-8')


def criar_cenarios_json(json_string):
    with open(DIRETORIO + '/cenarios.json', 'w', encoding='utf-8') as outfile:
        outfile.write(json_string.decode('utf-8'))

   
def main():
    json_string = parsear_input(DIRETORIO+"/entradas.txt")
    criar_cenarios_json(json_string)
main()