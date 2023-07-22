#include <bits/stdc++.h>
using namespace std;

bool vis[1001];
vector<int> G[1001];
int N, M, U, V;

void dfs(int v){
	vis[v]=1;
	for(int i=0;i<G[v].size();i++){
		int idx = G[v][i];
		if(!vis[idx])
			dfs(idx);
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, ans=0;
    cin >> N >> M;
    
    for(i=0;i<M;i++){
    	cin >> U >> V;
    	G[U].push_back(V);
    	G[V].push_back(U);
	}
	
	for(i=1;i<=N;i++)
		if(!vis[i]){
			ans++;
			dfs(i);
		}
	
	cout << ans;
}
