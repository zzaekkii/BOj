#include <bits/stdc++.h>
using namespace std;

int N,M,R,U,V;
vector<int> gph[100001];
bool vis[100001];
int ans[100001];
int ord;
queue<int> Q;

int bfs(int r) {
	Q.push(r);
	vis[r]=1;
	ans[r]=++ord;
	while(!Q.empty()){
		int frt=Q.front(); Q.pop();
		for(int i=0;i<gph[frt].size();i++){
			int tmp=gph[frt][i];
			if(!vis[tmp]){
				ans[tmp]=++ord;
				Q.push(tmp);
				vis[tmp]=1;
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> R;
    
    for(int i=0;i<N;i++){
    	cin >> U >> V;
    	gph[U].push_back(V);
    	gph[V].push_back(U);
	}
	for(int i=1;i<=N;i++)
		sort(gph[i].begin(),gph[i].end());
	bfs(R);
	for(int i=1;i<=N;i++)
		cout << ans[i] << ' ';	
}
