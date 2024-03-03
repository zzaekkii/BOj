#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
int cnt=1;
int board[126][126];
int zelda[126][126];

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
queue<pair<int,int>> Q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while(1){
    	cin >> N;
    	if(!N)break;
    	
    	for(int i=0;i<N;i++)
    		for(int j=0;j<N;j++)
    			cin >> board[i][j];
    			
   	  fill_n(zelda[0],126*126,200000);
    	
    	Q.push({0,0});
    	zelda[0][0]=board[0][0];
    	
    	while(!Q.empty()){
    		auto cur=Q.front(); Q.pop();
    		for(int i=0;i<4;i++){    			
				int nx=cur.X+dx[i];
				int ny=cur.Y+dy[i];
				
				if(nx>=0&&nx<N&&ny>=0&&ny<N)
					if(zelda[nx][ny]>zelda[cur.X][cur.Y]+board[nx][ny]){
						Q.push({nx,ny});
						zelda[nx][ny]=zelda[cur.X][cur.Y]+board[nx][ny];
					}
			}
		}
    	
    	cout << "Problem " << cnt++ << ": " << zelda[N-1][N-1] << '\n';
	}
}
