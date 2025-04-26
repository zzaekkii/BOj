#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
typedef long long ll;

int N, K, G, X;
int arr[1000001];
ll sum, mx;

int main(){
    scanf("%d %d",&N,&K);
    
    for(int i=0;i<N;i++){
        scanf("%d %d",&G,&X);
        arr[X]=G;
    }
    
    K=2*K+1;
    for(int i=0;i<=1000000;i++){
        if(i>=K)sum-=arr[i-K];
        
        sum+=arr[i];
        mx=MAX(mx,sum);
    }
    
    printf("%lld",mx);
}