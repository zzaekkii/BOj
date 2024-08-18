#include <stdio.h>
#include <stdlib.h>

int cmp(int* a, int* b) {
	return *b - *a;
}

int A[3];

int main(){
    for(int i=0;i<3;i++)
        scanf("%d",&A[i]);
    
    qsort(A,3,4,cmp);
    
    printf("%d",A[1]);
}
