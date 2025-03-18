#include <stdio.h>
#include <stdlib.h>

typedef struct Bar {
	int x, y;
}Bar;

int N;
Bar bar[1001];
_Bool check[1001];

int cmp(Bar* a, Bar* b) {
	return (*a).x - (*b).x;
}

int getArea() {
	int total = 0;

	for (int i = 0; i < N;) {
		int nx = bar[i].x;
		int ny = bar[i].y;

		int next_y = ny;
		int next_idx = i;

		// 뒤에 있는 막대 탐색.
		for (int j = i + 1; j < N; j++)
			if (bar[j].y >= next_y) {
				next_y = bar[j].y;
				next_idx = j;
				break;
			}

//		printf("현재 막대: %d번째 (%d, %d) - 뒤 막대: %d번째 (%d, %d) [total: %d]\n", i, nx, ny, next_idx, bar[next_idx].x, next_y, total);

		if (next_idx == i) { // 뒤에 더 큰 거 없음.
			next_y = bar[i + 1].y;
			next_idx = i + 1;

			// 뒤 막대 중 가장 큰 것.
			for (int j = i + 2; j < N; j++)
				if (bar[j].y >= next_y) {
					next_y = bar[j].y;
					next_idx = j;
				}
			
			if (!check[i]) {
//				printf("현재 막대가 가장 큽니다. %d에 현재 막대 높이인 %d와 다음 막대 까지의 넓이 %d를 더합니다.\n", total, ny, (bar[next_idx].x - nx) * next_y);
				total += ny;
			}
//			else printf("현재 막대가 가장 큽니다. %d에 다음 막대 까지의 넓이 %d를 더합니다.\n", total, (bar[next_idx].x - nx) * next_y);

			total += (bar[next_idx].x - nx) * next_y;
			check[next_idx] = 1;
			i = next_idx;
		}
		else { // 뒤에 큰 거 있음.
			int width = bar[next_idx].x - nx;
//			printf("뒤에 큰 막대가 있네요. %d + %d를 수행합니다.\n", total, width * ny);
			total += width * ny;

			i = next_idx;
		}
	}

	return total;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &bar[i].x, &bar[i].y);

	qsort(bar, N, sizeof(Bar), cmp);

	printf("%d", getArea());
}