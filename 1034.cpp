#include <bits/stdc++.h>
using namespace std;

int N,M,K;
string S[51];
int cnt,eq,ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++)cin >> S[i];
    	
    cin >> K;
	
	for(int i=0;i<N;i++){
		cnt=eq=0;
		
		for(int j=0;j<M;j++)
			if(S[i][j]==48)cnt++;
		
		for(int j=i;j<N;j++)
			if(!S[i].compare(S[j]))eq++;
		
		if(cnt<=K&&!((K-cnt)%2))ans=max(ans,eq);
	}	
	cout << ans;
}
