#include<stdio.h>

void impressaoDeDivisores(int a){
    int i, ultimo;
    for(i=1; i<a; i++){
        if(a%i==0){
            ultimo = i;
        }
    }
    for(i=1; i<ultimo; i++){
        if(a%i==0){
            printf("%d, ",i);
        }
    }
    if(a>1){
        printf("%d e ",ultimo);
    }
    printf("%d.",a);
}

int main () {
    int a;
    scanf("%d", &a);
    impressaoDeDivisores(a);
}
