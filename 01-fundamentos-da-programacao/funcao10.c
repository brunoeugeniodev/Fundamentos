#include<stdio.h>

int somaDosPares(int a, int b){
    int i, soma=0;
    for(i=a; i<=b; i++){
        if(i%2==0){
            soma = soma+i;
        }
    }
    return soma;
}

int main () {
    int a, b, result;
    scanf("%d %d", &a, &b);
    result = somaDosPares(a, b);
    printf("%d", result);
}
