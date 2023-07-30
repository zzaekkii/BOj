#include <bits/stdc++.h>
using namespace std;
int L, R, C;

char board[31][31][31];
int vis[31][31][31];
int dx[]={-1,0,1,0,0,0},dy[]={0,-1,0,1,0,0},dz[]={0,0,0,0,-1,1};
queue<tuple<int,int,int>> Q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, j, k;
    
    while(1){
    	int w, x, z;
    	fill_n(&vis[0][0][0],31*31*31,-1);
    	cin >> L >> R >> C;
    	if (L == 0 && R == 0 && C == 0) return 0;
    	for (i = 0; i < L; i++)
	        for (j = 0; j < R; j++)
	            for (k = 0; k < C; k++){
	                cin >> board[i][j][k];
	                if (board[i][j][k] == 'S'){
	                    Q.push(make_tuple(i,j,k));
	                    vis[i][j][k]=0;
	                }
	                if (board[i][j][k] == 'E')
	                	w=i,x=j,z=k;
	    		}
		
		 while (!Q.empty()) {
	        auto cur = Q.front(); Q.pop();
	        int curX, curY, curZ;
	        tie(curX, curY, curZ) = cur;
	        for (int dir = 0; dir < 6; dir++) {
	            int nx = curX + dx[dir];
	            int ny = curY + dy[dir];
	            int nz = curZ + dz[dir];
	
	            if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C) continue;
	            if (vis[nx][ny][nz] >= 0||board[nx][ny][nz]=='#') continue;
	            vis[nx][ny][nz] = vis[curX][curY][curZ] + 1;
	            Q.push(make_tuple(nx, ny, nz));
	        }
    	}
    	    	
    	if(vis[w][x][z]==-1) cout << "Trapped!\n";
    	else cout << "Escaped in " << vis[w][x][z] << " minute(s).\n";
	}
}
