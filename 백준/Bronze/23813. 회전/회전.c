#include <stdio.h>

long long total;
int N;
int sum;

int main(){
    scanf("%d",&N);
    
    int size=0;
    while(N){
        sum+=N%10;
        N/=10;
        size++;
    }
    
    for(int i=0,x=1;i<size;i++,x*=10){
        total+=(long long)x*sum;
    }
    
    printf("%lld",total);
}