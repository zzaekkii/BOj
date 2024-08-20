#include <stdio.h>

int N,D;
int ans;

int main(){
    scanf("%d %d",&N,&D);
    for(int i=1;i<=N;i++){
        int num=i;
        while(num>0){
            if(num%10==D)ans++;
            num/=10;
        }
    }
    printf("%d",ans);
}