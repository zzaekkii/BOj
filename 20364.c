// 20364번 부동산 다툼 - 실버1 / #트리
#include <stdio.h>

int N, Q; // 땅 N(1-N)개, 오리 Q마리.
int X; // 오리가 가고 싶은 땅 번호.

_Bool occu[1050000]; // 땅(최대 2^20) 점유 여부.

int main() {
	scanf("%d %d", &N, &Q);

	while (Q--) {
		scanf("%d", &X);

		int end = 0, tmp = X;
		while (tmp > 0) {
			if (occu[tmp])end = tmp;
			tmp /= 2;
		}

		if (!end) {
			puts("0");
			occu[X] = 1;
		}
		else printf("%d\n", end);
	}
}
