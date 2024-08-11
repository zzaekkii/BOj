#include <bits/stdc++.h>
using namespace std;

int N,K;
int I,T;
int dp[10001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	
	while(K--){
		cin >> I >> T;
		for(int i=N;i>=T;i--)
			dp[i]=max(dp[i-T]+I,dp[i]);
	}
	
	cout << dp[N];
}
