#include <bits/stdc++.h>
using namespace std;

int N;
int P[1001];
int dp[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=1;i<=N;i++)
    	cin >> P[i];
        
    for(int i=1;i<=N;i++){
    	dp[i]=P[i];
    	for(int j=i;j>0;j--)
    		dp[i]=min(dp[i-j]+P[j],dp[i]);
    }
    		
    cout << dp[N];
}
