#include <bits/stdc++.h>
using namespace std;

int N, K, W, V;
int dp[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    while(N--){
    	cin >> W >> V;
    	for(int i=K;i>=W;i--){
    		dp[i]=max(dp[i-W]+V,dp[i]);
		}
	}
    cout << dp[K];
}
