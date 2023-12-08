#include <bits/stdc++.h>
using namespace std;
int R,S,m=3000;
string board[3001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> S;
	for(int i=0;i<R;i++)
		cin >> board[i];
	
	for(int j=0;j<S;j++){
		int cnt=0;
		for(int i=R-1;i>=0;i--){
			if(board[i][j]=='X')break;
			if(board[i][j]=='.')cnt++;
		}
		if(m>cnt)m=cnt;
	}
	
	for(int i=R-1;m&&(i>=0);i--)
		for(int j=0;j<S;j++){
			if(board[i][j]=='X'){
				board[i+m][j]='X';
				board[i][j]='.';
			}
		}		
	
	for(int i=0;i<R;i++)
		cout << board[i] << '\n';
}
