#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    int len = strlen(s);
    int size = (len % 2) ? 1 : 2;    
    char* answer = (char*)malloc(size + 1);
    
    int mid = (len - size) / 2;
    memcpy(answer, s + mid, size);
    answer[size] = 0;
    
    return answer;
}