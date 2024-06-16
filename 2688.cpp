#include <bits/stdc++.h>
using namespace std;

int T,N;
long long dp[65][10];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	
	for(int i=0;i<10;i++)
		dp[1][i]=1;
	
	for(int i=2;i<65;i++)
		for(int j=0;j<10;j++)
			for(int k=j;k<10;k++)
				dp[i][j]+=dp[i-1][k];
	
	while(T--){
		cin >> N;
		long long ans=0;
		for(int i=0;i<10;i++)
			ans+=dp[N][i];
		cout << ans << '\n';
	}	
}
