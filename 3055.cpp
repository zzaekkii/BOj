// 3055번 탈출 - 골드4 / #BFS 
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int R, C; // RxC 크기 보드.
char board[51][51]; // 비버 'D', 고슴 'S', 물 '*', 돌 'X', 길 '.' 

int time_gs[51][51], time_wt[51][51];
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};

queue<pair<int,int>> gosm;
queue<pair<int,int>> water;

void Init(){
	for(int i=0;i<50;i++)
		for(int j=0;j<50;j++){
			time_gs[i][j]=time_wt[i][j]=-1;
		}
}

void Input(){
	cin >> R >> C; 
	
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++){
			cin >> board[i][j];
			
			// 고슴이 스타트. 
			if(board[i][j]=='S'){
				gosm.push({i,j});
				time_gs[i][j]=0;
			}
			// 물 위치.
			else if(board[i][j]=='*'){
				water.push({i,j});
				time_wt[i][j]=0;
			}
		}
}

void Bfs(){
	// 홍수 레츠고. 
	while(!water.empty()){
		auto cur=water.front(); water.pop();
		
		for(int dir=0;dir<4;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
			
			if(nx>=0&&nx<R&&ny>=0&&ny<C)
				if(time_wt[nx][ny]==-1&&board[nx][ny]=='.'){
					water.push({nx,ny});
					time_wt[nx][ny]=time_wt[cur.X][cur.Y]+1;
				}
		}
	}
	
	
	// 고슴이 레츠고. 
	while(!gosm.empty()){
		auto cur=gosm.front(); gosm.pop();
		
		// 비버굴 도착, 탈출 성공. 
		if(board[cur.X][cur.Y]=='D'){
			cout << time_gs[cur.X][cur.Y];
			exit(0); 
		}
		
		for(int dir=0;dir<4;dir++){
			int nx=cur.X+dx[dir];
			int ny=cur.Y+dy[dir];
			
			if(nx>=0&&nx<R&&ny>=0&&ny<C){				
				// 벽이 아니고, 이전에 갔던 길 아니고. 
				if(board[nx][ny]!='X'&&time_gs[nx][ny]==-1){
					// 현재 시점에 아직 물이 없는 길이면 레츠고. 
					if(time_wt[nx][ny]==-1||time_wt[nx][ny]>time_gs[cur.X][cur.Y]+1){
						time_gs[nx][ny]=time_gs[cur.X][cur.Y]+1;
						gosm.push({nx,ny}); 
					}
				}
			}
		}
	}
	
	// 고슴이 탈출 실패. 
	cout << "KAKTUS";
} 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	Init(); 
	Input();
	Bfs();
}
