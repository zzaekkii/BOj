#include <stdio.h>
#define PI 3.1415927
#define FT 12.0
#define MILE 5280.0

double D, R, T;

int main() {
    for(int c=1;;c++){
        scanf("%lf %lf %lf", &D, &R, &T);
        if(!R)break;
        
        double dist=D/(FT*MILE)*R*PI;
        printf("Trip #%d: %.2lf %.2lf\n", c, dist, dist/T*3600);
    }
}