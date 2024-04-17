#include <stdio.h>
#define ll long long

ll N;

int main(){
    scanf("%lld",&N);
    
    ll t=N;
    for(ll i=2;i*i<=N;i++){
        if(!(N%i))t=t/i*(i-1);
        while(!(N%i))N/=i;
    }
    
    printf("%lld",N==1?t:t/N*(N-1));
}
