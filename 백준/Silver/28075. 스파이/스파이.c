#include <stdio.h>

int N, M; // N일간 M이상 기여도.
int point[2][3];

int cnt;

void Dfs(int day, int place, int earn) {
	if (day == N) {
		if (earn >= M) cnt++;
		return;
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			if (place == j) Dfs(day + 1, j, earn + point[i][j] / 2);
			else Dfs(day + 1, j, earn + point[i][j]);
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &point[i][j]);

	Dfs(0, -1, 0);

	printf("%d", cnt);
}