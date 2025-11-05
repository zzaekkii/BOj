#include <stdio.h>
#define MAX 1000001

int T, N;
int prime[MAX]={0,1};

int main(){
    scanf("%d",&T);
    
    for(int i=2;i<MAX;i++)prime[i]=i;
    
    for(int i=2;i<MAX;i++)
        for(int j=i+i;j<MAX;j+=i)
            prime[j]=0;
    
    while(T--){
        scanf("%d",&N);
        
        int cnt=0;
        for(int i=2;i<N;i++)
            if(prime[i]+prime[N-i]==N)
                cnt+=1+(i==N-i);
        
        printf("%d\n",cnt/2);
    }
}