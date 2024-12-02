// 2169번 로봇 조종하기 - 골드2 / #DP
#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[1001][1001]; // 화성 지역 탐사가치.
int l_dp[1001][1001], r_dp[1001][1001];
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++)
    	for(int j=0;j<M;j++){
    		cin >> board[i][j];
    		dp[i][j]=l_dp[i][j]=r_dp[i][j]=MIN;
    	}
    
    dp[0][0]=l_dp[0][0]=r_dp[0][0]=board[0][0];
    // 첫째 줄은 오른쪽으로밖에 못감. 
    for(int i=1;i<M;i++)
    	dp[0][i]=l_dp[0][i]=r_dp[0][i]=dp[0][i-1]+board[0][i];
    
    // 내려온 애는 default.
	// 오른쪽 가보고, 왼쪽 가보고.
	// 최종 조합. 
    for(int i=1;i<N;i++){
    	// 오른쪽으로 탐사. 
    	for(int j=0;j<M;j++){
    		// 일단 위에서 내려온 친구 first. 
    		l_dp[i][j]=dp[i-1][j]+board[i][j];
    		
    		if(j>0)
    			l_dp[i][j]=max(l_dp[i][j],l_dp[i][j-1]+board[i][j]);
		}
		
		// 왼쪽으로 탐사. 
		for(int j=M-1;j>=0;j--){
			// 내려온 애 default.
			r_dp[i][j]=dp[i-1][j]+board[i][j]; 
			
			if(j<M-1)
				r_dp[i][j]=max(r_dp[i][j],r_dp[i][j+1]+board[i][j]);
		}
		
		// 최종 결정. 
		for(int j=0;j<M;j++)
			dp[i][j]=max(l_dp[i][j],r_dp[i][j]);
	}
    
    cout << dp[N-1][M-1];
}
