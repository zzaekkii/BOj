#include <bits/stdc++.h>
using namespace std;

int N,M,T;
int VIP[41];
int dp[41]={1,1,2};
int ans=1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=1;i<=M;i++)
		cin >> VIP[i];
	
	sort(VIP,VIP+M+1);
	
	for(int i=3;i<=N;i++)
		dp[i]=dp[i-1]+dp[i-2];
	
	for(int i=0;i<M;i++)
		ans*=dp[VIP[i+1]-VIP[i]-1];
	
	cout << ans*dp[N-VIP[M]];
}
