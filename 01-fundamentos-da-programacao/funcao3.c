#include<stdio.h>

void impressaoNumero(int n){
    int i;
    for(i=1; i<=n; i++){
        printf("%d",i);
    }
}

int main () {

    int a;
    scanf("%d",&a);
    impressaoNumero(a);
    return 0;
}
