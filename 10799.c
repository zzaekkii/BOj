// 10799번 쇠막대기 - 실버2 / 스택 or 구현
#include <stdio.h>

char S[100001];

int cur;
int del;
int ans;

int main(){
    gets(S);
    
    for(int i=1;S[i];i++){
        if(S[i]=='('){
            if(S[i-1]=='('){
                cur++;
            }
            else{ // )
                
            }
        }
        else{ // )
            if(S[i-1]=='('){
                ans+=cur+del;
                del=0;
            }
            else{ // )
                del++;
                cur--;
                if(cur==0){
                    ans+=del;
                    del=0;
                }
            }
        }
    }
    
    printf("%d",ans);
}
