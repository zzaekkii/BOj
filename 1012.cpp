#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
 
int T, M, N, K;
int cab[51][51];
bool vis[51][51];
int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};
queue<pair<int,int>> Q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, j, x, y;
    cin >> T;
    
    while(T--){
	    cin >> M >> N >> K; // 가로, 세로, 배추 개수.
		    
	    for(i=0;i<N;i++){ // 각 배열 초기화.
		    fill(cab[i],cab[i]+M,0);
		    fill(vis[i],vis[i]+M,0);    	
		}
		
	    for(i=0;i<K;i++){ // 배추 위치 저장.
	    	cin >> y >> x;
	    	cab[x][y]=1; // 행 열~~ 오우..
		}
		
		int cnt=0;		
	    for(i=0;i<N;i++)
	    	for(j=0;j<M;j++){
	    		if(cab[i][j]&&!vis[i][j]){ // 방문 안 한 배추인가.
	    			vis[i][j]=1;
	    			Q.push({i,j});
	    			while (!Q.empty()) {
				        auto cur = Q.front(); Q.pop();
				        for(int dir=0;dir<4;dir++){
				        	int nx=cur.X+dx[dir];
				        	int ny=cur.Y+dy[dir];
				        	if(nx<0||nx>=N||ny<0||ny>=M)continue;
				        	if(vis[nx][ny]||!cab[nx][ny])continue;
				        	vis[nx][ny]=1;
				        	Q.push({nx,ny});
						}
					}
	    			cnt++; // 지렁이 추가.
				}
	    	}
	    cout << cnt << "\n";
	}
}
