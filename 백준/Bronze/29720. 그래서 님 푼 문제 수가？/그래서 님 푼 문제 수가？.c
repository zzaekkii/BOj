#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int N, M, K;
int mn, mx;

int main() {
    scanf("%d %d %d", &N, &M, &K);
    
    mn = max(0, N - M * K);
    mx = max(mn, N - M * (K - 1) - 1);
    
    printf("%d %d", mn, mx);
}