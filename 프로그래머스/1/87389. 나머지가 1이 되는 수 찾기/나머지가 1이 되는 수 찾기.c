#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 1;
    
    while (n % answer != 1) {
        answer += 1;
    }
    
    return answer;
}