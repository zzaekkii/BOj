#include <stdio.h>
int N;

int main(){
    scanf("%d",&N);
    N%=8;
    printf("%d",!N||N>5?(10-N)%8:N);
}
