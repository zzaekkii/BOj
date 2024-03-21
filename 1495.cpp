#include <bits/stdc++.h>
using namespace std;

int N,S,M;
int Gap[51];
bool dp[51][1001];
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S >> M;
    
    for(int i=0;i<N;i++)
    	cin >> Gap[i];
    
    if((S-Gap[0])>=0)dp[0][S-Gap[0]]=1;
    if((S+Gap[0])<=M)dp[0][S+Gap[0]]=1;
    	
    for(int i=1;i<N;i++)
    	for(int j=0;j<=M;j++){
    		if((j-Gap[i])>=0&&dp[i-1][j])
    			dp[i][j-Gap[i]]=1;
    		if((j+Gap[i])<=M&&dp[i-1][j])
    			dp[i][j+Gap[i]]=1;
    	}
    
    for(ans=M;ans>=0;ans--)
    	if(dp[N-1][ans])break;
    cout << ans;
}
