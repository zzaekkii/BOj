#include <stdio.h>

int N, M, K, A, B;
int price[10001];

int root[10001];
int minPrice[10001];
int total;

int Find(int x) {
	if (root[x] == x)return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	int rootX = Find(x);
	int rootY = Find(y);

	if (rootX != rootY)
		root[rootY] = rootX;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++)root[i] = i;

	for (int i = 1; i <= N; i++)
		scanf("%d", &price[i]);

	while (M--) {
		scanf("%d %d", &A, &B);
		Union(A, B);
	}

	for (int i = 1; i <= N; i++) {
		int father = Find(i);

		if (!minPrice[father])
			minPrice[father] = price[i];
		else if (minPrice[father] > price[i])
			minPrice[father] = price[i];
	}

	for (int i = 1; i <= N; i++)
		total += minPrice[i];

	if (total > K)puts("Oh no");
	else printf("%d", total);
}