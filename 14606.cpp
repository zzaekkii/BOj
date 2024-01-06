#include <bits/stdc++.h>
using namespace std;
int N;
int dp[11]={0,0,1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=3;i<=N;i++)
    	dp[i]=i/2*(i-i/2)+dp[i/2]+dp[i-(i/2)];

    cout << dp[N];
}
