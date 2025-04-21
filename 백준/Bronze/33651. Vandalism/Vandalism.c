#include <stdio.h>

char S[4];
_Bool ex[26];

int main(){
    gets(S);
    
    for(int i=0;S[i];i++)
        ex[S[i]-65]++;
    
    if(!ex['U'-65])printf("U");
    if(!ex['A'-65])printf("A");
    if(!ex['P'-65])printf("P");
    if(!ex['C'-65])printf("C");
}