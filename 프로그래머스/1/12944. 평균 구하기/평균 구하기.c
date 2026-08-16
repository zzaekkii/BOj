#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

double solution(int arr[], size_t arr_len) {
    int sum = 0;
    
    for (int i = 0; i < arr_len; i++) {
        sum += arr[i];
    }
    
    double answer = (double)sum / arr_len;
    
    return answer;
}