#include <stdio.h>

int N, M, K, A, B;
int cost[10001];

int root[10001];
int total;

int Find(int x) {
	if (root[x] == x)return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	int rootX = Find(x);
	int rootY = Find(y);

	if (rootX != rootY) {
		root[rootY] = rootX;
		if (cost[rootX] > cost[rootY])cost[rootX] = cost[rootY];
		cost[rootY] = 0;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
		root[i] = i;
	}

	while (M--) {
		scanf("%d %d", &A, &B);
		Union(A, B);
	}

	for (int i = 1; i <= N; i++)
		total += cost[i];

	if (total > K)puts("Oh no");
	else printf("%d", total);
}