#include <stdio.h>
int S,W;
int main(){
    scanf("%d%d",&S,&W);
    printf("%d",S>19?24-S+W:W-S);
}
