#include <cstdio>
#include <set>

struct Conjunto{
    int cjt[20];
    int n;
    void criarConj(){
        n = 0;
        printf("Conjunto vazio criado!\n");
    }
    void ler(){
        printf("Quantos elementos voce deseja adicionar?\n");
        int qtd;
        scanf("%d", &qtd);
        if(qtd > 20){
            printf("Quantidade maxima = 20\n");
            qtd = 20;
        }
        for(int i=0; i<qtd; i++){
            scanf("%d", &cjt[i]);
            n++;
        }
    }
    void imprimir(){
        if(n==0) {
            printf("Conjunto vazio\n");
            return;
        }
        for(int i=0; i<n; i++){
            printf("%d ", cjt[i]);
        }
        printf("\n");
    }
};

struct Operacoes{
    Conjunto cjts[2];
    void uniao(){
        printf("Preencha os dados dos conjuntos:\n");
        printf("Conjunto 1:\n");
        cjts[0].criarConj();
        cjts[0].ler();
        printf("Conjunto 2:\n");
        cjts[1].criarConj();
        cjts[1].ler();

        printf("Uniao dos dois conjuntos:\n");
        std::set<int> cjtUniao;
        for(int i=0; i<cjts[0].n; i++){
            cjtUniao.insert(cjts[0].cjt[i]);
        }
        for(int i=0; i<cjts[1].n; i++){
            cjtUniao.insert(cjts[1].cjt[i]);
        }
        printf("{");
        for(auto i:cjtUniao){
            printf("%d ", i);
        }
        printf("}");
        printf("\n\n");
    }
    void intersecao(){
        printf("Preencha os dados dos conjuntos:\n");
        printf("Conjunto 1:\n");
        cjts[0].criarConj();
        cjts[0].ler();
        printf("Conjunto 2:\n");
        cjts[1].criarConj();
        cjts[1].ler();

        printf("Intersecao dos dois conjuntos:\n");
        printf("{");
        for(int i=0; i<cjts[0].n; i++){
            for(int j=0; j<cjts[1].n; j++){
                if(cjts[0].cjt[i] == cjts[1].cjt[j]){
                    printf("%d ", cjts[0].cjt[i]);
                }
            }
        }
        printf("}");
        printf("\n\n");
    }
};
int main(){
    Conjunto c;
    Operacoes o;
    int opcao=0;
    while(opcao != 6){
        printf("1 - Criar um conjunto vazio\n");
        printf("2 - Ler os dados de um conjunto\n");
        printf("3 - Fazer a uniao de 2 conjuntos\n");
        printf("4 - Fazer a intersecao de 2 conjuntos\n");
        printf("5 - Imprimir conjunto\n");
        printf("6 - Sair do programa\n");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            c.criarConj();
            break;
        
        case 2:
            c.ler();
            break;
        
        case 3:
            o.uniao();
            break;
            
        case 4:
            o.intersecao();
            break;

        case 5:
            c.imprimir();
            break;
        }
    }
    return 0;
}

