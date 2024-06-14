#iinclude <stdio.h>
double X,Y,Z;
int main(){
    scanf("%lf %lf %lf",&X,&Y,&Z);
    if(X+Y<=Z+0.5)puts("1");
    else puts("0");
}
