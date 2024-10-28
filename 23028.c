#include <stdio.h>

typedef struct {
	int maj, lib;
} Sub;

int N, A, B;
Sub s[11];
_Bool able;

int main() {
	scanf("%d %d %d", &N, &A, &B);

	for (int i = 0; i < 10; i++)
		scanf("%d %d", &s[i].maj, &s[i].lib);

	int ml = 66 - A;
	int tl = 130 - B;

	// 아 어차피 전공으로 다 채워도 상관없잖아?
	// 괜히 어렵게 생각했네.
	for (int i = 0; i < 8 - N; i++) {
		int cur = s[i].maj;
		ml -= cur * 3;
		tl -= cur * 3;
		if (cur < 6)tl -= (6 - cur > s[i].lib) ? s[i].lib * 3 : (6 - cur) * 3;
	}

	if (ml <= 0 && tl <= 0)able = 1;
	puts(able ? "Nice" : "Nae ga wae");
}
