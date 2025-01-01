#include <stdio.h>

char S[1000001];

int main(){
    gets(S);
    
    for(int i=0;S[i];i++){
        switch(S[i]){
            case 'a':
                printf("4");
                break;
            case 'e':
                printf("3");
                break;
            case 'i':
                printf("1");
                break;
            case 'o':
                printf("0");
                break;
            case 's':
                printf("5");
                break;
            default:
                printf("%c", S[i]);
                break;
        }
    }
}
