#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N;
int dp[51]={1,1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);    
	cin >> N;
	
	for(int i=2;i<=N;i++)
		dp[i]=(1+dp[i-2]+dp[i-1])%MOD;
	
	cout << dp[N];
}
