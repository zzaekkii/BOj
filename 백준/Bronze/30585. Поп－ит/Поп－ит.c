#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))

int N, M;
char S[101];
int color[2];

int main(){
    scanf("%d %d ",&N,&M);
    
    while(N--){
        gets(S);
        for(int i=0;i<M;i++)
            if(S[i]==48)color[0]++;
            else color[1]++;
    }
    
    printf("%d",min(color[0],color[1]));
}