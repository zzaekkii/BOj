#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1001];
int dp[1001];
int mx;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=1;i<=N;i++)
		cin >> arr[i];
	
	for(int i=1;i<=N;i++){
		dp[i]=1;
		for(int j=1;j<i;j++)
			if(arr[j]<arr[i]&&dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
		if(mx<dp[i])mx=dp[i];
	}
	cout << mx;
}
