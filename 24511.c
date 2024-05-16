#include <stdio.h>

int N, T, M;
int A[100001];
int B[100001];

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int t = 0;
	for (int i = 0; i < N; i++){
		scanf("%d", &T);
		if (!A[i])B[t++] = T;
	}

	for (int i = 0; i < t / 2; i++)
		B[i] ^= B[t - 1 - i], B[t - 1 - i] ^= B[i], B[i] ^= B[t - 1 - i];

	scanf("%d", &M);

	int h = 0;
	while (M--){
		scanf("%d", &B[t++]);
		printf("%d ", B[h++]);
	}
}
