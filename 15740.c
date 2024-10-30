// 15740번 A+B (9) #큰수연산
#include <stdio.h>
#include <string.h>

// 연산은 덧셈/뺄셈 총 2가지.

char A[10005], B[10005], res[10005];
_Bool as = 1, bs = 1; // A와 B의 default 부호는 일단 +.
int carry, la, lb; // 캐리 비트, a길이, b길이.
_Bool flag; // 만약 결과가 0이라면 부호 표시 x.

// 연산 편의를 위해 뒤집기.
void reverse() {
	for (int i = 0; i < la / 2; i++) {
		char tmp = A[i];
		A[i] = A[la - i - 1];
		A[la - i - 1] = tmp;
	}

	for (int i = 0; i < lb / 2; i++) {
		char tmp = B[i];
		B[i] = B[lb - i - 1];
		B[lb - i - 1] = tmp;
	}
}

int main() {
	scanf("%s %s", A, B);
	la = strlen(A), lb = strlen(B);

	if (A[0] == '-') as = 0;
	if (B[0] == '-') bs = 0;

	// 덧셈 연산.
	if (as == bs) {
		// 긴쪽을 A로.
		if (la < lb) {
			char tmp[10005];
			strcpy(tmp, A);
			strcpy(A, B);
			strcpy(B, tmp);
		}
		// 길이도 재설정.
		la = strlen(A);
		lb = strlen(B);

		// 연산 편의를 위해 뒤집기.
		reverse();

		// 부호 미포함.
		for (int i = 0; i < (as ? la : la - 1); i++) {
			int ta = (A[i] - 48);
			int tb = i < (as ? lb : lb - 1) ? (B[i] - 48) : 0;
			int cur = carry + ta + tb;
			carry = cur / 10;
			res[i] = cur % 10 + 48;
		}
		int lr = as ? la : la - 1;
		if (carry)res[lr++] = '1';
		res[lr] = 0;

		// 앞에 0 없애기.
		for (int i = 0; i < lr / 2; i++) {
			char tmp = res[i];
			res[i] = res[lr - i - 1];
			res[lr - i - 1] = tmp;
		}
		// 결과가 0인지 확인.
		for (int i = 0; i < lr; i++) {
			if (res[i] != '0') break;
			if (i == lr - 1)flag = 1;
		};

		// 결과가 0이 아니고, 둘 다 음수면 - 출력 먼저하고.
		if (!flag && !as)printf("-");

		// 결과 출력.
		for (int i = 0; i < lr; i++) {
			if (res[i] != '0') {
				for (int j = i; j < lr; j++)
					printf("%c", res[j]);
				break;
			}
			if (i == lr - 1)printf("0");
		};

	} // 뺄셈 연산.
	else {
		// 우선 절댓값이 큰 쪽을 A로 정의한다.

		_Bool da = 0, db = 0; // 탐색 중 부호 스킵할 더미 a, b.
		if (!as) db = 1;
		if (!bs) da = 1;

		_Bool bigger = 0; // 0은 A고, 1은 B.
		if (la + da < lb + db) bigger = 1;
		else if (la + da == lb + db)
			for (int i = 1; i <= (la < lb ? la : lb); i++) {
				if (A[i - da] > B[i - db])break;
				else if (A[i - da] < B[i - db]) {
					bigger = 1;
					break;
				}
			}

		// B의 절댓값이 A보다 더 크면 swap.
		if (bigger) {
			char tmp[10005];
			strcpy(tmp, A);
			strcpy(A, B);
			strcpy(B, tmp);
		}
		// 길이도 재설정.
		la = strlen(A);
		lb = strlen(B);
		as = A[0] != '-';
		bs = B[0] != '-';

		// 연산 편의를 위해 뒤집기.
		reverse();

		int lr = 0;
		for (int i = 0; i < (as ? la : la - 1); i++) {
			if (i == (as ? la - 1 : la - 2) && A[i] == '0') break;
			int ta = (A[i] - 48);
			int tb = i < (bs ? lb : lb - 1) ? (B[i] - 48) : 0;
			if (ta < tb) {
				for (int j = i + 1; j < (as ? la : la - 1); j++) {
					if (A[j] > '0') {
						A[j]--;
						carry = 10;
						for (int k = j - 1; k > i; k--)
							A[k] = ((A[k] - 48 - 1 + 10) % 10) + 48;
						break;
					}
				}
			}
			int cur = carry + ta - tb;

			carry = 0;
			res[i] = cur % 10 + 48;
			res[i + 1] = 0;
			lr = i + 1;
		}


		// 앞에 0 없애기.
		for (int i = 0; i < lr / 2; i++) {
			char tmp = res[i];
			res[i] = res[lr - i - 1];
			res[lr - i - 1] = tmp;
		}
		// 결과가 0인지 확인.
		for (int i = 0; i < lr; i++) {
			if (res[i] != '0') break;
			if (i == lr - 1)flag = 1;
		};

		// 결과 0 아니면, 큰 수 부호따라감.
		if (!flag && !as) printf("-");
		
		// 결과 출력.
		for (int i = 0; i < lr; i++) {
			if (res[i] != '0') {
				for (int j = i; j < lr; j++)
					printf("%c", res[j]);
				break;
			}
			if (i == lr - 1) printf("0");
		}
	}
}
