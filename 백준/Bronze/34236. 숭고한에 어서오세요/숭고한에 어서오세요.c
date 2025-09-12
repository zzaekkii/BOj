#include <stdio.h>

int N, A, B;

int main(){
    scanf("%d",&N);
    
    for(int i=0;i<N-1;i++)
        scanf("%d",&A);
    
    scanf("%d",&B);
    
    printf("%d",B+(B-A));
}