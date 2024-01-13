#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int T,N;
int dp[1000001]={0,1,2,4};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    for(int i=4;i<=1000000;i++)
		dp[i]=((dp[i-1]+dp[i-2])%MOD+dp[i-3])%MOD;
    
    cin >> T;
    
    while(T--){
    	cin >> N;
    	cout << dp[N] << '\n';
	}
}
