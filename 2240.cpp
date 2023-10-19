#include <iostream>
using namespace std;

int T, W, N, ans;
int dp[32];

int main(){
    cin >> T >> W;
    while(T--){
        cin >> N;
        for(int i=0;i<=W;i++){
            dp[i]=max(dp[i+1],dp[i]);
            if(i%2+1==N)dp[i]++;
            ans=max(ans,dp[i]);
        }
    }
    cout << ans;
}
