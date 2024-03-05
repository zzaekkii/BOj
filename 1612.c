#include <stdio.h>

int N;
int i,tmp;

int main(){
    scanf("%d",&N);
    if(!(N%2&&N%5))puts("-1");
    else{
        for(i=1;;i++){
            tmp=(10*tmp+1)%N;
            if(!(tmp%N))break;
        }
        printf("%d",i);
    }
}
