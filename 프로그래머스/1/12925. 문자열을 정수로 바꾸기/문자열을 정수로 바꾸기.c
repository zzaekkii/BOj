#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    _Bool is_min = 0;
    
    for (int i = 0; s[i]; i++) {
        if (s[i] < 48) {
            if (s[i] == '-') {
                is_min = 1;
            }
            continue;
        }
        
        answer = answer * 10 + (s[i] - 48);
    }
    
    if (is_min) {
        answer *= -1;
    }
    
    return answer;
}