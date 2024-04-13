#include <stdio.h>
#include <stdlib.h>

int cmp(int*a,int*b){
    return *b-*a;
}

int N,A,B,C;
int D[10001];

int main(){
    scanf("%d%d%d%d",&N,&A,&B,&C);
    for(int i=0;i<N;i++)
        scanf("%d",&D[i]);
    qsort(D,N,4,cmp);
    
    int sum=A,kcal=C,mx=C/A;
    for(int i=0;i<N;i++){
        sum+=B;
        kcal+=D[i];
        if(mx<=kcal/sum)mx=kcal/sum;
        else break;
    }
    printf("%d",mx);
}
