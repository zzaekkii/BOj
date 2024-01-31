#include <bits/stdc++.h>
#define MOD 10'007
using namespace std;

int N;
int dp[1001][10];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<10;i++)
    	dp[1][i]=1;
    
    for(int i=2;i<=N;i++){
    	dp[i][0]=1;
    	for(int j=1;j<10;j++)
    		dp[i][j]=(dp[i][j-1]+dp[i-1][j])%MOD;
	}
    
    int ans=0;
    for(int i=0;i<10;i++)
    	ans+=dp[N][i]%MOD;
    
    cout << ans%MOD;
}
