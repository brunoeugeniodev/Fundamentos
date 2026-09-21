#include <stdio.h>

int retornoDoDelta(int x, int y, int z){
    int delta;
    delta = (b*b-(4*a*c));
    return delta;
}

int main () {
    int a, b, c, result;
    scanf("%d %d %d", &a, &b, &c);
    result = retornoDoDelta(a, b, c);
    printf("%d", result);

}
