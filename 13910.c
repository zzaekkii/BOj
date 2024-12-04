// 13910번 개업 - 골드5 / DP
#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define MAX 1000000

int N, M; // 짜장면 N그릇, 웍 M개.
int S[101]; // 웍 크기.
int dp[10001]; // 짜장면 완성 최소 웍.

int cmp(int* a, int* b) {
	return *a - *b;
}

int main() {
	scanf("%d %d", &N, &M);

	// 주문 처리 못하면 -1임.
	for (int i = 0; i <= N; i++)
		dp[i] = MAX;

	for (int i = 0; i < M; i++) {
		scanf("%d", &S[i]);
		dp[S[i]] = 1;
	}

	qsort(S, M, 4, cmp);

	for (int i = 0; i < M; i++)
		for (int j = i + 1; j < M && S[i] + S[j] <= N; j++)
			dp[S[i] + S[j]] = 1;

	for (int i = 1; i <= N; i++) {
		if (dp[i] != MAX)continue;
		for (int j = 1; j < i; j++)
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
	}

	printf("%d", dp[N] == MAX ? -1 : dp[N]);
}
