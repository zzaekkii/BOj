// 2098번 - 외판원 순회 #DP #비트마스킹 
#include <bits/stdc++.h>
#define BIG 1'000'000'000
using namespace std;

int N; // 전체 도시 수. 

int mat[17][17];
int dp[17][1<<17]; // X -> Y로의 최소 비용.

// 전체 도시 수가 16이니까 2^17-1은? 삽가능.
int Tsp(int cur,int vis){
	// 다 돌아봤다?
	if(vis==(1<<N)-1)
		return !mat[cur][0]?BIG:mat[cur][0];
	
	// 이전에 봤었던 경우다? 
	if(dp[cur][vis]!=-1)return dp[cur][vis];
	
	dp[cur][vis]=BIG;
	
	for(int i=0;i<N;i++){
		// 경로에 이미 포함돼있거나, 길이 없다? 
		if(vis&(1<<i)||!mat[cur][i])continue;
		
		// 지금까지의 경로에 이 길도 추가하고 다녀보기.		
		// 그걸로 다녀봤을 때 지금보다 좋다? 그걸로 ㄱ~ 
		dp[cur][vis]=min(dp[cur][vis],Tsp(i,vis|(1<<i))+mat[cur][i]);
	}
	return dp[cur][vis]; 
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	for(int j=0;j<N;j++)
    		cin >> mat[i][j];
    
    memset(dp,-1,sizeof(dp));
	
    // 시작점은 어쨌든 포함되니 다 돌아볼 필요없다.
	cout << Tsp(0,1);	
}
