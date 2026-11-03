#include <bits/stdc++.h>
#define MAX 102
using namespace std;

int dx_8[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy_8[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int dx_4[] = {0, 1, 0, -1};
int dy_4[] = {-1, 0, 1, 0};

bool is_outline(int x, int y, int board[][MAX]) {
    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx_8[dir];
        int ny = y + dy_8[dir];
        
        if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) {
            continue;
        }
        
        if (board[nx][ny] == -1) {
            return true;
        }
    }
    
    return false;
}


int solution(
    vector<vector<int>> rectangle,
    int characterX, int characterY,
    int itemX, int itemY
) {
    int board[MAX][MAX] = { 0 };
    memset(board, -1, sizeof(board));
    
    characterX *= 2;
    characterY *= 2;
    
    itemX *= 2;
    itemY *= 2;
    
    for (auto r : rectangle) {
        int st_x = r[0] * 2, st_y = r[1] * 2;
        int en_x = r[2] * 2, en_y = r[3] * 2;
        
        for (int i = st_x; i <= en_x; i++) {
            for (int j = st_y; j <= en_y; j++) {
                board[i][j] = 0;
            }
        }
    }
    
    queue<pair<int,int>> q;
    q.push({characterX, characterY});
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur_x + dx_4[dir];
            int ny = cur_y + dy_4[dir];
            
            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) {
                continue;
            }
            
            if (!(nx == characterX && ny == characterY)
                    && is_outline(nx, ny, board)
                    && board[nx][ny] == 0) {
                q.push({nx,ny});
                board[nx][ny] = board[cur_x][cur_y] + 1;
            }
        }
    }
    
    return board[itemX][itemY] / 2;
}