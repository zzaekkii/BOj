#include <bits/stdc++.h>
using namespace std;

int N;
int dp[31]={1,0,3}; // dp[0]은 추가될 형태. 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);    
    cin >> N;
    
    for(int i=4;i<=N;i+=2){
    	dp[i]=dp[i-2]*dp[2]; // 이전 형태 ×가능 형태 (끼워넣기) 
    	for(int j=i-4;j>=0;j-=2)
    		dp[i]+=dp[j]*2; // 상하 반전 (뒤집어 주기) + 새로운 형태 추가.
	}
    	
    cout << dp[N];
}
