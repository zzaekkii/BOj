#include <bits/stdc++.h>
using namespace std;

int N;
char C;
int s[35][35];
long long dp[35][35];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1){
    	cin >> N;
    	if(N==-1)break;
    	
    	memset(dp,0,sizeof(dp));
    	dp[1][1]=1;
    	
    	for(int i=1;i<=N;i++)
    		for(int j=1;j<=N;j++){
    			cin >> C;
    			s[i][j]=C-48;
    		}
    	
    	for(int i=1;i<=N;i++)
    		for(int j=1;j<=N;j++){
    			if(i==N&&j==N)continue; 
    			if(i+s[i][j]<=N)dp[i+s[i][j]][j]+=dp[i][j];
    			if(j+s[i][j]<=N)dp[i][j+s[i][j]]+=dp[i][j];
			}
			
		cout << dp[N][N] << '\n';
    }
}
