#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

int N;
ll T;
ll arr[1000001];

int cmp(ll* a, ll* b) {
    if(*a>*b)return 1;
    else if(*a<*b)return -1;
	return 0;
}

ll reverse(ll x) {
	ll tmp = 0;

	while (x > 0) {
		tmp = tmp * 10 + x % 10;
		x /= 10;
	}

	return tmp;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &T);
		arr[i] = reverse(T);
	}

	qsort(arr, N, sizeof(ll), cmp);

	for (int i = 0; i < N; i++)
		printf("%lld\n", arr[i]);
}