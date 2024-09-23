#include <bits/stdc++.h>
using namespace std;

int N,M;
string board[51];
bool vis[51][51];
int cnt;
 
bool st; // 0: - 가로, 1: | 세로. 
char sh[3]={'-','|'}; // 실제 모양 콜렉션. 

void Dfs(int x,int y){
	if(x==N||y==M||sh[st]!=board[x][y]){
		cnt++;
		return;
	}
	
	vis[x][y]=1;
	if(st){ // 세로 모양이면, 아래로. 
		if(x<N)Dfs(x+1,y);
	} else { // 가로 모양이면, 오른쪽으로. 
		if(y<M)Dfs(x,y+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
		cin >> board[i];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			if(!vis[i][j]){
				if(board[i][j]=='|')st=1;
				else st=0;
				Dfs(i,j);
			}
		}
	
	cout << cnt;
}
