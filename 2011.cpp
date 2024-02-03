#include <bits/stdc++.h>
#define MOD 1000000
using namespace std;

string S;
int dp[5001]={1,1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S;

    if(S[0]==48){ // 첫자리가 0이면 망호. 
    	cout << 0;
    	return 0;
    }
    
    int l=S.length();
    
    for(int i=2;i<=l;i++){
    	if(S[i-1]!=48)dp[i]=dp[i-1]%MOD;
    	
    	int tmp=(S[i-2]-48)*10+(S[i-1]-48); // 앞코드 포함. 
    	
    	if(tmp>9&&tmp<27) // 그게 말이 됨. 
    		dp[i]=(dp[i-2]+dp[i])%MOD; // 의심받던 0도 여기서 치료. 
	}	// 포함 코드가 말이 되면, 그거 미포함 경우 + 포함 경우로 2개가 됨. 
    	
    cout << dp[l];
}
