#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    printf("%lld 3", (long long)(N-2)*(N-1)*N/6); // 시그마 합
}
