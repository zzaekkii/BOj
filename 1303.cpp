#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,M;
int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};

queue<pair<int,int>> Q;

string board[101];
bool vis[101][101];
int W,B;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;

    for(int i=0;i<N;i++)
        cin >> board[i];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
        	if(!vis[i][j]){
        	    vis[i][j]=1;
        	    Q.push({i,j});
        	    int cnt=0;
            	while(!Q.empty()){
                    auto cur=Q.front();Q.pop();
                    cnt++;
                    for(int dir=0;dir<4;dir++){
                    	int nx=cur.X+dx[dir];
                    	int ny=cur.Y+dy[dir];
                    	if(nx<0||nx>=N||ny<0||ny>=M)continue;
                    	if(vis[nx][ny]||board[i][j]!=board[nx][ny])continue;
                    	vis[nx][ny]=1;
                    	Q.push({nx,ny});
                    }
            	}
            	if(board[i][j]=='W')W+=cnt*cnt;
            	else B+=cnt*cnt;
        	}
        }

    cout << W << ' ' << B;
}
