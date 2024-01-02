#include <bits/stdc++.h>
using namespace std;
int N;
long long dp[116]={0,1,1,1,2};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=5;i<=N;i++)
    	dp[i]=dp[i-1]+dp[i-3];
    
    cout << dp[N];
}
