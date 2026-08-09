#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int get_size(long long n) {
    int size = 1;
    
    while (n >= 10) {
        size += 1;
        n /= 10;
    }
    
    return size;
}

int* solution(long long n) {
    int size = get_size(n);
    int* answer = (int*)calloc(size, 4);
    
    for (int i = 0; n > 0; i++) {
        answer[i] = n % 10;
        n /= 10;
    }
    
    return answer;
}
