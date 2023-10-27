#include <stdio.h>
int N, A, B, C;
int main(){
    scanf("%d",&N);
    while(N--){
        scanf("%d%d%d",&A,&B,&C);
        printf("%d\n",A*(C-1)+B);
    }
}
