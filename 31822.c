#include <stdio.h>

char S[11],T[11];
int N;
int cnt;

int main(){
    gets(S);
    scanf("%d ",&N);
    while(N--){
        gets(T);
        _Bool flag=1;
        for(int i=0;i<5;i++)
            if(S[i]!=T[i])flag=0;
        if(flag)cnt++;
    }
    printf("%d",cnt);
}
