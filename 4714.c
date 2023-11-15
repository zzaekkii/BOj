#include <stdio.h>
double X;

int main(){
    while(1){
        scanf("%lf",&X);
        if(X<0)break;
        printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n",X,X*0.167);
    }
}
