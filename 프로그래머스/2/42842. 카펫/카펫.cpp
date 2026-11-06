#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 1; i <= yellow; i++) {
        if (yellow % i != 0) {
            continue;
        }
        
        int width = yellow / i;
        int length = i;
        
        int result = width * 2 + length * 2 + 4;
        if (result == brown) {
            answer.emplace_back(width + 2);
            answer.emplace_back(length + 2);
            break;
        }
    }
    
    return answer;
}