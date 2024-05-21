#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char A[5],B[5],C[5];

int main(){
    scanf("%s %s %s",A,B,C);
    printf("%d\n",atoi(A)+atoi(B)-atoi(C));
    
    strcat(A,B);
    printf("%d",atoi(A)-atoi(C));
}
