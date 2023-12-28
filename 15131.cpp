#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1000001]={0,0,1,7,4,8,14,11};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	if(N<=7)cout << dp[N];
	else{
		for(int i=8;i<=N;i++){
			dp[i]=max(dp[i-2]+dp[2],max(dp[i-3]+dp[3],max(dp[i-4]+dp[4],max(dp[i-5]+dp[5],max(dp[i-7]+dp[7],dp[i-6]+dp[6])))));
		}
		cout << dp[N];
	}
}
