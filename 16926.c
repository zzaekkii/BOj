#include <stdio.h>
#define MAX 303

typedef struct Element {
	int r, c;
}Element;

int N, M, R;
int MAP[MAX][MAX];
int temp[MAX][MAX];

Element arr[MAX * MAX];

void input() {
	scanf("%d %d %d", &N, &M, &R);

	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			scanf("%d", &MAP[r][c]);
}

void printMap(){
	for (int r = 0; r < N; r++, puts(""))
		for (int c = 0; c < M; c++)
			printf("%d ", MAP[r][c]);
}

void copyMap() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			temp[r][c] = MAP[r][c];
}

void rotateStep(int sr, int sc, int n, int m, int rotateCount) {
	int er = sr + n - 1;
	int ec = sc + m - 1;

	copyMap();

	int idx = 0;

	// 상단.
	for (int c = sc; c < ec; c++) {
		arr[idx].r = sr;
		arr[idx++].c = c;
	}

	// 우측.
	for (int r = sr; r < er; r++) {
		arr[idx].r = r;
		arr[idx++].c = ec;
	}

	// 하단.
	for (int c = ec; c > sc; c--) {
		arr[idx].r = er;
		arr[idx++].c = c;
	}

	// 좌측.
	for (int r = er; r > sr; r--) {
		arr[idx].r = r;
		arr[idx++].c = sc;
	}

	for (int i = 0; i < idx; i++) {
		int newIdx = (i + idx - rotateCount % idx) % idx;

		Element front = arr[newIdx];

		MAP[front.r][front.c] = temp[arr[i].r][arr[i].c];
	}
}

void rotate(int rotateCount) {
	int sr = 0, sc = 0;
	int n = N, m = M;
	int step = N < M ? N / 2 : M / 2;

	for (int s = 0; s < step; s++) {
		rotateStep(sr, sc, n, m, rotateCount);

		sr++, sc++; // \방향으로 증가.
		n -= 2, m -= 2; // 폭은 양쪽에서 줄어듦.
	}
}

int main() {
	input();

	rotate(R);

	printMap();
}
