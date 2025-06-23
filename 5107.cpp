// 5107번 마니또 - 실버1 / 맵, DFS 
#include <bits/stdc++.h>
using namespace std;

int N;
string A, B;

map<string, string> m;
map<string, bool> visited;
int cnt;

void Dfs(string name){
	if(visited[m[name]])cnt++;
	else{
		visited[m[name]]=1;
		Dfs(m[name]);
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
	for(int i=1;cin >> N;i++){
    	if(!N)break;
    	
    	cnt=0;
    	m.clear();
    	visited.clear();
    	
    	while(N--){
    		cin >> A >> B;
    		m[A]=B;
		}
    	
    	for(auto a: m){
    		if(!visited[a.first])
    			Dfs(a.first);
		}
		
		cout << i << ' ' << cnt << '\n';
	}
}
