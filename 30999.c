#include <stdio.h>

int N,M;
char S[101];
int ans;

int main(){
    scanf("%d %d ",&N,&M);
    while(N--){
        int t=0;
        gets(S);
        for(int j=0;S[j];j++)
            if(S[j]=='O')t++;
        if(t>M/2)ans++;
    }
    printf("%d",ans);
}
