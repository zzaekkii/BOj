// 2096번 내려가기 - 골드5 / DP
#include <stdio.h>
#define max(a, b) (((a)>(b))?(a):(b))
#define min(a, b) (((a)<(b))?(a):(b))

int N;
int board[3];
int mn_dp[3];
int mx_dp[3];

int main() {
	scanf("%d", &N);

	for (int i = 0; i < 3; i++) {
		scanf("%d", &board[i]);
		mn_dp[i] = mx_dp[i] = board[i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &board[j]);

		// 최소.
		int tmp0 = mn_dp[0], tmp2 = mn_dp[2];
		mn_dp[0] = min(mn_dp[0], mn_dp[1]) + board[0];
		mn_dp[2] = min(mn_dp[1], mn_dp[2]) + board[2];
		mn_dp[1] = min(mn_dp[1], min(tmp0, tmp2)) + board[1];

		// 최대.
		tmp0 = mx_dp[0], tmp2 = mx_dp[2];
		mx_dp[0] = max(mx_dp[0], mx_dp[1]) + board[0];
		mx_dp[2] = max(mx_dp[1], mx_dp[2]) + board[2];
		mx_dp[1] = max(mx_dp[1], max(tmp0, tmp2)) + board[1];
	}

	int mx_ans = max(mx_dp[0], max(mx_dp[1], mx_dp[2]));
	int mn_ans = min(mn_dp[0], min(mn_dp[1], mn_dp[2]));
	printf("%d %d", mx_ans, mn_ans);
}
