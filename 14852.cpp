#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
int N;
int dp[1'000'000][3];

int Tile(int n,int bit){
	if(n<0)return 0;
	if(n<1)return bit==0;
	if(dp[n][bit])return dp[n][bit];

	int ret=0;
	switch(bit){
		case 0:
			ret=(ret+(2*Tile(n-1,0))%MOD)%MOD;
			ret=(ret+(Tile(n-1,1)%MOD))%MOD;
			ret=(ret+(Tile(n-1,2)%MOD))%MOD;
			ret=(ret+(Tile(n-2,0)%MOD))%MOD;
			break;
		case 1:
			ret=(ret+(Tile(n-1,0)%MOD))%MOD;
			ret=(ret+(Tile(n-1,2)%MOD))%MOD;
			break;
		case 2:
			ret=(ret+(Tile(n-1,0)%MOD))%MOD;
			ret=(ret+(Tile(n-1,1)%MOD))%MOD;
			break;
	}
	return dp[n][bit]=ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	cout << Tile(N,0);
}
