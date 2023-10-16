#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll dp[100001]={0,2,2,4};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    
    if(N<4)cout << dp[N];
    else{
        for(int i=4;i<=N;i++)
            if(i%2)dp[i]=(dp[i-1]*2)%16769023;
            else dp[i]=dp[i-1];
        cout << dp[N];
    }
}
