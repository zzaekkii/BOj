#include <stdio.h>

int X, Y, ans;

int main(){
    scanf("%d %d",&X,&Y);
    
    int tmp=0;
    for(int i=0;i<X;i++)ans=ans*10+1;
    for(int i=0;i<Y;i++)tmp=tmp*10+1;
    
    printf("%d",ans+tmp);
}
