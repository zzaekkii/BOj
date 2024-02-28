#include <bits/stdc++.h>
using namespace std;

int N;
int dp[250001];
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1){
        cin >> N;
        if(!N)break;
        for(int i=0;i<N;i++)
            cin >> dp[i];
        
	    for(int i=N-2;i>=0;i--)
	        dp[i]=max(dp[i],dp[i]+dp[i+1]);
    
        ans=dp[0];
	    for(int i=0;i<N;i++)ans=max(ans,dp[i]);
	    
        cout << ans << '\n';
    }
}
