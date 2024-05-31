#include <bits/stdc++.h>
using namespace std;

int N,M,A,B;
vector<int> V[2001];
bool vis[2001];
bool ans;

void Dfs(int idx,int cnt){
	if(cnt==4){
		ans=1;
		return;
	}
	vis[idx]=1;
	int l=V[idx].size();
	for(int i=0;i<l;i++)
		if(!vis[V[idx][i]]){
			Dfs(V[idx][i],cnt+1);
			vis[V[idx][i]]=0;
		}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	while(M--){
		cin >> A >> B;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	
	for(int i=0;i<N;i++)
		if(!vis[i]){
			Dfs(i,0);
			vis[i]=0;
            if(ans)break;
		}
	
	cout << ans;
}
