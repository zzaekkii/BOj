#include <stdio.h>

int T, N, A, D;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &A, &D);
		int sum = A;
		for (int i = 1; i < N; i++)
			sum += A + D * i;
		printf("%d\n", sum);
	}
}
