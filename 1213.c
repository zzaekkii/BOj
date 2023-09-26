#include <stdio.h>
#include <string.h>

char S[51];
int a[26];
int odd, x=-1;

int main(){
    gets(S);
    int l=strlen(S);
    for(int i=0;i<l;i++)
        a[S[i]-65]++;
    for(int i=0;i<26;i++)
        if(a[i]%2)odd++;
    
    if(!(l%2)&&odd||odd>1){
        puts("I'm Sorry Hansoo");
        return 0;
    }
    for(int i=0;i<26;i++){
        if(a[i]==1){
            a[i]--;
            x=i;
            continue;
        }
        for(int j=0;j<a[i]/2;j++)printf("%c",65+i);
        if(a[i]%2){
            x=i;
            a[i]--;
        }
        a[i]/=2;
    }
    if(x!=-1)printf("%c",x+65);
    for(int i=25;i>=0;i--)
        for(int j=0;j<a[i];j++)printf("%c",65+i);
}
