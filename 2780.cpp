#include <bits/stdc++.h>
#define MOD 1'234'567
using namespace std;

int T,N;
vector<int> V[10];
int dp[1001][11];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	
	V[0].push_back(7);
	V[1].push_back(2);V[1].push_back(4);
	V[2].push_back(1);V[2].push_back(3);V[2].push_back(5);
	V[3].push_back(2);V[3].push_back(6);
	V[4].push_back(1);V[4].push_back(5);V[4].push_back(7);
	V[5].push_back(2);V[5].push_back(4);V[5].push_back(6);V[5].push_back(8);
	V[6].push_back(3);V[6].push_back(5);V[6].push_back(9);
	V[7].push_back(0);V[7].push_back(4);V[7].push_back(8);
	V[8].push_back(5);V[8].push_back(7);V[8].push_back(9);
	V[9].push_back(6);V[9].push_back(8);
	
	for(int i=0;i<10;i++)
		dp[1][i]=1;
	
	for(int i=2;i<1001;i++)
		for(int j=0;j<10;j++){
			for(auto a:V[j])
				dp[i][j]+=dp[i-1][a]%MOD;
		}
	
	while(T--){
		cin >> N;
		int sum=0;
		for(int i=0;i<10;i++)
			sum+=dp[N][i];
		cout << sum % MOD << '\n';
	}
}
