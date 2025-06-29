#include <stdio.h>
#define MAX 505

int T, N, D;
int MAP[MAX][MAX];
int temp[MAX][MAX];

void input() {
	scanf("%d %d", &N, &D);

	D = (D + 360) % 360;

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			scanf("%d", &MAP[r][c]);
}

void printMap(){
	for (int r = 0; r < N; r++, puts(""))
		for (int c = 0; c < N; c++)
			printf("%d ", MAP[r][c]);
}

void copyMap() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			temp[r][c] = MAP[r][c];
}

void rotate45() {
	copyMap();

	int arr[MAX] = { 0 };
	int half = N / 2;

	// - => \.
	for (int i = 0; i < N; i++) arr[i] = temp[half][i];
	for (int i = 0; i < N; i++) MAP[i][i] = arr[i];
	
	// \ => |.
	for (int i = 0; i < N; i++) arr[i] = temp[i][i];
	for (int i = 0; i < N; i++) MAP[i][half] = arr[i];
	
	// | => /.
	for (int i = 0; i < N; i++) arr[i] = temp[i][half];
	for (int i = 0; i < N; i++) MAP[i][N - i - 1] = arr[i];
	
	// / => -.
	for (int i = 0; i < N; i++) arr[i] = temp[N - i - 1][i];
	for (int i = 0; i < N; i++) MAP[half][i] = arr[i];
}

int main() {
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++) {
		input();

		// 회전수.
		int cnt = D / 45;
		for (int c = 0; c < cnt; c++) rotate45();

		printMap();
	}
}
