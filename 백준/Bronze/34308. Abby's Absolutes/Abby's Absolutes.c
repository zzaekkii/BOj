#include <stdio.h>

int N, K, T;

int main(){
    scanf("%d %d",&N,&K);
    
    while(K--){
        scanf("%d",&T);
        
        int a=1-T;
        int b=N-T;
        a*=a<0?-1:1;
        
        printf("%d ",b<a?N:1);
    }
}