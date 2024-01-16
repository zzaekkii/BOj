#include <bits/stdc++.h>
#define MAX 0x3f3f3f3f
using namespace std;

int N,K;
int Co[101];
int dp[100'001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> K;
	memset(dp,MAX,100001);
	dp[0]=0;
	
	for(int i=1;i<=N;i++)
		cin >> Co[i];
	
	sort(Co,Co+N);
	
	for(int i=1;i<=N;i++)
		for(int j=Co[i];j<=K;j++)
			dp[j]=min(dp[j],dp[j-Co[i]]+1);
			
	if(dp[K]==MAX) cout << -1;
	else cout << dp[K];
}
