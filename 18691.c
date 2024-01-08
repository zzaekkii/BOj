#include <stdio.h>
int T,G,C,E;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&G,&C,&E);
        int ans=E-C;
        if(G==2)ans*=3;
        else if(G==3)ans*=5;
        
        if(ans<=0)puts("0");
        else printf("%d\n",ans);
    }
}
