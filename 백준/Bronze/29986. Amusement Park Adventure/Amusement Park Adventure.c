#include <stdio.h>

int N, H, T;
int ans;

int main(){
    scanf("%d %d",&N,&H);
    
    while(N--){
        scanf("%d",&T);
        if(T<=H)ans++;
    }
    
    printf("%d",ans);
}