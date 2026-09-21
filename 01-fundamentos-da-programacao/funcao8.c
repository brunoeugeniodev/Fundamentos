#include<stdio.h>

double jurosCobrados(double c, double m, double t){
    double juros;
    juros = c*m*t;
    return juros;
}

int main () {
    double c, m, t, result;
    scanf("%lf %lf %lf", &c, &m, &t);
    result = jurosCobrados(c, m, t);
    printf("%.2lf", result);
    return 0;
}
