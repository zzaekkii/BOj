#include <stdio.h>
#include <string.h>
char S[20];
int main(){
    gets(S);
    if(!strcmp(S,"SONGDO"))puts("HIGHSCHOOL");
    else if(!strcmp(S,"CODE"))puts("MASTER");
    else if(!strcmp(S,"2023"))puts("0611");
    else if(!strcmp(S,"ALGORITHM"))puts("CONTEST");
}
