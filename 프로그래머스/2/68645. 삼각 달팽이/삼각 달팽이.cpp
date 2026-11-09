#include <bits/stdc++.h>
#define MOD 3

using namespace std;

int dx[] = {1, 0, -1};
int dy[] = {0, 1, -1};

vector<int> solution(int n) {
    vector<vector<int>> snail(n);
    for (int i = 0; i < n; i++) {
        snail[i].resize(i + 1);
    }

    int x = -1;
    int y = 0;
    
    int cur = 1;
    
    for (int i = 0; i < n; i++) {
        int dir = i % MOD;
        
        for (int j = 0; j < n - i; j++) {
            x += dx[dir];
            y += dy[dir];
            
            snail[x][y] = cur++;
        }
    }
    
    
    vector<int> answer;
    answer.reserve(n * (n - 1) / 2);
    
    for (const auto& row : snail) {
        for (int num : row) {
            answer.emplace_back(num);
        }
    }

    return answer;
}