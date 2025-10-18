#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(const char* s) {
    char str[100001];
    strcpy(str, s);
    
    int st[100001];
    st[1]=str[0];
    
    int idx=1;
    int len=strlen(str);
    for(int i=1;i<len;i++){
        if(st[idx]=='('&&str[i]==')'){
            idx--;
        }
        else{
            st[++idx]=str[i];
        }
    }
    
    return (idx==0);
}