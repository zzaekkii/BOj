#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs_return_area_size(
    pair<int,int> cur,
    int visited[][501],
    const vector<vector<int>>& land
) {
    queue<pair<int,int>> q;
    q.push(cur);
    
    int area_size = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= land.size()
               || ny < 0 || ny >= land[0].size()) {
                continue;
            }
            
            if (visited[nx][ny] != -1 || land[nx][ny] == 0) {
                continue;
            }
            
            area_size += 1;
            q.push({nx,ny});
            visited[nx][ny] = visited[cur.X][cur.Y];
        }
    }
    
    return area_size;
}

// 번호-크기 -> 열
int solution(vector<vector<int>> land) {
    int area_num = 0;
    unordered_map<int,int> area_size;
    int visited[501][501];
    memset(visited, -1, sizeof(visited));
    
    int len = land.size();
    int wid = land[0].size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < wid; j++) {
            if (land[i][j] == 1 && visited[i][j] == -1) {
                visited[i][j] = area_num;
                area_size[area_num++] = bfs_return_area_size({i,j}, visited, land);
            }
        }
    }
    
    int answer = 0;
    for (int j = 0; j < wid; j++) {
        int col_area = 0;
        unordered_set<int> us;
        
        for (int i = 0; i < len; i++) {
            if (visited[i][j] != -1
               && us.find(visited[i][j]) == us.end()) {
                col_area += area_size[visited[i][j]];
                us.insert(visited[i][j]);
            }
        }
        
        answer = max(answer, col_area);
    }
    return answer;
}