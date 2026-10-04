#include <stdio.h>

int solution(int slice, int n) {
    return n / slice + (n % slice != 0);
}