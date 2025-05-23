#include <stdio.h>

int A, K;
int cnt;

int main(){
    scanf("%d %d",&A,&K);
    
    while(K>A){
        if(!(K%2)&&(K/2>=A))K/=2;
        else K--;
        cnt++;
    }
    
    printf("%d",cnt);
}