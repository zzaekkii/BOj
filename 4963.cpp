#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int W,H;
int dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,1,1,1,0,-1,-1,-1};

queue<pair<int,int>> Q;

int board[51][51];
bool vis[51][51];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(1){
        cin >> W >> H;
        if(!W&&!H)break;
        
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
                cin >> board[i][j];
                
        int cnt=0;
        memset(vis,0,sizeof(vis));
        
        for(int i=0;i<H;i++)
        	for(int j=0;j<W;j++){
        	    if(board[i][j]&&!vis[i][j]){
        	        vis[i][j]=1;
        	        cnt++;
        	        Q.push({i,j});
            	    while(!Q.empty()){
                    	auto cur=Q.front();Q.pop();
                    	for(int dir=0;dir<8;dir++){
                    		int nx=cur.X+dx[dir];
                    		int ny=cur.Y+dy[dir];
                    		if(nx<0||nx>=H||ny<0||ny>=W)continue;
                    		if(vis[nx][ny]||!board[nx][ny])continue;
                    		vis[nx][ny]=1;
                    		Q.push({nx,ny});
                        }
            	    }
        	    }
        	}
        cout << cnt << '\n';
    }
}
