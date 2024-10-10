#include <stdio.h>
#include <string.h>

int N;
char S[11];

int main() {
	scanf("%d ", &N);

	int k1 = 0, k2 = 0;
	for (int i = 1; i <= N;i++) {
		gets(S);
		if (!strcmp(S, "KBS1"))
			k1 = i;
		if (!strcmp(S, "KBS2"))
			k2 = i;
	}
	if (k2 < k1)k2++;

	if (k1 != 1) {
		for (int i = 1; i < k1; i++)
			printf("1");
		for (int i = 1; i < k1; i++)
			printf("4");
	}

	if (k2 != 2) {
		for (int i = 1; i < k2; i++)
			printf("1");
		for (int i = 1; i < k2 - 1; i++)
			printf("4");
	}
}
