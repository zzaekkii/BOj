#include <stdio.h>
long long A, B;

long long GCD(long long a, long long b){
	if (!b)return a;
	else return GCD(b, a % b);
}
int main(){
    scanf("%lld %lld",&A,&B);
    printf("%lld",A*B/GCD(A,B));
}
