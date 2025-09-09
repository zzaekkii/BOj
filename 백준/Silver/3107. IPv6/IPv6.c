#include <stdio.h>
#include <string.h>

char S[45];
char ip_v6[45];

int main(){
    gets(S);
    
    int cnt=0, total=7;
    for(int i=0;S[i];i++)
        if(S[i]==':')cnt++;
    
    int idx=0;
    int len=strlen(S);
    for(int i=len-1;i>=0;i--){
        if(S[i]==':'){
            while(idx%4){
                ip_v6[idx++]='0';
            }
            cnt--, total--;
            
            if(i>0&&S[i-1]==':'){
                cnt--, total--;
                
                int tmp=total+1-cnt;
                if(i==len-1)tmp+=1;
                for(int j=0;j<4*(tmp);j++)
                    ip_v6[idx++]='0';
            }
        }
        else ip_v6[idx++]=S[i];
    }
    
    while(idx<32){
        ip_v6[idx++]='0';
    }
    
    for(int i=idx-1;i>=0;i--){
        printf("%c",ip_v6[i]);
        
        if(i!=0&&!(i%4))printf(":");
    }
}