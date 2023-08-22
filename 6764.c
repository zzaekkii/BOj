#include <stdio.h>
int A[4];
int u,d;
int main(){
    scanf("%d",&A[0]);
    for(int i=1;i<4;i++){
        scanf("%d",&A[i]);
        if(A[i]<A[i-1])d++;
        else if(A[i]>A[i-1])u++;
    }
    puts((!u&&!d)?"Fish At Constant Depth":u==3?"Fish Rising":d==3?"Fish Diving":"No Fish");
}
