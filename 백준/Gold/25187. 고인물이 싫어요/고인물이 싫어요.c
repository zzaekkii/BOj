#include <stdio.h>

int N, M, Q, P, A, B, T;

int root[100001];
int pure[100001];

int Find(int x) {
	if (root[x] == x)return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	int rootX = Find(x);
	int rootY = Find(y);

	if (rootX != rootY) {
		pure[rootX] += pure[rootY];
		root[rootY] = rootX;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &Q);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &P);
		pure[i] = P ? 1 : -1;
		root[i] = i;
	}

	while (M--) {
		scanf("%d %d", &A, &B);

		Union(A, B);
	}

	while (Q--) {
		scanf("%d", &T);

		puts(pure[Find(T)] > 0 ? "1" : "0");
	}
}