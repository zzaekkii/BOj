// 10211번 Maximum Subarray - 실버4 / #누적합, #메모이제이션
#include <stdio.h>

int T, N, X; // 테스트 T개, 배열 크기 N, 입력 X.
int mx; // 최댓값.

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		int mx = -10000; // MIN.
		int sum = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &X);

			// X가 더 크냐.
			// sum+X가 더 크냐.
			// mx가 더 크냐?
			if (X > sum + X)sum = X;
			else sum += X;

			if (mx < sum)mx = sum;
		}

		printf("%d\n", mx);
	}
}
