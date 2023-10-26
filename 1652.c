#include <stdio.h>

int N, w, l, sp;
char S[101][101];

int main(){
    scanf("%d ",&N);
    for(int i=0;i<N;i++)gets(S[i]);
    
    for(int i=0;i<N;i++){
        for(int j=sp=0;j<N;j++){
            if(S[i][j]=='X'){
                if(sp>1)w++;
                sp=0;continue;
            }
            else sp++;
        }
        if(sp>1)w++;
        
        for(int j=sp=0;j<N;j++){
            if(S[j][i]=='X'){
                if(sp>1)l++;
                sp=0;continue;
            }
            else sp++;
        }
        if(sp>1)l++;
    }
    printf("%d %d",w,l);
}
