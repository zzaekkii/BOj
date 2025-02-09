// 15353번 큰 수 A+B (2) - 실버3 / 문자열, 사칙연산
#include <stdio.h>
#include <string.h>

char A[10005], B[10005], ans[10006];
int carry;

int main() {
	scanf("%s %s", A, B);

	int lenA = strlen(A);
	int lenB = strlen(B);

	int idx = 0;
	while (lenA > 0 || lenB > 0 || carry) {
		lenA--;
		lenB--;
		int curA = 0, curB = 0;
		if (lenA >= 0) curA = (A[lenA] - 48);
		if (lenB >= 0) curB = (B[lenB] - 48);

		int sum = curA + curB + carry;
		carry = sum >= 10;

		ans[idx++] = (sum % 10) + 48;
	}

	int len = strlen(ans);
	for (int i = len - 1; i >= 0; i--)
		printf("%c", ans[i]);
}
