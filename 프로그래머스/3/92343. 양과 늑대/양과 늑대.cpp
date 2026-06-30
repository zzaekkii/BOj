#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<int> node_info;
int answer = 0;

void dfs(int sheep, int wolf, vector<int> nexts) {
    answer = max(answer, sheep);
    
    for (int i = 0; i < nexts.size(); i++) {
        int cur = nexts[i];
        
        int next_sheep = sheep;
        int next_wolf = wolf;
        
        if (node_info[cur] == 0) {
            next_sheep += 1;
        } else {
            next_wolf += 1;
        }
        
        if (next_wolf >= next_sheep) {
            continue;
        }
        
        // 지금 양 삭제
        vector<int> new_nexts = nexts;
        new_nexts[i] = new_nexts.back();
        new_nexts.pop_back();
        
        for (int next : tree[cur]) {
            new_nexts.emplace_back(next);
        }
        
        dfs(next_sheep, next_wolf, new_nexts);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    node_info = info;
    tree.assign(info.size(), {});
    
    for (auto edge : edges) {
        tree[edge[0]].emplace_back(edge[1]);
    }
    
    vector<int> nexts;
    for (int next : tree[0]) {
        nexts.emplace_back(next);
    }
    
    dfs(1, 0, nexts);
    
    return answer;
}