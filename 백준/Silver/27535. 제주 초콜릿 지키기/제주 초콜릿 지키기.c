// 27535번 제주 초콜릿 지키기 - 실버4 / 구현, 정렬
#include <stdio.h>
#include <stdlib.h>
#define CNT 5

typedef struct Choco {
	int cnt;
	char name;
}Choco;

Choco choco[5] = { {0,'H'},{0,'T'},{0,'C'},{0,'K'},{0,'G'} };

int T, M;
int total;

int cmp(const void* a, const void* b) {
	const Choco* x = (const Choco*)a;
	const Choco* y = (const Choco*)b;

	if (x->cnt == y->cnt)
		return (x->name - y->name);
	return (y->cnt - x->cnt);
}

int main() {
	for (int i = 0; i < CNT; i++) {
		scanf("%d", &T);
		choco[i].cnt = T;

		total += T;
	}

	scanf("%d", &M);

	while (M--) {
		int prev = total;

		for (int i = 0; i < CNT; i++) {
			scanf("%d", &T);
			choco[i].cnt -= T;

			total -= T;
		}

		// 진법 변환 + "7H" 출력
		int last = prev % 10;
		if (last == 0 || last == 1)
			printf("%d7H\n", total);
		else {
			char res[25]="H7";
			int tmp = total, idx = 2;
			
			if (tmp == 0)
				res[idx++] = '0';

			while (tmp > 0) {
				res[idx++] = (tmp % last) + 48;
				tmp /= last;
			}

			for (int i = idx - 1; i >= 0; i--)
				printf("%c", res[i]);
			puts("");
		}

		// 내림차순 종류별 개수 출력
		if (total == 0) puts("NULL");
		else {
			Choco tmp[5];
			for (int i = 0; i < CNT; i++)
				tmp[i].cnt = choco[i].cnt, tmp[i].name = choco[i].name;

			qsort(tmp, CNT, sizeof(Choco), cmp);

			for (int i = 0; i < CNT; i++)
				if (tmp[i].cnt == 0) break;
				else printf("%c", tmp[i].name);
			puts("");
		}
	}
}