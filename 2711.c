#include <stdio.h>

int main() {
	int i, r, n;
	char s[81];
	scanf("%d", &r);
	while (r--) {
		scanf("%d %s", &n, s);
		for (i = 0; s[i] != 0; i++) {
			if (i == n-1)
				continue;
			printf("%c", s[i]);
		}puts("");
	}
}
