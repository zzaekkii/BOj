#include <stdio.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int max1 = 0, max2 = 0;
    for (int i = 0; i < numbers_len; i++) {
        int cur = numbers[i];
        
        if (cur > max1) {
            max2 = max1;
            max1 = cur;
        } else if (cur > max2) {
            max2 = cur;
        }
    }
    
    return max1 * max2;
}