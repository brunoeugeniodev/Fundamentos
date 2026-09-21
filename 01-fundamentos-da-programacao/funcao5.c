#include<stdio.h>

int enesimo(int primeiroNum, int enesimoNum, int n){
    int Sn;
    Sn = (n*(primeiroNum + enesimoNum)/2);
    return Sn;
}

int main () {
    int a, b ,c, result;
    scanf("%d %d %d",&a, &b, &c);
    result = enesimo(a, b ,c);
    printf("%d", result);

    return 0;
}
