#include <bits/stdc++.h>
using namespace std;

int N,M;
int dp[301][301];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=1;i<=N;i++)
    	for(int j=1;j<=M;j++)
    		cin >> dp[i][j];
    
    for(int i=1;i<=N;i++)
    	for(int j=1;j<=M;j++)
    		dp[i][j]=max(dp[i-1][j],dp[i][j-1])+dp[i][j];
    
    cout << dp[N][M];
}
