// 31048번 Last Factorial Digit - 브론즈4 / 사칙연산
#include <stdio.h>

int T, N;

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        int total=1;
        for(int i=2;i<=N;i++) total*=i;
        
        printf("%d\n",total%10);
    }
}
