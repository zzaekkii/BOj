#include <stdio.h>
#include <string.h>

char S[51];

int main(){
    gets(S);
    int l=strlen(S);
    if(S[0]=='"'&&S[l-1]=='"'&&l>2)
        for(int i=1;i<l-1;i++)printf("%c",S[i]);
    else puts("CE");
}
