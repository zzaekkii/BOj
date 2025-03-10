#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

int N, K;
int arr[100001];

int dp[2][100001];
int ans = 1;

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i < N; i++)
		scanf("%d", &arr[i]);

	dp[0][0] = dp[1][0] = 1;

	for (int i = 1; i < N; i++) {
		if (arr[i] <= K) {
			dp[0][i] = dp[0][i - 1] + 1;
			dp[1][i] = dp[1][i - 1] + 1;
		}
		else {
			dp[0][i] = 1;
			dp[1][i] = dp[0][i - 1] + 1;
		}

		ans = max(ans, max(dp[0][i], dp[1][i]));
	}

	printf("%d", ans);
}