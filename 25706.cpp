#include <bits/stdc++.h>
using namespace std;

int N;
int board[200001];
int dp[200001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=1;i<=N;i++)
		cin >> board[i];
	
	dp[N]=1;
	
	for(int i=N-1;i>0;i--)
		if(i+board[i]+1>N)dp[i]=1;
		else dp[i]=dp[i+board[i]+1]+1;
	
	for(int i=1;i<=N;i++)
		cout << dp[i] << ' ';
}
