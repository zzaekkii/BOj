#include <stdio.h>

int N,P,S,M,T;
_Bool f;

int main(){
    scanf("%d %d %d",&N,&P,&S);
    while(S--){
        scanf("%d",&M);
        f=0;
        while(M--){
            scanf("%d",&T);
            if(T==P)f=1;
        }
        if(f)puts("KEEP");
        else puts("REMOVE");
    }
}
