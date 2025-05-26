// 11279번 최대 힙 - 실버2 / 우선순위 큐, 최대 힙
#include <stdio.h>

int N, O;
int heap[100001];
int pos = 1;

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void insert(int val) {
	int idx = pos;
	heap[pos++] = val;

	// 부모보다 크면 위치 교환 반복.
	while ((idx > 1) && (heap[idx >> 1] < heap[idx])) {
		swap(&heap[idx], &heap[idx >> 1]);
		idx >>= 1;
	}
}

int delete() {
	if (pos == 1) return 0;

	int top = 1, ret = heap[1];

	// 가장 마지막 원소를 루트로 올림.
	heap[top] = heap[--pos];
	heap[pos] = 0;

	while ((top << 1) < pos) {
		int child = top << 1;

		// 두 자식 중 더 큰 애로 타겟.
		if (child + 1 < pos && heap[child + 1] > heap[child]) child++;

		if (heap[child] > heap[top]) {
			swap(&heap[top], &heap[child]);
			top = child;
		}
        else break;
	}

	return ret;
}

int main() {
	scanf("%d", &N);

	while (N--) {
		scanf("%d", &O);

		if (!O) printf("%d\n", delete());
		else insert(O);
	}
}