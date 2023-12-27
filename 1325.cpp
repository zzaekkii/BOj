#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int N,M,A,B;
vector<int> com[MAX];
int hack[MAX];
bool vis[MAX];
int mx;

void dfs(int n){
	hack[n]++;
	mx=max(mx,hack[n]);
	
	int l=com[n].size();
	for(int i=0;i<l;i++)
		if(!vis[com[n][i]]){
			vis[com[n][i]]=1;
			dfs(com[n][i]);
		}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    while(M--){
    	cin >> A >> B;
    	com[A].push_back(B);
	}

	for(int i=1;i<=N;i++){
		memset(vis,0,N+1);
		vis[i]=1;
		dfs(i);
	}
		
	for(int i=1;i<=N;i++)
		if(hack[i]==mx)cout << i << ' ';
}
