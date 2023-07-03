#include <stdio.h>
#include <math.h>

int main() {
	int N, p = 0;
	long long ans = 0; // int 범위를 벗어날 수 있음.
	scanf("%d", &N);

	while (N >= 9 * pow(10, p)) { // 규칙: 9*10의 i제곱 만큼 빼면 됨.
		ans += 9 * pow(10, p)*(p+1); // 자리수: p+1
		N -= 9 * pow(10, p++);
	}

	printf("%lld", ans + N*(p+1));
}