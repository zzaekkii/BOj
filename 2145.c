#include <stdio.h>
#include <string.h>

int main() {
	while (1) {
		int N, l, i;
		char S[7];
		gets(S);
		if (S[0]==48) break;
		while (1) {
			l = strlen(S);
			for (N = i = 0; i < l; i++)N += S[i] - 48;
			for (i = 0; N; i++) {
				S[i] = N % 10 + 48;
				N /= 10;
			}
			S[i] = 0;
			if (i < 2)break;
		}
		printf("%d\n", S[0]-48);
	}
