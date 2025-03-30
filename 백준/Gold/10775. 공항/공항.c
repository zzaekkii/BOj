#include <stdio.h>

int G, P, T;
int root[100001];
int cnt;

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
	scanf("%d %d", &G, &P);

	for (int i = 1; i <= G; i++)root[i] = i;

	while (P--) {
		scanf("%d", &T);

		T = Find(T);

		if (!T)break;

		Union(T - 1, T);
		cnt++;
	}

	printf("%d", cnt);
}