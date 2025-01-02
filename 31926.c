// 31926번 밤양갱 - 실버1 / #그리디 #애드혹
#include <stdio.h>

int N;

int main() {
    scanf("%d", &N);

    long long ans = 10;
    while (N > 1) {
        N /= 2;
        ans++;
    }

    printf("%lld\n", ans);
}
