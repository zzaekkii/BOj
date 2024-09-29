#include <stdio.h>

int N,T;
int adv[300001];
int fst_v = 0, fst_idx = 0, scd = 0;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &adv[i]);
		if (fst_v < adv[i]) {
			fst_v = adv[i];
			fst_idx = i;
		}
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &T);
		if (fst_idx != i && scd < adv[i])scd = adv[i];
	}

	for (int i = 0; i < N; i++)
		if (fst_v == adv[i])printf("%d ", fst_v - scd);
		else printf("%d ", adv[i] - fst_v);
}
