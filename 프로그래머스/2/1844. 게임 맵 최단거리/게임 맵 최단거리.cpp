#include <bits/stdc++.h>
#define X first
#define Y second
#define MAX 101

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    int dist[MAX][MAX];
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    
    q.push({0, 0});
    dist[0][0] = 1;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int cur_x = cur.X;
        int cur_y = cur.Y;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            
            if (maps[nx][ny] == 0 || dist[nx][ny] != -1) {
                continue;
            }
            
            dist[nx][ny] = dist[cur_x][cur_y] + 1;
            q.push({nx, ny});
        }
    }
    
    return dist[n - 1][m - 1];
}