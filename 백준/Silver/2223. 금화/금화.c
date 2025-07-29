#include <stdio.h>

int T, X, M, D, S;
int mn=0x3f3f3f3f;
int ans;

int main(){
    scanf("%d %d %d",&T,&X,&M);
    
    if(M){
        while(M--){
            scanf("%d %d",&D,&S);
            if(mn>((D-1)/S))
                mn=(D-1)/S;
        }
        
        if(mn==0)ans=0;
        else if(mn>T)ans=T*X;
        else{
            ans=mn*X;
            ans+=(T-mn)/2*X;
        }
    }
    else ans=T*X;
    
    printf("%d",ans);
}