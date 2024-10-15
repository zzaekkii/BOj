#include <stdio.h>

int P, T;
int A[21];

int main() {
	scanf("%d", &P);

	while (P--) {
		scanf("%d", &T);
		for (int i = 0; i < 20; i++)
			scanf("%d", &A[i]);

		int cnt = 0;
		for (int i = 1; i < 20; i++) {
			int tmp = A[i];
			int j = i - 1;

			while (j >= 0 && A[j] > tmp) {
				A[j + 1] = A[j];
				j--;
				cnt++;
			}
			A[j + 1] = tmp;
		}
		printf("%d %d\n", T, cnt);
	}
}
