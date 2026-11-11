
#include <bits/stdc++.h>
#define X first
#define Y second
#define UNREACHED -1
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();

    int dist[101][101];
    memset(dist, -1, sizeof(dist));

    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                start = {i, j};
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    dist[start.X][start.Y] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (board[cur.X][cur.Y] == 'G') {
            return dist[cur.X][cur.Y];
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X;
            int ny = cur.Y;

            while (true) {
                int tx = nx + dx[dir];
                int ty = ny + dy[dir];

                if (tx < 0 || tx >= n ||
                    ty < 0 || ty >= m ||
                    board[tx][ty] == 'D') {
                    break;
                }

                nx = tx;
                ny = ty;
            }

            if (dist[nx][ny] != UNREACHED) {
                continue;
            }

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    return -1;
}
