#include <bits/stdc++.h>
using namespace std;
int T, W;
int plum[1001];
int dp[1001][31][3];

int func(int t, int w, int l){
    if(t>T||w>W)return 0;
    if(dp[t][w][l]!=-1)return dp[t][w][l];
    dp[t][w][l]=(plum[t]==l?1:0);
    dp[t][w][l]+=max(func(t+1,w,l),func(t+1,w+1,3-l));
    return dp[t][w][l];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T >> W;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=T;i++)cin >> plum[i];
    cout << max(func(1,0,1),func(1,1,2));
}
