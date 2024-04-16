#include <bits/stdc++.h>
using namespace std;

string A,B;
int dp[1001][1001];
string ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;
    
    int len_A=A.length(),len_B=B.length();
    for(int i=1;i<=len_A;i++)
        for(int j=1;j<=len_B;j++)
            if(A[i-1]==B[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    
    cout << dp[len_A][len_B] << '\n';
    
    while(len_A>0&&len_B>0){
        if(A[len_A-1]==B[len_B-1]){
            ans=A[len_A-1]+ans;
            len_A--,len_B--;
            continue;
        }
        else if(len_A>1&&dp[len_A-1][len_B]==dp[len_A][len_B])
            len_A--;
        else if(len_B>1&&dp[len_A][len_B-1]==dp[len_A][len_B])
            len_B--;
        else break;
    }
    
    cout << ans;
}
