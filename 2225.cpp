#include <bits/stdc++.h>
#define MOD 1'000'000'000
using namespace std;

int N,K;
int dp[201][201];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    
    for(int i=0;i<201;i++){
    	dp[i][1]=i;
    	dp[0][i]=1;
    }
    
    for(int i=1;i<=N;i++)
    	for(int j=1;j<=K;j++)
    		dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
    
    cout << dp[N][K];
}
