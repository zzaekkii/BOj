#include <stdio.h>
#include <string.h>

char S[51];

_Bool isVowel(char c){
    if(c=='a'||c=='e'||c=='o'||c=='u'||c=='i'
       ||c=='A'||c=='E'||c=='O'||c=='U'||c=='I') // 첫글자만 모음일까봐.
        return 1;
    return 0;
}

int main(){
    gets(S);
    
    if(!strcmp(S,"Britain"))puts("Britaintry");
    else{
        int l=strlen(S);
        
        if(isVowel(S[l-1]))printf("%sntry",S);
        else{
            int idx=l-1;
            for(;idx>=0;idx--)
                if(isVowel(S[idx]))break;
            
            for(int i=0;i<=idx;i++)printf("%c",S[i]);
            puts("ntry");
        }
    }
}