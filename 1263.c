#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int T, S; // 작업 시간, 마감 시간.
}Work;

int N;
Work w[1001];
_Bool pos=1; // possible.
int idx,ans;

// ① 마감 시간, ② 작업 시간 기준 오름차순.
int cmp(Work *a, Work *b) {
	if ((*a).S == (*b).S) return (*a).T - (*b).T;
	else return (* a).S - (* b).S;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &w[i].T, &w[i].S);

	qsort(w, N, sizeof(Work), cmp);

	idx = w[N - 1].S;
	for (int i = N - 1; i >= 0; i--) {
		if (idx > w[i].S)idx = w[i].S;

		if (w[i].S >= w[i].T) {
			for (int j = w[i].S; j > w[i].S - w[i].T; j--, idx--);
		} else {
			pos = 0;
			break;
		}
	}

	printf("%d", pos ? idx : -1);
}
