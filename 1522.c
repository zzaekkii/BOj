// 1522번 문자열 교환 - 실버1 / 브루트포스
#include <stdio.h>
#include <string.h>

char S[1001];
int ans=1001;

int main() {
	gets(S);

	int l = strlen(S);
	int total = 0;
	for (int i = 0; i < l; i++)
		if (S[i] == 'a')total++;

	for (int i = 0; i < l; i++) {
		int cnt = total, change = 0;
		for (int j = i; j < i + l; j++) {
			if (!cnt)break;
			if (S[j % l] == 'b')change++, cnt--;
			else cnt--;
		}
		if (ans>change)ans = change;
	}

	printf("%d", ans);
}
