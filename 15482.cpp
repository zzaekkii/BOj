#include <bits/stdc++.h>
using namespace std;

string A,B;
int dp[3001][3001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;
    
    int len_A=A.length(),len_B=B.length();
    
    for(int i=3;i<=len_A;i+=3)
        for(int j=3;j<=len_B;j+=3)
            if(A.substr(i-3,3)==B.substr(j-3,3))dp[i][j]=dp[i-3][j-3]+1;
            else dp[i][j]=max(dp[i-3][j],dp[i][j-3]);
    
    cout << dp[len_A][len_B];
}
