#include <stdio.h>

char S[101]; // 후위 표기식.
int N;
int num[26]; // A~Z(-65)에 매칭되는 숫자를 저장할 배열.
double stack[55];
int top = -1;

int main() {
	scanf("%d ", &N);
	
	gets(S);

	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	for (int i = 0; S[i]; i++) {
		if (S[i] >= 65 && S[i] <= 90) { // 대문자 알파벳일 때 push.
			stack[++top] = num[S[i] - 65];
		}
		else { // 연산자일 때 top과 top-1 숫자 연산.
			double tmp = 0;
			switch (S[i]) {
			case '+':
				tmp = stack[top - 1] + stack[top];
				break;
			case '-':
				tmp = stack[top - 1] - stack[top];
				break;
			case '*':
				tmp = stack[top - 1] * stack[top];
				break;
			case '/':
				tmp = stack[top - 1] / stack[top];
				break;
			}

			stack[--top] = tmp;
		}
	}
	printf("%.2lf", stack[0]);
}
