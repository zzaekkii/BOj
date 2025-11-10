#include <stdio.h>

int N, S, C, A, R;
int ans;

int main(){
    scanf("%d",&N);
    
    while(N--){
        scanf("%d %d %d %d",&S,&C,&A,&R);
        ans+=(S>999)|(C>1599)|(A>1499)|(R>0&&R<31);
    }
    
    printf("%d",ans);
}