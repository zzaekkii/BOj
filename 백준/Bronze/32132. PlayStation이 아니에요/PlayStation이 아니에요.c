#include <stdio.h>

int N;
char S[51];

int idx;
char ans[51];

int main(){
    scanf("%d %s", &N, S);
    
    _Bool flag=0;
    for(int i=0;i<N;i++){
        while(flag&&(i<N)&&(S[i]=='4'||S[i]=='5')){
            i++;
        }
        flag=0;
        
        if(S[i]=='P'&&(i+1<N)&&S[i+1]=='S'){
            flag=1;
            ans[idx++]=S[i++];
        }
        
        ans[idx++]=S[i];
    }
    ans[idx]=0;
    
    puts(ans);
}