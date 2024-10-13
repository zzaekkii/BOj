#include <stdio.h>

typedef struct {
	char title[12];
	int power;
} Spec;

Spec s[100001];
int N, M, C;

int main() {
	scanf("%d %d ", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%s %d ", s[i].title, &s[i].power);

	while (M--) {
		scanf("%d", &C);
		int st = 0, en = N - 1;
		while (st < en) {
			int md = (st + en) / 2;
			if (s[md].power < C)
				st = md + 1;
			else en = md;
		}
		puts(s[en].title);
	}
}
