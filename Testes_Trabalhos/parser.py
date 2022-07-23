import json, sys, getopt



def parsear_input(arquivo, diretorio, encoding):
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
            test_file_input = "Teste"+line.split()[1].replace(":", "")+'.txt'
            test_file_out = "Teste"+line.split()[1].replace(":", "")+'-out.txt'

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
            with open(diretorio + test_file_input, 'a+') as f:
                f.write(line)
        
        elif isOutput:
            with open(diretorio + test_file_out, 'a+') as f:
                f.write(line)
    
    cenarios["testes"] = testes
    return json.dumps(cenarios, indent=4, ensure_ascii=False).encode(encoding)


def criar_cenarios_json(json_string, diretorio, encod):
    with open(diretorio + 'cenarios.json', 'w', encoding=encod) as outfile:
        outfile.write(json_string.decode(encod))

   
def main(argv):
    diretorio = ''
    encod = 'utf-8'

    try:
        opts, args = getopt.getopt(argv, "d:")
    except getopt.GetoptError:
        print("parser.py -d <tests_dataset_dir>")
    for opt, arg in opts:
        if opt is "-d":
            diretorio = arg + '/'

    json_string = parsear_input(diretorio+"/entradas.txt", diretorio, encod)
    criar_cenarios_json(json_string, diretorio, encod)

if __name__ == "__main__":
       main(sys.argv[1:])