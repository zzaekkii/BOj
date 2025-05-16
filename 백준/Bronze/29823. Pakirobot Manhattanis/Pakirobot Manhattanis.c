#include <stdio.h>

int N;
char S[1001];
int dir[2];
int cnt;

int main(){
    scanf("%d ",&N);
    gets(S);
    
    for(int i=0;i<N;i++){
        if(S[i]=='N')dir[0]++;
        else if(S[i]=='S')dir[0]--;
        else if(S[i]=='E')dir[1]++;
        else if(S[i]=='W')dir[1]--;
    }
    
    cnt=(dir[0]<0?-dir[0]:dir[0])+(dir[1]<0?-dir[1]:dir[1]);
    printf("%d",cnt);
}