#include <stdio.h>

int N, M, I, O;
int max;

int main(){
    scanf("%d %d",&N,&M);
    
    max=M;
    for(int i=0;i<N;i++){
        scanf("%d %d",&I,&O);
        M=M+I-O;
        if(M<0){max=0;break;}
        if(max<M)max=M;
    }
    printf("%d",max);
}