#include <stdio.h>

int N,S,P,L;
int ans=1,cnt;

int main(){
    scanf("%d %d %d",&N,&S,&P);
    
    for(int i=0;i<N;i++){
        scanf("%d",&L);
        if(L>S)ans++;
        else if(L<S)break;
        cnt++;
    }
    if(cnt==P)puts("-1");
    else printf("%d",ans);
}
