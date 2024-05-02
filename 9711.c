#include <stdio.h>

int T,P,Q;

int main(){
    scanf("%d",&T);
    for(int j=1;j<=T;j++){
        unsigned int dp[10001]={0,1};
        scanf("%d%d",&P,&Q);
        for(int i=2;i<=P;i++)
            dp[i]=dp[i-2]%Q+dp[i-1]%Q;
        printf("Case #%d: %u\n",j,dp[P]%Q);
    }
}
