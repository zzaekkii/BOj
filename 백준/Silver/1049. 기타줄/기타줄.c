#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define MAX 1001
#define PKG 6

int N, M, P, E;
int pk, ec;

int main(){
    pk=ec=MAX;
    scanf("%d %d",&N,&M);
    
    while(M--){
        scanf("%d %d",&P,&E);
        pk=min(pk,P);
        ec=min(ec,E);
    }
    
    printf("%d",min(ec*N,min(pk*(N/PKG)+ec*(N%PKG),pk*(N/PKG+1))));
}