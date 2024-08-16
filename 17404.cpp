#include <bits/stdc++.h>
using namespace std;

int N;
int cost[1001][3];
int dp[1001][3];
int ans=0x7FFFFFFF;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<3;j++)
			cin >> cost[i][j];
	
	dp[0][0]=cost[0][0];
	dp[0][1]=cost[0][1];
	dp[0][2]=cost[0][2];
	
	// 첫 집이 0. 
	dp[1][0]=0x7FFFFFFF;
	dp[1][1]=dp[0][0]+cost[1][1];
	dp[1][2]=dp[0][0]+cost[1][2];
	
	for(int i=2;i<N;i++){
		dp[i][0]=min(dp[i-1][1],dp[i-1][2])+cost[i][0];
		dp[i][1]=min(dp[i-1][2],dp[i-1][0])+cost[i][1];
		dp[i][2]=min(dp[i-1][0],dp[i-1][1])+cost[i][2];
	}
	
	ans=min(ans,min(dp[N-1][1],dp[N-1][2]));
	
	// 첫 집이 1. 
	dp[1][0]=dp[0][1]+cost[1][0];
	dp[1][1]=0x7FFFFFFF;
	dp[1][2]=dp[0][1]+cost[1][2];
	
	for(int i=2;i<N;i++){
		dp[i][0]=min(dp[i-1][1],dp[i-1][2])+cost[i][0];
		dp[i][1]=min(dp[i-1][2],dp[i-1][0])+cost[i][1];
		dp[i][2]=min(dp[i-1][0],dp[i-1][1])+cost[i][2];
	}
	
	ans=min(ans,min(dp[N-1][0],dp[N-1][2]));
	
	// 첫 집이 2.
	dp[1][0]=dp[0][2]+cost[1][0];
	dp[1][1]=dp[0][2]+cost[1][1];
	dp[1][2]=0x7FFFFFFF;
	
	for(int i=2;i<N;i++){
		dp[i][0]=min(dp[i-1][1],dp[i-1][2])+cost[i][0];
		dp[i][1]=min(dp[i-1][2],dp[i-1][0])+cost[i][1];
		dp[i][2]=min(dp[i-1][0],dp[i-1][1])+cost[i][2];
	}
	
	ans=min(ans,min(dp[N-1][0],dp[N-1][1]));
	
	cout << ans;
}
