#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    if (a > b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    long long answer = 0;
    while (a <= b) {
        answer += a;
        a += 1;
    }
    return answer;
}