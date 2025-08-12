#include <bits/stdc++.h>
using namespace std;

int N,M;
char C;
int dp[2][1001];
int mx;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=1;i<=N;i++){
    	for(int j=1;j<=M;j++){
    		cin >> C;
    		if(C==48){
    			dp[i%2][j]=0;
				continue;
			}
    		dp[i%2][j]=min(dp[!(i%2)][j-1],min(dp[!(i%2)][j],dp[i%2][j-1]))+1;
    		mx=max(mx,dp[i%2][j]);
    	}
    }
	cout << mx*mx;
}
