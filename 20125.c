#include <stdio.h>

// 심장(+)의 위치만 파악하면 끝~

int N;
char board[1001][1001];

int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
int la, ra, b, ll, rl; // left arm, right '', back, left leg, right ''.

int main() {
	scanf("%d ", &N);

	for (int i = 0; i < N; i++)
		gets(board[i]);

	for (int i = 1; i < N - 1; i++)
		for (int j = 1; j < N - 1; j++)
			if (board[i][j] == '*') {
				_Bool flag = 1;

				// 심장 탐색.
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (board[nx][ny] == '_')flag = 0;
				}

				// 이곳이 심장.
				if (flag) {
					for (int k = j - 1; board[i][k] == '*'; k--, la++);
					for (int k = j + 1; board[i][k] == '*'; k++, ra++);
					for (int k = i + 1; board[k][j] == '*'; k++, b++);
					for (int k = i + b + 1; board[k][j - 1] == '*'; k++, ll++);
					for (int k = i + b + 1; board[k][j + 1] == '*'; k++, rl++);

					printf("%d %d\n", i + 1, j + 1);
					printf("%d %d %d %d %d", la, ra, b, ll, rl);
					return 0;
				}
			}
}
