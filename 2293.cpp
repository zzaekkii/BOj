#include <bits/stdc++.h>
using namespace std;

int N,K;
int dp[10'001]={1};
int Coin[101];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	
	for(int i=1;i<=N;i++)
		cin >> Coin[i];
	
	sort(Coin,Coin+N);
	
	for(int i=1;i<=N;i++)
		for(int j=Coin[i];j<=K;j++)
			dp[j]+=dp[j-Coin[i]];
	
	cout << dp[K];
}
