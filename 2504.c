// 2504번 괄호의 값 - 스택
#include <stdio.h>

char S[31];
char stack[31];
int top = -1;
int cur = 1, sum = 0; // 결합 전 값, 최종값.

int main() {
	gets(S);

	for (int i = 0; S[i]; i++) {
		switch (S[i]) {
		case '(':
			cur *= 2;
			stack[++top] = '(';
			break;
		case '[':
			cur *= 3;
			stack[++top] = '[';
			break;
		case ')':
			if (top == -1 || stack[top] != '(') {
				puts("0");
				return 0;
			}
			if (S[i - 1] == '(') sum += cur;
			cur /= 2;
			top--;
			break;
		case ']':
			if (top == -1 || stack[top] != '[') {
				puts("0");
				return 0;
			}
			if (S[i - 1] == '[')sum += cur;
			cur /= 3;
			top--;
			break;
		}
	}
	if (top != -1)puts("0");
	else printf("%d", sum);
}
