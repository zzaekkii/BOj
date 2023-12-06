#include <stdio.h>
#include <string.h>
int N, M, T;
int arr[10001];

int main(){
    while(1){
        int mx=0;
        memset(arr,0,40004);
        scanf("%d%d",&N,&M);
        if(!N&&!M)break;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                scanf("%d",&T);
                arr[T]++;
                if(arr[T]>mx)mx=arr[T];
            }
        for(int i=1;i<10001;i++)
            if(arr[i]==mx)arr[i]=0;
        mx=0;
        for(int i=1;i<10001;i++)
            if(arr[i]>mx)mx=arr[i];
        for(int i=1;i<10001;i++)
            if(arr[i]==mx)printf("%d ",i);
        puts("");
    }
}
