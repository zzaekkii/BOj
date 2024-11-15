// 1389번 케빈 베이컨의 6단계 법칙 - 실버1 / #플로이드-워셜
#include <bits/stdc++.h>
#define INF 1'000'000'000
using namespace std;

int N, M; // 유저 N명, 친구 관계 M줄.
int A, B; // A와 B는 친구. 

int dp[101][101]; // dp[X][Y] X와 Y 관계 거리. 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    // 알기 전엔 일단 아무튼 먼~관계. 
    for(int i=1;i<=N;i++)
    	for(int j=1;j<=N;j++)
    		dp[i][j]=INF;
    
    // 자기 자신은 잘 알고 있다. 
    for(int i=1;i<=N;i++)
    	dp[i][i]=0;
    
    for(int i=0;i<M;i++){
    	cin >> A >> B;
    	dp[A][B]=1;
    	dp[B][A]=1;
    }
    
    for(int k=1;k<=N;k++)
    	for(int i=1;i<=N;i++)
    		for(int j=1;j<=N;j++)
    			dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    
    int mn=INF, ans=0; // 작은 베이컨, 인싸. 
    for(int i=1;i<=N;i++){
    	int bacon=0;
    	
    	// 베이컨 수 합산. 
    	for(int j=1;j<=N;j++)
    		bacon+=dp[i][j];
    	
    	// 인싸 판별식. 
    	if(mn>bacon){
    		mn=bacon;
    		ans=i;
		}
	}
	
	cout << ans; 
}
