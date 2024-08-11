#include <stdio.h>
#include <math.h>

typedef struct Point {
	long long x, y; // 곱셈 과정에서 int 범위 넘어감.
} Point;

int N;
Point p[10001];
double ans;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%lld %lld", &p[i].x, &p[i].y);

	for (int i = 1; i < N - 1; i++)
		ans += (double)(p[0].x * p[i].y + p[i].x * p[i + 1].y + p[i + 1].x * p[0].y 
			- p[0].x * p[i + 1].y - p[i].x * p[0].y - p[i + 1].x * p[i].y) / 2;

	printf("%.1lf", fabs(ans));
}
