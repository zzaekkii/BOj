#include <bits/stdc++.h>
using namespace std;

int N,K;
string S[11];

bool vis[11];
map<string,bool> M;
string tmp;

void Dfs(int cnt){
	if(cnt==K){
		M.insert({tmp,1});
		return;
	}
	string bf=tmp;
	for(int i=0;i<N;i++){
		if(!vis[i]){
			tmp+=S[i];
			vis[i]=1;
			Dfs(cnt+1);
			tmp=bf;
			vis[i]=0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	
	for(int i=0;i<N;i++)
		cin >> S[i];
	
	Dfs(0);
	
	cout << M.size();
}
