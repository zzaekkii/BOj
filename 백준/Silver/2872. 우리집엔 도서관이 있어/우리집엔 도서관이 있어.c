#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

int N, B;
int mx, ans;

int main(){
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        scanf("%d",&B);
        
        if(B<mx)ans=max(ans,B);
        
        mx=max(mx,B);
    }
    
    printf("%d",ans);
}