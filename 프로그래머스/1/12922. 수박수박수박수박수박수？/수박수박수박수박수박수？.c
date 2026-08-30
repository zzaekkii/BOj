#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* solution(int n) {
    char* answer = (char*)malloc(n * 3 + 1);
    answer[0] = 0;
    
    for (int i = 0; i < n; i++) {
        strcat(answer, i % 2 ? "박" : "수");
    }
    
    return answer;
}