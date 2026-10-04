#include <string.h>
#include <stdlib.h>

char* solution(const char* my_string, const char* letter) {
    int len = strlen(my_string);
    
    int idx = 0;
    char* answer = (char*)malloc(len + 1);
    
    for (int i = 0; i < len; i++) {
        if (my_string[i] != letter[0]) {
            answer[idx++] = my_string[i];
        }
    }
    
    answer[idx] = 0;
    
    return answer;
}