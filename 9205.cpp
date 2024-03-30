#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int T,N,A,B;
vector<pair<int,int>> V;
queue<int> Q;

bool Bfs(){
	bool vis[101]={1};
	Q.push(0);
	
	while(!Q.empty()){
		int cur=Q.front(); Q.pop();
		
		if(cur==N+1){
            while(!Q.empty())Q.pop();
            return 1;
        }
		
		for(int i=0;i<N+2;i++){
			int dis=abs(V[i].X-V[cur].X)+abs(V[i].Y-V[cur].Y);
			if(!vis[i]&&dis<=1000){
				Q.push(i);
				vis[i]=1;
			}
		}
	}
	return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--){
    	cin >> N;
    	
    	for(int i=0;i<N+2;i++){
    		cin >> A >> B;
    		V.push_back({A,B});
		}
		
		if(Bfs())cout << "happy\n";
		else cout << "sad\n";
		
    V.clear();
	}
}
