#include <stdio.h>
long long R,C,N,X,Y;

int main(){
    scanf("%lld %lld %lld",&R,&C,&N);
    if(R%N)X=R/N+1;
    else X=R/N;
    if(C%N)Y=C/N+1;
    else Y=C/N;
    printf("%lld",X*Y);
}
