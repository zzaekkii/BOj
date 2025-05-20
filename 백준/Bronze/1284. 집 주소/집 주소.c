#include <stdio.h>

int N;

int main(){
    while(scanf("%d",&N)){
        if(!N)break;
        
        int sum=2; // 앞 뒤 여백.
        while(1){
            if(N%10==1)sum+=2;
            else if(N%10==0)sum+=4;
            else sum+=3;
            
            if(N<10)break;
            N/=10;
            sum+=1; // 띄어쓰기.
        }
        
        printf("%d\n",sum);
    }
}