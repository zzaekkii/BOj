#include <stdio.h>
#include <string.h>

char S[1000001];
char z[1000001]="0";

int main(){
    scanf("%s",S);
    
    while(strlen(S)%3){
        strcat(z,S);
        strcpy(S,z);
        strcpy(z,"0");
    }
 
    for(int i=0;S[i];i+=3)
        printf("%d",(S[i]-48)*4+(S[i+1]-48)*2+(S[i+2]-48));
}
