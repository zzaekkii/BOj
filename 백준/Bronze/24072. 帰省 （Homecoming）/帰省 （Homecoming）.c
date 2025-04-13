#include <stdio.h>

int start, leave, come;

int main(){
    scanf("%d %d %d", &start, &leave, &come);
    puts(start<=come&&come<leave?"1":"0");
}