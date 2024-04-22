#include <stdio.h>

char S[10];
int ans;

int main(){
    for(int i=0;i<8;i++){
        scanf("%s",S);
        for(int j=0;j<8;j++){
            if(S[j]=='p')ans-=1;
            else if(S[j]=='P')ans+=1;
            else if(S[j]=='n')ans-=3;
            else if(S[j]=='N')ans+=3;
            else if(S[j]=='b')ans-=3;
            else if(S[j]=='B')ans+=3;
            else if(S[j]=='r')ans-=5;
            else if(S[j]=='R')ans+=5;
            else if(S[j]=='q')ans-=9;
            else if(S[j]=='Q')ans+=9;
        }
    }
    printf("%d",ans);
}
