#include <stdio.h>
int N;

int main(){
    scanf("%d",&N);
    if(N>=620)puts("Red");
    else if(N>=590)puts("Orange");
    else if(N>=570)puts("Yellow");
    else if(N>=495)puts("Green");
    else if(N>=450)puts("Blue");
    else if(N>=425)puts("Indigo");
    else puts("Violet");
}