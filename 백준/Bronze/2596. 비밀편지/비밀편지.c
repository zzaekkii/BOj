#include <stdio.h>

char num[8][7] = {"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};

int N;
char S[55];
char ans[10];

int main(){
    scanf("%d ",&N);
    gets(S);
    
    for(int i=0,x=0;i<N;i++,x+=6){
        _Bool decode=0;
        
        for(int j=0;j<8;j++){
            int cnt=0;
            
            for(int k=0;k<6;k++){
                if(S[x+k]!=num[j][k]){
                    cnt++;
                }
            }
            
            if(!cnt||cnt==1){
                ans[i]=j+65;
                decode=1;
                break;
            }
        }
        
        if(!decode){
            printf("%d",i+1);
            return 0;
        }
    }
    
    ans[N]=0;    
    printf("%s",ans);
}