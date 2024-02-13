#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,M;
int dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,1,1,1,0,-1,-1,-1};

queue<pair<int,int>> Q;

int board[101][71];
bool vis[101][71];
bool peak;
int cnt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> board[i][j];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
        	if(!vis[i][j]){
        		peak=1;
        	    vis[i][j]=1;
        	    Q.push({i,j});
            	while(!Q.empty()){
                    auto cur=Q.front();Q.pop();
                    for(int dir=0;dir<8;dir++){
                    	int nx=cur.X+dx[dir];
                    	int ny=cur.Y+dy[dir];
                    	if(nx<0||nx>=N||ny<0||ny>=M)continue;
                    	if(board[i][j]<board[nx][ny])peak=0;
                    	if(vis[nx][ny]||board[i][j]!=board[nx][ny])continue;
                    	vis[nx][ny]=1;
                    	Q.push({nx,ny});
                    }
            	}
        		if(peak)cnt++;
        	}
        }

    cout << cnt;
}
