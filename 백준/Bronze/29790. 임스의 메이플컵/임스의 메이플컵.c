// 29790번 임스의 메이플컵 - 브론즈4 / 구현
#include <stdio.h>

int N, U, L; // 해결한 문제 N개, 유니온 레벨 U, 최고 레벨 L.

int main() {
	scanf("%d %d %d", &N, &U, &L);

	if (N >= 1000 && (U >= 8000 || L >= 260))puts("Very Good");
	else if (N >= 1000)puts("Good");
	else puts("Bad");
}