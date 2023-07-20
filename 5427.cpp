#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int T, W, H;
string board[1002];
int fire[1001][1001];
int sg[1001][1001];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0 ,1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, j;
    cin >> T;
    
    while(T--){
		queue<pair<int, int>> Q1; // 불. 
		queue<pair<int, int>> Q2; // 상근. 
		
    	cin >> W >> H;
    	
    	for (i = 0; i < H; i++){ // 배열 초기화 & 입력받기. 
	    	fill(fire[i],fire[i]+W,-1);
	    	fill(sg[i],sg[i]+W,-1);
	    	cin >> board[i];
	    }
	    
	    for(i = 0; i < H; i++)
	    	for(j = 0; j < W; j++)
	    		if(board[i][j] == '*'){ // 불.
	    			Q1.push({i, j});
	    			fire[i][j] = 0;
				}
				else if(board[i][j] == '@'){ // 상근스. 
	    			Q2.push({i, j});
	    			sg[i][j] = 0;				
				} 
    	
		while(!Q1.empty()){
			auto cur = Q1.front(); Q1.pop();
			
	        for (int dir = 0; dir < 4; dir++) {
	            int nx = cur.X + dx[dir];
	            int ny = cur.Y + dy[dir];
				
	            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
	            if (fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
	            
	            fire[nx][ny]=fire[cur.X][cur.Y]+1;
	            Q1.push({nx, ny});
	        }
		}
		
    	bool flag = 1;
    	while (flag&&!Q2.empty()) {
	        auto cur = Q2.front(); Q2.pop();
	        for (int dir = 0; dir < 4; dir++) {
	            int nx = cur.X + dx[dir];
	            int ny = cur.Y + dy[dir];
	
	            if (nx < 0 || nx >= H || ny < 0 || ny >= W){ // 탈출 성공 
	            	cout << sg[cur.X][cur.Y]+1 << '\n';
	            	flag=0;
	            	break;
				}
	            if (sg[nx][ny] >= 0 || board[nx][ny] == '#') continue;
	            if (fire[nx][ny] != -1 && fire[nx][ny] <= sg[cur.X][cur.Y]+1) continue;
	            // 이미 불 붙었거나, 전파 시간이 더 이르면 패스 
	            sg[nx][ny]=sg[cur.X][cur.Y]+1;
	            Q2.push({nx, ny});
        	}
    	}
    	
    	if(flag) cout << "IMPOSSIBLE\n";
	}
}
