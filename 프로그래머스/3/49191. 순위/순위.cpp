#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<bool>> win_graph(n + 1, vector<bool>(n + 1, false));
    
    for (auto result : results) {
        int winner = result[0];
        int loser = result[1];
        win_graph[winner][loser] = true;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int s = 1; s<= n; s++) {
            for (int e = 1; e<= n; e++) {
                if (win_graph[s][k] && win_graph[k][e]) {
                    win_graph[s][e] = true;
                }
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            
            if (win_graph[i][j] || win_graph[j][i]) {
                count += 1;
            }
        }
        
        if (count == n - 1) {
            answer += 1;
        }
    }
    
    return answer;
}