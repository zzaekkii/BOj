#include <stdio.h>

int N, A, B, C;
char O;

int root[1000001];
int robot[1000001];

void Init() {
	for (int i = 0; i < 1000001; i++) {
		root[i] = i;
		robot[i] = 1;
	}
}

int Find(int x) {
	if (root[x] == x) return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	int rootX = Find(x);
	int rootY = Find(y);

	if (rootX != rootY) {
		root[rootY] = rootX;
		robot[rootX]+=robot[rootY];
	}
}

int main() {
	Init();

	scanf("%d ", &N);

	while (N--) {
		scanf("%c", &O);

		switch (O) {
		case 'I':
			scanf("%d %d ", &A, &B);
			Union(A, B);
			break;
		case 'Q':
			scanf("%d ", &C);
			printf("%d\n", robot[Find(C)]);
			break;
		}
	}
}