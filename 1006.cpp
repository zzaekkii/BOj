#include <bits/stdc++.h>
#define BLOCK 100'000'000
using namespace std;

int T,N,W;
int en[2][10001];
int dp[10001][3]; // 상태: 00, 10, 01

void as(){
	for(int i=2;i<=N;i++){
		int top=en[1][i]+en[1][i-1]<=W?1:2; // 앞뒤 췍. 
		int bot=en[0][i]+en[0][i-1]<=W?1:2; // 앞뒤 췍. 
		int all=en[1][i]+en[0][i]<=W?1:2; // 위아래 췍.
		
		dp[i][0]=min(min(dp[i-1][0]+all,dp[i-2][0]+top+bot),min(dp[i-1][1]+bot+1,dp[i-1][2]+top+1));
		dp[i][1]=min(dp[i-1][2]+top,dp[i-1][0]+1); // 빈 곳에서 1개 or 아래 채운거 + 위. 
		dp[i][2]=min(dp[i-1][1]+bot,dp[i-1][0]+1); // 빈 곳 1개 or 위 채운거 + 아래. 
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	
	while(T--){
		cin >> N >> W;
		int ans=2*N;
		
		for(int i=0;i<2;i++)
			for(int j=1;j<=N;j++)
				cin >> en[i][j];
		
		if(N==1)ans=en[0][1]+en[1][1]<=W?1:2;
		else{
			memset(dp,0,sizeof(dp));
			int top=en[1][1],bot=en[0][1];
			
			// 노 서클 (default).
			dp[1][0]=en[0][1]+en[1][1]<=W?1:2;
			dp[1][1]=dp[1][2]=1; // 한 칸 남은 건 한 개.
			as();
			ans=min(ans,dp[N][0]);
			
			if(en[0][1]+en[0][N]<=W){ // (문제 상 1~8) 아래 라인 서클.
				dp[1][0]=2; // 서클 고려, 잇지 않기. 
				dp[1][1]=dp[1][2]=1;
				en[0][1]=BLOCK;
				as(); 
				ans=min(ans,dp[N][1]);
				en[0][1]=bot;
			}			
			
			if(en[1][1]+en[1][N]<=W){ // (문제 상 9~16) 위 라인 서클.
				dp[1][0]=2;
				dp[1][1]=dp[1][2]=1;
				en[1][1]=BLOCK;
				as();
				ans=min(ans,dp[N][2]);
				en[1][1]=top;
			}
			
			if(en[0][1]+en[0][N]<=W&&en[1][1]+en[1][N]<=W){ // 위 아래 모두 서클.
				dp[1][0]=2;
				dp[1][1]=dp[1][2]=1;
				en[0][1]=en[1][1]=BLOCK;
				as();
				ans=min(ans,dp[N-1][0]);
				en[0][1]=bot,en[1][1]=top;
			}
		}
		
		cout << ans << '\n';
	}
}
