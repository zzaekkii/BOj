#include <stdio.h>

int N, M;

int main(){
    scanf("%d %d",&N,&M);
    
    if(N==M)printf("%d",2*N);
    else{
        if(N>M)N^=M^=N^=M;
        printf("%d",N*2+1);
    }
}