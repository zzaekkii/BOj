#include <stdio.h>

int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

int T, N, R1, C1, R2, C2;

int main() {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		_Bool flag = 0;
		scanf("%d %d %d %d %d", &N, &R1, &C1, &R2, &C2);
		for (int i = 0; i < 8; i++) {
			int nx = R1 + dx[i];
			int ny = C1 + dy[i];
			if (nx == R2 && ny == C2) {
				flag = 1;
				break;
			}
		}
		printf("Case %d: %s\n", t, flag ? "YES" : "NO");
	}
}
