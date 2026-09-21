#include <cstdio>
#include <ctime>
#include <cstring>

struct Data{
    int dia, mes, ano;
    int diaAtual, mesAtual, anoAtual;

    void setarDataAtual() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        diaAtual = ltm->tm_mday;
        mesAtual = ltm->tm_mon + 1;
        anoAtual = ltm->tm_year + 1900;
    }

    int calcularIdade(){
        int idade = anoAtual - ano;
        if(mesAtual - mes < 0){
            idade--;
        } else if(mesAtual - mes == 0){
            if(diaAtual - dia < 0) idade--;
        }
        return idade;
    }
};

struct Cliente{
    char nome[200];
    Data dataNasc;
    char sexo;

    void ler(){
        printf("Digite o nome: ");
        scanf("%s", nome);
        printf("Digite a data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &dataNasc.dia, &dataNasc.mes, &dataNasc.ano);
        printf("Digite o sexo (M/F): ");
        scanf(" %c", &sexo);
    }

    void imprimir(){
        printf("Dados do cliente:\n");
        printf("Nome: %s\n", nome);
        printf("Data de nascimento: %d/%d/%d\n", dataNasc.dia, dataNasc.mes, dataNasc.ano);
        printf("Sexo: %c\n", sexo);
        printf("Idade: %d\n\n", dataNasc.calcularIdade());
    }
};

int main(){
    Cliente clientes[50];
    int qtdClientes = 0;
    int opcao = 1;
    while(opcao != 3){
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Sair do programa\n");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            if(qtdClientes < 50){
                clientes[qtdClientes].ler();
                qtdClientes++;
            } else {
                printf("Limite de clientes atingido\n");
            }
            break;
        
        case 2:
            if(qtdClientes == 0){
                printf("Nenhum cliente cadastrado\n");
            } else {
                for(int i = 0; i < qtdClientes; i++){
                    clientes[i].imprimir();
                }
            }
            break;
        }
    }
    return 0;
}
