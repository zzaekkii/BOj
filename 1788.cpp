#include <bits/stdc++.h>
#define MOD 1'000'000'000
using namespace std;

int N;
int dp[1000001]={0,1};
int op=1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);    
	cin >> N;
	
	if(N<0){
		if(!(N%2))op=-1;
		N*=-1;
	}
	else op=N?1:0;
	
	for(int i=2;i<=N;i++)
		dp[i]=(dp[i-1]+dp[i-2])%MOD;		
	
	cout << op << '\n' << dp[N];
}
