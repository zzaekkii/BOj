#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	printf("%lld\n%d", (long long)N * (N - 1) / 2, 2);
}