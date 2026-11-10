#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int cmp(int* a, int* b) {
	return *a - *b;
}

int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    
    for (int i = 0; i < sizes_rows; i++) {
        qsort(sizes[i], sizes_cols, sizeof(int), cmp);
    }
    
    int max_low = 0;
    int max_col = 0;
    for (int i = 0; i < sizes_rows; i++) {
        max_low = max(max_low, sizes[i][0]);
        max_col = max(max_col, sizes[i][1]);
    }
    
    return max_low * max_col;
}