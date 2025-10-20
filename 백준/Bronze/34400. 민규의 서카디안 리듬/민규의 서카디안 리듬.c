#include <stdio.h>
#define DAY 25
#define WAKE 17

int T, N;

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        puts(N%DAY<WAKE?"ONLINE":"OFFLINE");
    }
}