#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
string board[1001];
int map[1000][1000];
int dx[]={0,1,1,1,0,-1,-1,-1},dy[]={-1,-1,0,1,1,1,0,-1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    for(int i=0;i<N;i++) cin >> board[i];
    
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]!='.'){
				cout << '*';
				continue;
			}
			int cnt=0;
			for(int k=0;k<8;k++){
				int nx=i+dx[k];
				int ny=j+dy[k];
				if(nx<0||nx>=N||ny<0||ny>=N)continue;
				if(board[nx][ny]=='.')continue;
				else cnt+=board[nx][ny]-48;
			}
			if(cnt>9) cout << 'M';
			else cout << cnt;
		}
		cout << '\n';
	}
}
