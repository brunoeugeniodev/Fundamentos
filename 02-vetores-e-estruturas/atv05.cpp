#include<stdio.h>

int funcao(int vetor[10], int *p1, int *p2){
    int minimo, maximo;
    minimo = vetor[0];
    for(int i = 1; i< 10; i++){
        if(vetor[i] < minimo){
            minimo = vetor[i];
        }
    }
    maximo = vetor[0];
    for(int i = 1; i< 10; i++){
        if(vetor[i] > maximo){
            maximo = vetor[i];
        }
    }
    *p1 = minimo;
    *p2 = maximo;
    return 0;
}

int main () {

    int vetor[10], a, b;


    for(int i = 0; i< 10; i++){
        scanf("%d", &vetor[i]);
    }

    vetor[10] = funcao(vetor, &a, &b);

    printf("O minimo: %d\n", a);
    printf("O maximo: %d\n", b);

    return 0;
}


