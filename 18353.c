#include <stdio.h>
#include <stdlib.h>
int N;

int main() {
	scanf("%d", &N);

	int* A = (int*)calloc(N, 4);
	int* dp = (int*)calloc(N, 4);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	dp[0] = 1;
	for (int i = N-1; i >= 0; i--) {
		dp[i] = 1;
		for (int j = N-1; j > i; j--)
			if (A[i] > A[j])
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
	}

    int mx=0;
	for (int i = 0; i < N; i++)
		if (mx < dp[i])
			mx = dp[i];
	
	printf("%d", N-mx);
}
