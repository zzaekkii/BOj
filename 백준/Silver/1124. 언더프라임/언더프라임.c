#include <stdio.h>

int A,B;
_Bool notPrime[100001]={1,1};
int cnt[100001];

int ans;

int main(){
    for(int i=2;i<=100000;i++)
        if(!notPrime[i])
            for(int j=i+i;j<=100000;j+=i){
                notPrime[j]=1;
                
                int tmp=j;
                while(!(tmp%i)){
                    tmp/=i;
                    cnt[j]++;
                }
            }
    
    scanf("%d %d",&A,&B);
    
    for(int i=A;i<=B;i++)
        if(!notPrime[cnt[i]])ans++;
    
    printf("%d",ans);
}