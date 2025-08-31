#include <stdio.h>
#include <string.h>

char S[1001];

int main(){
    gets(S);
    
    char *ret=strstr(S,"DKSH");
    
    int cnt=0;
    while(ret!=0){
        cnt++;
        ret=strstr(ret+4,"DKSH");
    }
    
    printf("%d",cnt);
}