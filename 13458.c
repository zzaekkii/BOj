#include <stdio.h>

long long N,B,C;
long long A[1000001];

int main(){
    scanf("%lld",&N);
    
    for(int i=0;i<N;i++)
        scanf("%lld",&A[i]);
    
    scanf("%lld %lld",&B,&C);
    
    long long ans=N;
    
    for(int i=0;i<N;i++)
        if(A[i]-B>0)
            ans+=(A[i]-B+C-1)/C;
    
    printf("%lld",ans);
}
