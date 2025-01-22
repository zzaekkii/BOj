// 17484번 진우의 달 여행 (Small) - 실버3 / #DP 
#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[7][7];

int dp[7][7][3];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			cin >> board[i][j];
			
			for(int k=0;k<3;k++)
				dp[i][j][k]=board[i][j];
			
			if(j==0)dp[i][j][0]=600;
			if(j==M-1)dp[i][j][2]=600;
		}
	
	for(int i=1;i<N;i++)
		for(int j=0;j<M;j++){
			if(j!=0)dp[i][j][0]+=min(dp[i-1][j-1][1],dp[i-1][j-1][2]);
			dp[i][j][1]+=min(dp[i-1][j][0],dp[i-1][j][2]);
			if(j!=M-1)dp[i][j][2]+=min(dp[i-1][j+1][0],dp[i-1][j+1][1]);
		}
	
	int ans = 600;
	for(int i=0;i<M;i++)
		for(int j=0;j<3;j++)
			ans=min(ans,dp[N-1][i][j]);
	
	cout << ans;
}
