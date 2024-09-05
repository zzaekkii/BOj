#include <stdio.h>

long long a[31]={1,1};
int N;

long long Dfs(long long x){
    if(a[x]>0)return a[x];
    return a[x]=Dfs(x-1)+Dfs(x-2)*2;
}

int main(){
    scanf("%d",&N);
    
    Dfs(N);
    
    if(N%2)printf("%lld",(a[N]+a[(N-1)/2])/2);
    else printf("%lld",(a[N]+a[N/2]+2*a[(N-2)/2])/2);
}
