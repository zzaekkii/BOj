#include <stdio.h>

int N, T;
char S[43][21];

int main(){
    scanf("%d",&N);
    for(int i=1;i<N;i++){
        scanf("%d ",&T);
        while(T--)scanf("%s",S[0]);
    }
    
    scanf("%d ",&T);
    for(int i=0;i<T;i++)scanf("%s",S[i]);
    
    printf("%d\n",T);
    for(int i=0;i<T;i++)puts(S[i]);
}
