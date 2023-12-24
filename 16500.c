#include <bits/stdc++.h>
using namespace std;
int N;
string S;
string T;
bool dp[101];
vector<string> A;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S >> N;
    int l=S.length();
    
    for(int i=0;i<N;i++){
    	cin >> T;
    	A.push_back(T);
	}
	
    for(int i=0;i<l;i++)
    	if(!i||dp[i]){
    		for(int j=0;j<N;j++){
    			bool corr=1;
    			int lj=A[j].length();
    			for(int k=0;k<lj;k++)
    				if(A[j][k]!=S[i+k]){
    					corr=0;
    					break;
					}
				if(corr)dp[i+lj]=1;
			}
		}
    cout << dp[l];
}