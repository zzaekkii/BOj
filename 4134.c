#include <stdio.h>

int T;
unsigned int N;

_Bool Prime(unsigned int n){
    if(n<=1)return 0;
    if(n<=3)return 1;
    if(!(n%2)||!(n%3))return 0;
    for(unsigned int i=5;i*i<=n;i+=6)
        if(!(n%i)||!(n%(i+2)))return 0;
    return 1;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%u",&N);
        while(!Prime(N))N++;
        printf("%u\n",N);
    }
}
