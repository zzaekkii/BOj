#include <bits/stdc++.h>
using namespace std;

int C,N;
int pro[20][2];
int dp[1001];

int ad(int goal){
	int mn=100000;
	int cost;
	
	if(goal<=0)return 0;
	else if(dp[goal]>0)return dp[goal];
	else{
		for(int i=0;i<N;i++){
			cost=ad(goal-pro[i][1])+pro[i][0];
			mn=min(mn,cost);
		}
		dp[goal]=mn;
		
		return mn;
	}	
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> C >> N;
    
    for(int i=0;i<N;i++)
    	cin >> pro[i][0] >> pro[i][1];
    	
    cout << ad(C);
}
