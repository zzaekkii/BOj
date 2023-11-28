#include <stdio.h>
int N;

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        printf("%d ",i);
        if(!(i%6)||i==N) printf("Go! ");
    }
}
