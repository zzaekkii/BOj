#include <bits/stdc++.h>
using namespace std;

int N,M;
string board[1001];
int dp[1001][1001][2];

int dx[]={0,1,0,-1},dy[]={-1,0,1,0};

queue<tuple<int,int,bool>> Q;

int Bfs(){
	Q.push(make_tuple(0,0,0));
	dp[0][0][0]=1;
	
	while(!Q.empty()){
		int curX,curY,pch;
		tie(curX,curY,pch)=Q.front(); Q.pop();
		
		if(curX==N-1&&curY==M-1)return dp[curX][curY][pch];
		
		for(int dir=0;dir<4;dir++){
			int nx=curX+dx[dir];
			int ny=curY+dy[dir];
			
			if(nx>=0&&nx<N&&ny>=0&&ny<M){
				if(board[nx][ny]==48&&!dp[nx][ny][pch]){
					dp[nx][ny][pch]=dp[curX][curY][pch]+1;
					Q.push(make_tuple(nx,ny,pch));
				}
				
				if(board[nx][ny]==49&&!pch){
					dp[nx][ny][1]=dp[curX][curY][pch]+1;
					Q.push(make_tuple(nx,ny,1));
				}
			}
		}
	}
	
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
		cin >> board[i];
	
	cout << Bfs();
}
