#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* solution(const char* s) {
    int len = strlen(s);
    char* answer = (char*)malloc(len + 1);
    strcpy(answer, s);
    
    int idx = 0;
    for (int i = 0; i < len; i++, idx++) {
        if (s[i] == ' ') {
            idx = -1;
            continue;
        }
        
        if (idx % 2) {
            if (s[i] < 'a') {
                answer[i] += 32;
            }
        }
        else {
            if (s[i] > 'Z') {
                answer[i] -= 32;
            }
        }
    }
    
    return answer;
}