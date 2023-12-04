#include <stdio.h>
char S[100001];
int L;
int main(){
    scanf("%d ",&L);
    gets(S);
    for(int i=5;i>0;i--)
        printf("%c",S[L-i]);
}
