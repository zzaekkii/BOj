#include <stdio.h>
#include <string.h>

char S[51];

_Bool is_palindrom(char *s){
    int l=strlen(s);
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-1-i])
            return 0;
    }
    
    return 1;
}

int main(){
    gets(S);
    
    for(int i=0;S[i];i++){
        char sub[51];
        strcpy(sub,S+i);
        
        if(is_palindrom(sub)){
            printf("%d",strlen(S)+i);
            break;
        }
    }
}