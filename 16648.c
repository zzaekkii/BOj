#include <stdio.h>

double T, P;

int main(){
    scanf("%lf %lf",&T,&P);
    
    double ans=0;
    if(P>=20){
        double per=(100-P)/T;
        ans+=(P-20)/per+20/(per/2);
    }
    else{
        double per=80/T+(20-P)*2/T;
        ans=P/(per/2);
    }
    printf("%.6lf",ans);
}
