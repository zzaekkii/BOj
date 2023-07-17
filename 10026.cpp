#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
char board[101][101];
bool vis[101][101];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

void bfs(int a, int b){
	queue<pair<int,int>> Q;
	Q.push({a,b});
	vis[a][b]=1;
	
	while(!Q.empty()){
		auto cur=Q.front(); Q.pop();
		for(int dir=0;dir<4;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
			if(nx<0||nx>=N||ny<0||ny>=N)continue;
			if(vis[nx][ny]||board[a][b]!=board[nx][ny])continue;
			Q.push({nx,ny});
			vis[nx][ny]=1;
		}
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, j;
    cin >> N;
    
    for(i=0;i<N;i++)
    	for(j=0;j<N;j++)
    		cin >> board[i][j];
    		
    int noG=0, yeG=0; // 색약 아닌 사람, 색약인 사람.
    
    for(i=0;i<N;i++) // 색약이 아닐 때의 구역.
    	for(j=0;j<N;j++)
    		if(!vis[i][j]){
    			bfs(i,j);
    			noG++;
    		}
    
    for(i=0;i<N;i++)
    	fill(vis[i],vis[i]+N,0);
    	 
    for(i=0;i<N;i++) // 색약 구역으로 변경. 
    	for(j=0;j<N;j++)
    		if(board[i][j]=='R')
    			board[i][j]='G';
			
	for(i=0;i<N;i++) // 색약일 때의 구역 수. 
    	for(j=0;j<N;j++)
    		if(!vis[i][j]){
    			bfs(i,j);
    			yeG++;
    		}
	
    cout << noG << " " << yeG;
}
