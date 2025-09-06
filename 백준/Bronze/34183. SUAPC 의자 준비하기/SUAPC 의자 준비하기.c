#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

int N,M,A,B;

int main(){
    scanf("%d %d %d %d",&N,&M,&A,&B);
    
    int tmp=max(N*3-M,0);
    printf("%d",tmp?max(0,tmp*A+B):0);
}