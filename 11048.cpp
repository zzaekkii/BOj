#include <bits/stdc++.h>
using namespace std;

int N,M;
int Arr[1001][1001];
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin >> Arr[i][j];
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            dp[i][j]=Arr[i][j]+max(dp[i-1][j],dp[i][j-1]);
    
    cout << dp[N][M];
}
