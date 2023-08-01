#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;
int board[301][301];
int copy_b[301][301];
bool vis[301][301];
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
queue<pair<int,int>> Q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, j, year=0;
    cin >> N >> M;
    
    for(i=0;i<N;i++)
    	for(j=0;j<M;j++)
    		cin >> board[i][j];
	
    while(1){
    	int area = 0, cnt=0;
    	fill_n(&vis[0][0],301*301,0);
    	fill_n(&copy_b[0][0],301*301,0);
    	
    	for(i=0;i<N;i++)
    		for(j=0;j<M;j++){
				if(board[i][j]&&!vis[i][j]){
					vis[i][j]=1;
			   		Q.push({i,j});
				   	while (!Q.empty()) {
					    auto cur = Q.front(); Q.pop();
					    for(int dir=0;dir<4;dir++){
					       	int nx=cur.X+dx[dir];
					       	int ny=cur.Y+dy[dir];
					       	if(nx<0||nx>=N||ny<0||ny>=M)continue;
					       	if(vis[nx][ny]||!board[nx][ny])continue;
					       	vis[nx][ny]=1;
					       	Q.push({nx,ny});
						}
		    		}
		    		cnt++;
				}
			}
					
		if(cnt>1){cout << year; break;}
		if(cnt==0){cout << 0; break;}
		
		for(i=0;i<N;i++)
			for(j=0;j<M;j++){
				int tmp=0;
				if(board[i][j]){
					for(int dir=0;dir<4;dir++){
					    int nx=i+dx[dir];
					    int ny=j+dy[dir];
					    if(!board[nx][ny])tmp++;
					}
				}
				copy_b[i][j]=board[i][j]-tmp; // 카피가 녹아야 보드가 원형을 유지. 
				if(copy_b[i][j]<0)copy_b[i][j]=0; // 보드가 녹으면 안쪽도 같이 녹음. 
			}
			
		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
				board[i][j]=copy_b[i][j]; 
				
		year++;
	}
}
