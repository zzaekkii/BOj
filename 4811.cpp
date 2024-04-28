#include <bits/stdc++.h>
using namespace std;

int N;
long long dp[31][31];

long long func(int n,int h){
	if(h==-1)return 0;
	if(!n)return 1;
	if(dp[n][h])return dp[n][h];
	return dp[n][h]=func(n-1,h+1)+func(n,h-1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while(1){
		cin >> N;				
		if(!N)break;		
		cout << func(N,0) << '\n';		
	}
}
