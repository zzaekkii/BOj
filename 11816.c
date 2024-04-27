#include <stdio.h>
#include <string.h>

char S[10];
int ans;

int main(){
    gets(S);
    int l=strlen(S);
    if(S[0]!=48)puts(S);
    else if(S[1]!=120){
        for(int i=1;i<l;i++){
            int tmp=1;
            for(int j=0;j<i-1;j++)
                tmp*=8;
            ans+=(S[l-i]-48)*tmp;
        }
        printf("%d",ans);
    }
    else{
        for(int i=1;i<l-1;i++){
            int tmp=1;
            for(int j=0;j<i-1;j++)
                tmp*=16;
            
            ans+=(S[l-i]>96?S[l-i]-96+9:S[l-i]-48)*tmp;
        }
        printf("%d",ans);
    }
}
