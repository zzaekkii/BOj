// 1717 집합의 표현 - 골드5 / #Union-find
#include <stdio.h>

int N, M; // 원소 0-N, 연산 M개.
int O, A, B; // 두 원소 A, B에 대한 명령 O(0: 합, 1: 확인)

int root[1000001];

int find(int x) {
	if (root[x] == x)
		return x;
	return root[x] = find(root[x]);
}

void union_set(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);

	if (rootX != rootY)
		root[rootY] = rootX;
}

int main() {
	scanf("%d %d", &N, &M);

	// 처음에는 자기 자신으로 초기화.
	for (int i = 0; i <= N; i++)
		root[i] = i;

	while (M--) {
		scanf("%d %d %d", &O, &A, &B);

		switch (O) {
		// 합집합 연산.
		case 0:
			union_set(A, B);
			break;

		// 같은 집합에 속해있는지 확인.
		case 1:
			puts(find(A) == find(B) ? "YES" : "NO");
			break;
		}
	}
}