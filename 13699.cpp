#include <bits/stdc++.h>
using namespace std;
int N;
long long dp[36]={1};

int main(){
	cin >> N;
	for(int i=1;i<=N;i++)
		for(int j=0;j<i;j++)
			dp[i]+=dp[j]*dp[i-j-1];
	cout << dp[N];
}
