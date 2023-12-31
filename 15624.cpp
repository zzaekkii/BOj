#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1000001]={0,1,1,2,3};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=5;i<=N;i++)
    	dp[i]=(dp[i-2]+dp[i-1])%1000000007;
    
    cout << dp[N];
}
