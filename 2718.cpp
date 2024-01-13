#include <bits/stdc++.h>
using namespace std;
int T,N;
int dp[100][13];

int Tile(int n,int bit){
	if(n<0)return 0;
	if(n<1)return bit==0;
	if(dp[n][bit])return dp[n][bit];
	
	int ret=0;
	switch(bit){
		case 0:
			ret+=Tile(n-1,0);
			ret+=Tile(n-1,3);
			ret+=Tile(n-1,9);
			ret+=Tile(n-1,12);
			ret+=Tile(n-2,0);
			break;
		case 3:
			ret+=Tile(n-1,0);
			ret+=Tile(n-1,12);
			break;
		case 6:
			ret+=Tile(n-1,9);
			break;
		case 9:
			ret+=Tile(n-1,0);
			ret+=Tile(n-1,6);
			break;
		case 12:
			ret+=Tile(n-1,0);
			ret+=Tile(n-1,3);
			break;
	}
	return dp[n][bit]=ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	
	while(T--){
		cin >> N;
		cout << Tile(N,0) << '\n';
	}
}
