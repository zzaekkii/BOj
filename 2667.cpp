#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
char board[26][26];
bool vis[26][26];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0 ,1};
queue<pair<int,int>> Q;
vector<int> V;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, j;
    cin >> N;
    
    for(i=0;i<N;i++)
    	for(j=0;j<N;j++)
			cin >> board[i][j];
	
	int cnt=0;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			int area=0; 
			if(board[i][j]=='1'&&!vis[i][j]){
				vis[i][j]=1;
		   		Q.push({i,j});
			   	while (!Q.empty()) {
			   		area++;
				    auto cur = Q.front(); Q.pop();
				    for(int dir=0;dir<4;dir++){
				       	int nx=cur.X+dx[dir];
				       	int ny=cur.Y+dy[dir];
				       	if(nx<0||nx>=N||ny<0||ny>=N)continue;
				       	if(vis[nx][ny]||board[nx][ny]=='0')continue;
				       	vis[nx][ny]=1;
				       	Q.push({nx,ny});
					}
	    		}
	    		cnt++;
	    		V.push_back(area);
			}
		}
		sort(V.begin(),V.end());
		cout << cnt << '\n';
		for(auto a : V) cout << a << '\n';
}
