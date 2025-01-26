#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char S[25];
char A[8], B[8], C[8];

void reverse(char* s) {
	int l = strlen(s);
	for (int i = 0; i < l / 2; i++) {
		s[i] ^= s[l - 1 - i];
		s[l - 1 - i] ^= s[i];
		s[i] ^= s[l - 1 - i];
	}
}

int main() {
	while (1) {
		gets(S);

		char* token = strtok(S, "+=");
		strcpy(A, token);
		token = strtok(0, "+="), strcpy(B, token);
		token = strtok(0, "+="), strcpy(C, token);

		reverse(A), reverse(B), reverse(C);

		int a = atoi(A), b = atoi(B), c = atoi(C);
		puts((a + b == c) ? "True" : "False");
		if (!a && !b && !c)break;
	}
}
