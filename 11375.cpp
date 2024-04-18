#include <bits/stdc++.h>
using namespace std;

int N,M,T,D;
vector<int> Jobs[1001];
bool check[1001];
int chosen[1001];

bool dfs(int p){
	int l=Jobs[p].size();
	for(int i=0;i<l;i++){
		int job=Jobs[p][i];
		if(check[job])continue;
		check[job]=1;
		if(!chosen[job]||dfs(chosen[job])){
			chosen[job]=p;
			return 1;
		}
	}
	return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=1;i<=N;i++){
    	cin >> T;
    	for(int j=0;j<T;j++){
    		cin >> D;
    		Jobs[i].push_back(D);
    	}
	}
	    
    int ans=0;
    for(int i=1;i<=N;i++){
    	memset(check,0,N+1);
    	if(dfs(i))ans++;
	}
	
	cout << ans;
}
