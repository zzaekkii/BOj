#include <stdio.h>

int N; // 개월 수.
char docu[37]; // 지난 등급 목록.

int membership[5]; // 실골플다.
int ans;

// 주의사항 1: 한 달 최대 다이아까지 충전 가능.
// 주의사항 2: 어차피 최대 과금액 추정이라, 입력대로 유추하면 됨.
int main() {
	// 입력부.
	scanf("%d", &N);

	for (int i = 0; i < 4; i++)
		scanf("%d", &membership[i]);

	getchar(); // 개행 처리.
	gets(docu);


	// 로직.
	int prev = 0; // 2달 합산이라 지난 달 기록.

	for (int i = 0; i < N; i++) {
		int limit = 0;

		switch (docu[i]) {
		case 'B':
			limit = membership[0] - 1;
			ans += prev = limit - prev;
			break;
		case 'S':
			limit = membership[1] - 1;
			ans += prev = limit - prev;
			break;
		case 'G':
			limit = membership[2] - 1;
			ans += prev = limit - prev;
			break;
		case 'P':
			limit = membership[3] - 1;
			ans += prev = limit - prev;
			break;
		case 'D':
			// 바로 한도 풀 충전. 그리고 D 이후는 D뿐임.
			ans += membership[3];
			break;
		}
	}

	printf("%d", ans);
}