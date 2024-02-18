#include <bits/stdc++.h>
using namespace std;

int N, M, W, D;
int dp[12881];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    while(N--){
    	cin >> W >> D;
    	for(int i=M;i>=W;i--)
    		dp[i]=max(dp[i-W]+D,dp[i]);
	}
    cout << dp[M];
}
