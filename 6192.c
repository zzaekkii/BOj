// 6192번 Cow Pie Treasures (DP)
#include <stdio.h>
#define MAX(a, b) (((a)>(b))?(a):(b))

int R, C;
int field[101][101];
int dp[101][101];

int main() {
	scanf("%d %d", &R, &C);

	for(int i=0;i<R;i++)
		for (int j = 0; j < C; j++)
			scanf("%d", &field[i][j]);

	dp[0][0] = field[0][0];

	// 가능한 경우는 최대 3가지가 있음.
	// 가는 것 보다, 내게 오는 입장으로 생각하는 게 편함.
	// 내가 시작행이 아니면, 이전행+이전열도 포함해 3가지.
	// 그 외엔 같은행+이전열, 이후행+이전열이 있음.
	// 내게 오는 길들을 코드로 풀어내면?
	for (int j = 1; j < C; j++) { // 열.
		int st = 0, en = R;
		if (j < R - 1) en = j + 1;
		if (j > R - C) st = (R - 1) - (C - j) + 1;
		for (int i = st; i < en; i++) { // 행.
			dp[i][j] = dp[i][j - 1] + field[i][j]; // 일단 같은행+이전열.
			if (i)dp[i][j] = MAX(dp[i][j], dp[i - 1][j - 1] + field[i][j]); // 가능하다면 이전행+이전열.
			if (i < R - 1)dp[i][j] = MAX(dp[i][j], dp[i + 1][j - 1] + field[i][j]); // 가능하다면 이후행+이전열.
		}
	}

	printf("%d", dp[R-1][C-1]);
}
