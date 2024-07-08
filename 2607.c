#include <stdio.h>
#include <string.h>

int N;
int alph[26],tmp[26];
char S[11];
int ans;

int main(){
    scanf("%d ",&N);
    scanf("%s",S);
    int l=strlen(S);
    for(int i=0;S[i];i++)
        alph[S[i]-65]++;
    
    for(int i=1;i<N;i++){
        scanf("%s",S);
        int cl=strlen(S);
        
        for(int j=0;j<26;j++)
            tmp[j]=0;
        for(int j=0;j<cl;j++)
            tmp[S[j]-65]++;
        
        _Bool f=1;
        int mn=0,pl=0;
        for(int j=0;j<26;j++){
            if(alph[j]!=tmp[j]){
                if(alph[j]-tmp[j]==1)mn++;
                else if(alph[j]-tmp[j]==-1)pl++;
                else f=0;
            }
        }
        
        if(f){
            if(l==cl&&!mn&&!pl)ans++;
            else if(l==cl&&mn==1&&pl==1)ans++;
            else if(l+1==cl&&!mn&&pl==1)ans++;
            else if(l-1==cl&&mn==1&&!pl)ans++;
        }
    }
    printf("%d",ans);
}
