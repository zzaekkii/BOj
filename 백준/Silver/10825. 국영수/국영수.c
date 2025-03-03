#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
	char name[11];
	int kor, eng, math;
}Student;

int N;
Student stu[100001];

// 국어 잘하는, 영어 못하는, 수학 잘하는, 이름 오름차순.
int cmp(Student* a, Student* b) {
	if ((*a).kor != (*b).kor) return (*b).kor - (*a).kor;
	if ((*a).eng != (*b).eng) return (*a).eng - (*b).eng;
	if ((*a).math != (*b).math) return (*b).math - (*a).math;
	return strcmp((*a).name, (*b).name);
}

int main() {
	scanf("%d ", &N);

	for (int i = 0; i < N; i++)
		scanf("%s %d %d %d ", stu[i].name, &stu[i].kor, &stu[i].eng, &stu[i].math);

	qsort(stu, N, sizeof(Student), cmp);

	for (int i = 0; i < N; i++)
		printf("%s\n", stu[i].name);
}