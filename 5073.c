#include <stdio.h>
#include <stdlib.h>

int cmp(int* a, int* b) {
	return *b - *a;
}

int main() {
	int A[3], i;

	while (1) {
		for (i = 0; i < 3; i++)scanf("%d", &A[i]);
		qsort(A, 3, 4, cmp);

		if (A[0] == A[2] && A[0] == 0)break;
		if (A[0] >= A[1] + A[2])puts("Invalid");
		else if (A[0] == A[2])puts("Equilateral");
		else if (A[0] != A[1] && A[1] != A[2] && A[2] != A[0])puts("Scalene");
		else puts("Isosceles");
	}
}