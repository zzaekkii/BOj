#include <bits/stdc++.h>
#define MOD 10007
using namespace std;

int N,K;
int dp[1001][1001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	
	dp[0][0]=dp[1][0]=dp[1][1]=1;
	
	for(int i=2;i<=N;i++)
		for(int j=0;j<=i;j++)
			if(!j||j==i)dp[i][j]=1;
			else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
	
	cout << dp[N][K];
}
