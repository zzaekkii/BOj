#include <stdio.h>

int N,L;
int ans;
char S[20];

char* itos(int num){
    sprintf(S,"%d",num);
    return S;
}

int main(){
    scanf("%d %d",&N,&L);
    while(N--)
        while(strchr(itos(++ans),L+48));
    printf("%d",ans);
}
