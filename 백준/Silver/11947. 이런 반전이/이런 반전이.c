#include <stdio.h>
#include <string.h>

int T;
char num[11];

int powTen(int x) {
	int res = 1;
	while (x--)res *= 10;
	return res;
}

int main() {
	scanf("%d ", &T);

	while (T--) {
		gets(num);

		long long ans = 0;
		int len = strlen(num);

		if (num[0] >= '5') {
			long long tmp = 5 * powTen(len - 1);
			ans = tmp * (tmp - 1);
		}
		else {
			// 첫 자리에 0이랑 9는 없음.
			long long tmp1 = (num[0] - 48), tmp2 = 9 - (num[0] - 48);

			for (int i = 1; i < len; i++) {
				tmp1 = tmp1 * 10 + (num[i] - 48);
				tmp2 = tmp2 * 10 + (9 - (num[i] - 48));
			}
			ans = tmp1 * tmp2;
		}

		printf("%lld\n", ans);
	}
}