#include <stdio.h>
#include <stdlib.h>

typedef struct Friend{
    char name[21];
    int num;
}Friend;

int T, N;
Friend F[501];

int cmp(Friend* a, Friend* b){
    return (*b).num-(*a).num;
}

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d ",&N);
        
        for(int i=0;i<N;i++)
            scanf("%s %d ",F[i].name,&F[i].num);
        
        qsort(F,N,sizeof(Friend),cmp);
        
        for(int i=0;i<N-1;i++)
            printf("%s, ",F[i].name);
        
        printf("%s\n",F[N-1].name);
    }
}