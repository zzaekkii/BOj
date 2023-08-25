#include <stdio.h>
int N,a=1;
int main(){
    scanf("%d",&N);
    while(N--){
        a*=N+1;
        a%=10;
    }
    printf("%d",a%10);
}
