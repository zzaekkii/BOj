#include <bits/stdc++.h>
#define X first
#define Y second
#define MAX 101
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(
    queue<pair<int,int>>& q,
    int (&dist)[MAX][MAX],
    const vector<string>& maps
) {
    int n = maps.size();
    int m = maps[0].size();
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            
            if (dist[nx][ny] == -1 && maps[nx][ny] != 'X') {
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx,ny});
            }
        }
    }
}

int solution(vector<string> maps) {
    // 지도 위 기물 위치 파악
    int n = maps.size();
    int m = maps[0].size();
    
    pair<int,int> start;
    pair<int,int> lever;
    pair<int,int> goal;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            switch (maps[i][j]) {
                case 'S' :
                    start = {i,j};
                    break;
                case 'L' :
                    lever = {i,j};
                    break;
                case 'E' :
                    goal = {i,j};
                    break;
            }
        }
    }
    
    
    // 시작 -> 레버 탐색
    queue<pair<int,int>> q;
    int dist[MAX][MAX];
    memset(dist, -1, sizeof(dist));
    
    q.push(start);
    dist[start.X][start.Y] = 0;
    
    bfs(q, dist, maps);
    
    int lever_dist = dist[lever.X][lever.Y];
    if (lever_dist == -1) {
        return -1;
    }
    
    
    // 레버 -> 출구
    memset(dist, -1, sizeof(dist));
    dist[lever.X][lever.Y] = 0;
    q.push(lever);
    
    bfs(q, dist, maps);
    
    int goal_dist = dist[goal.X][goal.Y];
    if (goal_dist == -1) {
        return -1;
    }
    
    
    return lever_dist + goal_dist;
}