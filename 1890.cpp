#include <bits/stdc++.h>
using namespace std;
short N;
short board[101][101];
long long dp[101][101];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(short i=0;i<N;i++)
    	for(short j=0;j<N;j++)
    		cin >> board[i][j];
	
    dp[0][0]=1;
    
    for(short i=0;i<N;i++)
    	for(short j=0;j<N;j++){
    		short tmp=board[i][j];
    		if(!tmp)break;
    		if(i+tmp<N)dp[i+tmp][j]+=dp[i][j];
    		if(j+tmp<N)dp[i][j+tmp]+=dp[i][j];
		}	
	cout << dp[N-1][N-1];
}
