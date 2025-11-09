#include <stdio.h>

int M, S;
int ans=1;

int main(){
    scanf("%d:%d",&M,&S);
    S+=M*60;
    
    if(S==30)S=0;
    if((S%60)>=30)S-=30;
    
    ans+=S/600, S%=600;
    ans+=S/60, S%=60;
    ans+=S/30, S%=30;
    ans+=S/10, S%=10;
    
    printf("%d",ans);
}