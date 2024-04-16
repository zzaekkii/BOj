#include <bits/stdc++.h>
using namespace std;

string A,B,C;
int dp[101][101][101];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B >> C;
	
	int len_A=A.length(),len_B=B.length(),len_C=C.length();
	
	for(int i=1;i<=len_A;i++)
		for(int j=1;j<=len_B;j++)
            for(int k=1;k<=len_C;k++)
			    if(A[i-1]==B[j-1]&&B[j-1]==C[k-1])dp[i][j][k]=dp[i-1][j-1][k-1]+1;
			    else dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
	
	cout << dp[len_A][len_B][len_C];
}
