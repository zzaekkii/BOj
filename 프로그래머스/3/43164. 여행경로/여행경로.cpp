#include <bits/stdc++.h>
using namespace std;

bool dfs(
    const string& cur,
    int count,
    int total,
    map<string, vector<pair<string,int>>>& adj,
    vector<bool>& visited,
    vector<string>& path
) {
    if (count == total) {
        return true;
    }
    
    for (auto& [nxt, idx] : adj[cur]) {
        if (visited[idx]) {
            continue;
        }
        
        visited[idx] = true;
        path.push_back(nxt);
        
        if (dfs(nxt, count + 1, total, adj, visited, path)) {
            return true;
        }
        
        path.pop_back();
        visited[idx] = false;
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    int n = tickets.size();
    
    map<string,vector<pair<string,int>>> adj;
    vector<bool> visited(n, false);
    vector<string> path = { "ICN" };
    
    for (int i = 0; i < n; i++) {
        adj[tickets[i][0]].push_back({tickets[i][1], i});
    }
    
    for (auto& [from, edges] : adj) {
        sort(edges.begin(), edges.end());
    }
    
    dfs("ICN", 0, n, adj, visited, path);
    
    return path;
}