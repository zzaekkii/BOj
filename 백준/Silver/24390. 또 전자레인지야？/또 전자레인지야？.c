#include <stdio.h>

int M, S;
int ans=1;

int main(){
    scanf("%d:%d",&M,&S);
    
    if(M==0&&S==30)S=0;
    if(S>=30)S-=30;
    
    ans+=M/10+M%10+S/10;
    
    printf("%d",ans);
}