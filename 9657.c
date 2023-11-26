#include <stdio.h>
int N;
_Bool dp[1001]={0,1,0,1,1,1};
int main(){
    scanf("%d",&N);
    for(int i=6;i<=N;i++)
		if(!dp[i-1]||!dp[i-3]||!dp[i-4])dp[i]=1;
	puts(dp[N]?"SK":"CY");
}
