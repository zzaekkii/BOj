#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int R, C;

string board[1002];
int fire[1001][1001];
int jh[1001][1001];

queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;

int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, j;
    cin >> R >> C;

    for (i = 0; i < R; i++){
    	fill(fire[i],fire[i]+C,-1);
    	fill(jh[i],jh[i]+C,-1);
    	cin >> board[i];
    }
    
    for(i = 0; i < R; i++)
    	for(j = 0; j < C; j++){
    		if(board[i][j] == 'F'){
    			Q1.push({i, j});
    			fire[i][j] = 0;
			}
			if(board[i][j] == 'J'){
    			Q2.push({i, j});
    			jh[i][j] = 0;				
			}
		}

    while (!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            
            fire[nx][ny]=fire[cur.X][cur.Y]+1;
            Q1.push({nx, ny});
        }
    }
    
    while (!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C){ // 이 경우, 탈출 성공 
            	cout << jh[cur.X][cur.Y]+1;
            	return 0;
			}
            if (jh[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= jh[cur.X][cur.Y]+1) continue;
            // 이미 불 붙었거나, 전파 시간이 더 이르면 패스 
            jh[nx][ny]=jh[cur.X][cur.Y]+1;
            Q2.push({nx, ny});
        }
    }    
    cout << "IMPOSSIBLE";
}
