#include <stdio.h>
int N,M,K;

int main(){
    scanf("%d%d%d",&N,&M,&K);
    printf("%d",(M>K?K:M)+((N-M)>(N-K)?(N-K):(N-M)));
}
