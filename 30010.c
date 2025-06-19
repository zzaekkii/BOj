#include <stdio.h>

int N;

int main(){
    scanf("%d",&N);
    
    printf("%d",N);
    for(int i=1;i<N;i++)
        printf(" %d",i);
}
