// 15738번 뒤집기 - 실버5 / 구현
#include <stdio.h>

int N, K, M, O;

int main() {
	scanf("%d %d %d", &N, &K, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &O);

	while (M--) {
		scanf("%d", &O);

		if (O > 0) {
			if (K <= O) K = O - K + 1;
		}
		else {
			O *= -1;
			if (K >= N - O + 1) K = 2 * N - K - O + 1;
		}
	}

	printf("%d", K);
}