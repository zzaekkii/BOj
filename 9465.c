#include <stdio.h>
#define MAX(a, b) (((a)>(b))?(a):(b))
int dp[2][100000];

int main() {
	int T, N, i, j;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);

	    for (i = 0; i < 2; i++)
	    	for (j = 0; j < N; j++)
	    		scanf("%d", &dp[i][j]);
    
	    dp[0][1] += dp[1][0];
	    dp[1][1] += dp[0][0];
    
	    for (i = 2; i < N; i++) {
	    	dp[0][i] += MAX(dp[1][i - 1], dp[1][i - 2]);
	    	dp[1][i] += MAX(dp[0][i - 1], dp[0][i - 2]);
	    }
	    printf("%d\n", MAX(dp[0][N - 1],dp[1][N-1]));
    }
}
