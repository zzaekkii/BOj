#include <stdio.h>

double D;

int main(){
    scanf("%lf",&D);
    printf("%.2lf",(D/100)+25<100?100:(D/100)+25>2000?2000:D/100+25);
}
