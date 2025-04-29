#include <stdio.h>
#include <string.h>

char S[500001];

int main(){
    gets(S);
    
    // 0번째는 무조건 '('로 시작함.
    printf("(");
    
    int l=strlen(S);
    for(int i=1;i<l;i++){
        if(S[i-1]==')'&&S[i]=='(')printf("+(");
        else if(S[i-1]=='('&&S[i]==')')printf("1)");
        else printf("%c",S[i]);
    }
}