#include <cstdio>
#include <cstring>

struct Funcionario{
    char nome[200], cargo[200];
    double salarioBase, beneficios, descontos, salarioLiquido;

    void ler(){
        printf("Digite o nome do funcionario: \n");
        scanf("%s", nome);
        printf("Digite o cargo do funcionario: \n");
        scanf("%s", cargo);
        printf("Digite o valor do salario base: \n");
        scanf("%lf", &salarioBase);
        printf("Digite o valor de beneficios: \n");
        scanf("%lf", &beneficios);
        printf("Digite o valor dos descontos: \n");
        scanf("%lf", &descontos);
        salarioLiquido = salarioBase+beneficios-descontos;
    }

    void imprimir(){
        printf("Dados do funcionario:\n");
        printf("Nome: %s\n", nome);
        printf("Cargo: %s\n", cargo);
        printf("Salario Base      %.2lf\n", salarioBase);
        printf("Beneficios        %.2lf\n", beneficios);
        printf("Descontos         %.2lf\n", descontos);
        printf("Salario Liquido   %.2lf\n\n", salarioLiquido);
    }
};
int qtdFunc = 0;
struct Loja{
    Funcionario funcionarios[10];
    void cadastrar(){
        if(qtdFunc > 10){
            printf("Limite de funcionarios atingido\n");
            return;
        }
        funcionarios[qtdFunc].ler();
        qtdFunc++;
    }
    void imprimir(){
        if(qtdFunc == 0){
            printf("Nenhum funcionario foi cadastrado.\n");
            return;
        }
        for(int i=0; i<qtdFunc; i++){
            funcionarios[i].imprimir();
        }
    }
    void mediaSalarial(){
        if(qtdFunc == 0){
            printf("Nenhum funcionario foi cadastrado.\n");
            return;
        }
        double media=0;
        for(int i=0; i<qtdFunc; i++){
            media += funcionarios[i].salarioLiquido;
        }
        media = media/qtdFunc;
        printf("Media salarial: %.2lf\n\n", media);
    }
    void maiorSalario(){
        if(qtdFunc == 0){
            printf("Nenhum funcionario foi cadastrado.\n");
            return;
        }
        double maior = 0;
        int pos;
        for(int i=0; i<qtdFunc; i++){
            if(funcionarios[i].salarioLiquido > maior){
                maior = funcionarios[i].salarioLiquido;
                pos = i;
            }
        }
        printf("Funcionario com maior salario:\n");
        funcionarios[pos].imprimir();
    }
};
int main(){
    Loja l;
    int opcao;
    while(opcao!=5){
        printf("1 - Cadastrar funcionarios\n");
        printf("2 - Listar funcionarios\n");
        printf("3 - Calcular media salarial\n");
        printf("4 - Maior salario\n");
        printf("5 - Sair do programa\n");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            l.cadastrar();
            break;

        case 2:
            l.imprimir();
            break;

        case 3:
            l.mediaSalarial();
            break;

        case 4:
            l.maiorSalario();
            break;
        }
    }
    return 0;
}
