#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N,M;
int dp[1001][1001];

int main(){
	cin >> N >> M;
	for(int i=1;i<=N;i++)dp[i][1]=1;
	for(int i=1;i<=M;i++)dp[1][i]=1;
	for(int i=2;i<=N;i++)
		for(int j=2;j<=M;j++)
			dp[i][j]=((dp[i][j-1]+dp[i-1][j])%MOD+dp[i-1][j-1])%MOD;
		
	cout << dp[N][M];
}
