#include <stdio.h>

char S[5];
_Bool flag;

int main(){
    for(int i=0;i<2;i++)scanf("%c",&S[i]);
    getchar();
    for(int i=3;i>=2;i--)scanf("%c",&S[i]);
    
    for(int i=0;i<4;i++)
        if(S[i]=='H'&&S[(i+1)%4]=='E'&&S[(i+2)%4]=='P'&&S[(i+3)%4]=='C')
            flag=1;
    
    for(int i=0;i<4;i++)
        if(S[i]=='H'&&S[(i+4-1)%4]=='E'&&S[(i+4-2)%4]=='P'&&S[(i+4-3)%4]=='C')
            flag=1;
    
    puts(flag?"YES":"NO");
}