#include <bits/stdc++.h>
using namespace std;

int N,M;
int A[101]; // 사용 중인 메모리. 
int C[101]; // 다시 키는 비용.
int dp[101][10001]; // [i][j]: i번까지 j비용으로 확보 가능한 메모리.
int ans=0x7fffffff;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=1;i<=N;i++)
		cin >> A[i];
	
	for(int i=1;i<=N;i++)
		cin >> C[i];
	
	for(int i=1;i<=N;i++)
		for(int j=0;j<=10000;j++){
			if(C[i]>j)dp[i][j]=dp[i-1][j]; // 감당 불가는 스킵. 
			else{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-C[i]]+A[i]);
				if(dp[i][j]>=M)ans=min(ans,j);
			}
		}
	
	cout << ans;
}
