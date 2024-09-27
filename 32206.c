#include <stdio.h>

int N;
char S[200001];

int main(){
    scanf("%d ",&N);
    gets(S);
    printf("%d",(N+1)*26-N);
}
