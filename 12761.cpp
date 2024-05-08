#include <bits/stdc++.h>
using namespace std;

int A,B,N,M;
bool vis[100001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B >> N >> M;
	
	queue<int> Q;
	int dx[]={-1,1,-A,-B,A,B};
	int cnt=0;
	vis[N]=1;
	Q.push(N);
	
	while(!Q.empty()&&!vis[M]){
		int dep=Q.size();
		cnt++;
		
		while(dep--&&!vis[M]){
			int cur=Q.front(); Q.pop();
			
			for(int i=0;i<6;i++){
				int nx=cur+dx[i];
				if(0<=nx&&nx<=100000&&!vis[nx]){
					vis[nx]=1;
					Q.push(nx);				
				}
			}
			
			for(int i=4;i<6;i++){
				int nx=cur*dx[i];
				if(0<=nx&&nx<=100000&&!vis[nx]){
					vis[nx]=1;
					Q.push(nx);
				}
			}
		}
	}
	
	cout << cnt;
}
