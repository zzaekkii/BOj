#include <stdio.h>
#include <string.h>

int R, C;
char before[11][11];
char after[11][11];

int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };

int main() {
	scanf("%d %d ", &R, &C);
	for (int i = 0; i < R; i++) {
		gets(before[i]);
		strcpy(after[i], before[i]);
	}

	for(int i=0;i<R;i++)
		for (int j = 0; j < C; j++) {
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= R || ny < 0 || ny >= C || before[nx][ny] == '.')cnt++;
			}
			if (cnt >= 3)after[i][j] = '.';
		}

	int x_s = R, x_e = -1, y_s = C, y_e = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (after[i][j] == 'X') {
				if (i < x_s) x_s = i;
				if (i > x_e) x_e = i;
				if (j < y_s) y_s = j;
				if (j > y_e) y_e = j;
			}
		}
	}

	if (x_e == -1 || y_e == -1)
		return 0;

	for (int i = x_s; i <= x_e; i++) {
		for (int j = y_s; j <= y_e; j++)
			printf("%c", after[i][j]);
		puts("");
	}
}
