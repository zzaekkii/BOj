// 2629번 양팔저울 - 골드3 / #DP #냅색
#include <stdio.h>
#include <stdlib.h>

int N, T, X; // 추 N개, 무게 확인할 구슬 T개(7개 이하), 구슬 무게 X.
int W[31]; // 각 추의 무게(오름차순 입력).
_Bool sum[15001];
_Bool dp[40001]; // 구슬 무게 최대 40000g.

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &W[i]);
		dp[W[i]] = 1;
	}

	sum[0] = 1;
	// 가능한 무게 조합 계산.
	for (int i = 0; i < N; i++)
		for (int j = 15000; j >= 0; j--)
			if (sum[j]) {
				sum[W[i] + j] = 1;
				dp[W[i] + j] = 1;
			}

	//for (int i = 0; i <= 50; i++)
	//	printf("%d는 조합 가능한가? %s\n", i, dp[i] ? "YESSSSSS" : "No");

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &X);
		
		_Bool pos = 0;

		// 0일 때는 본래 무게.
		for (int i = 0; i <= 15000 && X + i <= 40000; i++)
			if (dp[X + i] && sum[i])pos = 1;

		printf("%c ", pos ? 'Y': 'N');
	}
}
