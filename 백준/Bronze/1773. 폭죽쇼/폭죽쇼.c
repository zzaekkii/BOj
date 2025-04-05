#include <stdio.h>

int N, C, T;
_Bool time[2000001];

int total;

int main(){
    scanf("%d %d",&N,&C);
    
    while(N--){
        scanf("%d",&T);
        for(int i=T;i<=C;i+=T)
            time[i]=1;
    }
    
    for(int i=0;i<=C;i++)
        if(time[i])total++;
    
    printf("%d",total);
}