#include <bits/stdc++.h>
#define MAX_STICKER 101
#define MAX_BOARD 41
using namespace std;

int n, m, k;
vector<vector<vector<bool>>> stickers(MAX_STICKER);
vector<vector<bool>> board;

vector<vector<bool>> rotate_sticker(const vector<vector<bool>>& origin) {
    vector<vector<bool>> result;
    
    int n = origin.size();
    int m = origin[0].size();
    
    result.resize(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i].push_back(origin[n - 1 - j][i]);
        }
    }
    
    return result;
}

bool can_attach(int row, int col, const vector<vector<bool>>& sticker) {
    int len = sticker.size();
    int wid = sticker[0].size();
    
    bool flag = true;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < wid; j++) {
            if (sticker[i][j] && board[row + i][col + j]) {
                flag = false;
                break;
            }
        }
        
        if (!flag) {
            break;
        }
    }
    
    if (!flag) {
        return false;
    }
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < wid; j++) {
            if (sticker[i][j]) {
                board[row + i][col + j] = true;
            }
        }
    }
    return true;
}

bool attached(const vector<vector<bool>>& sticker) {
    int len = sticker.size();
    int wid = sticker[0].size();
    
    if (n < len || m < wid) return false;
    
    bool attachable = false;
    for (int i = 0; i <= n - len; i++) {
        for (int j = 0; j <= m - wid; j++) {
            if (can_attach(i, j, sticker)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    
    board.resize(n);
    for (int i = 0; i < n; i++) {
        board[i].resize(m);
    }
    
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        
        stickers[i].resize(row, vector<bool>(col));
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                int x;
                cin >> x;
                
                stickers[i][r][c] = (x == 1);
            }
        }
    }
    
    // 스티커 차례대로 붙이기
    for (int i = 0; i < k; i++) {
        vector<vector<bool>> sticker = stickers[i];
        
        for (int dir = 0; dir < 4; dir++) {
            if (attached(sticker)) {
                break;
            }
            
            sticker = rotate_sticker(sticker);
        }
    }
    
    // 영역 카운트
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j]) count += 1;
        }
    }
    
    cout << count;
}
