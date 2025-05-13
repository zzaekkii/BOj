#include <stdio.h>

char p[]="SciComLove";

char S[11];
int ans;

int main(){
    gets(S);
    
    for(int i=0;S[i];i++)
        if(S[i]!=p[i])ans++;
    
    printf("%d",ans);
}