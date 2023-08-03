#include <bits/stdc++.h>
using namespace std;
int T, N;

int cnt;
bool vis[100001];
bool done[100001];
int G[100001];

void dfs(int v){
	vis[v]=1;
	
	int pick=G[v];
	
	if(!vis[pick])
		dfs(pick);
	else if(!done[pick]){
		for(int i=pick;i!=v;i=G[i]){
			cnt++;
		}
		cnt++;
	}
	
	done[v]=1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, num;
    
    cin >> T;
    
    while(T--){
    	cnt=0;
    	fill(vis, vis+N, 0);
    	fill(done, done+N, 0);
    	cin >> N;
    	
    	for(i=0;i<N;i++){
    		cin >> num;
    		G[i]= num-1;
		}
		
		for(i=0;i<N;i++)
			if(!vis[i])
				dfs(i);

		cout << N-cnt << '\n';
	}
}
