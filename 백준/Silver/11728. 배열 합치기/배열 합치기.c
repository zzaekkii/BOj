#include <stdio.h>
#include <stdlib.h>

int N,M;
int A[2000001];

int cmp(int* a, int* b){
    return *a-*b;
}

int main(){
    scanf("%d %d",&N,&M);
    N+=M;
    
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    
    qsort(A,N,sizeof(int),cmp);
    
    for(int i=0;i<N;i++)
        printf("%d ",A[i]);
}