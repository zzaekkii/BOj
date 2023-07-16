#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;
int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

queue<pair<int,int>> Q;

int board[1001][1001];
int dist[1001][1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, j;
    cin >> N >> M;
    
    for(i=0;i<N;i++)fill(dist[i],dist[i]+M,0);
    
    for(i=0;i<N;i++)
    	for(j=0;j<M;j++){
    		cin >> board[i][j];
    		if(board[i][j]==1)dist[i][j]=0;
    		if(board[i][j]==2){
    			dist[i][j]=0;
    			Q.push({i,j});
			}
    	}
    
    while(!Q.empty()){
    	auto cur=Q.front();Q.pop();
    	for(int dir=0;dir<4;dir++){
    		int nx=cur.X+dx[dir];
    		int ny=cur.Y+dy[dir];
    		if(nx<0||nx>=N||ny<0||ny>M)continue;
    		if(dist[nx][ny]>0||board[nx][ny]!=1)continue;
    		dist[nx][ny]=dist[cur.X][cur.Y]+1;
    		Q.push({nx,ny});
		}
	}
	
	for(i=0;i<N;i++, cout << "\n")
		for(j=0;j<M;j++){
			if(!dist[i][j]&&board[i][j]==1)cout << -1 << " ";
			else cout << dist[i][j] << " ";
		}
}
