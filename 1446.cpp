#include <bits/stdc++.h>
using namespace std;

int N,D;
int S,E,C;

vector<pair<int,int>> G[10001];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> D;
    
    for(int i=0;i<=D;i++)
    	dp[i]=i;
    
    while(N--){
    	cin >> S >> E >> C;
    	
    	if (E>D||(E-S)-C<0)
			continue;
			
		G[S].push_back({E,C});
	}
	
	for(int i=0;i<=D;i++) {
        if(i)dp[i]=min(dp[i],dp[i-1]+1);
        
        for(auto &shortcut: G[i]){
            int e=shortcut.first;
            int c=shortcut.second;
            if(dp[e]>dp[i]+c)
                dp[e]=dp[i]+c;
        }
    }
	
	cout << dp[D];
}
