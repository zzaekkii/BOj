#include <stdlib.h>

int* solution(int num_list[], size_t num_list_len) {
    int* answer = (int*)calloc(2, sizeof(int));
    
    for (int i = 0; i < num_list_len; i++) {
        answer[num_list[i] % 2] ++;
    }
    
    return answer;
}