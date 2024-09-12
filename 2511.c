#include <stdio.h>

int A[11],B[11];
int f=0;

int main(){
    for(int i=1;i<11;i++)
        scanf("%d",&A[i]);
    for(int i=1;i<11;i++)
        scanf("%d",&B[i]);
    
    for(int i=1;i<11;i++)
        if(A[i]>B[i])A[0]+=3,f=1;
        else if(A[i]<B[i])B[0]+=3,f=-1;
        else A[0]++,B[0]++;
    
    printf("%d %d\n%c",A[0],B[0],A[0]>B[0]?'A':A[0]<B[0]?'B':!f?'D':f==1?'A':'B');
}
