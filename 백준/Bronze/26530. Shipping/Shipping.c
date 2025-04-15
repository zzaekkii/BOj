#include <stdio.h>

int T, N, cnt;
char S[51];
double cost, total;

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d ",&N);
        
        total=0;
        while(N--){
            scanf("%s %d %lf ",S,&cnt,&cost);
            total+=cost*cnt;
        }
        
        printf("$%.2lf\n",total);
    }
}