#include <bits/stdc++.h>
#define MAX_TOPPING 10'001
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int len = topping.size();
    
    int left_total = 0;
    int right_total = 0;
    
    int left_topping[MAX_TOPPING] = { 0 };
    int right_topping[MAX_TOPPING] = { 0 };
    
    // 유니크 토핑 췌크
    left_total += 1;
    left_topping[topping[0]] = 1;
    
    for (int i = 1; i < len; i++) {
        int cur = topping[i];
        right_topping[cur] += 1;
        
        if (right_topping[cur] == 1) {
            right_total += 1;
        }
    }
    
    if (left_total == right_total) {
        answer += 1;
    }
    
    // 자리 옮기기 시작
    for (int i = 1; i < len - 1; i++) {
        int cur = topping[i];
        
        right_topping[cur] -= 1;
        if (right_topping[cur] == 0) {
            right_total -= 1;
        }
        
        left_topping[cur] += 1;
        if (left_topping[cur] == 1) {
            left_total += 1;
        }
        
        if (left_total == right_total) {
            answer += 1;
        }
    }
    
    return answer;
}