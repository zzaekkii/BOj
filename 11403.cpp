#include <bits/stdc++.h>
using namespace std;

int N;
bool T;
vector<int> V[101];
bool vis[101];

void Dfs(int idx){
	int l=V[idx].size();
	for(int i=0;i<l;i++)
		if(!vis[V[idx][i]]){
			vis[V[idx][i]]=1;
			Dfs(V[idx][i]);
		}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin >> T;
			if(T)V[i].push_back(j);
		}
	
	for(int i=0;i<N;i++){
		memset(vis,0,101);
		Dfs(i);
		for(int j=0;j<N;j++)
			cout << vis[j] << ' ';
		cout << '\n';
	}
}
