#include <stdio.h>
int N;
char S[]="WelcomeToSMUPC";
int main(){
    scanf("%d",&N);
    printf("%c",S[(N-1)%14]);
}
