#include <bits/stdc++.h>
using namespace std;

void dfs(
    int idx,
    int sum,
    const int& target,
    int& count,
    vector<int>& numbers
) {
    if (idx == numbers.size()) {
        if (sum == target) {
            count += 1;
        }
        
        return;
    }
    
    dfs(idx + 1, sum + numbers[idx], target, count, numbers);
    dfs(idx + 1, sum - numbers[idx], target, count, numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(1, numbers[0], target, answer, numbers);
    dfs(1, -numbers[0], target, answer, numbers);
    
    return answer;
}