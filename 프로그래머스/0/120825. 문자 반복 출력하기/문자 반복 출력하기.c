#include <string.h>
#include <stdlib.h>

char* solution(const char* my_string, int n) {
    int len = strlen(my_string);
    char* answer = (char*)calloc(len * n + 1, sizeof(char));
    answer[len] = 0;
    
    int idx = 0;
    for (int i = 0; i < len; i++) {
        for (int r = 0; r < n; r++) {
            answer[idx++] = my_string[i];
        }
    }
    
    return answer;
}