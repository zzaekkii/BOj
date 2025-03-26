#include <stdio.h>

int N, M, K, A, B;

int cost[10001];
int total;

int Find(int x) {
	if (cost[x] < 0)return x;
	return cost[x] = Find(cost[x]);
}

void Union(int x, int y) {
	int rootX = Find(x);
	int rootY = Find(y);

	if (rootX != rootY) {
		if (cost[rootX] < cost[rootY])cost[rootX] = cost[rootY];
		cost[rootY] = rootX;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
		cost[i] *= -1;
	}

	while (M--) {
		scanf("%d %d", &A, &B);
		Union(A, B);
	}

	for (int i = 1; i <= N; i++)
		if(cost[i]<0)
			total += -cost[i];

	if (total > K)puts("Oh no");
	else printf("%d", total);
}