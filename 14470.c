#include <stdio.h>
#include <stdlib.h>
int A,B,C,D,E;

int main(){
    scanf("%d %d %d %d %d",&A,&B,&C,&D,&E);
    if(A<0)printf("%d",abs(A)*C+D+B*E);
    else if(!A)printf("%d",D+(B-A)*E);
    else printf("%d",(B-A)*E);
}