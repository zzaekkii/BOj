#include <bits/stdc++.h>
using namespace std;

int N;
bool board[11][11];
bool l_vis[21],r_vis[21]; // 뾰족네모.
int ans;

void Dfs(int idx,int cnt){
	if(idx==N*2-1){
		ans=max(ans,cnt);
		return;
	}
	bool ex=1;
	
	for(int i=0;i<N-abs(idx-(N-1));i++){
		int x=idx<N?idx-i:N-1-i;
		int y=idx<N?i:idx-(N-1)+i;
		if(board[x][y]&&!l_vis[N-1+(x-y)]&&!r_vis[idx]){
			ex=0;
			l_vis[N-1+(x-y)]=r_vis[idx]=1;
			Dfs(idx+1,cnt+1);
			l_vis[N-1+(x-y)]=r_vis[idx]=0;
		}
	}
	if(ex)Dfs(idx+1,cnt);		
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> board[i][j];
	
	Dfs(0,0);
	
	cout << ans;
}
