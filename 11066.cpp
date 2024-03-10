#include <bits/stdc++.h>
using namespace std;

int T,K,P;
int sum[501];
int dp[501][501];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--){
    	cin >> K;
    	for(int i=1;i<=K;i++){
    		cin >> P;
    		sum[i]=sum[i-1]+P;
    	}
    	
    	for(int i=1;i<K;i++)
    		for(int st=1;st+i<=K;st++){
    			int en=st+i;
    			dp[st][en]=0x7FFFFFFF;
    			for(int md=st;md<en;md++)
    				dp[st][en]=min(dp[st][en],dp[st][md]+dp[md+1][en]+sum[en]-sum[st-1]);
			}
		cout << dp[1][K] << '\n';    	
	}
}
