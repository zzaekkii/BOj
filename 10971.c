// 10971번 외판원 순회2 - 실버2 / TSP, DP, 비트마스킹.
#include <stdio.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define BIG 1000000000

int N;

int W[11][11]; // W[i][j]: 도시 i에서 j로 가기 위한 비용. 
int dp[11][(1 << 11)]; // 가장 적은 비용. 

int Tsp(int cur, int vis) {
	// 경로 다 봤을 때 탈출. 
	if (vis == (1 << N) - 1)
		// 마지막애가 시작점까지 이어지는 애가 아니면 X. 
		return !W[cur][0] ? BIG : W[cur][0];

	// 이전에 계산한 경로면 그걸로 고. 
	if (dp[cur][vis] != -1)return dp[cur][vis];

	dp[cur][vis] = BIG;

	for (int i = 1; i < N; i++) {
		// 길이 없거나, 경로에 포함돼있으면 X. 
		if (!W[cur][i] || vis & (1 << i))continue;

		dp[cur][vis] = min(dp[cur][vis], W[cur][i] + Tsp(i, vis | (1 << i)));
	}

	return dp[cur][vis];
}

int main() {
	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &W[i][j]);

	printf("%d", Tsp(0, 1));
}
