#include <stdio.h>

int N, m, M, T, R;

int func(){
    if(m+T>M)return -1;
    
    int time=0,pul=m;
    while(N>0){
        if(pul+T<=M){
            pul+=T;
            N--;
        }
        else{
            pul-=R;
            if(pul<m)pul=m;
        }
        time++;
    }
    
    return time;
}

int main(){
    scanf("%d %d %d %d %d",&N,&m,&M,&T,&R);
    
    printf("%d",func());
}
