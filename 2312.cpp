#include <stdio.h>
int T,N;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        if(!(N%2)){ // 짝수 미리 제거.
            int c=0;
            while(!(N%2))c++,N/=2;
            printf("2 %d\n",c);
        }
        for(int i=3;i*i<=N;i+=2) // 그 외 홀수.
            if(!(N%i)){
                int c=0;
                while(!(N%i))c++,N/=i;
                printf("%d %d\n",i,c);
            }
        if(N>1)printf("%d 1\n",N); // 홀수 제곱보다 작은 소수. ex: 5,7..
    }
}
