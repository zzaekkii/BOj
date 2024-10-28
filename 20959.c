#include <stdio.h>

_Bool ex[1000];
char S[101];

int main() {
	fgets(S, sizeof(S), stdin);

	for (int i = 0; S[i]; i++) {
		if (48 <= S[i] && S[i] <= 57) {
			int tmp = 0;
			int idx = 0;
			while (48 <= S[i] && S[i] <= 57)
				tmp = tmp * 10 + (S[i++] - 48);
			ex[tmp] = 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < 1000; i++)
		if (ex[i])ans++;

	printf("%d", ans);
}
