#include<stdio.h>

int quadradoOuRetangulo(int b, int h){
    int resposta;
    if(b == h){
        resposta = 1;
    }else {
        resposta = 0;
    }
    return resposta;
}

int main () {
    int b, h, result;
    scanf("%d %d",&b, &h);
    result = quadradoOuRetangulo(b, h);
    printf("%d", result);

    return 0;
}
