#include <bits/stdc++.h>
using namespace std;

int D,K;
long long dp[31];

void func(){
	for(int i=3;i<=D;i++)
		dp[i]=dp[i-2]+dp[i-1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> D >> K;
    
    for(int i=1;i<=100000;i++){
    	dp[1]=i;
    	for(int j=i;j<=100000;j++){
    		if(dp[D]==K){
    			cout << dp[1] << '\n' << dp[2];
    			return 0;
			}
			dp[2]=j;
			func();
		}
	}
}
