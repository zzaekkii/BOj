#include <bits/stdc++.h>
using namespace std;
int N;
int A[1001];
int dp[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    	cin >> A[i];    
	fill(dp,dp+1001,1111);
	dp[0]=dp[1]=0;
	for(int i=1;i<N;i++)
		for(int j=1;j<=A[i];j++){
			if(i+j>N)break;
			dp[i+j]=min(dp[i+j],dp[i]+1);
		}
		
	if(dp[N]==1111)cout << -1;
	else cout << dp[N];
}
