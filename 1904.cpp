#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1000001]={0,1,2,3,5};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    if(N<5)cout << dp[N];
    else{
        for(int i=5;i<=N;i++)
            dp[i]=(dp[i-2]+dp[i-1])%15746;
        cout << dp[N];
    }
}
