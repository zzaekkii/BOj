#include <stdio.h>

int T;

int pt[]={13,7,5,3,3,2};
double total[2]={0,1.5};

int main(){
    for(int i=0;i<2;i++)
        for(int j=0;j<6;j++){
            scanf("%d",&T);
            total[i]+=T*pt[j];
        }
    
    puts(total[0]>total[1]?"cocjr0208":"ekwoo");
}