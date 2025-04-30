#include <stdio.h>

int N;
int arr[101];

int main(){
    while(1){
        scanf("%d",&N);
        if(!N)break;
        
        for(int i=0;i<N;i++)
            scanf("%d",&arr[i]);
        
        for(int i=N-1;i>=0;i--)
            printf("%d\n",arr[i]);
        
        puts("0");
    }
}