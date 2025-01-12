#include <stdio.h>

int N;
char S[101];

int main(){
    scanf("%d ",&N);
    gets(S);
    
    for(int i=0;i<N;i++)
        if(S[i]=='I')printf("J");
        else if(S[i]=='O')printf("I");
        else printf("O");
}
