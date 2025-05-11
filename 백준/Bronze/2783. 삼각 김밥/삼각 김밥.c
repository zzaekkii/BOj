#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))

int N;
double X, Y;
double ans;

int main(){
    scanf("%lf %lf", &X, &Y);
    ans=(X*1000)/Y;
    
    scanf("%d",&N);
    
    while(N--){
        scanf("%lf %lf", &X, &Y);
        ans=min(ans,(X*1000)/Y);
    }
    
    printf("%.2lf", ans);
}