#include <bits/stdc++.h>
using namespace std;

void dfs(int now, vector<int>* edge, bool* visited) {
    visited[now] = true;
    
    for (int next : edge[now]) {
        if (!visited[next]) {
            dfs(next, edge, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<int> edge[201];
    bool visited[201] = { false, };
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && computers[i][j] == 1) {
                edge[i].push_back(j);
            }
        }
    }
    
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer += 1;
            dfs(i, edge, visited);
        }
    }
    
    return answer;
}