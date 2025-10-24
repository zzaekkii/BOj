#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))

int N;

long long A, B, T;

int main(){
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        scanf("%lld",&T);
        
        A=A*(T>9?100:10)+T;
    }
    
    
    for(int i=0;i<N;i++){
        scanf("%lld",&T);
        
        B=B*(T>9?100:10)+T;
    }
    
    printf("%lld",min(A,B));
}
