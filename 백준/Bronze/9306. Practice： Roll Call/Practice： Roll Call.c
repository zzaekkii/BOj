#include <stdio.h>

int N;
char S[2][21];

int main(){
    scanf("%d ",&N);
    
    for(int c=1;c<=N;c++){
        for(int i=0;i<2;i++)
            gets(S[i]);
        printf("Case %d: %s, %s\n",c,S[1],S[0]);
    }
}