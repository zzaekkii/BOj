#include <bits/stdc++.h>
using namespace std;

int N,M,T,D;
vector<int> Fenc[201];
bool check[201];
int chosen[201];

bool dfs(int c){
	int l=Fenc[c].size();
	for(int i=0;i<l;i++){
		int pl=Fenc[c][i];
		if(check[pl])continue;
		check[pl]=1;
		if(!chosen[pl]||dfs(chosen[pl])){
			chosen[pl]=c;
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
    		Fenc[i].push_back(D);
    	}
	}
	    
    int ans=0;
    for(int i=1;i<=N;i++){
    	memset(check,0,201);
    	if(dfs(i))ans++;
	}
	
	cout << ans;
}
