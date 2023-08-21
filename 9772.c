#include <stdio.h>
double A,B;
int main(){
    while(1){
        scanf("%lf%lf",&A,&B);
        if(!A&&!B){
            puts("AXIS");
            break;
        }
        else if(!A||!B)puts("AXIS");
        else if(A>0&&B>0)puts("Q1");
        else if(A<0&&B>0)puts("Q2");
        else if(A<0&&B<0)puts("Q3");
        else if(A>0&&B<0)puts("Q4");
    }
}
