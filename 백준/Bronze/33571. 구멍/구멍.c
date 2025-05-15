#include <stdio.h>

int lo[]={1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0};
int up[]={1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};

char S[1001];
int cnt;

int main(){
    gets(S);
    
    for(int i=0;S[i];i++){
        if(S[i]=='@')cnt++;
        else if('a'<=S[i]&&S[i]<='z')cnt+=lo[S[i]-97];
        else if('A'<=S[i]&&S[i]<='Z')cnt+=up[S[i]-65];
    }
    
    printf("%d",cnt);
}