#include <stdio.h>
#include <math.h>

int main() {
	int N, p = 0;
	long long ans = 0; // int ������ ��� �� ����.
	scanf("%d", &N);

	while (N >= 9 * pow(10, p)) { // ��Ģ: 9*10�� i���� ��ŭ ���� ��.
		ans += 9 * pow(10, p)*(p+1); // �ڸ���: p+1
		N -= 9 * pow(10, p++);
	}

	printf("%lld", ans + N*(p+1));
}