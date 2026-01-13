#include <stdio.h>
#include <string.h>

int N;
char univ[51];
int y, k;

int main() {
    scanf("%d ", &N);
    
    for(int i=0;i<N;i++){
        gets(univ);
        if(!strcmp(univ,"yonsei"))y=i;
        if(!strcmp(univ,"korea"))k=i;
    }
    
    puts(y<k?"Yonsei Won!":"Yonsei Lost...");
}