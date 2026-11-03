#include <bits/stdc++.h>
using namespace std;

int get_diff(const string& a, const string& b) {
    int count = 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            count++;
        }
    }
    
    return count;
}


int solution(string begin, string target, vector<string> words) {
    int n = words.size();
    words.push_back(begin);
    
    vector<bool> visited(n + 1, false);
    queue<pair<int,int>> q;
    
    q.push({n, 0});
    visited[n] = true;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        string cur_word = words[cur.first];
        int cur_depth = cur.second;
        
        if (cur_word == target) {
            return cur_depth;
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && get_diff(cur_word, words[i]) == 1) {
                q.push({i, cur_depth + 1});
                visited[i] = true;
            }
        }
    }
    
    return 0;
}