#include <stdio.h>
int N,W,H,L;

int main(){
    scanf("%d %d %d %d",&N,&W,&H,&L);
    if((W/L)*(H/L)>N)printf("%d",N);
    else printf("%d",(W/L)*(H/L));
}
