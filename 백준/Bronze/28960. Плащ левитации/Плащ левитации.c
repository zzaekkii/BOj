#include <stdio.h>

int H,L,A,B;

int main(){
    scanf("%d%d%d%d",&H,&L,&A,&B);
    
    puts((A<=H*2&&B<=L)||(B<=H*2&&A<=L)?"YES":"NO");
}