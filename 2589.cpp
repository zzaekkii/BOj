#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N,M;
string board[51];
queue<pair<int,int>> Q;
int dis[51][51];
int ans;

int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

void Bfs(int x,int y){
	memset(dis,-1,sizeof(dis));
	Q.push({x,y});
	dis[x][y]=0;
	
	while(!Q.empty()){
		auto cur=Q.front(); Q.pop();
		for(int dir=0;dir<4;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
			if(nx>=0&&nx<N&&ny>=0&&ny<M)
				if(board[nx][ny]=='L'&&dis[nx][ny]==-1){
					dis[nx][ny]=dis[cur.X][cur.Y]+1;
					ans=max(ans,dis[nx][ny]);
					Q.push({nx,ny});
				}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
		cin >> board[i];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			if(board[i][j]=='L')
				Bfs(i,j);
		}
	
	cout << ans;
}
