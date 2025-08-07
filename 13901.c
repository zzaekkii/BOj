// 13901번 로봇 - 실버1 / 구현, 시뮬레이션
#include <stdio.h>

typedef struct Point {
	int x, y;
} Point;

int R, C, K;
int board[1001][1001];
int visited[1001][1001];

Point point[1001];
Point robot;

int dir[4];
int dx[] = { -1,1,0,0 } , dy[] = { 0, 0, -1, 1 };

void inputs() {
	scanf("%d %d %d", &R, &C, &K);

	for (int i = 0; i < K; i++) {
		int X = 0, Y = 0;
		scanf("%d %d", &X, &Y);
		board[X][Y] = 1;
	}

	scanf("%d %d", &robot.x, &robot.y);
	visited[robot.x][robot.y] = 1;

	for (int i = 0; i < 4; i++) {
		int T = 0;
		scanf("%d", &T);

		dir[i] = T - 1;
	}
}

int in_range(int x, int y) {
	if (x >= 0 && x < R && y >= 0 && y < C)return 1;
	return 0;
}

int move(int dr) {
	for (int i = dr; i < 4; i++) {
		int nx = robot.x + dx[dir[i]];
		int ny = robot.y + dy[dir[i]];

		if (in_range(nx, ny) && !board[nx][ny] && !visited[nx][ny]) {
			visited[nx][ny] = 1;
			robot.x = nx;
			robot.y = ny;
			move(i);
			return 1;
		}
	}

	return 0;
}


int main() {
	inputs();

	while (move(0)) {}

	printf("%d %d", robot.x, robot.y);
}
