// 30868번 개표 - 브론즈4 / 구현
#include <stdio.h>

int T, N;

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N/5;i++)printf("++++ ");
        for(int i=0;i<N%5;i++)printf("|");
        puts("");
    }
}
