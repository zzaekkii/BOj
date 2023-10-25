#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

int arr[100000];
int dp[100000];
int cu[100000];

int MSS(int* arr, int N) {
	int i;
	cu[0] = dp[0] = arr[0];

	for (i = 1; i < N; i++) {
		cu[i] = max(cu[i - 1] + arr[i],arr[i]);
		dp[i] = max(dp[i - 1], cu[i]);
	}
	return dp[N - 1];
}

int main() {
	int N, i;
	scanf("%d", &N);

	for (i = 0; i < N; i++)scanf("%d", &arr[i]);

	printf("%d", MSS(arr, N));
}
