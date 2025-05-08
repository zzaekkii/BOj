#include <stdio.h>
#define DAY 1440

int T, M, walk[2];
int total;

int main(){
    for(int i=0;i<2;i++){
        scanf("%d %d",&T,&M);
        walk[i]=T*60+M;
    }
    
    if(walk[1]<walk[0]) // 다음 날.
        total=DAY-walk[0]+walk[1];
    else total=walk[1]-walk[0];
    
    printf("%d %d",total,total/30);
}