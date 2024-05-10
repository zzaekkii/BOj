#include <stdio.h>

_Bool ch[3];
char S[21];

int main(){
    for(int i=0;i<3;i++){
        gets(S);
        if(S[0]=='l')ch[0]=1;
        else if(S[0]=='k')ch[1]=1;
        else if(S[0]=='p')ch[2]=1;
    }
    _Bool f=1;
    for(int i=0;i<3;i++)
        if(!ch[i])f=0;
    
    puts(f?"GLOBAL":"PONIX");
}
