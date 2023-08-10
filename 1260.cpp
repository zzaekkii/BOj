#include <bits/stdc++.h>
using namespace std;

int N, M, V, A, B;

vector<int> vec[10001];
vector<int> res_bfs;
vector<int> res_dfs;
bool vis[1001];
queue<int> Q;

void bfs(int v){
	Q.push(v);
	vis[v]=1;
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		res_bfs.push_back(cur);
		
		int i, l=vec[cur].size();
		for(i=0;i<l;i++)
			if(!vis[vec[cur][i]]){
				Q.push(vec[cur][i]);
				vis[vec[cur][i]]=1;
			}				
	}
}

void dfs(int v){
	int i, l=vec[v].size();
	vis[v]=1;
	res_dfs.push_back(v);
	
	for(int i=0;i<l;i++)
		if(!vis[vec[v][i]])
			dfs(vec[v][i]);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int i, l;
	cin >> N >> M >> V;
	
	for(i=0;i<M;i++){
		cin >> A >> B;
		vec[A].push_back(B); // 양방향.
		vec[B].push_back(A);
	}
	
	for(i=1;i<=N;i++)
		sort(vec[i].begin(),vec[i].end()); // 작은 순으로 방문. 
	
	dfs(V);
	memset(vis,0,1001);
	bfs(V);
	
	l=res_dfs.size();
	for(i=0;i<l;i++)
		cout << res_dfs[i] << ' ';
	cout << '\n';
	
	l=res_bfs.size();
	for(i=0;i<l;i++)
		cout << res_bfs[i] << ' ';
}
