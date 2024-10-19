#include <stdio.h>

int N, M;
int A[100001];
int ans;

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
		scanf("%d", &A[i]);

	if (A[0])ans = A[0];
	if (A[M - 1] != N && ans < N - A[M - 1])ans = N - A[M - 1];

	for (int i = 1; i < M; i++)
		if ((A[i] - A[i - 1] + 1) / 2 > ans)ans = (A[i] - A[i - 1] + 1) / 2;

	printf("%d", ans);
}
