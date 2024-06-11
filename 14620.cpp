#include <bits/stdc++.h>
using namespace std;

int N;
int G[11][11];
bool vis[11][11];
int sum;
int dx[]={0,-1,0,1,0},dy[]={0,0,-1,0,1};

int ans=0x7FFFFFFF;

void Dfs(int cnt){
	if(cnt==3){
		ans=min(ans,sum);
		return;
	}
	
	for(int i=1;i<N-1;i++)
		for(int j=1;j<N-1;j++){
			int flag=1;
			for(int dir=0;dir<5;dir++)
				if(vis[i+dx[dir]][j+dy[dir]])flag=0;
			if(flag){
				for(int dir=0;dir<5;dir++){
					vis[i+dx[dir]][j+dy[dir]]=1;
					sum+=G[i+dx[dir]][j+dy[dir]];
				}				
				Dfs(cnt+1);
				for(int dir=0;dir<5;dir++){
					vis[i+dx[dir]][j+dy[dir]]=0;
					sum-=G[i+dx[dir]][j+dy[dir]];
				}	
			}	
		}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> G[i][j];
	
	Dfs(0);
	
	cout << ans;
}
