#include <stdio.h>

int N;
int A[2];

int main(){
    for(int i=0;i<2;i++)
        for(int j=1;j<4;j++){
            scanf("%d",&N);
            A[i]+=j*N;
        }
    puts(A[0]>A[1]?"1":A[0]<A[1]?"2":"0");
}
