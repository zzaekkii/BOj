#include <stdio.h>

int A, P;

int main(){
    scanf("%d %d",&A,&P);
    puts(A*7>P*13?"Axel":A*7<P*13?"Petra":"lika");
}