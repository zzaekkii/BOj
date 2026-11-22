#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> patterns = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    vector<int> scores(3, 0);
    
    int len = answers.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 3; j++) {
            if (answers[i] == patterns[j][i % patterns[j].size()]) {
                scores[j] += 1;
            }
        }
    }
    
    int max_score = *max_element(scores.begin(), scores.end());
    
    vector<int> answer;
    for (int j = 0; j < 3; j++) {
        if (scores[j] == max_score) {
            answer.emplace_back(j + 1);
        }
    }
    return answer;
}