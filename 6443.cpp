#include <bits/stdc++.h>
using namespace std;

int N;
string S;
bool vis[21];
char ans[21];
int l;

void Dfs(int idx){
	if(idx==l){
	    for(int i=0;i<l;i++)
	        cout << ans[i];
	    cout << '\n';
		return;
	}
	
	char prev=0;
	for(int i=0;i<l;i++)
		if(prev!=S[i]&&!vis[i]){
			ans[idx]=prev=S[i];
			vis[i]=1;
			Dfs(idx+1);
			vis[i]=0;
		}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	while(N--){
		cin >> S;
		l=S.length();
		sort(S.begin(),S.end());		
		Dfs(0);
	}
}
