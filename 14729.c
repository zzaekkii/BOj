// 14729번 칠무해 #정렬
#include <stdio.h>
#include <stdlib.h>

int N;
double stu[10000001];

int cmp(double* a, double* b) {
	return ( * a)*1000 - ( * b)*1000;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%lf", &stu[i]);

	qsort(stu, N, sizeof(double), cmp);

	for (int i = 0; i < 7; i++)
		printf("%.3lf\n", stu[i]);
}
