// 14728번 벼락치기 - 골드5 / #DP 
/*
#include <bits/stdc++.h>
using namespace std;

typedef struct Sub{
	int K, S; // 해당 단원 예상 공부 시간 K, 배점 S. 
};

int N, T; // 시험 범위 N단원, T시간 공부 가능.
int dp[101][10001];

Sub X[101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T;
    
    for(int i=1;i<=N;i++)
    	cin >> X[i].K >> X[i].S;
    
    for(int i=1;i<=N;i++)
    	for(int j=0;j<=T;j++){
    		if(X[i].K>j)dp[i][j]=max(dp[i][j],dp[i-1][j]);
    		else dp[i][j]=max(dp[i-1][j],dp[i-1][j-X[i].K]+X[i].S);
		}
	
	cout << dp[N][T];
}
*/
#include <bits/stdc++.h>
using namespace std;
int N,K;
int I,T;
int dp[10001];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> K >> N;
	
	while(K--){
		cin >> T >> I;
		for(int i=N;i>=T;i--)
			dp[i]=max(dp[i-T]+I,dp[i]);
	}
	
	cout << dp[N];
}
