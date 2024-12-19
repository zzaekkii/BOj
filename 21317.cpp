// 21317번 징검다리 건너기 - 실버1 / #DP 
#include <bits/stdc++.h>
using namespace std;

struct Energy{
	int S, B; // 작은 점프 필요 에너지, 큰 점프 필요 에너지.
};

int N, K; // 돌 N개, 매우큰 점프 필요 에너지 K. 
Energy E[21]; // 각 돌에서 필요한 점프 에너지.
int dp[21][2]; // 에너지량. 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
	
	// 작점 1, 큰점2(1개 스킵)
	for(int i=0;i<N-1;i++)
		cin >> E[i].S >> E[i].B;
	
	memset(dp,0x3f3f3f3f,sizeof(dp));
	
	// 매큰점3(2개 스킵)
	cin >> K;
	
	// 초기 세팅 (N이 작으면 어차피 안쓰여서 무시됨) 
	dp[0][0]=0;
	dp[1][0]=dp[0][0]+E[0].S;
	dp[2][0]=min(dp[0][0]+E[0].B,dp[1][0]+E[1].S);
	
	for(int i=3;i<N;i++){
		// 작점 혹은 큰점. 
		dp[i][0]=min(dp[i-1][0]+E[i-1].S,dp[i-2][0]+E[i-2].B);
		
		// 매큰점프 (이미 쓴 거에서 작점/큰점 혹은 매큰점) 
		dp[i][1]=min(dp[i-3][0]+K,min(dp[i-1][1]+E[i-1].S,dp[i-2][1]+E[i-2].B));
	}
	
	cout << min(dp[N-1][0],dp[N-1][1]);
}
