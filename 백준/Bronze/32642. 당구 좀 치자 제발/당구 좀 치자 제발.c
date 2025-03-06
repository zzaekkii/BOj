#include <stdio.h>

int N;

_Bool wth;
int cur;
long long sum;

int main(){
    scanf("%d",&N);
    while(N--){
        scanf("%d",&wth);
        if(wth){
            cur++;
            sum+=cur;
        }
        else{
            cur--;
            sum+=cur;
        }
    }
    
    printf("%lld",sum);
}