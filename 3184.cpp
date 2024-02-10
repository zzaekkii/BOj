#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int R,C;
int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

queue<pair<int,int>> Q;

string board[251];
bool vis[251][251];

int lam,wol;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;

    for(int i=0;i<R;i++)
        cin >> board[i];

    for(int i=0;i<R;i++)
    	for(int j=0;j<C;j++){
    	    Q.push({i,j});
    	    int l=0,w=0;
    	    while(!Q.empty()){
            	auto cur=Q.front();Q.pop();
            	for(int dir=0;dir<4;dir++){
            		int nx=cur.X+dx[dir];
            		int ny=cur.Y+dy[dir];
            		if(nx<0||nx>=R||ny<0||ny>=C)continue;
            		if(vis[nx][ny]||board[nx][ny]=='#')continue;
            		vis[nx][ny]=1;
            		Q.push({nx,ny});
            		if(board[nx][ny]=='o')l++;
            		else if(board[nx][ny]=='v')w++;
                }
    	    }
    	    if(l>w)lam+=l;
    	    else wol+=w;
    	}
    cout << lam << ' ' << wol;
}
