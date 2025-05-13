#include <stdio.h>

// SciComLove

char S[11];
int up[26], low[26];
int ans;

int main(){
    up['S'-'A']=up['C'-'A']=up['L'-'A']=1;
    low['c'-'a']=low['i'-'a']=low['m'-'a']=low['v'-'a']=low['e'-'a']=1;
    low['o'-'a']=2;
    
    gets(S);
    
    for(int i=0;S[i];i++){
        if(S[i]>='a'){
            if(low[S[i]-'a'])low[S[i]-'a']--;
            else ans++;
        }
        else{
            if(up[S[i]-'A'])up[S[i]-'A']--;
            else ans++;
        }
    }
    
    printf("%d",ans);
}