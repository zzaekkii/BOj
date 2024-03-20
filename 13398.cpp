#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[100001];
int dp[100001][2];
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=1;i<=N;i++)
    	cin >> Arr[i];
    
    ans=dp[1][0]=dp[1][1]=Arr[1];
    for(int i=2;i<=N;i++){
    	dp[i][0]=max(dp[i-1][0]+Arr[i],Arr[i]);
    	dp[i][1]=max(dp[i-1][0],dp[i-1][1]+Arr[i]);
    	ans=max(ans,max(dp[i][0],dp[i][1]));
    }
    cout << ans;
}
