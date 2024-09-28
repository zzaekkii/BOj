#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
}Pool;

Pool p[10001];

int N, L;

int cmp(Pool *a, Pool *b) {
	return (*a).x - (*b).x;
}

int main() {
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &p[i].x, &p[i].y);

	qsort(p, N, sizeof(Pool), cmp);

	int tail = 0;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (tail < p[i].x) {
			cnt++;
			tail = p[i].x + L;
		}
		while(tail < p[i].y) {
			cnt++;
			tail += L;
		}
	}

	printf("%d", cnt);
}
