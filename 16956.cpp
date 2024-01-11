#include <bits/stdc++.h>
using namespace std;

int R,C;
string board[501];
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    
    for(int i=0;i<R;i++)
    	cin >> board[i];
    
    for(int i=0;i<R;i++)
    	for(int j=0;j<C;j++)
    		if(board[i][j]=='W'){
	    	for(int dir=0;dir<4;dir++){
	    		int nx=i+dx[dir];
	    		int ny=j+dy[dir];
	    		if(nx<0||nx>=R||ny<0||ny>=C)continue;
	    		if(board[nx][ny]=='S'){
	    			cout << 0;
	    			return 0;
				}
				if(board[nx][ny]=='.')
					board[nx][ny]='D';
		}
    		}
    
	cout << 1 << '\n';
	for(int i=0;i<R;i++)
		cout << board[i] << '\n';
}
