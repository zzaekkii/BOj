#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int T;
int dp[101];
ll N,ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    for(int i=1;i<=100;i++){
    	dp[i]=dp[i-1]+1;
    	if(i>=10)dp[i]=min(dp[i],dp[i-10]+1);
    	if(i>=25)dp[i]=min(dp[i],dp[i-25]+1);
	}
    
    while(T--){
    	cin >> N;
    	ans=0;
    	while(N){
    		ans+=dp[N%100];
    		N/=100;
		}
		cout << ans << '\n';
	}
}
