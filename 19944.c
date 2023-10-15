#include <stdio.h>

int N, M;

int main(){
    scanf("%d%d",&N,&M);
    if(M<3)puts("NEWBIE!");
    else if(M<=N)puts("OLDBIE!");
    else puts("TLE!");
}
