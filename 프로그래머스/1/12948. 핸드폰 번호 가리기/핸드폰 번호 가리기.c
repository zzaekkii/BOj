#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* solution(const char* phone_number) {
    int length = strlen(phone_number);
    char* answer = (char*)calloc(length + 1, sizeof(char));
    
    for (int i = 0; i < length - 4; i++) {
        answer[i] = '*';
    }
    
    for (int i = length - 4; i < length; i++) {
        answer[i] = phone_number[i];
    }
    
    return answer;
}