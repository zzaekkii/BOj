#include <stdio.h>

int N,D;
int arr[31];
int total;

int main(){
    scanf("%d %d",&N,&D);
    
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        total+=arr[i];
    }
    
    D/=total;
    
    for(int i=0;i<N;i++)
        printf("%d\n",arr[i]*D);
}
