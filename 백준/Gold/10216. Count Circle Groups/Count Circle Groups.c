#include <stdio.h>

typedef struct Barracks {
	int x, y, r; // 좌표 + 통신범위. 
}Barracks;

int T, N;
Barracks B[3001];
int root[3001];
int rank[3001];

void Init(int x) {
	for (int i = 0; i <= x; i++) {
        root[i] = i;
        rank[i] = 0;
    }
}

int Find(int x) {
	if (root[x] == x)return x;
	return root[x] = Find(root[x]);
}

void Union(int x, int y) {
	int rootX = Find(x);
	int rootY = Find(y);

	if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            root[rootX] = rootY;
		else {
            root[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) rank[rootX]++;
        }
    }
}

_Bool isAbut(Barracks A, Barracks B) {
	int dx = A.x - B.x;
	int dy = A.y - B.y;

	int distance = dx * dx + dy * dy;
	int radiusSum = A.r + B.r;
	return distance <= radiusSum * radiusSum;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		Init(N);

		for (int i = 0; i < N; i++)
			scanf("%d %d %d", &B[i].x, &B[i].y, &B[i].r);

		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
				if (isAbut(B[i], B[j]))
					Union(i, j);

		int cnt = 0;
		_Bool visited[3001] = { 0 };
		for (int i = 0; i < N; i++) {
			int headquarter = Find(i);

			if (!visited[headquarter]) {
				visited[headquarter] = 1;
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}
}