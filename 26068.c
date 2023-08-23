#include <stdio.h>
int cnt,T,N;
char a,b;
int main(){
    scanf("%d ",&T);
    while(T--){
        scanf("%c%c%d ",&a,&b,&N);
        if(N<91)cnt++;
    }
    printf("%d",cnt);
}
