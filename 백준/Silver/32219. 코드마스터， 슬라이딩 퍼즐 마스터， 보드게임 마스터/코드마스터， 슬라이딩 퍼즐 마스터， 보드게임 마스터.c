#include <stdio.h>

int T, R, C;

int main(){
    scanf("%d", &T);
    
    while(T--){
        scanf("%d %d", &R, &C);
        if(R==C)puts("dohoon");
        else{
            puts("jinseo");
            int tmp = R > C ? C : R;
            printf("%d %d\n", tmp, tmp);
        }
    }
}