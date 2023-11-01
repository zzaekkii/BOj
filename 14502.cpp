#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

bool vis[9][9];
int board[9][9];
int w;
int N, M;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
vector<pair<int,int>> virus;
vector<pair<int,int>> V;
queue<pair<int,int>> Q;
int ans;

int bfs(){
	memset(vis,0,sizeof(vis));
	int cnt=0;
	
	for(;cnt<virus.size();cnt++)
		Q.push({virus[cnt].X,virus[cnt].Y});
	
	while(!Q.empty()){
		auto cur=Q.front();Q.pop();
		for(int i=0;i<4;i++){
			int nx=cur.X+dx[i];
			int ny=cur.Y+dy[i];
			
			if(nx<0||nx>=N||ny<0||ny>=M)continue;
			if(vis[nx][ny]||board[nx][ny])continue;
			Q.push({nx,ny});
			vis[nx][ny]=1;
			cnt++;
		}
	}
	return N*M-(cnt+w+3);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++)
    	for(int j=0;j<M;j++){
    		cin >> board[i][j];
    		switch(board[i][j]){
    			case 0: V.push_back({i,j});break;
    			case 1: w++;break;
    			case 2: virus.push_back({i,j});break;
			}
		}
	
	int l=V.size();
	for(int i=0;i<l;i++)
		for(int j=i+1;j<l;j++)
			for(int k=j+1;k<l;k++){
				board[V[i].X][V[i].Y]=1;
				board[V[j].X][V[j].Y]=1;
				board[V[k].X][V[k].Y]=1;
				
				ans=max(ans,bfs());
				
				board[V[i].X][V[i].Y]=0;
				board[V[j].X][V[j].Y]=0;
				board[V[k].X][V[k].Y]=0;
			}
			    
    cout << ans;
}
