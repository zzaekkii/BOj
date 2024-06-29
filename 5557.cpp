#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[101];
long long dp[101][21];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=1;i<=N;i++)
		cin >> Arr[i];
	
	dp[1][Arr[1]]=1;
	
	for(int i=2;i<N;i++)
		for(int j=0;j<=20;j++)
			if(dp[i-1][j]){
				if(j+Arr[i]<=20)dp[i][j+Arr[i]]+=dp[i-1][j];
				if(j-Arr[i]>=0)dp[i][j-Arr[i]]+=dp[i-1][j];
			}
	
	cout << dp[N-1][Arr[N]];
}
