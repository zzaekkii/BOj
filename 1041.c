#include <stdio.h>
typedef long long ll;

int N;
int cube[6];
ll ans; // 최종 합.

// [3면]: (4)개, [2면]: (8N-16+4)개, [1면]: 5N^2-20N+20+4N-8.
int main() {
	scanf("%d", &N);

	for (int i = 0; i < 6; i++)
		scanf("%d", &cube[i]);

	if (N == 1) {
		int sum = 0;
		int maxx = 0;
		for (int i = 0; i < 6; i++) {
			if (maxx < cube[i])maxx = cube[i];
			sum += cube[i];
		}
		ans = sum - maxx;
	}
	else {
		// 대척점에 있는 인덱스 (접하지 않음)
		// 0-5, 1-4, 2-3 => 5 - i로 표현 가능.

		// 3면 중 최소합.
		int sum_3 = 0x7fffffff;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
				if (j != i && j != 5 - i)
					for (int k = 0; k < 6; k++)
						if (k != i && k != 5 - i && k != j && k != 5 - j && sum_3 > cube[i] + cube[j] + cube[k])
							sum_3 = cube[i] + cube[j] + cube[k];

		// 2면 중 최소합.
		int sum_2 = 0x7fffffff;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
				if (j != i && j != 5 - i && sum_2 > cube[i] + cube[j])
					sum_2 = cube[i] + cube[j];

		// 주사위에 쓰인 최솟값.
		ll minn = cube[0];
		for (int i = 1; i < 6; i++)
			if (minn > cube[i])minn = cube[i];

		if (N == 2) ans = sum_3 * 4 + sum_2 * 4;
		else ans = sum_3 * 4 + sum_2 * (8 * N - 12) + minn * ((ll)5 * N * N - 16 * N + 12);
	}

	printf("%lld", ans);
}
