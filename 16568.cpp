#include <bits/stdc++.h>
using namespace std;

int N,A,B;
int dp[1'000'001];
int t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> A >> B;
    
    fill(dp,dp+N,N);
    dp[0]=0;
    
    for(int i=1;i<=N;i++){
    	dp[i]=dp[i-1]+1;
    	if(i-A>0)dp[i]=min(dp[i],dp[i-A-1]+1);
    	if(i-B>0)dp[i]=min(dp[i],dp[i-B-1]+1);
	}
    
    cout << dp[N];
}
