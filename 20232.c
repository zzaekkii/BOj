#include <stdio.h>
int Y;
int main(){
    scanf("%d",&Y);
    if(Y==1996||Y==1997||Y==2000||Y==2007||Y==2008||Y==2013||Y==2018)puts("SPbSU");
    else if(Y==2006)puts("PetrSU, ITMO");
    else puts("ITMO");
}
