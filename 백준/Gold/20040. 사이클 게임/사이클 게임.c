// 20040번 사이클 게임 - 골드5 / 유니온 파인드
#include <stdio.h>

int N, M;
int A, B;
int root[500001];
int rank[500001];
int ans;

int Find(int x) {
	if (root[x] == x)return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	int rootX = root[x];
	int rootY = root[y];

	if (rootX != rootY) {
		if (rank[rootX] > rank[rootY]) {
			root[rootY] = rootX;
		} else if (rank[rootX] < rank[rootY]) {
			root[rootX] = rootY;
		} else {
			root[rootY] = rootX;
			rank[rootX]++;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)root[i] = i;

	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &A, &B);

		if (Find(A) == Find(B)) {
			ans = i;
			break;
		}
		else Union(A, B);
	}

	printf("%d", ans);
}