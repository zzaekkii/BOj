#include <stdio.h>

int T;
int mn=500;
int sum;

int main(){
    for(int i=0;i<4;i++){
        scanf("%d",&T);
        if(mn>T)mn=T;
        sum+=T;
    }
    printf("%d",sum-mn+1);
}
