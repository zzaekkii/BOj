#include <stdio.h>

int X, D;

int main(){
    scanf("%d %d", &X, &D);
    puts(X * 2 > D ? "take it" : "double it");
}