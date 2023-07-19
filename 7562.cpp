#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int T, I, FX, FY, TX, TY;
int dis[301][301];
int dx[8]={-1, -2, -2, -1,  1,  2,  2,  1};
int dy[8]={-2, -1,  1,  2,  2,  1, -1, -2};

void bfs(){
	queue<pair<int,int>> Q;
	Q.push({FX,FY});
	dis[FX][FY]=0;
	
	while(!Q.empty()){
		auto cur=Q.front(); Q.pop();
		for(int dir=0;dir<8;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
			if(nx<0||nx>=I||ny<0||ny>=I)continue;
			if(dis[nx][ny]!=-1)continue;
			Q.push({nx,ny});
			dis[nx][ny]=dis[cur.X][cur.Y]+1;
			if(nx==TX&&ny==TY)return;
		}
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, j;
    cin >> T;
    
    while(T--){
    	cin >> I >> FX >> FY >> TX >> TY;
    	for(i=0;i<I;i++)fill(dis[i],dis[i]+I,-1);
    	bfs();    	
    	cout << dis[TX][TY] << '\n';
	}
}
