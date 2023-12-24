#include <stdio.h>
#include <string.h>

int N;
char *ret;
char S[101];
int vis[101];
char A[101];

int main(){
    gets(S);
    int l=strlen(S);
    scanf("%d ",&N);
    while(N--){
        gets(A);
        int end=strlen(A);
        ret=strstr(S,A);
        while(ret!=NULL){
            int st=ret-S;
            for(int i=st;i<st+end;i++)vis[i]=1;
            ret=strstr(ret+end,A);
        }
    }
    int f=1;
    for(int i=0;i<l;i++)
        if(!vis[i])f=0;
    puts(f?"1":"0");
}
