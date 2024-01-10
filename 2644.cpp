#include <bits/stdc++.h>
using namespace std;
int N,M,A,B,X,Y;

vector<int> V[101];
bool vis[101];
int ans=-1;

void dfs(int n,int cnt){
	vis[n]=1;
	
	if(n==B){
		ans=cnt;
		return;
	}
	
	int l=V[n].size();
	for(int i=0;i<l;i++)
		if(!vis[V[n][i]])
			dfs(V[n][i],cnt+1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> A >> B >> M;
    
    while(M--){
    	cin >> X >> Y;
    	V[X].push_back(Y);
    	V[Y].push_back(X);
	}
	dfs(A,0);
	cout << ans;
}
