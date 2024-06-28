#include <bits/stdc++.h>
using namespace std;

int N;
int A[100001][3];
int dp[100001][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int x=1;;x++){
		cin >> N;
		if(!N)break;
        
		for(int i=0;i<N;i++)
			for(int j=0;j<3;j++)
				cin >> A[i][j];
		
		dp[0][0]=0x7fffffff,dp[0][1]=A[0][1],dp[0][2]=A[0][1]+A[0][2];
		
		for(int i=1;i<N;i++){
			dp[i][0]=min(dp[i-1][0],dp[i-1][1])+A[i][0];
			dp[i][1]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i][0]})+A[i][1];
			dp[i][2]=min({dp[i-1][1],dp[i-1][2],dp[i][1]})+A[i][2];
		}
		
		cout << x << ". " << dp[N-1][1] << '\n';
	}
}
