#include <stdio.h>
#include <math.h>

int T;
long long N;

long long reverseInt(long long x){
    long long res=0;
    while(x){
        res=res*10+x%10;
        x/=10;
    }
    
    return res;
}

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld",&N);
        
        _Bool flag=0;
        long long tmp=sqrt(N);
        if(tmp*tmp==N){
            long long rev=reverseInt(N);
            long long rtmp=sqrt(rev);
            
            if(rtmp*rtmp==rev)flag=1;
        }
        
        puts(flag?"YES":"NO");
    }
}