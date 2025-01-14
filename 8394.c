#include <stdio.h>

int N;
int dp[10000001]={0,1,2};

int main(){
    scanf("%d",&N);
    
    for(int i=3;i<=N;i++)
        dp[i]=(dp[i-1]+dp[i-2])%10;
    
    printf("%d",dp[N]);
}
