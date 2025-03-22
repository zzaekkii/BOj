#include <stdio.h>
#include <math.h>

double D;

int main(){
    scanf("%lf",&D);
    D=2*sqrt(D/M_PI);
    printf("%.10lf",D);
}