#include <stdio.h>
#define abs(x) ((x)<0?-(x):(x))

int N, K, T, D;
int ans;

int main(){
    scanf("%d %d %d",&N,&K,&T);
    
    while(N--){
        scanf("%d",&D);
        
        if(T<K)T+=abs(T-K);
        else if(T>K)T-=(T-K);
        T+=D;
        
        ans+=abs(T-K);
    }
    
    printf("%d",ans);
}