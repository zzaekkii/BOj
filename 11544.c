#include <stdio.h>

int N, M, B, C;
int prev,fut;

int main() {
	scanf("%d %d", &N, &M);

	while (M--) {
		scanf("%d", &B);
		int sum = 0, tmp = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &C);
			if (!i) tmp += C;
			if (i > 0)sum += C;
		}
		if (sum + tmp <= B) prev += tmp;
		int p = B - sum;
		int a = 0, x = 1;

		while (p >= x) {
			a = x;
			x *= 10;
		}
        if(a>10000)a=10000;

		fut += a;
	}
	printf("%d", fut - prev);
}
