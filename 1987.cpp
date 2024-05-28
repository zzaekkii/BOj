#include <bits/stdc++.h>
using namespace std;

int R,C;
string board[21];
bool alph[26];
int ans;

int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

void Dfs(int x,int y,int cnt){
	ans=max(ans,cnt);
	for(int dir=0;dir<4;dir++){
		int nx=x+dx[dir];
		int ny=y+dy[dir];
		if(nx>=0&&nx<R&&ny>=0&&ny<C&&!alph[board[nx][ny]-65]){
			alph[board[nx][ny]-65]=1;
			Dfs(nx,ny,cnt+1);
			alph[board[nx][ny]-65]=0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	
	for(int i=0;i<R;i++)
		cin >> board[i];
	
	alph[board[0][0]-65]=1;
	Dfs(0,0,1);
	
	cout << ans;
}
