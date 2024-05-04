#include <stdio.h>										
#include <string.h>
#define MAX 1000001

char T[MAX], P[MAX];
int pi[MAX], ans[MAX]; // 수미상관, 답.
int n, m, idx;

int main() {
	gets(T);
	gets(P);

	int n = strlen(T), m = strlen(P);

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1]; // 가능한 애로 점프.
		if (P[i] == P[j])
			pi[i] = ++j;
	}

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];
		if (T[i] == P[j]) {
			if (j == m - 1) {
				ans[idx++] = (i - m + 1) + 1;
				j = pi[j];
			}
			else
				j++;
		}
	}

	printf("%d\n", idx);
	for (int i = 0; i < idx; i++)
		printf("%d ", ans[i]);
}
