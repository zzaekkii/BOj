#include <stdio.h>
#include <stdlib.h>

int N, M; // 방 크기 N × M
int R, C, D; // 로봇 청소기 현재 위치 (R, C) 보는 방향 D
// 0: 북, 1: 동, 2: 남, 3: 서

_Bool board[51][51];
_Bool clean[51][51];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int cnt = 0;

int main() {
	scanf("%d %d %d %d %d", &N, &M, &R, &C, &D);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &board[i][j]);

	while (1) {
		// case 1 - 현재 칸이 빈 칸이고, 더럽다면
		if (!board[R][C] && !clean[R][C]) {
			clean[R][C] = 1;
			cnt++;
		}

		// 주위 더러운 칸 존재 유무
		_Bool dirty_exist = 0;

		for (int dir = 0; dir < 4; dir++) {
			int nx = R + dx[dir];
			int ny = C + dy[dir];

			// 아직 더러운 칸 발견
			if (!board[nx][ny] && !clean[nx][ny])
				dirty_exist = 1;
		}

		// case 3 - 반시계 90도 rotate하며 더러운칸에 전진
		if (dirty_exist) {
			for (int sub = 1; sub <= 4; sub++) {
				int nx = R + dx[(D - sub + 4) % 4];
				int ny = C + dy[(D - sub + 4) % 4];
				if (!board[nx][ny] && !clean[nx][ny]) {
					D = (D - sub + 4) % 4;
					R = nx, C = ny;
					break;
				}
			}
			continue;
		}
		// case 2 - 뒤가 뚫렸다면 후진, 벽이면 작동 정지
		else {
			// 뒤칸 판별
			int back_x=0, back_y=0;

			switch (D) {
			case 0: // 뒤쪽이 남쪽 -> (R+1, C)
				back_x = R + 1;
				back_y = C;
				break;
			case 1: // 뒤쪽이 서쪽 -> (R, C-1)
				back_x = R;
				back_y = C - 1;
				break;
			case 2: // 뒤쪽이 북쪽 -> (R-1, C)
				back_x = R - 1;
				back_y = C;
				break;
			case 3: // 뒤쪽이 동쪽 -> (R, C+1)
				back_x = R;
				back_y = C + 1;
				break;
			}

			// 뒤가 벽인 경우 1 - 영역 이탈
			if (back_x < 0 || back_x >= N || back_y < 0 || back_y >= M)
				break;
			// 뒤가 벽인 경우 2 - board[][] 값이 1
			if (board[back_x][back_y])
				break;

			// 뒤가 빈 칸인 경우 -> 방향 유지, 후진
			if (!board[back_x][back_y]) {
				R = back_x, C = back_y;

				// case 1로 복귀
				continue;
			}
		}
	}

	// 청소 한 칸의 개수 출력
	printf("%d", cnt);
}
