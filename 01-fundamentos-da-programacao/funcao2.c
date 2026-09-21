#include<stdio.h>

int oMaior(int a, int b){
    int maior;
    if(a>b){
        maior = a;
    }else{
        maior = b;
    }
}

int main () {

    int x, y, result;
    scanf("%d %d", &x, &y);
    result = oMaior(x, y);
    printf("%d",result);

    return 0;
}
