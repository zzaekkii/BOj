#include <stdio.h>
#include <stdlib.h>

int N;
int idx,cnt;

int main() {
	scanf("%d", &N);

	int* balloon = (int*)calloc(N + 1, 4);

	for (int i = 0; i < N; i++)
		scanf("%d", &balloon[i]);
	
	cnt = balloon[0];
	balloon[0] = 1001;
	printf("1 ");

	for (int j = 1; j < N;j++) {
		if (cnt > 0) {
			for (int i = 0; i < cnt; i++) {
				idx = (idx + 1 + N) % N;
				if (balloon[idx] == 1001)i--;
			}
		}
		else {
			for (int i = 0; i > cnt; i--) {
				idx = (idx - 1 + N) % N;
				if (balloon[idx] == 1001)i++;
			}
		}

		cnt = balloon[idx];
		balloon[idx] = 1001;

		printf("%d ", idx+1);
	}
}
