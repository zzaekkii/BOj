#include <stdio.h>
#include <string.h>

int N, l;
char P[4];
char S[101];

int main(){
    scanf("%d ",&N);
    gets(P);
    while(N--){
        gets(S);
        l=strlen(S);
        puts(P[0]==S[0]&&P[2]==S[l-1]?"DA":"NE");
    }
}
