#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};
int board[101][101];
bool vis[101][101];
queue<pair<int,int>> Q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, j, high=0;
    cin >> N;
    
    for(i=0;i<N;i++)
    	for(j=0;j<N;j++){
	    	cin >> board[i][j];
	    	if(high<board[i][j])
	    		high=board[i][j];
	    }
    
    int ans=0;
    while(high>=0){
    	int cnt=0;
    	for(i=0;i<N;i++) fill(vis[i], vis[i]+N, 0);
    	
    	for(i=0;i<N;i++)
    		for(j=0;j<N;j++)
    			if(board[i][j]>high&&!vis[i][j]){
    				Q.push({i,j});
    				while(!Q.empty()){
				    	auto cur=Q.front(); Q.pop();
				    	for(int dir=0;dir<4;dir++){
					        int nx = cur.X + dx[dir];
					        int ny = cur.Y + dy[dir];
				    		if(nx<0||nx>=N||ny<0||ny>=N)continue;
				    		if(vis[nx][ny]||board[nx][ny]<=high)continue;
				    		Q.push({nx,ny});
				    		vis[nx][ny]=1;
						}
					}    				
    				cnt++;
				}
    	
    	if(ans<cnt) ans=cnt;
    	high--;
	}
    cout << ans;
}
