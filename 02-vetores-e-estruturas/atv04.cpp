#include<stdio.h>
#define PI 3.14

double area(double a){
    a = (4*PI)*(a*a);
    return a;
}
double volume (double b){
    b = ((4/3)*PI)*((b*b)*b);
    return b;
}

int main (){

    double a, b, *p1, *p2;
    p1 = &a;
    p2 = &b;

    scanf("%lf %lf", &a, &b);

    *p1 = area(*p1);
    *p2 = volume(*p2);

    printf("%.2lf %.2lf\n", *p1, *p2);
    printf("%d %d", p1, p2);


    return 0;
}


