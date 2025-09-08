#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int N;
int mn[10001], mx[10001];

int main(){
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++)
        mn[i]=0x3f3f3f3f;
    
    int meat=1, cnt=2; // 치킨, 사람 수.
    while(cnt<=N){
        for(int i=cnt;i<=N;i++){
            mn[i]=min(mn[i],mn[i-cnt]+meat);
            mx[i]=max(mx[i],mx[i-cnt]+meat);
        }
        int tmp=cnt;
        cnt+=meat;
        meat=tmp;
    }
    
    printf("%d %d",mn[N],mx[N]);
}