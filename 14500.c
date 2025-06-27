// 14500번 테트로미노 - 골드4 / 구현
#include <stdio.h>
#define SWAP(a, b) do { int _tmp = (a); (a) = (b); (b) = _tmp; } while (0)


int N, M;
int board[501][501];
_Bool vis[501][501];
int mx;

int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };

void Sort(int arr[], int n) {
	if (n == 3) {
		if (arr[0] < arr[1]) SWAP(arr[0], arr[1]);
		if (arr[1] < arr[2]) SWAP(arr[1], arr[2]);
		if (arr[0] < arr[1]) SWAP(arr[0], arr[1]);
	}
	else if (n == 4) {
		if (arr[0] < arr[1]) SWAP(arr[0], arr[1]);
		if (arr[2] < arr[3]) SWAP(arr[2], arr[3]);

		if (arr[0] < arr[2]) SWAP(arr[0], arr[2]);
		if (arr[1] < arr[3]) SWAP(arr[1], arr[3]);

		if (arr[1] < arr[2]) SWAP(arr[1], arr[2]);
	}
}

void Dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		if (mx < sum)mx = sum;
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny]) {
			vis[nx][ny] = 1;
			Dfs(nx, ny, cnt + 1, sum + board[x][y]);
			vis[nx][ny] = 0;
		}
	}
}

// ㅗ 모양을 어떻게 할 것인가가 이 문제의 포인트.
void Check(int x, int y) {
	int cnt = 0;
	int arr[4] = {0};

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			arr[cnt++] = board[nx][ny];
	}

	if (cnt >= 3) {
		int sum = board[x][y];

		Sort(arr, cnt);

		for (int i = 0; i < 3; i++)
			sum += arr[i];

		if (mx < sum) mx = sum;
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &board[i][j]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			Check(i, j);

			vis[i][j] = 1;
			Dfs(i, j, 0, 0);
			vis[i][j] = 0;
		}

	printf("%d", mx);
}
