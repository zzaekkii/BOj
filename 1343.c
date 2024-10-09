#include <stdio.h>

char S[51];
char ans[51];

int main() {
	gets(S);

	_Bool flag = 1;
	for (int i = 0; S[i]; i++) {
		if (S[i] == '.') {
			ans[i] = '.';
			continue;
		}
		int cnt = 0;
		for (int j = i; S[j] && j < i + 4; j++)
			if (S[j] == 'X')cnt++;
			else break;

		if (cnt == 4) {
			for (int j = i; j < i + 4; j++)
				ans[j] = 'A';
			i += 3;
		}
		else if (cnt >= 2) {
			for (int j = i; j < i + 2; j++)
				ans[j] = 'B';
			i += 1;
		}
		else {
			flag = 0;
			break;
		}
	}

	puts(flag ? ans : "-1");
}
