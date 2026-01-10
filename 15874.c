#include <stdio.h>

int K, N;
char S[100001];

int main(){
    scanf("%d %d ", &K, &N);
    gets(S);
    for(int i=0;S[i];i++){
        if(65<=S[i]&&S[i]<=90){
            int tmp=S[i]-65;
            tmp=(tmp+K)%26;
            S[i]=tmp+65;
        }
        else if(97<=S[i]&&S[i]<=122){
            int tmp=S[i]-97;
            tmp=(tmp+K)%26;
            S[i]=tmp+97;
        }
    }
    puts(S);
}
