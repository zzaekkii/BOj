#include <bits/stdc++.h>
using namespace std;

int N,M,K;
long long dp[16][16];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    
    dp[1][1]=1;
    
    for(int i=1;i<=N;i++)
    	for(int j=1;j<=M;j++)
    		dp[i][j]+=dp[i-1][j]+dp[i][j-1];
    		
    int x=0,y=0;
    if(K){
    	if(K%M)y=K/M+1,x=K%M;
		else y=K/M,x=M;
	}
	if(!K)cout << dp[N][M];
	else cout << dp[y][x]*dp[N-y+1][M-x+1];
}
