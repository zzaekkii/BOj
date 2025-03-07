#include <stdio.h>

int T, N;
int arr[11];

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        printf("Denominations:");
        for(int i=0;i<N;i++){
            scanf("%d",&arr[i]);
            printf(" %d",arr[i]);
        }
        
        _Bool flag=1;
        for(int i=1;i<N;i++)
            if(arr[i]<arr[i-1]*2)flag=0;
        
        printf("\n%s coin denominations!\n\n",flag?"Good":"Bad");
    }
}