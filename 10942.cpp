#include <bits/stdc++.h>
using namespace std;

int N,M,S,E;
int Arr[2001];
bool dp[2001][2001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=1;i<=N;i++)
    	cin >> Arr[i];
    	
    for(int i=1;i<=N;i++){
    	dp[i][i]=1;
    	if(Arr[i-1]==Arr[i])dp[i-1][i]=1;
	}
	
	for(int i=N-1;i>=1;i--)
		for(int j=i+1;j<=N;j++)
			if(Arr[i]==Arr[j]&&dp[i+1][j-1])
				dp[i][j]=1;
    
    cin >> M;
    
    while(M--){
    	cin >> S >> E;
    	cout << dp[S][E] << '\n';
	}
}
