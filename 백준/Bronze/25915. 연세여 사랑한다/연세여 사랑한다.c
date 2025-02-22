#include <stdio.h>

char C;

int main(){
    scanf("%c",&C);
    printf("%d",((73-C)^((73-C)>>31))-((73-C)>>31)+84);
}