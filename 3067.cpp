#include <bits/stdc++.h>
using namespace std;

int T,N,A;
int Co[21];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	
	while(T--){
		int dp[10'001]={1};
		cin >> N;
		for(int i=1;i<=N;i++)
			cin >> Co[i];
		cin >> A;
		
		for(int i=1;i<=N;i++)
			for(int j=Co[i];j<=A;j++)
				dp[j]+=dp[j-Co[i]];
		
		cout << dp[A] << '\n';
	}
}
