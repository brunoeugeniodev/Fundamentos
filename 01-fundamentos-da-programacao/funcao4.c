#include<stdio.h>

void ePar(int a, int b, int c){
    if(a%2==0){
        printf("%d",a);
    }
    if(b%2==0){
        printf("%d",b);
    }
    if(c%2==0){
        printf("%d",c);
    }
}

int main() {

    int a, b, c;
    scanf("%d %d %d",&a, &b, &c);
    ePar(a, b, c);
    return 0;
}
