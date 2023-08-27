#include <stdio.h>
long long A[2], B[2];

long long GCD(long long a, long long b){
	if (!b)return a;
	else return GCD(b, a % b);
}

int main(){
    for(int i=0;i<2;i++)
        scanf("%lld %lld", &A[i], &B[i]);
    A[0]*=B[1], A[1]*=B[0];
    A[0]+=A[1], B[0]*=B[1];
    printf("%lld %lld",A[0]/GCD(A[0],B[0]),B[0]/GCD(A[0],B[0]));
}
