#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
string A,B;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B;
	
	int len_A=A.size();
	int len_B=B.size();
	
	for(int i=1;i<=len_A;i++)
		for(int j=1;j<=len_B;j++)
			if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	
	cout << dp[len_A][len_B];
}
