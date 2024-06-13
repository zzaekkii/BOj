#include <bits/stdc++.h>
using namespace std;

int N;
int board[21][21];
int ans;

void Merge(int dir){
	queue<int> Q;
	
	switch(dir){
		case 0: // 상.
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if(board[j][i])
						Q.push(board[j][i]);
					board[j][i]=0;
				}
				int nx=0;
				while(!Q.empty()){
					int cur=Q.front(); Q.pop();
					
					if(!board[nx][i]) // 채우기. 
						board[nx][i]=cur;
					else if(board[nx][i]==cur){ // 합치기. 
						board[nx][i]*=2;
						nx++;
					}
					else{ // 넘어가 채우기. 
						nx++;
						board[nx][i]=cur; 
					}
				}
			}
			break;
		case 1: // 우.
			for(int i=0;i<N;i++){
				for(int j=N-1;j>=0;j--){
					if(board[i][j])
						Q.push(board[i][j]);
					board[i][j]=0;
				}
				int ny=N-1;
				while(!Q.empty()){
					int cur=Q.front(); Q.pop();
					
					if(!board[i][ny])
						board[i][ny]=cur;
					else if(board[i][ny]==cur){
						board[i][ny]*=2;
						ny--;
					}
					else{
						ny--;
						board[i][ny]=cur;
					}
				}
			}
			break;
		case 2: // 하.
			for(int i=0;i<N;i++){
				for(int j=N-1;j>=0;j--){
					if(board[j][i])
						Q.push(board[j][i]);
					board[j][i]=0;
				}
				int nx=N-1;
				while(!Q.empty()){
					int cur=Q.front(); Q.pop();
					
					if(!board[nx][i])
						board[nx][i]=cur;
					else if(board[nx][i]==cur){
						board[nx][i]*=2;
						nx--;
					}
					else{
						nx--;
						board[nx][i]=cur;
					}
				}
			}
			break;
		case 3: // 좌.
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if(board[i][j])
						Q.push(board[i][j]);
					board[i][j]=0;
				}
				int ny=0;
				while(!Q.empty()){
					int cur=Q.front(); Q.pop();
					
					if(!board[i][ny])
						board[i][ny]=cur;
					else if(board[i][ny]==cur){
						board[i][ny]*=2;
						ny++;
					}
					else{
						ny++;
						board[i][ny]=cur;
					}
				}
			}
			break;
	}
}

void Dfs(int cnt){
	if(cnt==5)return;
	
	int tmp[21][21];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			tmp[i][j]=board[i][j];
	
	for(int dir=0;dir<4;dir++){
		Merge(dir);
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(board[i][j]>ans)ans=board[i][j];
		
		Dfs(cnt+1);
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				board[i][j]=tmp[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> board[i][j];
	
	Dfs(0);
	
	cout << ans;
}
