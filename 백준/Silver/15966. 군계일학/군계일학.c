#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

int N;
int arr[100001];
int dp[1000001];

int main(){
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    
    int ans=0;
    for(int i=0;i<N;i++){
        dp[arr[i]]=max(dp[arr[i]],dp[arr[i]-1]+1);
        ans=max(ans,dp[arr[i]]);
    }
    
    printf("%d",ans);
}