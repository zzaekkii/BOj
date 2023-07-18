#include <stdio.h>

int main(){
    int A,B,C;
    scanf("%d%d%d",&A,&B,&C);
    if(A==B&&B==C)
        puts("*");
    else if(B==C)
        puts("A");
    else if(A==C)
        puts("B");
    else puts("C");
}
