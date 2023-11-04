#include <stdio.h>
int N;

int main(){
    scanf("%d",&N);
    int sum=N*(N+1)/2;
    int tp=0;
    for(int i=1;i<=N;i++)
        tp+=i*i*i;
    printf("%d\n%d\n%d",sum,sum*sum,tp);
}
