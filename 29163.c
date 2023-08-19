#include <stdio.h>
int N, T, od, ev;
int main(){
    scanf("%d",&N);
    while(N--){
        scanf("%d",&T);
        if(T%2)od++;
        else ev++;
    }
    puts(ev>od?"Happy":"Sad");
}
