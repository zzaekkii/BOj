// 11404번 플로이드 - 골드4 / #최단경로 #플로이드-워셜
#include <bits/stdc++.h>
#define INF 1'000'000'000
using namespace std;

int N, M; // 도시 N개, 버스 M개.
int A, B, C; // A에서 B로 가는 비용 C. 
int dp[101][101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    // 일단 최대로 먹여주고. 
    for(int i=1;i<=N;i++)
    	for(int j=1;j<=N;j++)
    		dp[i][j]=INF;
    
    // 자신과의 거리는 0. 
    for(int i=1;i<=N;i++)
    	dp[i][i]=0;
    
    for(int i=0;i<M;i++){
    	cin >> A >> B >> C;
		dp[A][B]=min(dp[A][B],C); 
	}
	
	// 지름길 있나 탐색.
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	
	// 기록해뒀던 최단 경로 정보 출력. 
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			if(dp[i][j]==INF)cout << 0 << ' ';
			else cout << dp[i][j] << ' ';
		cout << '\n';
	}
}
