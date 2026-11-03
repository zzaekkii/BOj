#include <bits/stdc++.h>
using namespace std;

void dfs(
    int idx,
    int sign,
    int sum,
    const int& target,
    int& count,
    vector<int>& numbers
) {
    sum += numbers[idx] * sign;
    
    if (idx == numbers.size() - 1) {
        if (sum == target) {
            count += 1;
        }
        
        return;
    }
    
    dfs(idx + 1, 1, sum, target, count, numbers);
    dfs(idx + 1, -1, sum, target, count, numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, 1, 0, target, answer, numbers);
    dfs(0, -1, 0, target, answer, numbers);
    
    return answer;
}