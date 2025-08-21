#include <stdio.h>

int M, T;

int main(){
    scanf("%d",&M);
    
    int f=0;
    for(int i=0;i<3;i++){
        scanf("%d",&T);
        f+=T;
    }
    
    if(M<=240||M<=f)puts("high speed rail");
    else puts("flight");
}