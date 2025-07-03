#include <stdio.h>

char S[81];
_Bool ans=1,hyphen;
int lenU,lenT;

int main(){
    gets(S);
    
    int i;
    for(i=0;S[i];i++){
        if(!hyphen&&S[i]=='-'){
            if(i>8){
                ans=0;
                break;
            }
            lenU=i;
            hyphen=1;
        }
    }
    lenT=i-lenU-1;
    
    puts((1<lenU&&lenU<=8)&&(1<=lenT&&lenT<=24)&&hyphen&&ans?"YES":"NO");
}
