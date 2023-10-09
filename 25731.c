#include <stdio.h>
#include <string.h>

char X[100001], Y[100001], Z[100001];
int a[10] = { 0 }; // 0 ~ 9 존재 확인용
int b[10] = { 0 };
int c; // Y <= Z를 만족하는지 확인용 (만족하면 1, 아니면 0)

int Exist(int num) { // num ~ 9 중 하나라도 없으면 0 반환, 있으면 1
	for (int i = num; i <= 9; i++)
		if (b[i] > 0) {
			b[i]--;
			return i;
		}
	return -1;
}

void MakeZZ() {
	int i, j, spot, l = strlen(X);

	for (i = 0; i <= 9; i++) b[i] = 0;

	for (i = 0; i < l; i++)
		if (Z[i] < Y[i])break;
	spot = i;
	if (spot == 0) {
		c = 0;
		return;
	}
	for (i = spot; i < l; i++) b[Z[i] - 48]++;

	while (strcmp(Z, Y) < 0||spot>=0) {
		int p = Exist(Y[i]);
		if (p != -1) {
			c = 1;
			Z[i] = p + 48;
			if (p > Y[i] - 48) { // Z의 한 자리라도 동일 인덱스 Y보다 클 때, 그 아래로는 배열 b에 남은 값으로 내림차순 정렬
				int k = 0;
				for (int w = i + 1; w < l; w++) {
					while (1) {
						if (b[k] > 0) { b[k]--; Z[w] = k + 48; break; }
						else k++;
					}
				}break;
			}
		}
		else {
			b[Z[spot] - 48]++;
			spot--;
		}
	}
	if (spot < 0) {
		c = 0;
	}
}

void MakeZ() {
	int i, l = strlen(X);
	for (i = 0; i <= 9; i++) b[i] = a[i];

	for (i = 0; i < l; i++) {
		int p = Exist(Y[i] - 48);
		if (p != -1) {
			c = 1;
			Z[i] = p + 48;
			if (p > Y[i] - 48) { // Z의 한 자리라도 동일 인덱스 Y보다 클 때, 그 아래로는 배열 b에 남은 값으로 내림차순 정렬
				int k = 0;
				for (int w = i + 1; w < l; w++) {
					while (1) {
						if (b[k] > 0) { b[k]--; Z[w] = k + 48; break; }
						else k++;
					}
				}break;
			}
		}
		else {
			c = 0; break;
		}
	}
}

int main() {
	int Q; // 반복 횟수 Q
	scanf("%s %s %d", X, Y, &Q); // X값, Y값, 반복 횟수

	int l = strlen(X); // 길이
	Z[l] = 0;
	for (int i = 0; i < l; i++) a[X[i] - 48]++; // 존재 확인

	MakeZ();// Z 제작
	while (Q--) {
		int n, i, x; // 옵션(1,2), 교체할 Y 인덱스, 교체할 값 
		scanf("%d", &n); // 1 또는 2 선택지 변수

		if (n == 1) {
			scanf("%d %d", &i, &x); // Y[i]값 x로 변경
			Y[i - 1] = x + 48;
			MakeZ();
			if (strcmp(Z, Y) < 0)
				MakeZZ();
		}
		else if (n == 2) {
			scanf("%d", &x); // Z[x] 출력 (Z가 Y보다 작으면 -1 출력)
			if (c) printf("%c\n", Z[x - 1]);
			else puts("-1");
		}
	}
}
