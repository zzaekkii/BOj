#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    char c1 = *(const char*)a;
    char c2 = *(const char*)b;

    return c2 - c1;
}

char* solution(const char* s) {
    int len = strlen(s);
    char* answer = (char*)malloc(len + 1);
    strcpy(answer, s);

    qsort(answer, len, sizeof(char), cmp);
    
    return answer;
}