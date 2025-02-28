#include <stdio.h>

int N;

int main(){
    scanf("%d",&N);
    puts(!(N%2024)&&N<=100000?"Yes":"No");
}