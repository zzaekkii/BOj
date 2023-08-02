#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;
bool board[101][101];
int air[101][101];
bool vis[101][101];
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
queue<pair<int,int>> Q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, j, sec=0;
    cin >> N >> M;

    for(i=0;i<N;i++)
    	for(j=0;j<M;j++)
    		cin >> board[i][j];

    while(1){
    	int cnt=0;
    	fill_n(&vis[0][0],101*101,0);
    	fill_n(&air[0][0],101*101,0);
		
		Q.push({0,0}); // 가장자리 공기 주입.		
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			if(vis[cur.X][cur.Y])continue;
			vis[cur.X][cur.Y]=1;
			for(int dir=0;dir<4;dir++){
			   	int nx=cur.X+dx[dir];
			   	int ny=cur.Y+dy[dir];
			   	if(nx<0||nx>=N||ny<0||ny>=M)continue;
			   	if(board[nx][ny])air[nx][ny]++;
			   	else if(!vis[nx][ny])Q.push({nx,ny});
			}
		}
		
		for(i=0;i<N;i++)
			for(j=0;j<M;j++){
				if(air[i][j]>1){
					board[i][j]=0;
					cnt++;
				}
			}
			
		if(!cnt){cout << sec; break;} // No Cheese, No loop. 
		else sec++;
	}
}
