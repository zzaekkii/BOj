#include <stdio.h>

char S[14];
int total, tmp=1;

int main(){
    gets(S);
    
    for(int i=0;S[i];i++){
        if(S[i]=='*'){
            if(i%2)tmp=3;
            continue;
        }
        
        if(i%2) // 3.
            total+=3*(S[i]-48);
        else // 1.
            total+=(S[i]-48);
    }
    
    total%=10;
    for(int i=0;i<10;i++)
        if(!((total+(tmp*i))%10)){
            printf("%d",i);
            break;
        }
}
