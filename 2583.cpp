#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int M, N, K; // 높이, 너비, 직사 개수.
int LX, LY, RX, RY; // 왼쪽 시작 좌표, 오른쪽 끝 좌표. 
int board[101][101];
bool vis[101][101]; 
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0 ,1};
queue<pair<int,int>> Q;
vector<int> V;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, j, k;
    cin >> M >> N >> K;
        
    for(i=0;i<K;i++){
    	cin >> LX >> LY >> RX >> RY;
    	for(j=LY;j<RY;j++)
    		for(k=LX;k<RX;k++)
    			board[j][k]=1;
	}
	
	int cnt=0; // 영역의 수.
	for(i=0;i<M;i++)
		for(j=0;j<N;j++){
			int area=0; 
			if(!board[i][j]&&!vis[i][j]){
				vis[i][j]=1;
		   		Q.push({i,j});
			   	while (!Q.empty()) {
			   		area++;
				    auto cur = Q.front(); Q.pop();
				    for(int dir=0;dir<4;dir++){
				       	int nx=cur.X+dx[dir];
				       	int ny=cur.Y+dy[dir];
				       	if(nx<0||nx>=M||ny<0||ny>=N)continue;
				       	if(vis[nx][ny]||board[nx][ny])continue;
				       	vis[nx][ny]=1;
				       	Q.push({nx,ny});
					}
	    		}
	    		cnt++; // 영역 추가.
	    		V.push_back(area);
			}
		}
		sort(V.begin(),V.end());
		cout << cnt << '\n';
		for(auto a : V) cout << a << ' ';
}
