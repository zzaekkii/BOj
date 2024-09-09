#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int M,N;
string board[1001];
bool vis[1001][1001];

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
queue<pair<int,int>> Q;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> M >> N;
	
	for(int i=0;i<M;i++)
		cin >> board[i];
	
	for(int i=0;i<N;i++)
		if(board[0][i]==48)Q.push({0,i});
	
	while(!Q.empty()){
		auto cur=Q.front(); Q.pop();
		if(vis[cur.X][cur.Y])continue;
		vis[cur.X][cur.Y]=1;
		for(int dir=0;dir<4;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
			if(nx>=0&&nx<M&&ny>=0&&ny<N)
				if(board[nx][ny]==48&&!vis[nx][ny])Q.push({nx,ny});
		}
	}
	
	bool flag=0;
	for(int i=0;i<N;i++)
		if(board[M-1][i]==48&&vis[M-1][i])flag=1;
	
	if(flag)cout << "YES";
	else cout << "NO";
}
