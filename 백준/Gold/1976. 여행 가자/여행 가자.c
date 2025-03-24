#include <stdio.h>

int N, M; // 도시 N곳, 여행지 M곳.
int T; // 도시 연결 정보 입력값 & 이후 여행지.
int A; // 계획된 첫 여행지.

int root[201];

int Find(int x) {
	if (root[x] == x)
		return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	int rootX = Find(x);
	int rootY = Find(y);

	if (rootX != rootY)
		root[rootY] = rootX;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		root[i] = i;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &T);
			if (T) Union(i, j);
		}

	scanf("%d", &A);
	A = Find(A);

	_Bool flag = 1;
	while (--M) {
		scanf("%d", &T);

		if (A != Find(T))
			flag = 0;
	}

	puts(flag ? "YES" : "NO");
}