#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int arr[10001];
int N;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=1;i<=N;i++) cin >> arr[i];
    
    dp[1]=arr[1];
    dp[2]=dp[1]+arr[2];
    
    for(int i=3;i<=N;i++){
        dp[i]=max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
        dp[i]=max(dp[i-1],dp[i]);
    }
    
    cout << dp[N];
}
