#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
int board[101][101];
bool vis[101][101];
int dis[101][101]; 
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
int ans=0x7fffffff;
queue<pair<int,int>> Q;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int i, j;
	cin >> N;
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			cin >> board[i][j];
	
	int num=1;
	for(i=0;i<N;i++) // ´ë·ú ±¸ºÐÁþ±â. 
		for(j=0;j<N;j++)
			if(board[i][j]&&!vis[i][j]){
				Q.push({i,j});
				vis[i][j]=1;
				board[i][j]=num;
				while(!Q.empty()){
					auto cur = Q.front(); Q.pop();
					for (int dir=0;dir<4;dir++){
                        int nx=cur.X+dx[dir];
                        int ny=cur.Y+dy[dir];
                        if(nx<0||nx>=N||ny<0||ny>=N)continue;
                        if(board[nx][ny]!=1||vis[nx][ny])continue;
                        Q.push({nx,ny});
                        board[nx][ny]=num;
                        vis[nx][ny]=1;
                    }
				}
				num++;
			}
	
	num=1;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(board[i][j]==num){
				Q.push({i,j});
				dis[i][j]=1;
				while(!Q.empty()){
					auto cur=Q.front(); Q.pop();
                    for (int dir=0;dir<4;dir++){
                        int nx=cur.X+dx[dir];
                        int ny=cur.Y+dy[dir];
                        if(nx<0||nx>=N||ny<0||ny>=N)continue;
                        if(dis[nx][ny]&&dis[nx][ny]<=dis[cur.X][cur.Y]+1)continue;
                        if(board[nx][ny]==num){
                            dis[nx][ny]=1;
                            Q.push({nx,ny});
                        }
                        else if(!board[nx][ny]){
                            dis[nx][ny]=dis[cur.X][cur.Y]+1;
                            Q.push({nx,ny});
                        }
                        else if(board[nx][ny]!=num)
                            ans=min(ans,dis[cur.X][cur.Y]-1);
                    }
				}
				num++;
				fill_n(&dis[0][0],N*N,0);
			}
	cout << ans;
}
