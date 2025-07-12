#include <stdio.h>

int K;
char S[1001];

int main(){
    scanf("%d ",&K);
    
    for(int i=1;i<=K;i++){
        int ingre=0;
        
        gets(S);
        
        int cnt=0;
        for(int j=0;S[j];j++){
            if(S[j]=='o')ingre++;
            else{
                if(!ingre)cnt++;
                else ingre--;
            }
        }
        
        printf("Data Set %d:\n%d\n\n",i,cnt+ingre);
    }
}
