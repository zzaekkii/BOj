#include <stdio.h>

int T;
char S[100001];

int main() {
	scanf("%d ", &T);

	while (T--) {
		gets(S);
		int alph[26] = { 0 };
		_Bool flag = 1;
		for (int i = 0; S[i]; i++) {
			alph[S[i] - 65]++;
			if (!(alph[S[i] - 65] % 3))
				if (!S[i + 1] || S[i + 1] != S[i]) {
					flag = 0;
					break;
				}
				else i++;
		}
		puts(flag ? "OK" : "FAKE");
	}
}
