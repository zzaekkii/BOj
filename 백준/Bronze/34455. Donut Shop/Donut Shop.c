#include <stdio.h>

int D, E, T;
char S;

int main() {
    scanf("%d %d " , &D, &E);
    
    while(E--){
        scanf("%c %d ", &S, &T);
        
        if(S == '-') D -= T;
        else D += T;
    }
    
    printf("%d", D);
}