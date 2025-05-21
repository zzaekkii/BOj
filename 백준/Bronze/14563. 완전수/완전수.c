#include <stdio.h>

int T,K;

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d", &K);
        
        int sum = 0;
        for (int i = 1; i * i <= K; i++)
            if (K % i == 0) {
                sum += i;
                
                if(i!=K/i)
                    sum += K / i;
            }
        
        if(sum>2*K)puts("Abundant");
        else if(sum==2*K)puts("Perfect");
        else puts("Deficient");
    }
}