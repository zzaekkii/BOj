#include <stdio.h>

int X, Y, Z;
int U, V, W;

int main() {
    scanf("%d %d %d %d %d %d", &X, &Y, &Z, &U, &V, &W);
    
    int total = 0;
    total += ((U + 99) / 100) * X;
    total += ((V + 49) / 50) * Y;
    total += ((W + 19) / 20) * Z;
    
    printf("%d", total);
}