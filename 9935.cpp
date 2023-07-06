#include <bits/stdc++.h>
using namespace std;

char stk[1000001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    using namespace std;
    string S, B;
    cin >> S;
	cin >> B;
    
    int idx=0;
    for(int i=0;i<S.length();i++){
    	stk[idx]=S[i];
    	if(stk[idx]==B[B.length()-1]){
    		bool f = 1;
    		for(int j=0;j<B.length();j++)
    			if(stk[idx-j]!=B[B.length()-1-j]){
    				f=0;
    				break;
				}
			if(f)idx-=B.length();
		}		
		idx++;
	}
	if(!idx)cout << "FRULA";
	else for(int i=0;i<idx;i++)cout << stk[i];
}
