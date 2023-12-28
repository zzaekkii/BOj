#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))

int main() {
	int i, j, N;
	scanf("%d", &N);
	int* a = calloc(N + 1, 4);

	for (i = 1; i <= N; i++) {
		a[i] = a[i - 1] + 1;
		for (j = 1; j * j <= i; j++)
			a[i] = min(a[i], a[i - j * j] + 1);
	}
	printf("%d", a[N]);
}
