#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))

int N, M;

int main(){
    scanf("%d %d",&N,&M);
    
    if(N!=M){
        int tmp=min(N,M)-1;
        printf("%d",tmp*tmp);
    }
    else{
        N--;
        printf("%d",N*N-2*N+2);
    }
}