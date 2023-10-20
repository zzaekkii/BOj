/*
#include <stdio.h>
#include <string.h>

int N, lp, ls;
char P[101];
char S[101];

int main() {
	scanf("%d ", &N);
	gets(P);
	lp = strlen(P);
	char* p = strchr(P, '*');
	int x = p - P;
	while (N--) {
		gets(S);
		_Bool f = 1;
		ls = strlen(S);
		if (lp - 1 > ls) {
			puts("NE");
			continue;
		}
		for (int i = 0; i <= lp - x - 1; i++)
			if (P[lp - i] != S[ls - i]) {
				f = 0;
				break;
			}
		puts(!strncmp(P, S, x) && f ? "DA" : "NE");
	}
}
*/
