#include <stdio.h>

typedef struct {
	int s, e;
} Emp;

int N;
int A[1001];
Emp E[1001];

int total, ans;

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &E[i].s, &E[i].e);
		for (int j = E[i].s; j < E[i].e; j++)
			A[j]++;
	}

	for (int i = 1; i <= 1000; i++)
		total += A[i] != 0;

	for (int i = 1; i <= N; i++) {
		int tmp = total;
		for (int j = E[i].s; j < E[i].e; j++)
			if (A[j] < 2)tmp--;
				
		if (ans < tmp)ans = tmp;
	}

	printf("%d", ans);
}
