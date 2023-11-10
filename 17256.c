#include <stdio.h>
int Ax,Ay,Az;
int Cx,Cy,Cz;
int main(){
    scanf("%d%d%d%d%d%d",&Ax,&Ay,&Az,&Cx,&Cy,&Cz);
    printf("%d %d %d",Cx-Az,Cy/Ay,Cz-Ax);
}
