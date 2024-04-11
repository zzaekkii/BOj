#include <stdio.h>

int N,T;
char S[6];

int bd[2];
int sco[101];
int tmp[101];
int ans[2];
int top=2880;

int main(){
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        scanf("%d %s",&T,S);
        bd[T-1]++;
        sco[i]=T-1;
        tmp[i]=(S[0]-48)*600+(S[1]-48)*60+(S[3]-48)*10+(S[4]-48);
    }
    
    for(int i=N-1;i>=0;i--){
        if(bd[1]>bd[0])ans[1]+=top-tmp[i];
        if(bd[0]>bd[1])ans[0]+=top-tmp[i];
        top=tmp[i];
        bd[sco[i]]--;
    }
    
    for(int i=0;i<2;i++)
        printf("%02d:%02d\n",ans[i]/60,ans[i]%60);
}
