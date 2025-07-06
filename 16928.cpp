// 16928번 뱀과 사다리 게임 - 골드5 / BFS
#include <bits/stdc++.h>
using namespace std;

int N, M, U, V;
int board[101]; 
int vis[101];

queue<int> Q;
int dx[]={1,2,3,4,5,6};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i<=100;i++)vis[i]=-1;
    cin >> N >> M;
    
    while(N--){
    	cin >> U >> V;
    	board[U]=V;
	}
	
	while(M--){
		cin >> U >> V;
		board[U]=V;
	} 
	
	Q.push(1);
	while(!Q.empty()){
		int cur=Q.front(); Q.pop();
		
		for(int dice=0;dice<6;dice++){
			int nxt=cur+dx[dice];
			
			if(nxt<=100){
				if(!board[nxt]){ // 일반칸. 
					if(vis[nxt]==-1){ // 처음. 
						Q.push(nxt);
						vis[nxt]=vis[cur]+1;
					}
					else if(vis[nxt]>vis[cur]+1){ // 이전보다 빠름.
						Q.push(nxt);
						vis[nxt]=vis[cur]+1;
					}
				}
				else{ // 사다리 or 뱀. 
					nxt=board[nxt];
					
					if(vis[nxt]==-1){
						Q.push(nxt);
						vis[nxt]=vis[cur]+1;
					}
					else if(vis[nxt]>vis[cur]+1){
						Q.push(nxt);
						vis[nxt]=vis[cur]+1;
					}
				}
			}
		}
	}
	
	cout << vis[100];
}
