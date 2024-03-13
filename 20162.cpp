#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[1001];
int dp[1001];
int ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> Arr[i];
		dp[i]=Arr[i];
	}

	for(int i=0;i<N;i++)
		for(int j=0;j<i;j++)
			if(Arr[j]<Arr[i]&&dp[i]<dp[j]+Arr[i])
				dp[i]=dp[j]+Arr[i];

	for(int i=0;i<N;i++)
        ans=max(ans,dp[i]); 
	cout << ans; 
}
